/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParticleSystem.h
 * Author: arksys
 *
 * Created on October 16, 2016, 4:19 PM
 */

#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <map>

#include "Provider.h"
#include "Renderable.h"
#include "Enviroment.h"
#include "Particle.h"
#include "DistanceConstraint.h"
#include "VectorMath.h"
#include "SelectRadioGroup.h"

/**
 * This is the class that takes particles and constraints for those particles and simole the particle system. It means you can add and remove new particles and constraints and set values to configure an environment for this system.
 */
class ParticleSystem : public Renderable{
    Enviroment* env;
    VectorMath* vectorMath;
    std::map<int, Particle*> particles;
    std::map<int, Constraint*> constraints;
    bool playValue;
    
    RadioGroup* selectorGroup;
public:
    /**
     * Create particle system and set enviroment for this system.
     * @param Enviroment* env
     */
    ParticleSystem(Enviroment* env);
    /**
     * Create particle system with enviroment and set if it should be in play state from the begining. Default value of play state is false.
     * 
     * @param Enviroment* env
     * @param bool play = false
     */
    ParticleSystem(Enviroment* env, bool play);
    
    /**
     * Get enviroment that is applied to this particle system.
     * @return 
     */
    Enviroment* getEnviroment();
    /**
     * Set enviroment values for this particle system. There is a possibility to have different enviroment for each particle system.
     * 
     * @param Enviroment* env
     */
    void SetEnvironment(Enviroment* env);
    
    /**
     * Check if the system is playing or if it is paused. If it is playing, that means that all physical vectors and forces are applied.
     * 
     * @return bool
     */
    bool isPlaying();
    /**
     * Set particle system to play state or pause state. True means it will bw playing.
     * 
     * @param bool play
     */
    void setPlay(bool play);
    /**
     * Set particle system to play state. It will be rendered and in each render step particle system will apply all forces and vectors to simulate particle system.
     */
    void play();
    /**
     * Set particle system to pause state. It will be rendered but it will not apply any forces and vectors to simulate particle system.
     */
    void pause();
    
    /**
     * Add particle that should be rendered in the particle system
     * 
     * @param Particle* p
     */
    void addParticle(Particle* p);
    /**
     * Remove particle from the particle system.
     * 
     * @param Particle* p
     */
    void removeParticle(Particle* p);
    /**
     * Remove particle from particle system by particle id.
     * 
     * @param int id
     */
    void removeParticle(int id);
    
    /**
     * Add constraint to a list of constraints that apply to this particle system
     * 
     * @param Constraint* c
     */
    void addConstrain(Constraint* c);
    /**
     * Remove constraint from a list of constraints that applies to this particle system.
     * 
     * @param Constraint* c
     */
    void removeConstraint(Constraint* c);
    /**
     * Remove constraint from a list of constraints that applies to this particle system.
     * 
     * @param int id
     */
    void removeConstraint(int id);
    
    void clear();
    
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    void render(sf::RenderWindow* window);
    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    void update(sf::RenderWindow* window) override;
};

class ParticleSystemShortcutListener : public ShortcutListener {
    ParticleSystem* system;
public:
    ParticleSystemShortcutListener(ParticleSystem* system);
    void onTrigger(KeyboardEvent* event) override;
};

class ParticleSystemDeselectShortcutListener : public ShortcutListener {
    ParticleSystem* system;
public:
    ParticleSystemDeselectShortcutListener(ParticleSystem* system);
    void onTrigger(KeyboardEvent* event) override;
};

#endif /* PARTICLESYSTEM_H */

