/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/SquareParticleShape.h"

SquareParticleShape::SquareParticleShape(Enviroment* env) : SquareParticleShape(env, 2, 2, 100, 300, 300) {}

SquareParticleShape::SquareParticleShape(Enviroment* env, int x, int y, float offset, sf::Vector2f position) : SquareParticleShape(env, x, y, offset, position.x, position.y) {
}

SquareParticleShape::SquareParticleShape(Enviroment* env, int x, int y, float offset, float pX, float pY) {
    this->system = new ParticleSystem(env);
    this->setDimension(x, y);
    this->setOffset(offset);
    this->setPosition(pX, pY);
}

SquareParticleShape::~SquareParticleShape() {
    delete this->system;
}

void SquareParticleShape::setDimension(int x, int y) {
    this->x = x;
    this->y = y;
}

void SquareParticleShape::setOffset(float offset) {
    this->offset = offset;
}

void SquareParticleShape::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

void SquareParticleShape::setPosition(sf::Vector2f position) {
    this->setPosition(position.x, position.y);
}

float SquareParticleShape::getOffset() {
    return this->offset;
}

sf::Vector2f SquareParticleShape::getPosition() {
    return this->position;
}

ParticleSystem* SquareParticleShape::getSystem() {
    return this->system;
}

int SquareParticleShape::getX() {
    return this->x;
}

int SquareParticleShape::getY() {
    return this->y;
}

ParticleSystem* SquareParticleShape::generate(float mass, float stiffness) {
    
    //Remove all
    
    int i = 0;
    int j = 0;
    Particle* particles[this->getY()][this->getX()];
    //Generate all particles
    for (i = 0; i < this->getY(); i++){
        for (j = 0; j < this->getX(); j++){
            particles[i][j] = new Particle(this->position.x + j * this->getOffset(), this->position.y + i * this->getOffset(), mass);
            this->system->addParticle(particles[i][j]);
        }
    }
    
    //Generate all constraints
    for (i = 0; i < this->getY(); i++){
        for (j = 0; j < this->getX(); j++){
            //UP
            if (i > 0){
                //RIGHT
                if (j + 1 < this->getX()){
                    this->system->addConstrain(new DistanceConstraint(particles[i][j], particles[i - 1][j + 1], stiffness));
                }
                //MIDDLE
                this->system->addConstrain(new DistanceConstraint(particles[i][j], particles[i - 1][j], stiffness));
                //LEFT
                if (j > 0){
                    this->system->addConstrain(new DistanceConstraint(particles[i][j], particles[i - 1][j - 1], stiffness));
                }
            }
            //LEFT
            if (j > 0){
                this->system->addConstrain(new DistanceConstraint(particles[i][j], particles[i][j - 1], stiffness));
            }
        }
    }
    
    return this->getSystem();
}
