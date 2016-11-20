/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParticleForm.h
 * Author: arksys
 *
 * Created on October 23, 2016, 6:30 PM
 */

#ifndef PARTICLEFORM_H
#define PARTICLEFORM_H

#include "Renderable.h"
#include "Input.h"
#include "LabelInput.h"
#include "Particle.h"
#include "HorizontalDevider.h"
#include "DistanceConstraint.h"
#include "ImageButton.h"
#include "RadioGroup.h"


class ParticleForm : public Radio{
    Input* name;
    LabelInput* mass;
    LabelInput* positionX;
    LabelInput* positionY;
    Particle* activeParticle;
public:
    ParticleForm();
    ParticleForm(bool selected);
    ~ParticleForm();
    
    void setParticlePosition(sf::Vector2f position);
    
    void fillParticle(Particle* p);
    
    Particle* getActiveParticle();
    bool hasActiveParticle();

    void setSelected(bool selected) override;
    
    void update(sf::RenderWindow* window) override;
    void render(sf::RenderWindow* window) override;
};

class FormParticleListener : public ParticleListener{
    ParticleForm* form;
public:
    FormParticleListener(ParticleForm* form);
    void onSelect(ParticleEvent* event) override;
    void onDeselect(ParticleEvent* event) override;
};

class MassInputListener : public InputListener {
    ParticleForm* form;
public:
    MassInputListener(ParticleForm* form);
    void onInput(InputEvent* event) override;
};

class PositionChangeListener : public ChangeListener {
    ParticleForm* form;
public:
    PositionChangeListener(ParticleForm* form);
    void onChange(Event* event) override;
};
#endif /* PARTICLEFORM_H */

