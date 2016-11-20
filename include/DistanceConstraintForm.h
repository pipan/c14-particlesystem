/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DistanceConstraintForm.h
 * Author: arksys
 *
 * Created on November 6, 2016, 11:30 PM
 */

#ifndef DISTANCECONSTRAINTFORM_H
#define DISTANCECONSTRAINTFORM_H

#include "Provider.h"
#include "Radio.h"
#include "DistanceConstraint.h"
#include "LabelInput.h"
#include "RadioGroup.h"


class DistanceConstraintForm : public Radio {
    DistanceConstraint* constraint;
    
    LabelInput* length;
    LabelInput* stiffness;
public:
    DistanceConstraintForm();
    DistanceConstraintForm(bool selected);
    ~DistanceConstraintForm();
    
    bool hasConstraint();
    void setConstraint(DistanceConstraint* constraint);
    DistanceConstraint* getConstraint();
    
    void fill();
    
    void setSelected(bool selected) override;
    
    void update(sf::RenderWindow* window) override;
    void render(sf::RenderWindow* window) override;
};

class LengthInputListener : public InputListener {
    DistanceConstraintForm* form;
public:
    LengthInputListener(DistanceConstraintForm* form);
    void onInput(InputEvent* event) override;
};

class StiffnessInputListener : public InputListener {
    DistanceConstraintForm* form;
public:
    StiffnessInputListener(DistanceConstraintForm* form);
    void onInput(InputEvent* event) override;
};

#endif /* DISTANCECONSTRAINTFORM_H */

