/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParticleService.h
 * Author: arksys
 *
 * Created on October 22, 2016, 6:21 PM
 */

#ifndef PARTICLESERVICE_H
#define PARTICLESERVICE_H

#include "Radio.h"
#include "Event.h"
#include "Particle.h"
#include "EventHandler.h"

class ParticleService {
    Radio* selected;
    
    std::list<ParticleListener*> particleListeners;
    
    /**
     * Method call onSelect method of all particle listeners that are registered.
     */
    void onSelect();
    /**
     * Method call onDeselect method of all particle listeners that are registered.
     */
    void onDeselect();
public:
    /**
     * Create particle service.
     */
    ParticleService();
    /**
     * Select particle that is a parameter. If the particle is already selected, then deselect it and call apropriate event method.
     * @param Particle* p
     */
    void select(Particle* p);
    
    /**
     * Add particle listener to the list of listeners. Event method in those listeners get called when particle is selected or deselected.
     * 
     * @param ParticleListener* listener
     */
    void setParticleListener(ParticleListener* listener);
    /**
     * check if there is at least one particle listener.
     * 
     * @return bool
     */
    bool hasPaticleListener();
    /**
     * Remove particle listener from the list of particle listeners. Event method in those listeners get called when particle is selected or deselected.
     * @param ParticleListener* listener
     */
    void removeParticleListener(ParticleListener* listener);
    
    void remove(Particle* p);
};

#endif /* PARTICLESERVICE_H */

