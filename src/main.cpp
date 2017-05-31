//============================================================================
// Name        : BallisticAggregationSim.cpp
// Author      : Vladimir Nikolic & Vanja Knezevic
// Version     :
// Copyright   : Copyleft
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "simulation/Simulation.h"
using simulation::Simulation;

#include <thread>
using std::this_thread::sleep_for;

#include <chrono>
using namespace std::chrono_literals;

int main() {
	Simulation::start();

    sleep_for(2000ms);

	Simulation::stop();

	return 0;
}
