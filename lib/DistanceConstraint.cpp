/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include <SFML/System/Vector2.hpp>

#include "../include/DistanceConstraint.h"
#include "../include/ParticleSystem.h"

DistanceConstraint::DistanceConstraint(Particle* p1, Particle* p2, float stiffness) : Radio() {
    this->vectorMath = (VectorMath*) Provider::getInstance()->get("vectorMath");
    this->p1 = p1;
    this->p2 = p2;
    this->setStiffness(stiffness);
    this->setDistance(this->vectorMath->distance(this->p1->getPosition(), this->p2->getPosition()));
    this->clickThickness = 7.0;
    
    this->p1->addConnection(this);
    this->p2->addConnection(this);
}

DistanceConstraint::DistanceConstraint(Particle* p1, Particle* p2, float stiffness, float distance) : DistanceConstraint(p1, p2, stiffness){
    this->setDistance(distance);
}

DistanceConstraint::~DistanceConstraint() {
    this->p1->removeCannection(this);
    this->p2->removeCannection(this);
}

sf::Vector2f DistanceConstraint::outerPosition(Particle* p1, Particle* p2) {
    sf::Vector2f v = this->vectorMath->unitVector(p1, p2);
    sf::Vector2f outer = p1->getPosition();
    outer.x += v.x * p1->getRadius();
    outer.y += v.y * p1->getRadius();
    return outer;
}

float DistanceConstraint::getDistance() {
    return this->distance;
}

float DistanceConstraint::getStiffness() {
    return this->stiffness;
}

void DistanceConstraint::setDistance(float d) {
    this->distance = d;
}

void DistanceConstraint::setStiffness(float s) {
    this->stiffness = s;
}

bool DistanceConstraint::hasParticle(Particle* p) {
    return (this->p1->getId() == p->getId() || this->p2->getId() == p->getId());
}

void DistanceConstraint::execute(float deltaTime, int projectionCount) {
    sf::Vector2f deltaP;    
    float size = this->vectorMath->distance(this->p1->getVirtualPosition(), this->p2->getVirtualPosition());
    
    if ((this->p1->getWeight() + this->p2->getWeight() == 0) || size == 0){
        return;
    }
    
    deltaP.x = (1 - std::pow(1 - this->getStiffness(), 1.0/projectionCount)) * (1 / (this->p1->getWeight() + this->p2->getWeight())) * (size - this->distance) * ((this->p1->getVirtualPosition().x - this->p2->getVirtualPosition().x) / size);
    deltaP.y = (1 - std::pow(1 - this->getStiffness(), 1.0/projectionCount)) * (1 / (this->p1->getWeight() + this->p2->getWeight())) * (size - this->distance) * ((this->p1->getVirtualPosition().y - this->p2->getVirtualPosition().y) / size);
    
    this->p1->setVirtualPosition(this->p1->getVirtualPosition().x - (this->p1->getWeight() * deltaP.x), this->p1->getVirtualPosition().y - (this->p1->getWeight() * deltaP.y));
    this->p2->setVirtualPosition(this->p2->getVirtualPosition().x + (this->p2->getWeight() * deltaP.x), this->p2->getVirtualPosition().y + (this->p2->getWeight() * deltaP.y));
}

sf::FloatRect DistanceConstraint::getBounds() {
    sf::FloatRect rect;
    sf::Vector2f v1 = this->outerPosition(this->p1, this->p2);
    sf::Vector2f v2 = this->outerPosition(this->p2, this->p1);
    rect.left = fmin(v1.x, v2.x);
    rect.top = fmin(v1.y, v2.y);
    rect.width = fabs(v1.x - v2.x);
    rect.height = fabs(v1.y - v2.y);
    return rect;
}

bool DistanceConstraint::collision(float x, float y) {
    sf::Vector2f v1 = this->outerPosition(this->p1, this->p2);
    sf::Vector2f v2 = this->outerPosition(this->p2, this->p1);
    float distance = this->vectorMath->distance(v1, v2);
    sf::Vector2f a(x,y);
    float sizep1a = this->vectorMath->distance(v1, a);
    float sizep2a = this->vectorMath->distance(v2, a);
    sf::Vector2f v = this->vectorMath->unitVector(v1, v2);
    sf::Vector2f u = this->vectorMath->unitVector(v2, v1);
    
    sf::Vector2f qv(sizep1a * v.x, sizep1a * v.y);
    sf::Vector2f qu(sizep2a * u.x, sizep2a * u.y);
    sf::Vector2f q(v1.x + qv.x, v1.y + qv.y);
    
    float distanceP1Q = this->vectorMath->size(qv);
    float distanceP2Q = this->vectorMath->size(qu);
    float penetration = this->vectorMath->distance(a, q);
    
    return (penetration < this->clickThickness && distanceP1Q <= distance && distanceP2Q <= distance);
}

int DistanceConstraint::getId() {
    return Radio::getId();
}

void DistanceConstraint::update(sf::RenderWindow* window) {

}

void DistanceConstraint::render(sf::RenderWindow* window) {
    sf::VertexArray line(sf::Lines, 2);
    
    line[0].position = this->outerPosition(this->p1, this->p2);
    line[1].position = this->outerPosition(this->p2, this->p1);
    
    if (this->isSelected()){
        line[0].color = *Template::getActive()->getAccent();
        line[1].color = *Template::getActive()->getAccent();
    }
    else{
        line[0].color = *Template::getActive()->getPrimary();
        line[1].color = *Template::getActive()->getPrimary();
    }
    
    window->draw(line);
}

void DistanceConstraint::onClick(MouseEvent* event) {
    RadioGroup* service = (RadioGroup*) Provider::getInstance()->get("constraintService");
    
    switch (event->getCursorType()){
        case ADD:
        case POINTER:
            event->setObject(this);
            service->select(this);
            break;
        case REMOVE:
            if (this->hasSystem()){
                if (service->isSelected() && service->getSelected()->getId() == this->getId()){
                    service->select(NULL);
                }
                this->getSystem()->removeConstraint(this);
            }
            break;       
    }
    
    Renderable::onClick(event);
}
