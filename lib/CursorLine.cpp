/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "../include/CursorLine.h"
#include "../include/Provider.h"

CursorLine::CursorLine() {
    Provider* provider = Provider::getInstance();
    this->time = (TimeService*) provider->get("time");
    this->cursotPosition = 0;
    this->visible = true;
    this->lastChange = this->time->now();
    this->line.setFillColor(sf::Color(*Template::getActive()->getAccent()));
}

void CursorLine::setCursorPosition(int position) {
    this->cursotPosition = position;
}

int CursorLine::getCursorPosition() {
    return this->cursotPosition;
}

void CursorLine::inc() {
    this->cursotPosition++;
}

void CursorLine::inc(int max) {
    if (this->cursotPosition < max){
        this->inc();
    }
}

void CursorLine::dec() {
    this->cursotPosition--;
}

void CursorLine::dec(int min) {
    if (this->cursotPosition > min){
        this->dec();
    }
}

void CursorLine::update(sf::RenderWindow* window) {

    this->getLayout()->refreshBounds();
}

void CursorLine::render(sf::RenderWindow* window){
    sf::Int32 now = this->time->now();
    sf::FloatRect myBound = this->getLayout()->getBounds();
    
    if (this->visible){
        if (now - CURSOR_SHOW_DURATION > this->lastChange){
            this->lastChange = now;
            this->visible = false;
        }
    }
    else{
        if (now - CURSOR_HIDE_DURATION > this->lastChange){
            this->lastChange = now;
            this->visible = true;
        }
    }
    
    if (this->visible){
        this->line.setPosition(myBound.left - (myBound.width / 2), myBound.top);
        this->line.setSize(this->getLayout()->getSize());
        window->draw(this->line);
    }
}
