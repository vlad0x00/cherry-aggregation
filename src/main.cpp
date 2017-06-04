//============================================================================
// Name        : CherryAggregation.cpp
// Author      : Vladimir Nikolic & Vanja Knezevic
// Version     :
// Copyright   : Copyleft
//============================================================================

#include "simulation/Simulation.h"
using simulation::Simulation;

#include <thread>
using std::this_thread::sleep_for;

#include <chrono>
using namespace std::chrono_literals;

int main() {
	Simulation::start();

    sleep_for(5000ms);

	Simulation::stop();

	return 0;
}
