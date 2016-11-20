/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/Radio.h"

Radio::Radio() : Radio(false){
    
}

Radio::Radio(bool selected) : Renderable(){
    this->setSelected(selected);
}

void Radio::deselect() {
    this->setSelected(false);
}

bool Radio::isSelected() {
    return this->selected;
}

void Radio::select() {
    this->setSelected(true);
}

void Radio::setSelected(bool selected) {
    this->selected = selected;
}
