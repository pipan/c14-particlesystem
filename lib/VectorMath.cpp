/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define _USE_MATH_DEFINES
#include <cmath>

#include "../include/VectorMath.h"

float VectorMath::size(sf::Vector2f v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

float VectorMath::distance(sf::Vector2f v1, sf::Vector2f v2){
    return sqrtf((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

float VectorMath::distance(Particle* p1, Particle* p2){
    return this->distance(p1->getPosition(), p2->getPosition());
}

float VectorMath::angle(sf::Vector2f v1, sf::Vector2f v2) {
    float deltaY = v2.y - v1.y;
    float deltaX = v2.x - v1.x;
    return atan2(deltaY, deltaX) * 180 / M_PI;
}

float VectorMath::angle(Particle* p1, Particle* p2) {
    return this->angle(p1->getPosition(), p2->getPosition());
}

sf::Vector2f VectorMath::vector(sf::Vector2f v1, sf::Vector2f v2) {
    sf::Vector2f v;
    v.x = v2.x - v1.x;
    v.y = v2.y - v1.y;
    return v;
}

sf::Vector2f VectorMath::vector(Particle* p1, Particle* p2) {
    return this->vector(p1->getPosition(), p2->getPosition());
}

sf::Vector2f VectorMath::unitVector(sf::Vector2f v) {
    float size = this->size(v);
    v.x = v.x / size;
    v.y = v.y / size;
    return v;
}

sf::Vector2f VectorMath::unitVector(sf::Vector2f v1, sf::Vector2f v2) {
    return this->unitVector(this->vector(v1, v2));
}

sf::Vector2f VectorMath::unitVector(Particle* p1, Particle* p2) {
    return this->unitVector(p1->getPosition(), p2->getPosition());
}
