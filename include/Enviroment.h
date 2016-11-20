/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enviroment.h
 * Author: arksys
 *
 * Created on October 22, 2016, 11:25 AM
 */

#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <iostream>
#include <sstream>

#include "TimeService.h"
#include "Renderable.h"
#include "TimeInterval.h"



/**
 * Class that stores informations about environment. It is sort of configuration object, but it can be change during application running.
 */
class Enviroment : public Renderable{
    TimeService* time;
    sf::Vector2f gravity;
    float dampingValue;
    float groundPosition;
    int projectIterations;
    sf::RectangleShape ground;
    sf::Text fps;
    sf::Font font;
public:
    /**
     * Basic enviroment setting consists of there three value. Other values will be set to default value.
     * 
     * @param TimeService* time time service object
     * @param sf::Vector2f gravity gravity value
     * @param float damping value of velocity dumping
     */
    Enviroment(TimeService* time, sf::Vector2f gravity, float damping);
    /**
     * Enviroment setting consists of there three value. Other values will be set to default value.
     * 
     * @param TimeService* time time service object
     * @param sf::Vector2f gravity gravity value
     * @param float damping value of velocity dumping
     * @param int projectionIterations number of iterations in constraint projection function
     */
    Enviroment(TimeService* time, sf::Vector2f gravity, float damping, int projectIterations);
    /**
     * Enviroment setting consists of there three value. Other values will be set to default value.
     * 
     * @param TimeService* time time service object
     * @param sf::Vector2f gravity gravity value
     * @param float damping value of velocity dumping
     * @param int projectionIterations number of iterations in constraint projection function
     * @param float grountPosition y position of ground in application
     */
    Enviroment(TimeService* time, sf::Vector2f gravity, float damping, int projectIterations, float groundPosition);
    /**
     * Retrieve time service assign to this environment
     * 
     * @return TimeService*
     */
    TimeService* getTimeService();
    /**
     * Return delta time since last render
     * 
     * @return float
     */
    float getChangedTime();
    
    /**
     * Get gravity vector
     * 
     * @return sf::Vector2f
     */
    sf::Vector2f getGravity();
    /**
     * return force of the gravity. Force is dependant on object mass
     * 
     * @param flaot mass
     * @return sf::Vector2f
     */
    sf::Vector2f getGravityForce(float mass);
    /**
     * return dumping coefficient value
     * 
     * @return float 
     */
    float getDampingValue();
    /**
     * get number of project constraint iterations
     * @return int 
     */
    int getProjectIterations();
    /**
     * return ground y position in application
     * 
     * @return float
     */
    float getGroundPosition();
    /**
     * set gravity value
     * @param sf::Vector2f gravity
     */
    void setGravity(sf::Vector2f gravity);
    /**
     * Set only one value in gravity vector. index specifie which value you want to change
     * 
     * @param float value gravity value
     * @param VECTOR_INDEX index in which direction you vant to change gravity
     */
    void setGravity(float value, VECTOR_INDEX index);
    /**
     * set velocity dumping coefficient
     * 
     * @param float damping
     */
    void setDampingValue(float damping);
    /**
     * set number of projection constraint iterations
     * 
     * @param int iterations
     */
    void setProjectIterations(int iterations);
    /**
     * set ground y position
     * @param float groundPosition
     */
    void setGroundPosition(float groundPosition);
    
    void setFps();

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
};

class EnviromentFpsTimeInterval : public TimeInterval {
    Enviroment* env;
public:
    EnviromentFpsTimeInterval(Enviroment* env, int millisecond);
    void timeIntervalCallback() override;
};

#endif /* ENVIROMENT_H */

