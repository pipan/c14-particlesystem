/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/TimeInterval.h"

TimeInterval::TimeInterval(int millisecond){       
    this->millisecond = millisecond;
    this->firedAt = -1;
}

TimeInterval::~TimeInterval() {}

void TimeInterval::fire(sf::Int32 now) {
    if (this->firedAt != -1 && now < this->firedAt + this->millisecond){
        return ;
    }
    
    this->timeIntervalCallback();
    this->firedAt = now;
}
