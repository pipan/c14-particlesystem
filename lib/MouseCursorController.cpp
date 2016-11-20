/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <map>

#include <SFML/Window/Event.hpp>

#include "../include/MouseCursorController.h"
#include "../include/Provider.h"
#include "../include/MouseService.h"
#include "../include/FormService.h"
#include "../include/ShortcutService.h"
#include "../include/ColisionGrid.h"
#include "../include/Particle.h"

PointerCursorController::PointerCursorController() {
    this->pressedObject = NULL;
    this->pressedObjectMoved = false;
}

void PointerCursorController::eventAll(MouseEvent* mouseEvent) {
    Provider* provider = Provider::getInstance();
    ColisionGrid* grid = (ColisionGrid*) provider->get("grid");
    MouseService* mouseService = (MouseService*) provider->get("mouseService");
    std::map<int, ColisionGridObject*>* objects = grid->getColision(mouseEvent->getX(), mouseEvent->getY());
    if (objects == NULL){
        return ;
    }
    
    std::map<int, ColisionGridObject*>::iterator i = objects->begin();
    std::map<int, ColisionGridObject*>::iterator iEnd = objects->end();

    while (i != iEnd){
        if (i->second->getObject()->isVisible() && i->second->getObject()->collision(mouseEvent->getX(), mouseEvent->getY())){
            mouseEvent->setObject(i->second->getObject());
            switch (mouseEvent->getEvent()->type){
                case sf::Event::MouseButtonPressed:
                    
                    break;
                case sf::Event::MouseButtonReleased:
                    i->second->getObject()->onClick(mouseEvent);
                    break;
                case sf::Event::MouseMoved:
                    i->second->getObject()->onMove(mouseEvent);
                    break;
            }
        }
        i++;
    }
}

void PointerCursorController::fire(Event* event){    
    Provider* provider = Provider::getInstance();
    MouseService* mouseService = (MouseService*) provider->get("mouseService");
    FormService* formService = (FormService*) provider->get("formService");
    ColisionGrid* grid = (ColisionGrid*) provider->get("grid");
    MouseEvent* mouseEvent = (MouseEvent*) event;
    
    Renderable* maxLevel = NULL;
    std::map<int, ColisionGridObject*>* objects = grid->getColision(mouseEvent->getX(), mouseEvent->getY());
    if (objects == NULL){
        return ;
    }
    
    if (event->getEvent()->type == sf::Event::MouseButtonPressed){
        std::map<int, ColisionGridObject*>::iterator i = objects->begin();
        std::map<int, ColisionGridObject*>::iterator iEnd = objects->end();

        while (i != iEnd){
            if (i->second->getObject()->isVisible() && i->second->getObject()->collision(mouseEvent->getX(), mouseEvent->getY())){
                if (maxLevel == NULL || maxLevel->getLevel() <= i->second->getObject()->getLevel()){
                    maxLevel = i->second->getObject();
                }
            }
            i++;
        }
        
        this->pressedObject = maxLevel;
        
        return ;
    }
    
    if (this->pressedObject != NULL ){
        mouseEvent->setObject(this->pressedObject);
        switch (mouseEvent->getEvent()->type){
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                if (this->pressedObjectMoved){
                    this->pressedObject->onDrop(mouseEvent);
                }
                else{
                    this->pressedObject->onClick(mouseEvent);
                    formService->blur(mouseEvent);
                }
                this->pressedObject = NULL;
                this->pressedObjectMoved = false;
                break;
            case sf::Event::MouseMoved:
                this->pressedObjectMoved = true;
                this->pressedObject->onDrag(mouseEvent);
                break;
        }
    }
    else{
        this->eventAll(mouseEvent);
    }    
}

AddCursorController::AddCursorController() {

}

void AddCursorController::fire(Event* event) {
    Provider* provider = Provider::getInstance();
    MouseService* mouseService = (MouseService*) provider->get("mouseService");
    FormService* formService = (FormService*) provider->get("formService");
    ColisionGrid* grid = (ColisionGrid*) provider->get("grid");
    MouseEvent* mouseEvent = (MouseEvent*) event;
}

RemoveCursorController::RemoveCursorController() {

}

void RemoveCursorController::fire(Event* event) {
    Provider* provider = Provider::getInstance();
    MouseService* mouseService = (MouseService*) provider->get("mouseService");
    FormService* formService = (FormService*) provider->get("formService");
    ColisionGrid* grid = (ColisionGrid*) provider->get("grid");
    MouseEvent* mouseEvent = (MouseEvent*) event;
}
