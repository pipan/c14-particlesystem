/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pane.h
 * Author: arksys
 *
 * Created on October 14, 2016, 12:05 AM
 */

#ifndef PANE_H
#define PANE_H


#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Renderable.h"
#include "Layout.h"

/**
 * Plate that holds renderable objects. This plate is used to devide window into multiple seperated parts.
 */
class Pane : public Renderable{
    sf::View* view;
    sf::RectangleShape background;
    sf::Color backgroundColor;
public:
    Pane();
    Pane(Layout* layout);
    
    /**
     * Assign a view for this plate.
     * 
     * @param sf::View* view
     */
    void setView(sf::View* view);
    /**
     * Retrieve view for this pane.
     * 
     * @return sf::View*
     */
    sf::View* getView();
    
    /**
     * Set background color for this pane.
     * 
     * @param sf::Color color
     */
    void setBackgroundColor(sf::Color color);
    /**
     * Getter for background color.
     * 
     * @return sf::Color
     */
    sf::Color getBackgroundColor();

    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    virtual void update(sf::RenderWindow* window) override;
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    virtual void render(sf::RenderWindow* window) override;
};

#ifdef __cplusplus
extern "C" {
#endif
    


#ifdef __cplusplus
}
#endif

#endif /* PANE_H */

