/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParticleSystemGenerator.h
 * Author: arksys
 *
 * Created on December 6, 2016, 11:10 PM
 */

#ifndef PARTICLESYSTEMGENERATOR_H
#define PARTICLESYSTEMGENERATOR_H

#include "ParticleSystem.h"
#include "CircleParticleShape.h"
#include "TriangleParticleShape.h"
#include "SquareParticleShape.h"

class ParticleSystemGenerator {
public:
    ParticleSystemGenerator();
    void generateSquare(ParticleSystem* pSys);
    void generateTriangle(ParticleSystem* pSys);
    void generateCircle(ParticleSystem* pSys);
};

#endif /* PARTICLESYSTEMGENERATOR_H */

