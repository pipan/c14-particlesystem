/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constraint.h
 * Author: arksys
 *
 * Created on October 21, 2016, 5:11 PM
 */

#ifndef DISTANCECONSTRAINT_H
#define DISTANCECONSTRAINT_H

#include <SFML/System/Vector2.hpp>

#include "Provider.h"
#include "RadioGroup.h"
#include "Particle.h"
#include "Constraint.h"
#include "VectorMath.h"

class DistanceConstraint : public Radio, public Constraint {
    VectorMath* vectorMath;
    float distance;
    float stiffness;
    Particle *p1;
    Particle *p2;
    float clickThickness;
    
    sf::Vector2f outerPosition(Particle* p1, Particle* p2);
public:
    /**
     * Create new distance constraint for two particles and stiffness. Stable distance is going to be the distance between two particles when the constraint is created.
     * 
     * @param Particle* p1
     * @param Particle* p2
     * @param float stiffness
     */
    DistanceConstraint(Particle* p1,  Particle* p2, float stiffness);
    /**
     * Create new distance constraint for two particles, stiffness, and stable distance between two particles.
     * 
     * @param Particle* p1
     * @param Particle* p2
     * @param float stiffness
     */
    DistanceConstraint(Particle* p1,  Particle* p2, float stiffness, float distance);
    /**
     * Destructor
     */
    virtual ~DistanceConstraint();
    
    /**
     * Get the stable distance of particles in constraint.
     * @return 
     */
    float getDistance();
    /**
     * Get the value of constraint stiffness
     * @return 
     */
    float getStiffness();

    /**
     * Set distance between two particles when they are in stable state.
     * 
     * @param float d
     */
    void setDistance(float d);
    /**
     * Set stiffness of this constraint. The lower the value the less stiff the string is. Stiffness with a value of 1.0 is actually solid connection.
     * 
     * @param s
     */
    void setStiffness(float s);
        
    bool hasParticle(Particle* p);
    
    sf::FloatRect getBounds() override;
    bool collision(float x, float y) override;
    
    int getId() override;

    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    void render(sf::RenderWindow* window);
    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    void update(sf::RenderWindow* window);
    /**
     * Method that is called during constraint projection method in particle system.
     * 
     * @param float deltaTime
     * @param int projectionCount
     */
    void execute(float deltaTime, int projectionCount);
    
    void onClick(MouseEvent* event) override;
public:
    
};

#endif /* DISTANCECONSTRAINT_H */