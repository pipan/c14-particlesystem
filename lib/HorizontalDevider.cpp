/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Window.hpp>

#include "../include/HorizontalDevider.h"

HorizontalDevider::HorizontalDevider(sf::Color color) : Renderable() {
    this->color = color;
    this->line.setFillColor(this->color);
}

void HorizontalDevider::update(sf::RenderWindow* window) {
    this->getLayout()->resize(this->getParent()->getLayout());
    
    sf::FloatRect rect = this->getBounds();
    this->line.setPosition(rect.left, rect.top);
    this->line.setSize(sf::Vector2f(rect.width, rect.height));
}

void HorizontalDevider::render(sf::RenderWindow* window) {
    window->draw(this->line);
}
