/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/SectionBlock.h"


void SectionBlock::update(sf::RenderWindow* window) {
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    std::list<Renderable*>::iterator end = this->getRenderableItems()->end();
    while (iterator != end){
        (*iterator)->update(window);
        iterator++;
    }
}

void SectionBlock::render(sf::RenderWindow* window){
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    std::list<Renderable*>::iterator end = this->getRenderableItems()->end();
    while (iterator != end){
        (*iterator)->render(window);
        iterator++;
    }
}
