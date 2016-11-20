/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/Particle.h"

#include "../include/ParticleSystem.h"

Particle::Particle(float x, float y, float mass) : Radio() {
    this->system = NULL;
    this->particleListener = NULL;
    this->changeListener = NULL;
    this->temporaryMass = 0;
    this->setSelected(false);
    this->setPosition(x, y);
    this->setMass(mass);
    this->setVelocity(0.0f, 0.0f);
    this->particleRadius = PARTICLE_RADIUS;
    
    this->circle.setFillColor(*Template::getActive()->getPrimary());
    this->circle.setRadius(this->particleRadius);
    this->circle.setPosition(this->position);
}

Particle::Particle(sf::Vector2f position, float mass) : Particle(position.x, position.y, mass){
    
}

Particle::~Particle() {}

ParticleSystem* Particle::getSystem() {
    return this->system;
}

bool Particle::hasSystem() {
    return (this->system != NULL);
}

void Particle::setSystem(ParticleSystem* system) {
    this->system = system;
}

sf::Vector2f Particle::getRenderPosition() {
    sf::Vector2f rp = this->getPosition();
    rp.x -= this->particleRadius;
    rp.y -= this->particleRadius;
    return rp;
}

sf::Vector2f Particle::getAcceleration() {
    return this->acceleration;
}

float Particle::getMass() {
    return this->mass;
}

sf::Vector2f Particle::getPosition() {
    return this->position;
}

sf::Vector2f Particle::getVirtualPosition() {
    return this->virtualPosition;
}

sf::Vector2f Particle::getVelocity() {
    return this->velocity;
}

float Particle::getWeight() {
    if (this->mass != 0){
        return 1/this->mass;
    }
    else{
        return 0;
    }
}

float Particle::getRadius() {
    return this->particleRadius;
}

void Particle::setAcceleration(float x, float y) {
    this->acceleration.x = x;
    this->acceleration.y = y;
}

void Particle::setAcceleration(sf::Vector2f acceleration) {
    this->setAcceleration(acceleration.x, acceleration.y);
}

void Particle::setMass(float mass) {
    this->mass = mass;
    
    if (this->mass == 0){
        this->setVelocity(0, 0);
    }
}

void Particle::setPosition(float x, float y) {
    bool change = false;
    if (x != this->position.x || y != this->position.y){
        change = true;
    }
    
    this->position.x = x;
    this->position.y = y;
    
    if (change && this->hasChangeListener()){
        Event* e = new Event();
        e->setObject(this);
        this->changeListener->onChange(e);
    }
}

void Particle::setPosition(sf::Vector2f position) {
    this->setPosition(position.x, position.y);
}

void Particle::setVirtualPosition(float x, float y) {
    this->virtualPosition.x = x;
    this->virtualPosition.y = y;
}

void Particle::setVirtualPosition(sf::Vector2f position) {
    this->setVirtualPosition(position.x, position.y);
}

void Particle::setVelocity(float x, float y) {
    this->velocity.x = x;
    this->velocity.y = y;
}

void Particle::setVelocity(sf::Vector2f velocity) {
    this->setVelocity(velocity.x, velocity.y);
}

void Particle::addConnection(DistanceConstraint* constraint) {
    this->connections.push_back(constraint);
}

void Particle::removeCannection(DistanceConstraint* constraint) {
    std::vector<DistanceConstraint*>::iterator i = this->connections.begin();
    std::vector<DistanceConstraint*>::iterator e = this->connections.end();
    
    while (i != e){
        if ((*i) == constraint){
            this->connections.erase(i);
            break;
        }
        i++;
    }
}

std::vector<DistanceConstraint*> Particle::getConnections(){
    return this->connections;
}

bool Particle::hasConnection(Particle* p) {
    std::vector<DistanceConstraint*>::iterator iterator = this->connections.begin();
    std::vector<DistanceConstraint*>::iterator end = this->connections.end();
    while (iterator != end){
        if ((*iterator)->hasParticle(p)){
            return true;
        }
        iterator++;
    }
    
    return false;
}

void Particle::doVelocity(float deltaTime, sf::Vector2f force) {
    this->velocity.x = this->velocity.x + this->getWeight() * deltaTime * force.x;
    this->velocity.y = this->velocity.y + this->getWeight() * deltaTime * force.y;
}

void Particle::doVelocityFromVirtualPosition(float deltaTime) {
    this->velocity.x = (this->virtualPosition.x - this->position.x) / deltaTime;
    this->velocity.y = (this->virtualPosition.y - this->position.y) / deltaTime;
}

void Particle::doVelocityDamping(float deltaTime, float damping) {
    this->velocity.x = this->velocity.x - damping * this->velocity.x * deltaTime;
    this->velocity.y = this->velocity.y - damping * this->velocity.y * deltaTime;
}

void Particle::doVirtualPosition(float deltaTime) {
    this->virtualPosition.x = this->position.x + this->velocity.x * deltaTime;
    this->virtualPosition.y = this->position.y + this->velocity.y * deltaTime;
}

void Particle::doPositionFromVirtualPosition() {
    this->setPosition(this->virtualPosition);
}

void Particle::updateVelocity() {

}

void Particle::setSelected(bool selected) {
    bool change = false;
    if (selected != this->isSelected()){
        change = true;
    }
    
    Radio::setSelected(selected);
    
    if (change && this->hasParticleListener()){
        if (this->isSelected()){
            this->particleListener->onSelect(new ParticleEvent(this));
        }
        else{
            this->particleListener->onDeselect(new ParticleEvent(this));
        }
    }
}

void Particle::setParticleListener(ParticleListener* listener) {
    if (this->hasParticleListener()){
        delete this->particleListener;
    }
    this->particleListener = listener;
}

ParticleListener* Particle::getParticleListener() {
    return this->particleListener;
}

bool Particle::hasParticleListener() {
    return (this->particleListener != NULL);
}

ChangeListener* Particle::getChangeListener() {
    return this->changeListener;
}

void Particle::setChangeListener(ChangeListener* listener) {
    if (this->hasChangeListener()){
        delete this->changeListener;
    }
    this->changeListener = listener;
}

bool Particle::hasChangeListener() {
    return (this->changeListener != NULL);
}

int Particle::getLevel() {
    return (Renderable::getLevel() + 1);
}

sf::FloatRect Particle::getBounds() {
    return this->circle.getGlobalBounds();
}

void Particle::update(sf::RenderWindow* window) {

}

void Particle::render(sf::RenderWindow* window) {
    
    if (this->isSelected()){
        this->circle.setFillColor(*Template::getActive()->getAccent());
    }
    else{
        if (this->getWeight() == 0){
            this->circle.setFillColor(*Template::getActive()->getBackgroundDark(DISABLED));
        }
        else{
            this->circle.setFillColor(*Template::getActive()->getPrimary());
        }
    }
    
    sf::Vector2f pos = this->getRenderPosition();
    this->circle.setPosition(pos.x, pos.y);
    window->draw(this->circle);
}

void Particle::onClick(MouseEvent* event) {
    RadioGroup* service = (RadioGroup*) Provider::getInstance()->get("particleService");
    Particle* p = (Particle*) service->getSelected();
    
    switch (event->getCursorType()){
        case ADD:
            if (service->getSelected() != NULL && service->getSelected()->getId() != this->getId() && !this->hasConnection(p)){
                this->getSystem()->addConstrain(new DistanceConstraint(this, p, 1.0));
            }
        case POINTER:
            event->setObject(this);
            service->select(this);
            break;
        case REMOVE:
            if (this->hasSystem()){
                if (service->isSelected() && service->getSelected()->getId() == this->getId()){
                    service->select(NULL);
                }
                this->getSystem()->removeParticle(this);
            }
            break;       
    }
    
    Renderable::onClick(event);
}

void Particle::onDrag(MouseEvent* event) {
    if (this->getMass() != 0){
        this->temporaryMass = this->getMass();
    }
    this->setPosition(event->getX(), event->getY());
    this->setMass(0);
    
    Renderable::onDrag(event);
}

void Particle::onDrop(MouseEvent* event) {
    this->setMass(this->temporaryMass);
    this->temporaryMass = 0;
    
    Renderable::onDrop(event);
}
