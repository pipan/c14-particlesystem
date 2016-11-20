/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/ParticleService.h"
#include "../include/Provider.h"

ParticleService::ParticleService(){
    this->selected = NULL;
}

void ParticleService::onSelect() {
    if (!this->hasPaticleListener()){
        return ;
    }
    
//    std::list<ParticleListener*>::iterator i = this->particleListeners.begin();
//    std::list<ParticleListener*>::iterator e = this->particleListeners.end();
//    while (i != e){
//        (*i)->onSelect(new ParticleEvent(this->selected));
//        i++;
//    }
}

void ParticleService::onDeselect() {
    if (!this->hasPaticleListener()){
        return ;
    }
    
//    std::list<ParticleListener*>::iterator i = this->particleListeners.begin();
//    std::list<ParticleListener*>::iterator e = this->particleListeners.end();
//    while (i != e){
//        (*i)->onDeselect(new ParticleEvent(this->selected));
//        i++;
//    }
}

void ParticleService::select(Particle* p){
    if (this->selected != NULL){
        this->selected->deselect();
        if (p != NULL && this->selected->getId() != p->getId()){
            p->select();
            this->selected = p;
        }
        else{
            this->selected = NULL;
            
        }
    }
    else{
        if (p != NULL){
            p->select();
        }
        this->selected = p;
    }
    
    if (this->selected != NULL){
        this->onSelect();
    }
    else{
        this->onDeselect();
    }
}

void ParticleService::setParticleListener(ParticleListener* listener) {
    this->particleListeners.push_back(listener);
}

bool ParticleService::hasPaticleListener() {
    return !this->particleListeners.empty();
}