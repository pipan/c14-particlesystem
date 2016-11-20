/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "../include/ImageButton.h"

ImageButton::ImageButton() : Radio(){
    this->setColor(*Template::getActive()->getForegroundLight());
    
    this->texture.setSmooth(false);
    this->texture.setRepeated(false);
}

ImageButton::ImageButton(std::string path, sf::Vector2f size) : ImageButton(){
    this->loadImage(path);
    this->setSize(size);
}


void ImageButton::setPosition(sf::Vector2i position){
    this->position = position;
}

sf::Vector2i ImageButton::getPosition() {
    return this->position;
}


void ImageButton::setSize(sf::Vector2f size){
    this->size = size;
}

sf::Vector2f ImageButton::getSize() {
    return this->size;
}


void ImageButton::loadImage(std::string imgPath){
    if (!this->texture.loadFromFile(imgPath)){
        std::cout << "CHYBA PRI CITANI OBRAZKU";
        return ;
    }
       
    this->shape.setTexture(&(this->texture));
}

void ImageButton::setColor(sf::Color color) {
    this->color = color;
}

sf::Color ImageButton::getColor() {
    return this->color;
}

void ImageButton::setSelected(bool selected) {
    Radio::setSelected(selected);
    
    if (this->isSelected()){
        this->setColor(*Template::getActive()->getAccent());
    }
    else{
        this->setColor(*Template::getActive()->getForegroundLight());
    }
}

sf::FloatRect ImageButton::getRect(){
    return this->shape.getGlobalBounds();
}

void ImageButton::update(sf::RenderWindow* window){
    this->getLayout()->resize(this->getParent()->getLayout());
    
    sf::FloatRect rect = this->getBounds();
    this->shape.setPosition(rect.left, rect.top);
    this->shape.setSize(sf::Vector2f(rect.width, rect.height));
}

void ImageButton::render(sf::RenderWindow* window){
    this->shape.setSize(this->getSize());
    this->shape.setFillColor(this->getColor());
    
    window->draw(this->shape);
}

/*On Click Listener*/
void ImageButtonOnClickListener::onClick(MouseEvent* event){
    ImageButton* button = (ImageButton*) event->getObject();
    button->setColor(sf::Color(255, 152, 0, 255));
}

void ImageButtonOnClickListener::onDrag(MouseEvent* event) {

}
