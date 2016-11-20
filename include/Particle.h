/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Particle.h
 * Author: arksys
 *
 * Created on October 21, 2016, 4:57 PM
 */

#ifndef PARTICLE_H
#define PARTICLE_H

class Constraint;
class DistanceConstraint;
class ParticleSystem;

#include "Provider.h"
#include "Radio.h"
#include "EventListener.h"
#include "Event.h"
#include "RadioGroup.h"

const float PARTICLE_RADIUS = 7.0f;

class Particle : public Radio{
    sf::Vector2f position;
    //this is the position particle would be in if we did not apply any constraints. Constraints adjust this value and then is the real position updated.
    sf::Vector2f virtualPosition;
    sf::Vector2f velocity;
    float mass;
    float temporaryMass;
    sf::Vector2f acceleration;
    std::vector<DistanceConstraint*> connections;
    sf::CircleShape circle;
    ParticleListener* particleListener;
    ChangeListener* changeListener;
    float particleRadius;
    ParticleSystem* system;
    
    sf::Vector2f getRenderPosition();
public:
    /**
     * Create particle at specified position, with specified mass
     * 
     * @param sf::Vector2f position
     * @param float mass
     */
    Particle(sf::Vector2f position, float mass);
    /**
     * Create particle at specified x and y position, with specified mass
     * 
     * @param float x
     * @param float y
     * @param float mass
     */
    Particle(float x, float y, float mass);
    virtual ~Particle();

    
    void setSystem(ParticleSystem* system);
    ParticleSystem* getSystem();
    bool hasSystem();
    
    /**
     * Retrieve particle real position
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getPosition();
    /**
     * Retrieve particle virtual position
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getVirtualPosition();
    /**
     * Retrieve particle velocity
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getVelocity();
    /**
     * Retrieve particle acceleration
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getAcceleration();
    /**
     * Retrieve particle mass
     * 
     * @return float
     */
    float getMass();
    /**
     * retrieve inverse value of particle mass. 1/m.
     * 
     * @return float
     */
    float getWeight();

    float getRadius();
    /**
     * Set particle's real position.
     * 
     * @param float x
     * @param float y
     */
    void setPosition(float x, float y);
    /**
     * Set particle's real position.
     * 
     * @param sf::Vector2f position
     */
    void setPosition(sf::Vector2f position);
    /**
     * Set particle's virtual position. 
     * 
     * @param float x
     * @param float y
     */
    void setVirtualPosition(float x, float y);
    /**
     * Set particle's virtual position.
     * 
     * @param sf::Vector2f position
     */
    void setVirtualPosition(sf::Vector2f position);
    /**
     * Set particle velocity.
     * 
     * @param float x
     * @param float y
     */
    void setVelocity(float x, float y);
    /**
     * Set particle velocity.
     * 
     * @param sf::Vector2f velocity
     */
    void setVelocity(sf::Vector2f velocity);
    /**
     * Set particle acceleration. Particle acceleration is not yet implemented, so this method will not have any effect.
     * 
     * @param float x
     * @param float y
     */
    void setAcceleration(float x, float y);
    /**
     * Set particle acceleration. Particle acceleration is not yet implemented, so this method will not have any effect.
     * 
     * @param sf::Vector2f acceleration
     */
    void setAcceleration(sf::Vector2f acceleration);
    /**
     * Set particle mass.
     * 
     * @param float mass
     */
    void setMass(float mass);
    
    /**
     * Add connection between this particle and particle defined in constraint.
     * 
     * @param DistanceConstraint* constraint
     */
    void addConnection(DistanceConstraint* constraint);
    /**
     * Remove a connection between this particle and particle set in constraint.
     * 
     * @param DistanceConstraint* constraint
     */
    void removeCannection(DistanceConstraint* constraint);
    /**
     * Retrieve array of all connections that this particle have with other particles.
     * 
     * @return std::vector<DistanceConstraint*>
     */
    std::vector<DistanceConstraint*> getConnections();
    bool hasConnection(Particle* p);
    
    /**
     * Compute what king of velocity should particle have if we apply forces that interact with the particle.
     * 
     * @param float deltaTime
     * @param sf::Vector2f force
     */
    void doVelocity(float deltaTime, sf::Vector2f force);
    /**
     * Compute velocity according to change of real and virtual position after projection constraints have been applied.
     * 
     * @param float deltaTime
     */
    void doVelocityFromVirtualPosition(float deltaTime);
    /**
     * Adjust velocity by some coefficient or some algorithm
     * 
     * @param float deltaTime
     * @param float damping
     */
    void doVelocityDamping(float deltaTime, float damping);
    /**
     * Compute where would particle be if we did not apply any constraints, just if we apply forces that interact with this particle.
     * 
     * @param float deltaTime
     */
    void doVirtualPosition(float deltaTime);
    /**
     * Basically assign virtual position value to real position value.
     */
    void doPositionFromVirtualPosition();
    /**
     * This method add friction and other forces to adjust velocity at the end of each cycle of particle simulation.
     */
    void updateVelocity();
    
    /**
     * This method is called whenever you click on particle, resp. when you select particle. This method calls onSelect method if this particle has particle listener.
     */
    void setSelected(bool selected) override;
    
    /**
     * Get particle listener bind to this particle or NULL.
     * 
     * @return ParticleListener*
     */
    ParticleListener* getParticleListener();
    /**
     * Set particle listener for this particle.
     * @param ParticleListener* listener
     */
    void setParticleListener(ParticleListener* listener);
    /**
     * Check if particle has a particle listener set.
     * 
     * @return bool
     */
    bool hasParticleListener();
    
    /**
     * Get change listener bind to this particle or NULL.
     * 
     * @return ChangeListener*
     */
    ChangeListener* getChangeListener();
    /**
     * Set change listener for this particle.
     * 
     * @param ChangeListener* listener
     */
    void setChangeListener(ChangeListener* listener);
    /**
     * Check if particle has a particle listener set.
     * 
     * @return bool
     */
    bool hasChangeListener();
    
    int getLevel() override;

    /**
     * Retrieve size and position of this object.
     * 
     * @return sf::FloatRect
     */
    sf::FloatRect getBounds() override;
    /**
     * This method is called every time object is clicked, hovered or moved over object. Particle has special functionality that comes with clicking on the particle. You can trigger default mouse event and you can also trigger particle event (onSelect onDeselect).
     * 
     * @param MouseEvent* event
     */
    //void mouse(MouseEvent* event) override;
    /**
     * update the position of elements. It might change because of the window size changed or because parent element changed its position.
     * 
     * @param sf::RenderWindow* window
     */
    void update(sf::RenderWindow* window) override;
    /**
     * render object to window
     * 
     * @param sf::RenderWindow* window
     */
    void render(sf::RenderWindow* window) override;
    
    void onClick(MouseEvent* event) override;
    void onDrag(MouseEvent* event) override;
    void onDrop(MouseEvent* event) override;
};
#endif /* PARTICLE_H */

