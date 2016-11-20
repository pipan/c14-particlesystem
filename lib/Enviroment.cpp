/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/Enviroment.h"

Enviroment::Enviroment(TimeService* time, sf::Vector2f gravity, float damping) : Enviroment(time, gravity, damping, 1){
    
}

Enviroment::Enviroment(TimeService* time, sf::Vector2f gravity, float damping, int projectIterations) : Enviroment(time, gravity, damping, projectIterations, 720){
    
}

Enviroment::Enviroment(TimeService* time, sf::Vector2f gravity, float damping, int projectIterations, float groundPosition) {
    this->time = time;
    this->setGravity(gravity);
    this->setDampingValue(damping);
    this->setProjectIterations(projectIterations);
    this->setGroundPosition(groundPosition);
    
    this->time->addTimeInterval(new EnviromentFpsTimeInterval(this, 1000));
    
    this->ground.setFillColor(*Template::getActive()->getBackgroundDark());
    
    if (!this->font.loadFromFile("assets/fonts/arial.ttf")){
        std::cout << "LOAD FONT ERROR";
        //ERROR
    }
    this->fps.setFont(this->font);
    this->fps.setColor(*Template::getActive()->getSecondary());
    this->fps.setCharacterSize(24);
}

float Enviroment::getChangedTime() {
    return this->time->getTimeChange();
}

TimeService* Enviroment::getTimeService() {
    return this->time;
}

sf::Vector2f Enviroment::getGravity() {
    return this->gravity;
}

float Enviroment::getDampingValue() {
    return this->dampingValue;
}

float Enviroment::getGroundPosition() {
    return this->groundPosition;
}

void Enviroment::setGravity(sf::Vector2f gravity) {
    this->gravity = gravity;
}

void Enviroment::setGravity(float value, VECTOR_INDEX index) {
    switch (index){
        case X:
            this->gravity.x = value;
            break;
        case Y:
            this->gravity.y = value;
            break;
    }
}

sf::Vector2f Enviroment::getGravityForce(float mass) {
    return this->gravity * mass;
}

void Enviroment::setDampingValue(float damping) {
    this->dampingValue = damping;
}

int Enviroment::getProjectIterations() {
    return this->projectIterations;
}

void Enviroment::setProjectIterations(int iterations) {
    this->projectIterations = iterations;
}

void Enviroment::setGroundPosition(float groundPosition) {
    this->groundPosition = groundPosition;
    
    this->ground.setPosition(0, this->groundPosition);
}

void Enviroment::setFps() {
    std::ostringstream stream;
    stream << this->time->getFps();
   
    this->fps.setString(stream.str());
}

void Enviroment::update(sf::RenderWindow* window) {

    this->fps.setPosition(window->getSize().x - 60, 12);
    this->ground.setSize(sf::Vector2f(window->getSize().x, 1));
}

void Enviroment::render(sf::RenderWindow* window) {
    
    window->draw(this->fps);
    window->draw(this->ground);
}

EnviromentFpsTimeInterval::EnviromentFpsTimeInterval(Enviroment* env, int millisecond) : TimeInterval(millisecond) {
    this->env = env;
}

void EnviromentFpsTimeInterval::timeIntervalCallback() {
    this->env->setFps();
}
