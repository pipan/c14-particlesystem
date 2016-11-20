/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TriangleParticleShape.h
 * Author: arksys
 *
 * Created on November 10, 2016, 6:39 PM
 */

#ifndef TRIANGLEPARTICLESHAPE_H
#define TRIANGLEPARTICLESHAPE_H

#include "SquareParticleShape.h"

class TriangleParticleShape : public SquareParticleShape {
public:
    TriangleParticleShape(Enviroment* env);
    TriangleParticleShape(Enviroment* env, int x, int y, float offset, sf::Vector2f position);
    TriangleParticleShape(Enviroment* env, int x, int y, float offset, float pX, float pY);
    virtual ~TriangleParticleShape();    

    ParticleSystem* generate(float mass, float stiffness) override;
};

#endif /* TRIANGLEPARTICLESHAPE_H */

