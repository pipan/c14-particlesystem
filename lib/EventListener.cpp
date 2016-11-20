/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/EventListener.h"

EVENT_TYPE EventListener::getType(){
    return this->type;
}

void EventListener::setType(EVENT_TYPE type) {
    this->type = type;
}

void EventListener::setObject(void* object) {
    this->object = object;
}

void* EventListener::getObject() {
    return this->object;
}


MouseListener::MouseListener() : EventListener(){
    this->setType(MOUSE);
}

FormListener::FormListener() : EventListener() {
    this->setType(FOCUS);
}

InputListener::InputListener() : EventListener() {
    this->setType(INPUT);
}

KeyboardListener::KeyboardListener() : EventListener() {
    this->setType(KEYBOARD);
}

ChangeListener::ChangeListener() : EventListener() {
    this->setType(CHANGE);
}

ShortcutListener::ShortcutListener() {
    this->setType(KEYBOARD);
}

ParticleListener::ParticleListener() {
    this->setType(PARTICLE);
}
