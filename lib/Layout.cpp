/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/Layout.h"

Layout::Layout() : Layout(0, 0, 0, 0){
    
}

Layout::Layout(sf::Vector2f position, sf::Vector2f size, LMN_LAYOUT_HORIZONTAL horizontalType) {
    this->setPosition(position);
    this->setSize(size);
    this->setType(horizontalType);
}

Layout::Layout(sf::Vector2f position, sf::Vector2f size) : Layout(position, size, ABSOLUTE) {
    
}

Layout::Layout(float positionX, float positionY, float width, float height, LMN_LAYOUT_HORIZONTAL horizontalType) {
    this->position.x = positionX;
    this->position.y = positionY;
    this->size.x = width;
    this->size.y = height;
    this->horizotalType = horizontalType;
    this->refreshBounds();
}

Layout::Layout(float positionX, float positionY, float width, float height) : Layout(positionX, positionY, width, height, ABSOLUTE) {
    
}

void Layout::setSize(sf::Vector2f size){
    this->size = size;
    this->refreshBounds();
}

void Layout::setSize(float width, float height) {
    this->size.x = width;
    this->size.y = height;
    this->refreshBounds();
}

sf::Vector2f Layout::getSize(){
    return this->size;
}

void Layout::setPosition(sf::Vector2f position) {
    this->position = position;
    this->refreshBounds();
}

void Layout::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
    this->refreshBounds();
}

sf::Vector2f Layout::getPosition() {
    return this->position;
}

void Layout::setPadding(float padding) {
    this->setPadding(padding, padding, padding, padding);
}

void Layout::setPadding(float paddingVertical, float paddingHorizontal) {
    this->setPadding(paddingVertical, paddingHorizontal, paddingVertical, paddingHorizontal);
}

void Layout::setPadding(float top, float right, float bottom, float left) {
    this->paddingVertical.x = top;
    this->paddingHorizontal.y = right;
    this->paddingVertical.y = bottom;
    this->paddingHorizontal.x = left;
}

void Layout::setPadding(LAYOUT_PADDING type, float padding){
    switch (type){
        case TOP:
            this->paddingVertical.x = padding;
            break;
        case RIGHT:
            this->paddingHorizontal.y = padding;
            break;
        case BOTTOM:
            this->paddingVertical.y = padding;
            break;
        case LEFT:
            this->paddingHorizontal.x = padding;
            break;
        case HORIZONTAL:
            this->paddingHorizontal.x = padding;
            this->paddingHorizontal.y = padding;
            break;
        case VERTICAL:
            this->paddingVertical.x = padding;
            this->paddingVertical.y = padding;
            break;
    }
}

sf::Vector2f Layout::getPadding(LAYOUT_PADDING type) {
    if (type == HORIZONTAL){
        return this->paddingHorizontal;
    }
    return this->paddingVertical;
}

void Layout::setType(LMN_LAYOUT_HORIZONTAL type){
    this->horizotalType = type;
    this->refreshBounds();
}

LMN_LAYOUT_HORIZONTAL Layout::getType(){
    return this->horizotalType;
}

sf::FloatRect Layout::getBounds() {
    return this->bounds;
}

void Layout::refreshBounds() {
    this->bounds.left = this->getPosition().x;
    this->bounds.top = this->getPosition().y;
    this->bounds.width = this->getSize().x;
    this->bounds.height = this->getSize().y;
}


void Layout::resize(Layout* parent) {
    this->refreshBounds();
    
    this->bounds.top = this->getPosition().y + parent->getBounds().top;
    
    switch(this->horizotalType){
        case PERCENTAGE:
            sf::Vector2f parentHorizontalPadding = parent->getPadding(HORIZONTAL);
            if (this->bounds.left <= 1){
                this->bounds.left = this->bounds.left * parent->getBounds().width + parent->getBounds().left + parentHorizontalPadding.x;
            }
            else{
                this->bounds.left = this->bounds.left + parent->getBounds().left + parentHorizontalPadding.x;
            }       
            this->bounds.width = this->bounds.width * parent->getBounds().width - (parentHorizontalPadding.x + parentHorizontalPadding.y);
            break;
    }       
}


void Layout::setRenderable(Renderable* object) {
    this->object = object;
}
