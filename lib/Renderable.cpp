/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <bits/stl_list.h>

#include "../include/Renderable.h"
#include "../include/Provider.h"
#include "../include/EventHandler.h"
#include "../include/ColisionGrid.h"
#include "../include/ShortcutService.h"
#include "../include/MouseService.h"

Renderable::Renderable() : Renderable(true){

}

Renderable::Renderable(bool registerToGrid) : MouseListener(){
    ColisionGrid* grid = (ColisionGrid*) (Provider::getInstance()->get("grid"));
    
    this->mouseListener = NULL;
    this->keyboardListener = NULL;
    this->parent = NULL;
    this->visible = true;
    
    this->id = Renderable::getNextId();
    this->renderItems = new std::list<Renderable*>();
    this->layout = new Layout();
    
    if (registerToGrid){
        grid->updateObject(this);
    }
}

Renderable::~Renderable(){
    ColisionGrid* grid = (ColisionGrid*) (Provider::getInstance()->get("grid"));
    grid->removeObject(this);
    delete this->layout;
}

int Renderable::currentId = 1;

int Renderable::getNextId() {
    int ret = Renderable::currentId;
    Renderable::currentId++;
    return ret;
}


int Renderable::getId() {
    return this->id;
}

void Renderable::hide() {
    this->setVisibility(false);
}

bool Renderable::isVisible() {
    return this->visible;
}

void Renderable::setVisibility(bool visible) {
    this->visible = visible;
    
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    std::list<Renderable*>::iterator end = this->getRenderableItems()->end();
    while (iterator != end){
        (*iterator)->setVisibility(this->isVisible());
        iterator++;
    }
}

void Renderable::show() {
    this->setVisibility(true);
}

int Renderable::getLevel() {
    if (this->parent == NULL){
        return 0;
    }
    return this->getParent()->getLevel() + 1;
}

Layout* Renderable::getLayout() {
    return this->layout;
}

void Renderable::setLayout(Layout* layout) {
    if (this->layout != NULL){
        delete this->layout;
    }
    
    this->layout = layout;
    layout->setRenderable(this);
}

void Renderable::addRenderable(Renderable* r){
    this->renderItems->push_back(r);
    r->setParent(this);
}

void Renderable::removeRenderable(Renderable* r) {
    this->renderItems->remove(r);
}

std::list<Renderable*>* Renderable::getRenderableItems() {
    return this->renderItems;
}

sf::FloatRect Renderable::getBounds() {
    if (this->layout != NULL){
        return this->layout->getBounds();
    }
    return sf::FloatRect();
}

bool Renderable::collision(float x, float y) {
    MouseService* mouseService = (MouseService*) Provider::getInstance()->get("mouseService");
    
    mouseService->isCollision(this, x, y);
}

void Renderable::keyboard(Event* event) {
    if (event->getType() != KEYBOARD){
        return ;
    }
    
    KeyboardEvent* keyboardEvent = (KeyboardEvent*) event;
    if (this->hasKeyboardListener()){
        if (keyboardEvent->isPressed()){
            this->getKeyboardListener()->onPress(keyboardEvent);
        }
        else{
            this->getKeyboardListener()->onReleas(keyboardEvent);
        }
    }
}

MouseListener* Renderable::getMouseListener() {
    return this->mouseListener;
}

void Renderable::setMouseListener(MouseListener* listener) {
    if (this->hasMouseListener()){
        delete this->mouseListener;
    }
    this->mouseListener = listener;
}

bool Renderable::hasMouseListener() {
    return (this->mouseListener != NULL);
}

void Renderable::setKeyboardListener(KeyboardListener* listener) {
    if (this->hasKeyboardListener()){
        delete this->keyboardListener;
    }
    this->keyboardListener = listener;
}

KeyboardListener* Renderable::getKeyboardListener() {
    return this->keyboardListener;
}

bool Renderable::hasKeyboardListener() {
    return (this->keyboardListener != NULL);
}

void Renderable::setParent(Renderable* parent) {
    this->parent = parent;
    if (this->parent != NULL && this->isVisible()){
        this->setVisibility(this->parent->isVisible());
    }
}

Renderable* Renderable::getParent() {
    return this->parent;
}

void Renderable::setShortcutListener(std::string uniqName, ShortcutListener* listener) {
    Provider* provider = Provider::getInstance();
    ShortcutService* shortcut = (ShortcutService*) provider->get("shortcut");
    
    listener->setObject(this);
    shortcut->registerCallback(uniqName, listener);
}

void Renderable::onClick(MouseEvent* event) {
    if (this->hasMouseListener()){
        this->getMouseListener()->onClick(event);
    }
    
    if (this->getParent() != NULL){
        this->parent->onClick(event);
    }
}

void Renderable::onDrag(MouseEvent* event) {
    if (this->hasMouseListener()){
        this->getMouseListener()->onDrag(event);
    }
}

void Renderable::onDrop(MouseEvent* event) {
if (this->hasMouseListener()){
        this->getMouseListener()->onDrop(event);
    }
}

void Renderable::onMove(MouseEvent* event) {
    if (this->hasMouseListener()){
        this->getMouseListener()->onMove(event);
    }
}
