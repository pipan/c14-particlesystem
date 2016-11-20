/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Layout.h
 * Author: arksys
 *
 * Created on October 14, 2016, 8:22 PM
 */

#ifndef LAYOUT_H
#define LAYOUT_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Template.h"
#include "System/Enum.h"

class Renderable;

class Layout{
    sf::Vector2f size;
    sf::Vector2f position;
    sf::FloatRect bounds;
    sf::Vector2f paddingHorizontal;
    sf::Vector2f paddingVertical;
    LMN_LAYOUT_HORIZONTAL horizotalType;
    Renderable* object;
public:
    /**
     * Create new empty Layout
     */
    Layout();
    /**
     * Create layout with specified position and size
     * 
     * @param sf::Vector2f position
     * @param sf::Vector2f size
     */
    Layout(sf::Vector2f position, sf::Vector2f size);
    /**
     * Create Layout with specified position size and type of behavior in horizontal axes.
     * 
     * @param sf::Vector2f position
     * @param sf::Vector2f size
     * @param LMN_LAYOUT_HORIZONTAL horizontalType
     */
    Layout(sf::Vector2f position, sf::Vector2f size, LMN_LAYOUT_HORIZONTAL horizontalType);
    /**
     * Create layout with specified position and size
     * 
     * @param float positionX
     * @param float positionY
     * @param float width
     * @param float height
     */
    Layout(float positionX, float positionY, float width, float height);
    /**
     * Create Layout with specified position size and type of behavior in horizontal axes.
     * 
     * @param float positionX
     * @param float positionY
     * @param float width
     * @param float height
     * @param LMN_LAYOUT_HORIZONTAL horizontalType
     */
    Layout(float positionX, float positionY, float width, float height, LMN_LAYOUT_HORIZONTAL horizontalType);
    
    /**
     * Set layout size.
     * 
     * @param sf::Vector2f size
     */
    void setSize(sf::Vector2f size);
    /**
     * Set layout size.
     * 
     * @param float width
     * @param float height
     */
    void setSize(float width, float height);
    /**
     * Retrieve layout size.
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getSize();
    
    /**
     * Set layout position.
     * 
     * @param sf::Vector2f position
     */
    void setPosition(sf::Vector2f position);
    /**
     * Set layout position.
     * 
     * @param float x
     * @param float y
     */
    void setPosition(float x, float y);
    /**
     * Retrieve layout position.
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getPosition();
    
    /**
     * Set padding for all sides (top, right, bottom, left)
     * 
     * @param float padding
     */
    void setPadding(float padding);
    /**
     * Set padding for oposite sides.
     * 
     * @param paddingVertical padding for top and bottom
     * @param paddingHorizontal padding for left and right
     */
    void setPadding(float paddingVertical, float paddingHorizontal);
    /**
     * Set padding for certain side. You have to specify side by LAYOUT_PADDING type.
     * 
     * @param LAYOUT_PADDING type
     * @param float padding
     */
    void setPadding(LAYOUT_PADDING type, float padding);
    /**
     * Set padding for each side individually
     * 
     * @param float top
     * @param float right
     * @param float bottom
     * @param float left
     */
    void setPadding(float top, float right, float bottom, float left);
    /**
     * Retrieve padding specified by LAYOUT_PADDING type parameter.
     * 
     * @param LAYOUT_PADDING type
     * @return sf::Vector2f
     */
    sf::Vector2f getPadding(LAYOUT_PADDING type);
    
    /**
     * Retrieve layout size and position of left top corner.
     * 
     * @return sf::FloatRect
     */
    sf::FloatRect getBounds();
    /**
     * Assign values from size and position to rect variable.
     */
    void refreshBounds();
    
    /**
     * Set horizontal behavior for this layout. You can have percentage or absolute behavior.
     * 
     * @param LMN_LAYOUT_HORIZONTAL
     */
    void setType(LMN_LAYOUT_HORIZONTAL);
    /**
     * Retrieve horizontal behavior for this layout. You can have percentage or absolute behavior.
     * @return LMN_LAYOUT_HORIZONTAL
     */
    LMN_LAYOUT_HORIZONTAL getType();
    
    /**
     * Recompute size and position for this layout.
     * 
     * @param Layout* parent layout of a parent object
     */
    void resize(Layout* parent);
    
    /**
     * Assign object that is using this layout.
     * 
     * @param Renderable* object
     */
    void setRenderable(Renderable* object);
};


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* LAYOUT_H */

