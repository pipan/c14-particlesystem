/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/ToggleRadioGroup.h"

ToggleRadioGroup::ToggleRadioGroup() : ToggleRadioGroup(NULL){}

ToggleRadioGroup::ToggleRadioGroup(Radio* radio) : RadioGroup(radio){
    this->select(radio);
}

ToggleRadioGroup::~ToggleRadioGroup() {}

void ToggleRadioGroup::select(Radio* radio) {
    if (this->isSelected() && radio != NULL){
        if (this->getSelected()->getId() != radio->getId()){
            this->getSelected()->deselect();
            this->setSelected(radio);
            this->getSelected()->select();
            this->onChange();
            return ;
        }
        else{
            radio = NULL;
        }
    }
    
    if (this->isSelected()){
        this->getSelected()->deselect();
        this->onChange();
    }
    
    this->setSelected(radio);
    
    if (this->isSelected()){
        this->getSelected()->select();
        this->onChange();
    }
}
