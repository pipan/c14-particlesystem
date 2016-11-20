/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/FormService.h"
#include "../include/Event.h"

FormService::FormService() {
    this->currentFocus = NULL;
    this->shouldBlur = true;
}


void FormService::focus(Event* e){
    Focusable* object = (Focusable*) e->getObject();
    
    if (this->currentFocus != object){
        if (this->currentFocus != NULL){
            this->currentFocus->blur();
        }
        if (object != NULL){
            object->focus();
        }
        this->currentFocus = object;
    }
    
    this->shouldBlur = false;
}

void FormService::blur(Event* e) {
    if (this->shouldBlur && this->currentFocus != NULL){
        this->currentFocus->blur();
        this->currentFocus = NULL;
    }
    
    this->shouldBlur = true;
}

bool FormService::hasCurrentFocus() {
    return (this->currentFocus != NULL);
}

Focusable* FormService::getCurrentFocus() {
    return this->currentFocus;
}

