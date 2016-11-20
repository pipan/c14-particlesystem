/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/SelectRadioGroup.h"

SelectRadioGroup::SelectRadioGroup() : SelectRadioGroup(NULL){}

SelectRadioGroup::SelectRadioGroup(Radio* radio) : RadioGroup(radio){
    this->select(radio);
}

SelectRadioGroup::~SelectRadioGroup() {
}

void SelectRadioGroup::select(Radio* radio) {
    if (this->getSelected() != NULL && radio != NULL){
        if (this->getSelected()->getId() != radio->getId()){
            this->getSelected()->deselect();
            this->setSelected(radio);
            this->getSelected()->select();
            this->onChange();
        }
        return ;
    }
    
    if (this->getSelected() != NULL){
        this->getSelected()->deselect();
        this->onChange();
    }
    
    this->setSelected(radio);
    
    if (this->getSelected() != NULL){
        this->getSelected()->select();
        this->onChange();
    }
}
