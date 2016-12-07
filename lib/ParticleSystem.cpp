/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/ParticleSystem.h"

ParticleSystem::ParticleSystem(Enviroment* env) : ParticleSystem(env, false) {
    
}

ParticleSystem::ParticleSystem(Enviroment* env, bool play) {
    this->selectorGroup = new SelectRadioGroup();
    
    this->SetEnvironment(env);
    this->setPlay(play);
    
    this->setShortcutListener("RemoveSelected", new ParticleSystemShortcutListener(this));
    this->setShortcutListener("Deselect", new ParticleSystemDeselectShortcutListener(this));
}

Enviroment* ParticleSystem::getEnviroment() {
    return this->env;
}

void ParticleSystem::SetEnvironment(Enviroment* env) {
    this->env = env;
}

bool ParticleSystem::isPlaying() {
    return this->playValue;
}

void ParticleSystem::setPlay(bool play) {
    this->playValue = play;
}

void ParticleSystem::play() {
    this->setPlay(true);
}

void ParticleSystem::pause() {
    this->setPlay(false);
}

void ParticleSystem::addParticle(Particle* p) {
    this->particles.insert({p->getId(), p});
    p->setSystem(this);
}

void ParticleSystem::removeParticle(Particle* p) {
    this->removeParticle(p->getId());
}

void ParticleSystem::removeParticle(int id) {
    Particle* p = this->particles.at(id);
    
    std::vector<DistanceConstraint*> conn = p->getConnections();
    std::vector<DistanceConstraint*>::iterator iterator = conn.begin();
    std::vector<DistanceConstraint*>::iterator end = conn.end();
    while (iterator != end){
        this->removeConstraint((*iterator)->getId());
        iterator++;
    }
    
    this->particles.erase(id);
    delete p;
}

void ParticleSystem::addConstrain(Constraint* c) {
    this->constraints.insert({c->getId(), c});
    c->setSystem(this);
}

void ParticleSystem::removeConstraint(Constraint* c) {
    this->removeConstraint(c->getId());
}

void ParticleSystem::removeConstraint(int id) {
    Constraint* c = this->constraints.at(id);
    this->constraints.erase(id);
    delete c;
}

void ParticleSystem::clear() {
    RadioGroup* constraintService = (RadioGroup*) Provider::getInstance()->get("constraintService");
    RadioGroup* particleService = (RadioGroup*) Provider::getInstance()->get("particleService");
    
    if (particleService->isSelected()){
        particleService->select(NULL);
    }
    if (constraintService->isSelected()){
        constraintService->select(NULL);
    }
    
    std::map<int, Constraint*>::iterator ci = this->constraints.begin();
    std::map<int, Constraint*>::iterator cend = this->constraints.end();
    while (ci != cend){
        delete this->constraints.at(ci->first);
        ci++;
    }
    this->constraints.clear();
    
    std::map<int, Particle*>::iterator i = this->particles.begin();
    std::map<int, Particle*>::iterator end = this->particles.end();
    while (i != end){
        delete this->particles.at(i->first);
        i++;
    }
    this->particles.clear();
}


void ParticleSystem::update(sf::RenderWindow* window) {

}

void ParticleSystem::render(sf::RenderWindow* window) {
    int i;
    std::map<int, Particle*>::iterator iterator =  this->particles.begin();
    std::map<int, Particle*>::iterator end =  this->particles.end();
    
    std::map<int, Constraint*>::iterator iCon = this->constraints.begin();
    std::map<int, Constraint*>::iterator eCon = this->constraints.end();
    
    float deltaTime = this->env->getChangedTime();
    
    if (this->isPlaying()){
        //compute position PBD
        while (iterator != end){
            iterator->second->doVelocity(deltaTime, this->env->getGravityForce(iterator->second->getMass()));
            iterator->second->doVelocityDamping(deltaTime, this->env->getDampingValue());
            iterator->second->doVirtualPosition(deltaTime);
            
            if (iterator->second->getVirtualPosition().y > this->env->getGroundPosition()){
                iterator->second->setVirtualPosition(iterator->second->getVirtualPosition().x, this->env->getGroundPosition());
            }
            iterator++;
        }
        
        for (i = 0; i < this->env->getProjectIterations(); i++){
            iCon = this->constraints.begin();
            while (iCon != eCon){
                iCon->second->execute(deltaTime, this->env->getProjectIterations());
                iCon++;
            }
        }

        iterator =  this->particles.begin();
        while (iterator != end){
            iterator->second->doVelocityFromVirtualPosition(deltaTime);
            iterator->second->doPositionFromVirtualPosition();
            iterator++;
        }
    }
    
    //render lines (constrains)
    iCon = this->constraints.begin();
    while (iCon != eCon){
        iCon->second->render(window);
        iCon++;
    }
    
    //render dots (particles)
    iterator =  this->particles.begin();
    while (iterator != end){
        iterator->second->render(window);
        iterator++;
    }
}

ParticleSystemShortcutListener::ParticleSystemShortcutListener(ParticleSystem* system) : ShortcutListener() {
    this->system = system;
}

void ParticleSystemShortcutListener::onTrigger(KeyboardEvent* event) {
    RadioGroup* constraintService = (RadioGroup*) Provider::getInstance()->get("constraintService");
    RadioGroup* particleService = (RadioGroup*) Provider::getInstance()->get("particleService");
    
    if (particleService->isSelected()){
        Radio* p = particleService->getSelected();
        particleService->select(NULL);
        this->system->removeParticle(p->getId());
    }
    if (constraintService->isSelected()){
        Radio* c = constraintService->getSelected();
        constraintService->select(NULL);
        this->system->removeConstraint(c->getId());   
    }
}

ParticleSystemDeselectShortcutListener::ParticleSystemDeselectShortcutListener(ParticleSystem* system) : ShortcutListener() {
    this->system = system;
}

void ParticleSystemDeselectShortcutListener::onTrigger(KeyboardEvent* event) {
    RadioGroup* constraintService = (RadioGroup*) Provider::getInstance()->get("constraintService");
    RadioGroup* particleService = (RadioGroup*) Provider::getInstance()->get("particleService");
    
    if (particleService->isSelected()){
        particleService->select(NULL);
    }
    if (constraintService->isSelected()){
        constraintService->select(NULL);
    }
}
