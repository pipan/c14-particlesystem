/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SquareParticleShape.h
 * Author: arksys
 *
 * Created on November 10, 2016, 5:47 PM
 */

#ifndef SQUAREPARTICLESHAPE_H
#define SQUAREPARTICLESHAPE_H

#include <iostream>

#include "ParticleSystem.h"

class SquareParticleShape {
    ParticleSystem* system;
    int x;
    int y;
    sf::Vector2f position;
    float offset;
public:
    SquareParticleShape(Enviroment* env);
    SquareParticleShape(Enviroment* env, int x, int y, float offset, sf::Vector2f position);
    SquareParticleShape(Enviroment* env, int x, int y, float offset, float pX, float pY);
    virtual ~SquareParticleShape();

    void setDimension(int x, int y);
    void setOffset(float offset);
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);
    
    ParticleSystem* getSystem();
    float getOffset();
    int getX();
    int getY();
    sf::Vector2f getPosition();
    
    virtual ParticleSystem* generate(float mass, float stiffness);
};

#endif /* SQUAREPARTICLESHAPE_H */

