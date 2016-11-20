/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MouseService.h
 * Author: arksys
 *
 * Created on October 15, 2016, 1:10 AM
 */

#ifndef MOUSESERVICE_H
#define MOUSESERVICE_H

#include "Renderable.h"


/**
 * Service that provides methods that are connected to mouse actions.
 */
class MouseService {
public:
    /**
     * Method, that check if position x and y is in object.
     * 
     * @param Renderable* object
     * @param int x
     * @param int y
     * @return bool
     */
    bool isCollision(Renderable* object, int x, int y);
};

#endif /* MOUSESERVICE_H */

