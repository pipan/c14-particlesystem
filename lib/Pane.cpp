/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "../include/Pane.h"

Pane::Pane(){
    this->view = new sf::View();
}
Pane::Pane(Layout* layout) : Pane() {
    this->setLayout(layout);
}

void Pane::setView(sf::View* view) {
    this->view = view;
}

sf::View* Pane::getView(){
    return this->view;
}

void Pane::setBackgroundColor(sf::Color color) {
    this->backgroundColor = color;
    this->background.setFillColor(this->backgroundColor);
}

sf::Color Pane::getBackgroundColor() {
    return this->backgroundColor;
}

void Pane::update(sf::RenderWindow* window) {
    sf::FloatRect rect = this->view->getViewport();
    sf::Vector2u windowSize = window->getSize();
    
    this->getLayout()->setSize(sf::Vector2f(windowSize.x * rect.width, windowSize.y * rect.height));
    
    this->view->setCenter(windowSize.x * rect.width / 2, windowSize.y * rect.height / 2);
    this->view->setSize(this->getLayout()->getSize().x, this->getLayout()->getSize().y);
    
    this->background.setPosition(this->getLayout()->getPosition().x, this->getLayout()->getPosition().y);
    this->background.setSize(this->getLayout()->getSize());
    
    Layout* l;
    float width = this->getLayout()->getBounds().width;
    std::list<Layout*> percentage;
    std::list<Renderable*>::const_iterator end = this->getRenderableItems()->end();
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    while (iterator != end){
        l = (*iterator)->getLayout();
        switch (l->getType()){
            case PERCENTAGE:
                percentage.push_back(l);
                break;
            default:
                l->refreshBounds();
                width -= l->getBounds().width;
                break;
        }
        iterator++;
    }
    
    std::list<Layout*>::const_iterator lEnd = percentage.end();
    std::list<Layout*>::iterator lIterator = percentage.begin();
    while (lIterator != lEnd){
        (*lIterator)->setSize(width / percentage.size(), (*lIterator)->getSize().y);
        (*lIterator)->refreshBounds();
        lIterator++;
    }
    
    iterator = this->getRenderableItems()->begin();
    while (iterator != end){
        (*iterator)->update(window);
        iterator++;
    }
}


void Pane::render(sf::RenderWindow* window) {
//    this->layout.set(this->view);
//    this->view->setViewport()
    
    window->setView(*(this->view));
    
    window->draw(this->background);
    

    std::list<Renderable*>::const_iterator end = this->getRenderableItems()->end();
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    while (iterator != end){
        (*iterator)->render(window);
        iterator++;
    }
}
