/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HorizontalDevider.h
 * Author: arksys
 *
 * Created on October 24, 2016, 9:46 PM
 */

#ifndef HORIZONTALDEVIDER_H
#define HORIZONTALDEVIDER_H

#include "Renderable.h"

/**
 * Visual element that provides simple horizontal line, that you can use to devide different parts of form.
 */
class HorizontalDevider : public Renderable{
    sf::Color color;
    sf::RectangleShape line;
public:
    /**
     * Create horizontal line with a provided color.
     * @param color
     */
    HorizontalDevider(sf::Color color);
    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    void update(sf::RenderWindow* window) override;
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    void render(sf::RenderWindow* window) override;
};

#endif /* HORIZONTALDEVIDER_H */

