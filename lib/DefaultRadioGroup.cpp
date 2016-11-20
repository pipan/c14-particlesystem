/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/DefaultRadioGroup.h"

DefaultRadioGroup::DefaultRadioGroup(Radio* def) : DefaultRadioGroup(def, NULL) {}

DefaultRadioGroup::DefaultRadioGroup(Radio* def, Radio* selected) : RadioGroup(selected) {
    this->def = def;
    if (selected == NULL){
        selected = this->def;
    }
    this->select(selected);
}

DefaultRadioGroup::~DefaultRadioGroup() {
}

void DefaultRadioGroup::select(Radio* radio) {
    if (radio == NULL){
        radio = this->def;
    }
    
    if (this->isSelected() && radio != NULL){
        if (this->getSelected()->getId() != radio->getId()){
            this->getSelected()->deselect();
            this->setSelected(radio);
            this->getSelected()->select();
            this->onChange();
        }
        return ;
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
