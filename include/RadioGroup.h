/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RadioGroup.h
 * Author: arksys
 *
 * Created on November 6, 2016, 12:58 PM
 */

#ifndef RADIOGROUP_H
#define RADIOGROUP_H

#include <iostream>
#include <list>

#include "Radio.h"

class RadioGroup {
    Radio* selected;
    
    ChangeListener* changeListener;
public:
    RadioGroup();
    RadioGroup(Radio* radio);
    virtual ~RadioGroup();

    virtual void select(Radio* radio) = 0;
    
    void setSelected(Radio* selected);
    Radio* getSelected();
    bool isSelected();
    
    void onChange();
    void setChangeListener(ChangeListener* listener);
    bool hasChangeListener();
    ChangeListener* getChangeListener();
};

#endif /* RADIOGROUP_H */

