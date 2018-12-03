/*
 * PROG24310: Assignment 3
 */

#include <cstdlib>
#include "Simulation.h"

using namespace std;

int main() {

    Simulation *sim = new Simulation();
    sim->printResult();
    delete sim;
    
    return 0;
}

