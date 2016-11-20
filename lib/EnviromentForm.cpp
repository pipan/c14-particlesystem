/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/EnviromentForm.h"
#include "../include/Event.h"

EnviromentForm::EnviromentForm(bool selected) : EnviromentForm(NULL, selected) {
    
}

EnviromentForm::EnviromentForm(Enviroment* env, bool selected) : Radio(selected){
    this->setEnviroment(env);
    
    this->gravityX = new LabelInput("Gx", "", "gravity X");
    this->gravityY = new LabelInput("Gy", "", "gravity Y");
    this->damping = new LabelInput("vd", "", "velocity damping");
    this->iterations = new LabelInput("i", "", "projection iterations");
    this->groundPosition = new LabelInput("Pg", "", "ground position");
    
    this->gravityX->setLayout(new Layout(0, 0, 0.5f, 32, PERCENTAGE));
    this->gravityX->getInput()->setInputListener(new GravityInputListener(this, X));
    this->addRenderable(this->gravityX);
    
    this->gravityY->setLayout(new Layout(0.5f, 0, 0.5f, 32, PERCENTAGE));
    this->gravityY->getInput()->setInputListener(new GravityInputListener(this, Y));
    this->addRenderable(this->gravityY);
    
    this->damping->setLayout(new Layout(0, 50, 1.0f, 32, PERCENTAGE));
    this->damping->getInput()->setInputListener(new DampingInputListener(this));
    this->addRenderable(this->damping);
    
    this->iterations->setLayout(new Layout(0, 100, 1.0f, 32, PERCENTAGE));
    this->iterations->getInput()->setInputListener(new IterationsInputListener(this));
    this->addRenderable(this->iterations);
    
    this->groundPosition->setLayout(new Layout(0, 150, 1.0f, 32, PERCENTAGE));
    this->groundPosition->getInput()->setInputListener(new GroundPositionInputListener(this));
    this->addRenderable(this->groundPosition);
}


EnviromentForm::~EnviromentForm() {
    delete this->gravityX;
    delete this->gravityY;
    delete this->damping;
    delete this->iterations;
    delete this->groundPosition;
}

void EnviromentForm::setEnviroment(Enviroment* env) {
    this->env = env;
    
    if (this->hasEnviroment()){
        this->gravityX->getInput()->setValue(this->env->getGravity().x);
        this->gravityY->getInput()->setValue(this->env->getGravity().y);
        this->damping->getInput()->setValue(this->env->getDampingValue());
        this->iterations->getInput()->setValue(this->env->getProjectIterations());
        this->groundPosition->getInput()->setValue(this->env->getGroundPosition());
    }
}

Enviroment* EnviromentForm::getEnviroment() {
    return this->env;
}

bool EnviromentForm::hasEnviroment() {
    return (this->env != NULL);
}

void EnviromentForm::setSelected(bool selected) {
    Radio::setSelected(selected);
    this->setVisibility(this->isSelected());
}

void EnviromentForm::update(sf::RenderWindow* window) {
    this->getLayout()->resize(this->getParent()->getLayout());
    
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    std::list<Renderable*>::iterator end = this->getRenderableItems()->end();
    while (iterator != end){
        (*iterator)->update(window);
        iterator++;
    }
}

void EnviromentForm::render(sf::RenderWindow* window) {
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

GravityInputListener::GravityInputListener(EnviromentForm* form, VECTOR_INDEX index) {
    this->form = form;
    this->index = index;
}

void GravityInputListener::onInput(InputEvent* event) {
    Input* input = (Input*) event->getFocusable();
    
    if (this->form->hasEnviroment()){
        this->form->getEnviroment()->setGravity(input->getFloat(), this->index);
    }
}

DampingInputListener::DampingInputListener(EnviromentForm* form) {
    this->form = form;
}

void DampingInputListener::onInput(InputEvent* event) {
    Input* input = (Input*) event->getFocusable();
    
    if (this->form->hasEnviroment()){
        this->form->getEnviroment()->setDampingValue(input->getFloat());
    }
}

IterationsInputListener::IterationsInputListener(EnviromentForm* form) {
    this->form = form;
}

void IterationsInputListener::onInput(InputEvent* event) {
    Input* input = (Input*) event->getFocusable();
    
    if (this->form->hasEnviroment()){
        this->form->getEnviroment()->setProjectIterations(input->getFloat());
    }
}

GroundPositionInputListener::GroundPositionInputListener(EnviromentForm* form) {
    this->form = form;
}

void GroundPositionInputListener::onInput(InputEvent* event) {
    Input* input = (Input*) event->getFocusable();
    
    if (this->form->hasEnviroment()){
        this->form->getEnviroment()->setGroundPosition(input->getFloat());
    }
}
