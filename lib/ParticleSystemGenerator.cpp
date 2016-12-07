/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/ParticleSystemGenerator.h"

ParticleSystemGenerator::ParticleSystemGenerator() {

}

void ParticleSystemGenerator::generateCircle(ParticleSystem* pSys) {
    CircleParticleShape* circleShape = new CircleParticleShape(pSys->getEnviroment(), 12, 12, 20, 550, 120);
    circleShape->generate(pSys, 2, 0.8);
}

void ParticleSystemGenerator::generateSquare(ParticleSystem* pSys) {
    SquareParticleShape* squareShape = new SquareParticleShape(pSys->getEnviroment(), 20, 20, 20, 550, 120);
    squareShape->generate(pSys, 3, 0.5);
}

void ParticleSystemGenerator::generateTriangle(ParticleSystem* pSys) {
    TriangleParticleShape* triangleShape = new TriangleParticleShape(pSys->getEnviroment(), 20, 20, 20, 550, 120);
    triangleShape->generate(pSys, 10, 0.2);
}
