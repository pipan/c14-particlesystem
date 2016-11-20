/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/Constraint.h"

Constraint::Constraint() {
    this->system = NULL;
}

Constraint::~Constraint() {
}

ParticleSystem* Constraint::getSystem() {
    return this->system;
}

bool Constraint::hasSystem() {
    return (this->system != NULL);
}

void Constraint::setSystem(ParticleSystem* system) {
    this->system = system;
}
