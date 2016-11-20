/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ToggleRadioGroup.h
 * Author: arksys
 *
 * Created on November 8, 2016, 11:22 AM
 */

#ifndef TOGGLERADIOGROUP_H
#define TOGGLERADIOGROUP_H

#include "RadioGroup.h"

class ToggleRadioGroup : public RadioGroup {
public:
    ToggleRadioGroup();
    ToggleRadioGroup(Radio* radio);
    virtual ~ToggleRadioGroup();

    void select(Radio* radio) override;
};

#endif /* TOGGLERADIOGROUP_H */

