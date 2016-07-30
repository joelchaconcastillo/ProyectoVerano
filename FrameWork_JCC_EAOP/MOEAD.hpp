/**
	Author: Joel Chacón Castillo
	Description: En este fichero se presenta la estructura del algoritmo.
**/
#ifndef MOEAD_HPP_INCLUDED
#define MOEAD_HPP_INCLUDED
#include "Benchmark.hpp"
#include "EvolutiveAlgorithm.hpp"
using namespace std;
class MOEAD : public EvolutiveAlgorithm
{
	public:
		MOEAD();
		MOEAD(int SizePool, double ProbCross, int NBitsMut, Benchmark &ObjBenchmark, int TotalGenerations);
	private:

};

#endif
