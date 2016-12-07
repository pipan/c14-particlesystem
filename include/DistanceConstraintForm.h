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
#include "ImageButton.h"


class DistanceConstraintForm : public Radio {
    DistanceConstraint* constraint;
    
    LabelInput* length;
    LabelInput* stiffness;
    ImageButton* currentLength;
public:
    DistanceConstraintForm();
    DistanceConstraintForm(bool selected);
    ~DistanceConstraintForm();
    
    bool hasConstraint();
    void setConstraint(DistanceConstraint* constraint);
    DistanceConstraint* getConstraint();
    
    void setCurrentConstraintLength();
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

class MouseCurrentLength : public MouseListener {
    DistanceConstraintForm* form;
public:
    MouseCurrentLength(DistanceConstraintForm* form);
    void onClick(MouseEvent* event) override;
    void onDrag(MouseEvent* event) override;
    void onDrop(MouseEvent* event) override;
    void onMove(MouseEvent* event) override;
};

class CurrentDistanceShortcutListener : public ShortcutListener{
    DistanceConstraintForm* form;
public:
    CurrentDistanceShortcutListener(DistanceConstraintForm* form);
    /**
     * Method that is called when user press SPACE.
     * 
     * @param KeyboardEvent* event
     */
    void onTrigger(KeyboardEvent* event);
};
#endif /* DISTANCECONSTRAINTFORM_H */

