/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arksys
 *
 * Created on October 9, 2016, 2:58 AM
 */

#include <string>
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "include/System/Enum.h"
#include "include/Pane.h"
#include "include/PlayButton.h"
#include "include/Provider.h"
#include "include/EventHandler.h"
#include "include/MouseService.h"
#include "include/Input.h"
#include "include/FormService.h"
#include "include/TimeService.h"
#include "include/Template.h"
#include "include/LabelInput.h"
#include "include/ColisionGrid.h"
#include "include/ShortcutService.h"
#include "include/Particle.h"
#include "include/Enviroment.h"
#include "include/ParticleSystem.h"
#include "include/DistanceConstraint.h"
#include "include/VectorMath.h"
#include "include/ParticleForm.h"
#include "include/ParticleService.h"
#include "include/EnviromentForm.h"
#include "include/MouseCursorService.h"
#include "include/MouseCursorController.h"
#include "include/RadioGroup.h"
#include "include/DistanceConstraintForm.h"
#include "include/ToggleRadioGroup.h"
#include "include/DefaultRadioGroup.h"
#include "include/SquareParticleShape.h"
#include "include/TriangleParticleShape.h"
#include "include/CircleParticleShape.h"
#include "include/SectionBlock.h"
#include "include/ParticleSystemGenerator.h"

/**
 */
class PlayChangeListener : public ChangeListener {
    ParticleSystem* system;
public:
    PlayChangeListener(ParticleSystem* system);
    void onChange(Event* event) override;
};

/**
 */
class CursorMouseListener : public MouseListener {
    RadioGroup* group;
    CURSOR_TYPE cursor;
public:
    CursorMouseListener(RadioGroup* group, CURSOR_TYPE cursor);
    virtual void onClick(MouseEvent* event) override;
    virtual void onDrag(MouseEvent* event) override;
    virtual void onMove(MouseEvent* event) override;
    virtual void onDrop(MouseEvent* event) override;
};

PlayChangeListener::PlayChangeListener(ParticleSystem* system){
    this->system = system;
}

void PlayChangeListener::onChange(Event* event) {
    PlayButton* button = (PlayButton*) event->getObject();
    
    if (button->isPlaying()){
        this->system->play();
    }
    else{
        this->system->pause();
    }
}

CursorMouseListener::CursorMouseListener(RadioGroup* group, CURSOR_TYPE cursor){
    this->group = group;
    this->cursor = cursor;
}

void CursorMouseListener::onClick(MouseEvent* event) {
    MouseCursorService* cursorService = (MouseCursorService*) Provider::getInstance()->get("cursorService");
    Radio* radio = (Radio*) event->getObject();
    
    this->group->select(radio);
    cursorService->setCursorType(this->cursor);
}

void CursorMouseListener::onDrag(MouseEvent* event) {

}

void CursorMouseListener::onDrop(MouseEvent* event) {

}

void CursorMouseListener::onMove(MouseEvent* event) {

}

/**
 */
class ChangeSelectedListener : public ChangeListener {
protected:
    RadioGroup* tabs;
    Radio* tab;
public:
    ChangeSelectedListener(RadioGroup* group, Radio* tab);
    virtual void onChange(Event* event) override;
};

ChangeSelectedListener::ChangeSelectedListener(RadioGroup* group, Radio* tab){
    this->tabs = group;
    this->tab = tab;
}

void ChangeSelectedListener::onChange(Event* event) {
    Radio* radio = (Radio*) event->getObject();
    if (radio != NULL && radio->isSelected()){
        this->tabs->select(this->tab);
    }
    else{
        this->tabs->select(NULL);
    }
}
/**
 * 
 * @param group
 * @param tab
 */
class ChangeSelectedParticleListener : public ChangeSelectedListener {
    ParticleForm* form;
public:
    ChangeSelectedParticleListener(RadioGroup* group, ParticleForm* tab);
    virtual void onChange(Event* event) override;
};

ChangeSelectedParticleListener::ChangeSelectedParticleListener(RadioGroup* group, ParticleForm* tab) : ChangeSelectedListener(group, tab) {
    this->form = tab;
}

void ChangeSelectedParticleListener::onChange(Event* event) {
    RadioGroup* particleService = (RadioGroup*) Provider::getInstance()->get("particleService");
    RadioGroup* constraintService = (RadioGroup*) Provider::getInstance()->get("constraintService");
    Radio* radio = (Radio*) event->getObject();
    if (radio != NULL && radio->isSelected()){
        constraintService->select(NULL);
    }
    
    ChangeSelectedListener::onChange(event);
    
    if (particleService->isSelected()){
        this->form->fillParticle((Particle*) particleService->getSelected());
    }
}

/**
 * 
 * @param group
 * @param tab
 */
class ChangeSelectedConstraintListener : public ChangeSelectedListener {
    DistanceConstraintForm* form;
public:
    ChangeSelectedConstraintListener(RadioGroup* group, DistanceConstraintForm* tab);
    virtual void onChange(Event* event) override;
};

ChangeSelectedConstraintListener::ChangeSelectedConstraintListener(RadioGroup* group, DistanceConstraintForm* tab) : ChangeSelectedListener(group, tab) {
    this->form = tab;
}

void ChangeSelectedConstraintListener::onChange(Event* event) {
    RadioGroup* particleService = (RadioGroup*) Provider::getInstance()->get("particleService");
    RadioGroup* constraintService = (RadioGroup*) Provider::getInstance()->get("constraintService");
    Radio* radio = (Radio*) event->getObject();
    if (radio != NULL && radio->isSelected()){
        particleService->select(NULL);
    }
    
    ChangeSelectedListener::onChange(event);
    
    if (constraintService->isSelected()){
        this->form->setConstraint((DistanceConstraint*) constraintService->getSelected());
    }
}

/**
 * 
 */
class PaneMouseListener : public MouseListener {
    ParticleSystem* system;
public:
    PaneMouseListener(ParticleSystem* system);
    virtual ~PaneMouseListener();

    void onClick(MouseEvent* event) override;
    void onDrag(MouseEvent* event) override;
    void onDrop(MouseEvent* event) override;
    void onMove(MouseEvent* event) override;
};

PaneMouseListener::PaneMouseListener(ParticleSystem* system) : MouseListener(){
    this->system = system;
}

PaneMouseListener::~PaneMouseListener() {
}

void PaneMouseListener::onClick(MouseEvent* event) {
    RadioGroup* service = (RadioGroup*) Provider::getInstance()->get("particleService");
    
    switch (event->getCursorType()){
        case ADD:
            Particle* p = new Particle(event->getX(), event->getY(), 0);
            this->system->addParticle(p);
            if (service->getSelected() != NULL){
                this->system->addConstrain(new DistanceConstraint(p, (Particle*) service->getSelected(), 1.0));
            }
            
            break;
    }
}

void PaneMouseListener::onDrag(MouseEvent* event) {

}

void PaneMouseListener::onDrop(MouseEvent* event) {

}

void PaneMouseListener::onMove(MouseEvent* event) {

}

class PSysGeneratorListener : public MouseListener {
public:
    ParticleSystem* pSys;
    PSysGeneratorListener(ParticleSystem* pSys);
    virtual void onClick(MouseEvent* event) override;
    virtual void onDrag(MouseEvent* event) override;
    virtual void onMove(MouseEvent* event) override;
    virtual void onDrop(MouseEvent* event) override;
};
class TriangleGeneratorListener : public PSysGeneratorListener {
public:
    TriangleGeneratorListener(ParticleSystem* pSys);
    virtual void onClick(MouseEvent* event) override;
};
class SquareGeneratorListener : public PSysGeneratorListener {
public:
    SquareGeneratorListener(ParticleSystem* pSys);
    virtual void onClick(MouseEvent* event) override;
};
class CircleGeneratorListener : public PSysGeneratorListener {
public:
    CircleGeneratorListener(ParticleSystem* pSys);
    virtual void onClick(MouseEvent* event) override;
};
class ClearGeneratorListener : public PSysGeneratorListener {
public:
    ClearGeneratorListener(ParticleSystem* pSys);
    virtual void onClick(MouseEvent* event) override;
};

PSysGeneratorListener::PSysGeneratorListener(ParticleSystem* pSys){
    this->pSys = pSys;
}
void PSysGeneratorListener::onClick(MouseEvent* event) {
    
}
void PSysGeneratorListener::onDrag(MouseEvent* event) {

}
void PSysGeneratorListener::onDrop(MouseEvent* event) {

}
void PSysGeneratorListener::onMove(MouseEvent* event) {

}

TriangleGeneratorListener::TriangleGeneratorListener(ParticleSystem* pSys) : PSysGeneratorListener(pSys){
}

void TriangleGeneratorListener::onClick(MouseEvent* event) {
    ParticleSystemGenerator* generator = (ParticleSystemGenerator*) Provider::getInstance()->get("particleSystemGenerator");
    
    generator->generateTriangle(this->pSys);
}

SquareGeneratorListener::SquareGeneratorListener(ParticleSystem* pSys) : PSysGeneratorListener(pSys){
}

void SquareGeneratorListener::onClick(MouseEvent* event) {
    ParticleSystemGenerator* generator = (ParticleSystemGenerator*) Provider::getInstance()->get("particleSystemGenerator");
    
    generator->generateSquare(this->pSys);
}

CircleGeneratorListener::CircleGeneratorListener(ParticleSystem* pSys) : PSysGeneratorListener(pSys){
}

void CircleGeneratorListener::onClick(MouseEvent* event) {
    ParticleSystemGenerator* generator = (ParticleSystemGenerator*) Provider::getInstance()->get("particleSystemGenerator");
    
    generator->generateCircle(this->pSys);
}

ClearGeneratorListener::ClearGeneratorListener(ParticleSystem* pSys) : PSysGeneratorListener(pSys){
}

void ClearGeneratorListener::onClick(MouseEvent* event) {
    this->pSys->clear();
}




void registerServices(){
    PointerCursorController* pointerCursorController = new PointerCursorController();
    
    Provider* provider = Provider::getInstance();
    provider->add("mouseService", new MouseService());
    provider->add("formService", new FormService());
    provider->add("keyboardEventHandler", new KeyboardEventHandler());
    provider->add("particleService", new ToggleRadioGroup());
    provider->add("constraintService", new ToggleRadioGroup());
    provider->add("shortcut", new ShortcutService());
    provider->add("grid", new ColisionGrid());
    provider->add("cursorService", new MouseCursorService(POINTER));
    provider->add("particleSystemGenerator", new ParticleSystemGenerator());
    
    provider->add("time", new TimeService());
    provider->add("vectorMath", new VectorMath());
}

/*
 * 
 */
int main(int argc, char** argv) {
    //register all services as singletons. they are accesibble trough provider
    registerServices();
    
    //get all important services
    Provider* provider = Provider::getInstance();
    ColisionGrid* grid = (ColisionGrid*) provider->get("grid");
    MouseCursorService* cursorService = (MouseCursorService*) provider->get("cursorService");
    KeyboardEventHandler* keyboardEventHandler = (KeyboardEventHandler*) provider->get("keyboardEventHandler");
    ShortcutService* shortcut = (ShortcutService*) provider->get("shortcut");
    TimeService* time = (TimeService*) provider->get("time");
    RadioGroup* particleService = (RadioGroup*) provider->get("particleService");
    RadioGroup* constraintService = (RadioGroup*) provider->get("constraintService");
    
    float timeAll = 0.0f;
    float zoom = 1.0;
    sf::Vector2f world;
    
    //set active color tempalte
    Template::activate(new ColorTemplate());
    //Template::activate(new ColorTemplate(sf::Color(1,87,156),sf::Color(129,208,250),sf::Color(0,188,208)));
    //Template::activate(new ColorTemplate(sf::Color(51,105,30),sf::Color(197, 225, 165),sf::Color(244, 67, 54)));
    
    //Create enviroment
    Enviroment* env = new Enviroment(time, sf::Vector2f(0, 90.81f), 0.1, 3, 650.0f);
    
    //Init window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Particle System - C14");
    
    //init interface elements
    Pane* left = new Pane(new Layout(0,0,1280/4,720));
    Pane* body = new Pane(new Layout(0,0,4 * 1280 / 4,720));
    SectionBlock* buttonSection = new SectionBlock();
    SectionBlock* formSection = new SectionBlock();
    PlayButton* button = new PlayButton(sf::Vector2f(48,48));
    ImageButton *pointerCursor = new ImageButton("assets/images/move.png", sf::Vector2f(48,48));
    ImageButton *addCursor = new ImageButton("assets/images/add.png", sf::Vector2f(48,48));
    ImageButton *removeCursor = new ImageButton("assets/images/remove.png", sf::Vector2f(48,48));
    ImageButton *clearPSys = new ImageButton("assets/images/clear.png", sf::Vector2f(48,48));
    ImageButton *squarePSys = new ImageButton("assets/images/square.png", sf::Vector2f(48,48));
    ImageButton *circlePSys = new ImageButton("assets/images/circle.png", sf::Vector2f(48,48));
    ImageButton *trianglePSys = new ImageButton("assets/images/triangle.png", sf::Vector2f(48,48));
    HorizontalDevider* cursorDevider = new HorizontalDevider(*Template::getActive()->getForegroundLight(DISABLED));
    HorizontalDevider* generatorDevider = new HorizontalDevider(*Template::getActive()->getForegroundLight(DISABLED));
    ParticleForm* particleForm = new ParticleForm(false);
    DistanceConstraintForm* distanceConstraintForm = new DistanceConstraintForm(false);
    EnviromentForm* enviromentForm = new EnviromentForm(false);
    RadioGroup* cursorGroup = new SelectRadioGroup(pointerCursor);
    RadioGroup* leftTab = new DefaultRadioGroup(enviromentForm);
    
    particleService->setChangeListener(new ChangeSelectedParticleListener(leftTab, particleForm));
    constraintService->setChangeListener(new ChangeSelectedConstraintListener(leftTab, distanceConstraintForm));
    
    //Particles

    ParticleSystem* pSys = new ParticleSystem(env, false);

//    Particle* p1 = new Particle(650, 320, 0);
//    Particle* p2 = new Particle(700, 300, 5);
//    Particle* p3 = new Particle(750, 300, 15);
//    Particle* p4 = new Particle(770, 300, 20);
//    Particle* p5 = new Particle(830, 300, 3);
//    Particle* p6 = new Particle(800, 330, 6);
//    Particle* pAlone = new Particle(900, 300, 0);
//    pSys->addParticle(p1);
//    pSys->addParticle(p2);
//    pSys->addParticle(p3);
//    pSys->addParticle(p4);
//    pSys->addParticle(p5);
//    pSys->addParticle(p6);
//    pSys->addParticle(pAlone);
//    pSys->addConstrain(new DistanceConstraint(p1, p2, 0.1f));
//    pSys->addConstrain(new DistanceConstraint(p2, p3, 0.1f));
//    pSys->addConstrain(new DistanceConstraint(p3, p4, 1.0f));
//    pSys->addConstrain(new DistanceConstraint(p4, p5, 0.2f));
//    pSys->addConstrain(new DistanceConstraint(p4, p6, 0.5f));
//    pSys->addConstrain(new DistanceConstraint(p5, p6, 0.5f));
    
    
    
    //allow some shortcuts
    shortcut->registerMapShortcut("SPACE", "PlayPause");
    shortcut->registerMapShortcut("DELETE", "RemoveSelected");
    shortcut->registerMapShortcut("ESCAPE", "Deselect");
    shortcut->registerMapShortcut("LEFT_CTRL+D", "Deselect");
    shortcut->registerMapShortcut("LEFT_CTRL+SPACE", "CurrentConstraintDistance");
    
    left->getView()->setViewport(sf::FloatRect(0,0,0.25f,1));
    left->setBackgroundColor(sf::Color(33, 33, 33, 255));
            
    body->getView()->setViewport(sf::FloatRect(0.0f,0.0f,1.0f,1.0f));
    body->setBackgroundColor(sf::Color(244, 244, 244, 255));
    body->setMouseListener(new PaneMouseListener(pSys));
    
    buttonSection->setLayout(new Layout(0, 0, 48, 700));
    formSection->setLayout(new Layout(48, 12, 1.0f, 700, PERCENTAGE));
    
    //Left view items
    button->setLayout(new Layout(sf::Vector2f(0, 0), sf::Vector2f(48,48)));
    button->setChangeListener(new PlayChangeListener(pSys));
    buttonSection->addRenderable(button);
    
    cursorDevider->setLayout(new Layout(0, 54, 1.0f, 1, PERCENTAGE));
    buttonSection->addRenderable(cursorDevider);
    
    pointerCursor->setLayout(new Layout(sf::Vector2f(0, 60), sf::Vector2f(48,48)));
    pointerCursor->setMouseListener(new CursorMouseListener(cursorGroup, POINTER));
    buttonSection->addRenderable(pointerCursor);
    addCursor->setLayout(new Layout(sf::Vector2f(0, 108), sf::Vector2f(48,48)));
    addCursor->setMouseListener(new CursorMouseListener(cursorGroup, ADD));
    buttonSection->addRenderable(addCursor);
    removeCursor->setLayout(new Layout(sf::Vector2f(0, 156), sf::Vector2f(48,48)));
    removeCursor->setMouseListener(new CursorMouseListener(cursorGroup, REMOVE));
    buttonSection->addRenderable(removeCursor);
    
    generatorDevider->setLayout(new Layout(0, 210, 1.0f, 1, PERCENTAGE));
    buttonSection->addRenderable(generatorDevider);
    
    squarePSys->setLayout(new Layout(sf::Vector2f(0, 216), sf::Vector2f(48,48)));
    squarePSys->setMouseListener(new SquareGeneratorListener(pSys));
    buttonSection->addRenderable(squarePSys);
    trianglePSys->setLayout(new Layout(sf::Vector2f(0, 264), sf::Vector2f(48,48)));
    trianglePSys->setMouseListener(new TriangleGeneratorListener(pSys));
    buttonSection->addRenderable(trianglePSys);
    circlePSys->setLayout(new Layout(sf::Vector2f(0, 312), sf::Vector2f(48,48)));
    circlePSys->setMouseListener(new CircleGeneratorListener(pSys));
    buttonSection->addRenderable(circlePSys);
    clearPSys->setLayout(new Layout(sf::Vector2f(0, 360), sf::Vector2f(48,48)));
    clearPSys->setMouseListener(new ClearGeneratorListener(pSys));
    buttonSection->addRenderable(clearPSys);
    
    left->addRenderable(buttonSection);
    left->addRenderable(formSection);
    
    particleForm->setLayout(new Layout(0, 0, 1.0f, 400, PERCENTAGE));
    particleForm->getLayout()->setPadding(12);
    formSection->addRenderable(particleForm);
    
    distanceConstraintForm->setLayout(new Layout(0, 0, 1.0f, 400, PERCENTAGE));
    distanceConstraintForm->getLayout()->setPadding(12);
    formSection->addRenderable(distanceConstraintForm);
    
    enviromentForm->setLayout(new Layout(0, 0, 1.0f, 400, PERCENTAGE));
    enviromentForm->getLayout()->setPadding(12);
    enviromentForm->setEnviroment(env);
    formSection->addRenderable(enviromentForm);
    
    //Body items
    body->addRenderable(pSys);
    body->addRenderable(env);
    
    window.setFramerateLimit(60);
    
    left->update(&window);
    body->update(&window);
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        //checkPositionChange
        grid->updateAll();
        
        if (pSys->isPlaying()){
            timeAll += time->getTimeChange();
        }
        
        time->reset();
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
//                case sf::Event::MouseButtonReleased:
//                case sf::Event::MouseEntered:
//                case sf::Event::MouseLeft:
//                case sf::Event::MouseWheelMoved:
                case sf::Event::MouseWheelScrolled:
                    zoom = 1.0 + event.mouseWheelScroll.delta/100;
                    //body->getView()->setCenter(0, -360);
                    //body->getView()->move(0, -20);
                    //body->getView()->zoom(zoom);
                    break;
                case sf::Event::MouseMoved:
                case sf::Event::MouseButtonReleased:
                case sf::Event::MouseButtonPressed:
                    //world = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    cursorService->fire(new MouseEvent(&event));
                    break;
                case sf::Event::KeyPressed:
                    keyboardEventHandler->fire(new KeyboardEvent(&event, true));
                    break;
                case sf::Event::KeyReleased:
                    keyboardEventHandler->fire(new KeyboardEvent(&event, false));
                    break;
                case sf::Event::TextEntered:
                    switch (event.text.unicode){
                        case LMN_KEY_BACKSPACE:
                        case LMN_KEY_ENTER:
                        case LMN_KEY_ESC:
                        case LMN_KEY_DELETE:
                            
                            break;
                        default:
                            keyboardEventHandler->fire(new KeyboardEvent(&event, TEXT));
                    }
                    break;
                case sf::Event::Resized:
                    //update the view to the new size of the window
                    left->update(&window);
                    body->update(&window);
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }       
        }
        
        //window.clear(*Template::getActive()->getBackgroundLight());
        window.clear(sf::Color::Black);
        
        body->render(&window);
        
        //render GUI
        left->render(&window);
        
        window.display();
    }

    
    return 0;
}

