/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <list>
#include <bits/stl_list.h>

#include "../include/TimeService.h"

TimeService::TimeService() {
    
}

sf::Int32 TimeService::now(){
    return this->nowValue;
}

float TimeService::getTimeChange() {
    return this->elapsedTime.asSeconds();
}

void TimeService::reset() {
    this->elapsedTime = this->clock.restart();
    this->nowValue += this->elapsedTime.asMilliseconds();
    
    std::list<TimeInterval*>::iterator iterator = this->intervals.begin();
    std::list<TimeInterval*>::iterator end = this->intervals.end();
    while (iterator != end){
        (*iterator)->fire(this->now());
        iterator++;
    }
}

int TimeService::getFps() {
    return floor(1/this->getTimeChange());
}

void TimeService::addTimeInterval(TimeInterval* interval) {
    this->intervals.push_back(interval);
}

void TimeService::removeTimeInterval(TimeInterval* interval) {
    this->intervals.remove(interval);
}
