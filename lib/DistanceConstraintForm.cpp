/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/DistanceConstraintForm.h"

DistanceConstraintForm::DistanceConstraintForm() : DistanceConstraintForm(false){
    
}

DistanceConstraintForm::DistanceConstraintForm(bool selected) : Radio(selected) {
    this->constraint = NULL;
    this->setVisibility(selected);
    
    this->length = new LabelInput("l", "", "length");
    this->stiffness = new LabelInput("kd", "", "stiffness");
    this->currentLength = new ImageButton("assets/images/link.png", sf::Vector2f(32,32));
    
    this->length->setLayout(new Layout(0, 0, 0.5f, 32, PERCENTAGE));
    this->length->getInput()->setInputListener(new LengthInputListener(this));
    this->addRenderable(this->length);
    
    this->currentLength->setLayout(new Layout(0.5, 0, 32, 32, PERCENTAGE));
    this->currentLength->setMouseListener(new MouseCurrentLength(this));
    this->addRenderable(this->currentLength);
    
    this->stiffness->setLayout(new Layout(0, 50, 1.0f, 32, PERCENTAGE));
    this->stiffness->getInput()->setInputListener(new StiffnessInputListener(this));
    this->addRenderable(this->stiffness);
    
    this->setShortcutListener("CurrentConstraintDistance", new CurrentDistanceShortcutListener(this));
}

DistanceConstraint* DistanceConstraintForm::getConstraint() {
    return this->constraint;
}

DistanceConstraintForm::~DistanceConstraintForm() {
    delete this->stiffness;
    delete this->length;
}

bool DistanceConstraintForm::hasConstraint() {
    return (this->constraint != NULL);
}

void DistanceConstraintForm::setConstraint(DistanceConstraint* constraint) {
    this->constraint = constraint;
    this->fill();
}

void DistanceConstraintForm::setCurrentConstraintLength() {
    VectorMath* vectorMath = (VectorMath*) Provider::getInstance()->get("vectorMath");
    if (this->hasConstraint()){
        float d = vectorMath->distance(this->getConstraint()->getParticle(1)->getPosition(), this->getConstraint()->getParticle(2)->getPosition());
        this->getConstraint()->setDistance(d);
        this->fill();
    }
}

void DistanceConstraintForm::fill() {
    if (this->hasConstraint()){
        this->length->getInput()->setValue(this->getConstraint()->getDistance());
        this->stiffness->getInput()->setValue(this->getConstraint()->getStiffness());
    }
    else{
        this->length->getInput()->setValue("");
        this->stiffness->getInput()->setValue("");
    }
}

void DistanceConstraintForm::setSelected(bool selected) {
    Radio::setSelected(selected);
    this->setVisibility(this->isSelected());
    
    if (this->isSelected()){
        RadioGroup* constraintService = (RadioGroup*) Provider::getInstance()->get("constraintService");
        this->setConstraint((DistanceConstraint*) constraintService->getSelected());
    }
}


void DistanceConstraintForm::update(sf::RenderWindow* window) {
    this->getLayout()->resize(this->getParent()->getLayout());
    
    std::list<Renderable*>::iterator iterator = this->getRenderableItems()->begin();
    std::list<Renderable*>::iterator end = this->getRenderableItems()->end();
    while (iterator != end){
        (*iterator)->update(window);
        iterator++;
    }
}

void DistanceConstraintForm::render(sf::RenderWindow* window) {
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

LengthInputListener::LengthInputListener(DistanceConstraintForm* form){
    this->form = form;
}

void LengthInputListener::onInput(InputEvent* event){
    Input* input = (Input*) event->getFocusable();
    
    if (this->form->hasConstraint()){
        this->form->getConstraint()->setDistance(input->getFloat());
    }
}

StiffnessInputListener::StiffnessInputListener(DistanceConstraintForm* form){
    this->form = form;
}

void StiffnessInputListener::onInput(InputEvent* event){
    Input* input = (Input*) event->getFocusable();
    
    if (this->form->hasConstraint()){
        this->form->getConstraint()->setStiffness(input->getFloat());
    }
}

MouseCurrentLength::MouseCurrentLength(DistanceConstraintForm* form) {
    this->form = form;
}

void MouseCurrentLength::onClick(MouseEvent* event) {
    this->form->setCurrentConstraintLength();
}

void MouseCurrentLength::onDrag(MouseEvent* event) {

}

void MouseCurrentLength::onDrop(MouseEvent* event) {

}

void MouseCurrentLength::onMove(MouseEvent* event) {

}

CurrentDistanceShortcutListener::CurrentDistanceShortcutListener(DistanceConstraintForm* form){
    this->form = form;
}

void CurrentDistanceShortcutListener::onTrigger(KeyboardEvent* event) {
    this->form->setCurrentConstraintLength();
}
