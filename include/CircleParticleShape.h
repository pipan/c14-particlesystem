/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircleParticleShape.h
 * Author: arksys
 *
 * Created on November 10, 2016, 9:19 PM
 */

#ifndef CIRCLEPARTICLESHAPE_H
#define CIRCLEPARTICLESHAPE_H

#define _USE_MATH_DEFINES
#include <cmath>

#include "SquareParticleShape.h"

class CircleParticleShape : public SquareParticleShape {
public:
    CircleParticleShape(Enviroment* env);
    CircleParticleShape(Enviroment* env, int x, int y, float offset, sf::Vector2f position);
    CircleParticleShape(Enviroment* env, int x, int y, float offset, float pX, float pY);
    virtual ~CircleParticleShape();    

    ParticleSystem* generate(float mass, float stiffness) override;
};

#endif /* CIRCLEPARTICLESHAPE_H */

