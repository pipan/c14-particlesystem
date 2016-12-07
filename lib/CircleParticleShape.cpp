/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/System/Vector2.hpp>
#include <list>

#include "../include/CircleParticleShape.h"

CircleParticleShape::CircleParticleShape(Enviroment* env) : CircleParticleShape(env, 2, 2, 100, 300, 300) {}

CircleParticleShape::CircleParticleShape(Enviroment* env, int x, int y, float offset, sf::Vector2f position) : CircleParticleShape(env, x, y, offset, position.x, position.y) {}

CircleParticleShape::CircleParticleShape(Enviroment* env, int x, int y, float offset, float pX, float pY) : SquareParticleShape(env, x, y, offset, pX, pY){
}

CircleParticleShape::~CircleParticleShape() {
}

void CircleParticleShape::generate(ParticleSystem* pSys, float mass, float stiffness) {
    VectorMath* vectorMath = (VectorMath*) Provider::getInstance()->get("vectorMath");
    
    float diagonal = sqrt(this->getX() * this->getOffset() * this->getX() * this->getOffset() / 2);
    sf::Vector2f center(this->getPosition().x + diagonal, this->getPosition().y + diagonal); 
    
    //Remove all
    pSys->clear();
    
    int i = 0;
    int j = 0;
    Particle* p;
    Particle* pprev;
    Particle* first;
    Particle* centerParticle = new Particle(center.x, center.y, mass);
    int numberOfParticles = 0;
    float radius = 0;
    float circumaferance;
    float angle;
    float addAngle;
    std::list<Particle*>* prev = NULL;
    std::list<Particle*>* current = NULL;
    //Generate all particles
    pSys->addParticle(centerParticle);
    
    float maxDistance = sqrt(2 * this->getOffset() * this->getOffset());
    
    for (i = 0; i < this->getX(); i++){
        radius += this->getOffset();
        angle = 0;
        circumaferance = 2 * M_PI * radius;
        numberOfParticles = round(circumaferance / this->getOffset());
        addAngle = M_PI * 2 / numberOfParticles;
        
        current = new std::list<Particle*>();
        for (j = 0; j < numberOfParticles; j++){
            p = new Particle(center.x + cos(angle) * radius, center.y + sin(angle) * radius, mass);
            current->push_back(p);
            pSys->addParticle(p);
            
            angle += addAngle;
            pprev = p;
        }
        
        //CONSTRAINT BETWEEN
        std::list<Particle*>::iterator iCur = current->begin();
        std::list<Particle*>::iterator eCur = current->end();
        first = *iCur;
        pprev = NULL;
        while (iCur != eCur){
            //Circumference
            if (pprev != NULL){
                pSys->addConstrain(new DistanceConstraint(pprev, (*iCur), stiffness));
            }
            
            //WITH  center
            if (prev == NULL){
                pSys->addConstrain(new DistanceConstraint(centerParticle, (*iCur), stiffness));
            }
            //With previous circumference
            else{
                std::list<Particle*>::iterator iPrev = prev->begin();
                std::list<Particle*>::iterator ePrev = prev->end();
                while (iPrev != ePrev){
                    if (vectorMath->distance((*iCur), (*iPrev)) < maxDistance){
                        pSys->addConstrain(new DistanceConstraint((*iCur), (*iPrev), stiffness));
                    }
                    iPrev++;
                }
            }
            
            pprev = (*iCur);
            iCur++;
        }
        //Last of circumference
        pSys->addConstrain(new DistanceConstraint(pprev, first, stiffness));
        
        prev = current;
    }
}
