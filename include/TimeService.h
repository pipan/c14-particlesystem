/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeService.h
 * Author: arksys
 *
 * Created on October 15, 2016, 10:48 PM
 */

#ifndef TIMESERVICE_H
#define TIMESERVICE_H

#include <list>

#include <SFML/System.hpp>

#include "TimeInterval.h"

/**
 * class handeling time and delta time. Actually this class is using SFML class sf::Closk to do the trick.
 */
class TimeService{
    sf::Clock clock;
    sf::Time elapsedTime;
    sf::Int32 nowValue;
    
    std::list<TimeInterval*> intervals;
public:
    TimeService();
    /**
     * Retrieve complete elapsed time from start of the application in milliseconds.
     * 
     * @return sf::Int32
     */
    sf::Int32 now();
    /**
     * Retrieve time change since last update (render cycle)
     * @return float
     */
    float getTimeChange();
    /**
     * Reset render cycle, resp. start new render cycle.
     */
    void reset();
    
    int getFps();
    
    void addTimeInterval(TimeInterval* interval);
    void removeTimeInterval(TimeInterval* interval);
};

#endif /* TIMESERVICE_H */

