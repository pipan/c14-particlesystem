/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/ColisionGridObject.h"

ColisionGridObject::ColisionGridObject(Renderable* object){
    this->object = object;
    this->previous = this->object->getBounds();
}

sf::FloatRect ColisionGridObject::getCurrentRect() {
    return this->object->getBounds();
}

int ColisionGridObject::getId() {
    return this->object->getId();
}

Renderable* ColisionGridObject::getObject() {
    return this->object;
}

sf::FloatRect ColisionGridObject::getPreviousRect() {
    return this->previous;
}

void ColisionGridObject::swap() {
    this->previous = this->object->getBounds();
}
