/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeInterval.h
 * Author: arksys
 *
 * Created on November 13, 2016, 11:22 AM
 */

#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

#include <SFML/System.hpp>

class TimeInterval {
    int millisecond;
    sf::Int32 firedAt;
public:
    TimeInterval(int millisecond);
    virtual ~TimeInterval();

    void fire(sf::Int32 now);
    
    virtual void timeIntervalCallback() = 0;
};

#endif /* TIMEINTERVAL_H */

