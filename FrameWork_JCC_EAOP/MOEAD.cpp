#include <iostream>
#include "EvolutiveAlgorithm.hpp"
#include "MOEAD.hpp"

MOEAD::MOEAD()
{
}
MOEAD::MOEAD(int SizePool, double ProbCross, int NBitsMut, Benchmark &ObjBenchmark, int TotalGenerations)
{
	this->SizePopulation = SizePool;
	this->ProbCross = ProbCross;
	this->NBitsMut = NBitsMut;
	this->ObjBenchmark = &ObjBenchmark;
	this->NumberGenerations = TotalGenerations;
	
}

