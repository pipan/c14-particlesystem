/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorMath.h
 * Author: arksys
 *
 * Created on October 22, 2016, 7:38 PM
 */

#ifndef VECTORMATH_H
#define VECTORMATH_H

#include <SFML/System.hpp>

#include "Particle.h"

/**
 * class that provides some vector math methods.
 */
class VectorMath {
public:
    float size(sf::Vector2f v);
    /**
     * Compute distance between two vectors. Result is always a positive number.
     * 
     * @param sf::Vector2f v1
     * @param sf::Vector2f v2
     * @return float distance
     */
    float distance(sf::Vector2f v1, sf::Vector2f v2);
    float distance(Particle* p1, Particle* p2);
    
    float angle(sf::Vector2f v1, sf::Vector2f v2);
    float angle(Particle* p1, Particle* p2);
    
    sf::Vector2f vector(sf::Vector2f v1, sf::Vector2f v2);
    sf::Vector2f vector(Particle* p1, Particle* p2);
    
    sf::Vector2f unitVector(sf::Vector2f v1, sf::Vector2f v2);
    sf::Vector2f unitVector(sf::Vector2f v);
    sf::Vector2f unitVector(Particle* p1, Particle* p2);
};

#endif /* VECTORMATH_H */

