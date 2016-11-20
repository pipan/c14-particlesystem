/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SelectRadioGroup.h
 * Author: arksys
 *
 * Created on November 8, 2016, 1:34 PM
 */

#ifndef SELECTRADIOGROUP_H
#define SELECTRADIOGROUP_H

#include "RadioGroup.h"

class SelectRadioGroup : public RadioGroup {
public:
    SelectRadioGroup();
    SelectRadioGroup(Radio* radio);
    virtual ~SelectRadioGroup();

    virtual void select(Radio* radio);
};

#endif /* SELECTRADIOGROUP_H */

