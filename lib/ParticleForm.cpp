/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "../include/Provider.h"
#include "../include/ParticleService.h"
#include "../include/ParticleForm.h"
#include "../include/Particle.h"

ParticleForm::ParticleForm() : ParticleForm(false) {
    
}

ParticleForm::ParticleForm(bool selected) : Radio(selected) {
    this->activeParticle = NULL;
    this->setVisibility(selected);
    
    this->name = new Input("", "particle name");
    this->mass = new LabelInput("m", "", "mass");
    this->positionX = new LabelInput("Px", "", "x");
    this->positionY = new LabelInput("Py", "", "y");
    
    this->name->setLayout(new Layout(0, 0, 1.0f, 32, PERCENTAGE));
    this->addRenderable(this->name);
    
    this->mass->setLayout(new Layout(0, 50, 0.5f, 32, PERCENTAGE));
    this->mass->getInput()->setInputListener(new MassInputListener(this));
    this->addRenderable(this->mass);
    
    this->positionX->setLayout(new Layout(0.0f, 100, 0.50f, 32, PERCENTAGE));
    this->addRenderable(this->positionX);
    
    this->positionY->setLayout(new Layout(0.50f, 100, 0.50f, 32, PERCENTAGE));
    this->addRenderable(this->positionY);
}

ParticleForm::~ParticleForm(){
    delete this->name;
    delete this->mass;
    delete this->positionX;
    delete this->positionY;
}

void ParticleForm::setParticlePosition(sf::Vector2f position) {
    if (this->hasActiveParticle()){
        this->positionX->getInput()->setValue(position.x);
        this->positionY->getInput()->setValue(position.y);
    }
}

void ParticleForm::fillParticle(Particle* p) {
    
    if (this->hasActiveParticle()){
        this->activeParticle->setChangeListener(NULL);
    }
    
    this->activeParticle = p;
    this->activeParticle->setChangeListener(new PositionChangeListener(this));
    this->mass->getInput()->setValue(p->getMass());
    this->setParticlePosition(p->getPosition());
}
Particle* ParticleForm::getActiveParticle() {
    return this->activeParticle;
}

bool ParticleForm::hasActiveParticle() {
    return (this->activeParticle != NULL);
}

void ParticleForm::setSelected(bool selected) {
    Radio::setSelected(selected);
    this->setVisibility(this->isSelected());
    
    if (this->isSelected()){
        RadioGroup* particleService = (RadioGroup*) Provider::getInstance()->get("particleService");
        this->fillParticle((Particle*) particleService->getSelected());
    }
}

void ParticleForm::update(sf::RenderWindow* window) {
    this->getLayout()->resize(this->getParent()->getLayout());
    
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    std::list<Renderable*>::iterator end = this->getRenderableItems()->end();
    while (iterator != end){
        (*iterator)->update(window);
        iterator++;
    }
}

void ParticleForm::render(sf::RenderWindow* window) {
    if (!this->isSelected()){
        return ;
    }
    
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    std::list<Renderable*>::iterator end = this->getRenderableItems()->end();
    while (iterator != end){
        (*iterator)->render(window);
        iterator++;
    }
}

FormParticleListener::FormParticleListener(ParticleForm* form) : ParticleListener() {
    this->form = form;
}

void FormParticleListener::onSelect(ParticleEvent* event){
    this->form->setSelected(true);
    this->form->fillParticle(event->getParticle());
}

void FormParticleListener::onDeselect(ParticleEvent* event) {
    this->form->deselect();
}

MassInputListener::MassInputListener(ParticleForm* form) {
    this->form = form;
}

void MassInputListener::onInput(InputEvent* event) {
    Input* input = (Input*) event->getFocusable();
    
    this->form->getActiveParticle()->setMass(input->getFloat());
}

PositionChangeListener::PositionChangeListener(ParticleForm* form){
    this->form = form;
}

void PositionChangeListener::onChange(Event* event) {
    Particle* p = (Particle*) event->getObject();
    
    this->form->setParticlePosition(p->getPosition());
}