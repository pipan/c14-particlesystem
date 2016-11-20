/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/RadioGroup.h"
#include "../include/Event.h"

RadioGroup::RadioGroup() : RadioGroup(NULL){

}

RadioGroup::RadioGroup(Radio* radio) {
    this->changeListener = NULL;
    
    this->selected = NULL;
}

RadioGroup::~RadioGroup() {}

void RadioGroup::setSelected(Radio* selected) {
    this->selected = selected;
}

Radio* RadioGroup::getSelected() {
    return this->selected;
}

bool RadioGroup::isSelected() {
    return  (this->selected != NULL);
}

void RadioGroup::setChangeListener(ChangeListener* listener) {
    this->changeListener = listener;
}

bool RadioGroup::hasChangeListener() {
    return (this->changeListener != NULL);
}

ChangeListener* RadioGroup::getChangeListener() {
    return this->changeListener;
}

void RadioGroup::onChange() {
    if(this->hasChangeListener()){
        Event* e = new Event();
        e->setObject(this->selected);
        this->getChangeListener()->onChange(e);
    }
}
