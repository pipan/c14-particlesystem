/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Shape.hpp>

#include "../include/LabelInput.h"

LabelInput::LabelInput(std::string label, std::string value) : LabelInput(label, value, ""){
    
}

LabelInput::LabelInput(std::string label, std::string value, std::string placeholder) : Renderable(){
    this->label = label;
    this->input = new Input(value, placeholder);
    this->addRenderable(this->input);
    
    if (!this->font.loadFromFile("assets/fonts/arial.ttf")){
        std::cout << "LOAD FONT ERROR";
        //ERROR
    }
    this->renderLabel.setFont(this->font);
    this->renderLabel.setColor(*Template::getActive()->getForegroundLight());
    this->renderLabel.setCharacterSize(16);
    this->renderLabel.setString(this->label);
    
    this->labelBg.setOutlineThickness(1);
    this->labelBg.setOutlineColor(*Template::getActive()->getBackgroundLight());
    this->labelBg.setFillColor(sf::Color::Transparent);
}

LabelInput::~LabelInput() {
    delete this->input;
}

void LabelInput::update(sf::RenderWindow* window) {
    this->getLayout()->resize(this->getParent()->getLayout());
    
    sf::FloatRect myBound = this->getLayout()->getBounds();
    
    this->renderLabel.setPosition(myBound.left + 12, myBound.top + 6);
    
    this->labelBg.setPosition(myBound.left, myBound.top);
    this->labelBg.setSize(sf::Vector2f(this->renderLabel.getLocalBounds().width + 24, myBound.height));
    
    this->input->getLayout()->setPosition(myBound.left + this->renderLabel.getLocalBounds().width + 24, 0);
    this->input->getLayout()->setSize(myBound.width - (this->renderLabel.getLocalBounds().width + 24), myBound.height);
    
    this->input->update(window);
}

Input* LabelInput::getInput() {
    return this->input;
}

void LabelInput::render(sf::RenderWindow* window) {
    
    if (this->input->hasFocus()){
        this->labelBg.setOutlineColor(*Template::getActive()->getAccent());
    }
    else{
        this->labelBg.setOutlineColor(*Template::getActive()->getBackgroundLight());
    }
    window->draw(this->labelBg);
    window->draw(this->renderLabel);
    
    this->input->render(window);
}
