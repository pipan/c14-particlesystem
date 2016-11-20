/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constraint.h
 * Author: arksys
 *
 * Created on October 22, 2016, 5:00 PM
 */

#ifndef CONSTRAINT_H
#define CONSTRAINT_H

class ParticleSystem;

#include "Renderable.h"

/**
 * This is the interface for every constraint. It implements renderable and update methods from renderable and adds one specific method execute, that actually computes constraint.
 */
class Constraint{
    ParticleSystem* system;
public:
    Constraint();
    virtual ~Constraint();

    void setSystem(ParticleSystem* system);
    ParticleSystem* getSystem();
    bool hasSystem();
    
    /**
     * Get unique number of this object.
     * 
     * @return int
     */
    virtual int getId() = 0;
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    virtual void render(sf::RenderWindow* window) = 0;
    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    virtual void update(sf::RenderWindow* window) = 0;
    /**
     * Method that is called during constraint projection method in particle system.
     * 
     * @param float deltaTime
     * @param int projectionCount
     */
    virtual void execute(float deltaTime, int projectionCount) = 0;
};

#endif /* CONSTRAINT_H */

