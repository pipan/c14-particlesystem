/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/TriangleParticleShape.h"

TriangleParticleShape::TriangleParticleShape(Enviroment* env) : TriangleParticleShape(env, 2, 2, 100, 300, 300) {
}

TriangleParticleShape::TriangleParticleShape(Enviroment* env, int x, int y, float offset, sf::Vector2f position) : TriangleParticleShape(env, x, y, offset, position.x, position.y) {}

TriangleParticleShape::TriangleParticleShape(Enviroment* env, int x, int y, float offset, float pX, float pY) : SquareParticleShape(env, x, y, offset, pX, pY) {}

TriangleParticleShape::~TriangleParticleShape() {}

ParticleSystem* TriangleParticleShape::generate(float mass, float stiffness) {
    //Remove all
    
    int i = 0;
    int j = 0;
    Particle* particles[this->getY()][this->getX()];
    //Generate all particles
    //kosobeznik
//    for (i = 0; i < this->getX(); i++){
//        for (j = 0; j < this->getX(); j++){
//            particles[i][j] = new Particle((this->getY() - i - 1) * this->getOffset() / 2 + this->getPosition().x + j * this->getOffset(), this->getPosition().y + i * this->getOffset(), mass);
//            this->getSystem()->addParticle(particles[i][j]);
//        }
//    }
    
    for (i = 0; i < this->getX(); i++){
        for (j = 0; j <= i; j++){
            particles[i][j] = new Particle((this->getY() - i - 1) * this->getOffset() / 2 + this->getPosition().x + j * this->getOffset(), this->getPosition().y + i * this->getOffset(), mass);
            this->getSystem()->addParticle(particles[i][j]);
        }
    }
    
    //Generate all constraints
    for (i = 0; i < this->getX(); i++){
        for (j = 0; j <= i; j++){
            //UP
            if (i > 0){
                //MIDDLE
                if (j < i){
                    this->getSystem()->addConstrain(new DistanceConstraint(particles[i][j], particles[i - 1][j], stiffness));
                }
                //LEFT
                if (j > 0){
                    this->getSystem()->addConstrain(new DistanceConstraint(particles[i][j], particles[i - 1][j - 1], stiffness));
                }
            }
            //LEFT
            if (j > 0){
                this->getSystem()->addConstrain(new DistanceConstraint(particles[i][j], particles[i][j - 1], stiffness));
            }
        }
    }
    
    return this->getSystem();
}
