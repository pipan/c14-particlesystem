/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <map>

#include <SFML/Window/Event.hpp>

#include "../include/EventHandler.h"
#include "../include/Provider.h"
#include "../include/MouseService.h"
#include "../include/FormService.h"
#include "../include/ShortcutService.h"
#include "../include/ColisionGrid.h"
#include "../include/Particle.h"

void EventHandler::addListener(Renderable* listener) {
    this->listeners.push_back(listener);
}

void EventHandler::removeListener(Renderable* listener) {
    this->listeners.remove(listener);
}

std::list<Renderable*>* EventHandler::getListeners() {
    return &(this->listeners);
}

void KeyboardEventHandler::fire(Event* event){
    Provider* provider = Provider::getInstance();
    FormService* formService = (FormService*) provider->get("formService");
    ShortcutService* shortcut = (ShortcutService*) provider->get("shortcut");
    KeyboardEvent* keyboardEvent = (KeyboardEvent*) event;
    
    if (formService->hasCurrentFocus()){
        keyboardEvent->setObject(formService->getCurrentFocus());
        formService->getCurrentFocus()->keyboard(keyboardEvent);
    }
    else{
        if (keyboardEvent->getType() == KEYBOARD){
            shortcut->fire(keyboardEvent);
        }
    }
}

