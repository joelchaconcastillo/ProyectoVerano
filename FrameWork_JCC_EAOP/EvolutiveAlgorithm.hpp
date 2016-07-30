/**
	Author: Joel Chacón Castillo
**/
#ifndef EVOLUTIVEALGORITHM_HPP_INCLUDED
#define EVOLUTIVEALGORITHM_HPP_INCLUDED
#include "Individual.hpp"
#include "Benchmark.hpp"
#include "EAOperators.hpp"	
using namespace std;
class EvolutiveAlgorithm 
{
	public: 
		EvolutiveAlgorithm();	
		virtual void Run();
	protected:
		int SizePopulation, NumberGenerations, NBitsMut, CurrentGeneration=0;
		double ProbCross; 
		Benchmark *ObjBenchmark;
		vector<Individual> Population, OffSpring;
		
		virtual void Reproduction();
		virtual void Generation();
		virtual void InitializePopulation();
		virtual void Selection();
		virtual void Recombination();
		virtual void Mutation();
		virtual void Evaluation();
		virtual void Improvement();
		};
vector< Individual > operator+(vector<Individual> PoolA, vector<Individual> PoolB );
ostream & operator << ( ostream &out,vector<Individual> Pool);
ostream & operator << ( ostream &out,vector<double> data);


#endif
