/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageButton.h
 * Author: arksys
 *
 * Created on October 14, 2016, 9:24 PM
 */

#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <string>

#include "Radio.h"
#include "EventListener.h"
#include "Event.h"

/**
 * Clickable button that has an image as a visibla and clickable object.
 */
class ImageButton : public Radio{
    sf::Color color;
    sf::Vector2i position;
    sf::Vector2f size;
protected:
    sf::RectangleShape shape;
    sf::Texture texture;
public:
    ImageButton();
    /**
     * Create and image button ot of path to the image and a button size.
     * 
     * @param std::string path
     * @param sf::Vector2f size
     */
    ImageButton(std::string path, sf::Vector2f size);
    /**
     * Set button position.
     * 
     * @param sf::Vector2i position
     */
    void setPosition(sf::Vector2i position);
    /**
     * Retreieve button position.
     * 
     * @return sf::Vector2i
     */
    sf::Vector2i getPosition();
    /**
     * Set button size.
     * 
     * @param sf::Vector2f size
     */
    void setSize(sf::Vector2f size);
    /**
     * Retrieve button size.
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getSize();
    /**
     * Set image for this button by specifying path to an image.
     * 
     * @param std::string imgPath
     */
    void loadImage(std::string imgPath);

    /**
     * Set color of an image.
     * 
     * @param sf::Color color
     */
    void setColor(sf::Color color);
    /**
     * Get image color.
     * 
     * @return sf::Color
     */
    sf::Color getColor();

    void setSelected(bool selected) override;
    
    /**
    * Retrieve size and position of this object.
    * 
    * @return sf::FloatRect
    */
    sf::FloatRect getRect();

    /**
    * update the position of elements. It might change because of the window size changed or because parent element changed its position.
    * 
    * @param sf::RenderWindow* window
    */
    virtual void update(sf::RenderWindow* window);
    /**
    * render object to window
    * 
    * @param sf::RenderWindow* window
    */
    virtual void render(sf::RenderWindow* window);
};

/**
 * On click listener for image button object
 */
class ImageButtonOnClickListener : public MouseListener{
public:
    /**
     * This method is trigered when user click on a object.
     * 
     * @param MouseEvent* event
     */
    virtual void onClick(MouseEvent* event) override;
    void onDrag(MouseEvent* event) override;
};

#endif /* IMAGEBUTTON_H */

