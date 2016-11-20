/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColisionGridObject.h
 * Author: arksys
 *
 * Created on October 17, 2016, 7:35 PM
 */

#ifndef COLISIONGRIDOBJECT_H
#define COLISIONGRIDOBJECT_H

#include "Renderable.h"

/**
 * this object takes cae of renderable object in window and transfer it into object that can be put into grid system. It means it stores previous size and position of the object.
 */
class ColisionGridObject{
    Renderable* object;
    sf::FloatRect previous;
public:
    /**
     * creating grid object from renderable object
     * 
     * @param Renderable* object
     */
    ColisionGridObject(Renderable* object);
    /**
     * retrieve object id
     * 
     * @return int
     */
    int getId();
    /**
     * retrieve renderable object
     * 
     * @return Renderable*
     */
    Renderable* getObject();
    /**
     * get previous size and position of renderable object
     * 
     * @return sf::FloatRect
     */
    sf::FloatRect getPreviousRect();
    /**
     * get current size and position of renderable object
     * 
     * @return sf::FloatRect
     */
    sf::FloatRect getCurrentRect();
    /**
     * set value of previous position and size to the value of current position and size
     * 
     * @return sf::FloatRect
     */
    void swap();
};

#endif /* COLISIONGRIDOBJECT_H */

