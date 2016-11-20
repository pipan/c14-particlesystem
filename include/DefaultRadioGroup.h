/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DefaultRadioGroup.h
 * Author: arksys
 *
 * Created on November 8, 2016, 2:07 PM
 */

#ifndef DEFAULTRADIOGROUP_H
#define DEFAULTRADIOGROUP_H

#include "RadioGroup.h"

class DefaultRadioGroup : public RadioGroup {
    Radio* def;
public:
    DefaultRadioGroup(Radio* def);
    DefaultRadioGroup(Radio* def, Radio* selected);
    virtual ~DefaultRadioGroup();

    void select(Radio* radio) override;
};

#endif /* DEFAULTRADIOGROUP_H */

