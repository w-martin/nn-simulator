/* 
 * File:   Trainer.h
 * Author: Will
 *
 * Created on 08 June 2011, 15:53
 */

#include "nn-simulator/main/trainer/Trainer.h"
#include <time.h>
#include <stdlib.h>

Trainer::Trainer() {
}

Trainer::~Trainer() {
}

void Trainer::initWeights(Neuron const &n) const {
    setRandomWeights(n);
}

void Trainer::setRandomWeights(Neuron const &n) const {
    Weights *w = n.getWeights();
    srand((unsigned) time(NULL));
    float limit = RAND_MAX + 1;
    for (int i = 0; i < w->getSize(); i++) {
        float multiplier = (float) rand() / limit;
        if (multiplier < 0) multiplier = multiplier * -1;
        multiplier = multiplier / 2;

        w->setValue(i, multiplier);
    }
}
