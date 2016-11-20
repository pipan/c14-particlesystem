/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Window/Event.hpp>
#include <iostream>

#include "../include/Event.h"

Event::Event() : Event(NULL){
    
}

Event::Event(sf::Event* sfmlEvent) {
    this->setEvent(sfmlEvent);
    this->object = NULL;
}

void Event::setEvent(sf::Event* event) {
    this->sfmlEvent = event;
}

sf::Event* Event::getEvent(){
    return this->sfmlEvent;
}

EVENT_TYPE Event::getType() {
    return this->type;
}

void Event::setType(EVENT_TYPE type) {
    this->type = type;
}

Renderable* Event::getObject() {
    return this->object;
}

void Event::setObject(Renderable* o) {
    this->object = o;
}

MouseEvent::MouseEvent() : MouseEvent(NULL){

}

MouseEvent::MouseEvent(sf::Event* sfmlEvent) : Event(sfmlEvent){
    this->setType(MOUSE);
    this->setEvent(sfmlEvent);
    this->buttonPressed = sf::Mouse::isButtonPressed(this->getButton());
}

void MouseEvent::setEvent(sf::Event* event) {
    Event::setEvent(event);   
    
    if (event != NULL){
        switch (event->type){
            case sf::Event::MouseMoved:
                this->x = event->mouseMove.x;
                this->y = event->mouseMove.y;
                break;
            default:
                this->x = event->mouseButton.x;
                this->y = event->mouseButton.y;
                this->button = event->mouseButton.button;
                break;
        }
    }
}

bool MouseEvent::isButton() {
    return !this->isMove();
}

bool MouseEvent::isButton(sf::Mouse::Button button) {
    if (this->isButton()){
        return (this->getButton() == button);
    }
    return false;
}

bool MouseEvent::isMove() {
    return (this->getEvent()->type == sf::Event::MouseMoved);
}

bool MouseEvent::isPressed() {
    return this->buttonPressed;
}

bool MouseEvent::isReleased() {
    return !this->isPressed();
}

sf::Mouse::Button MouseEvent::getButton() {
    return this->button;
}

int MouseEvent::getX() {
    return this->x;
}

int MouseEvent::getY() {
    return this->y;
}

CURSOR_TYPE MouseEvent::getCursorType() {
    return this->cursor;
}

void MouseEvent::setCursorType(CURSOR_TYPE cursor) {
    this->cursor = cursor;
}


FormEvent::FormEvent(Focusable* focusable) : Event(NULL){
    this->setType(FOCUS);
    this->focusable = focusable;
}

Focusable* FormEvent::getFocusable() {
    return this->focusable;
}

InputEvent::InputEvent(Focusable* focusable) : Event(NULL){
    this->setType(INPUT);
    this->focusable = focusable;
}

Focusable* InputEvent::getFocusable() {
    return this->focusable;
}

KeyboardEvent::KeyboardEvent(sf::Event* sfmlEvent, EVENT_TYPE type, bool pressed) : Event(sfmlEvent) {
    this->setType(type);
    this->pressed = pressed;
}

KeyboardEvent::KeyboardEvent(sf::Event* sfmlEvent, EVENT_TYPE type) : KeyboardEvent(sfmlEvent, type, true){

}

KeyboardEvent::KeyboardEvent(sf::Event* sfmlEvent, bool pressed) : KeyboardEvent(sfmlEvent, KEYBOARD, pressed){
    
}

char KeyboardEvent::getChar() {
    return this->getEvent()->text.unicode;
}

bool KeyboardEvent::isPressed() {
    return this->pressed;
}

ParticleEvent::ParticleEvent(Particle* p) : Event(NULL){
    this->setType(PARTICLE);
    this->particle = p;
}

Particle* ParticleEvent::getParticle() {
    return this->particle;
}
