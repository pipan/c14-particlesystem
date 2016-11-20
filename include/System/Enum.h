/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enum.h
 * Author: arksys
 *
 * Created on November 8, 2016, 12:51 AM
 */

#ifndef ENUM_H
#define ENUM_H

enum CURSOR_TYPE {POINTER, ADD, REMOVE};
enum EVENT_TYPE {MOUSE, KEYBOARD, TEXT, FOCUS, CHANGE, INPUT, PARTICLE};
enum LAYOUT_PADDING {TOP, RIGHT, BOTTOM, LEFT, VERTICAL, HORIZONTAL};
enum LMN_LAYOUT_HORIZONTAL {FILL, WRAP, ABSOLUTE, PERCENTAGE};

/**
 * Values that represent modifications for certain colors. For example opacity modifications
 */
enum COLOR_MODE {NORMAL, LOW, DISABLED};

/**
 * Different types of vector indexes. We are working in 2D space, so we will use only X and Y
 */
enum VECTOR_INDEX {X, Y};

#endif /* ENUM_H */

