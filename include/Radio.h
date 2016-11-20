/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Radio.h
 * Author: arksys
 *
 * Created on November 6, 2016, 12:58 PM
 */

#ifndef RADIO_H
#define RADIO_H

#include "Renderable.h"

class Radio : public Renderable {
    bool selected;
public:
    Radio();
    Radio(bool selected);
    bool isSelected();
    virtual void setSelected(bool selected);
    void select();
    void deselect();
};

#endif /* RADIO_H */

