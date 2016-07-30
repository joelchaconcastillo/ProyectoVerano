/**
	Author: Joel Chacón Castillo
**/
#ifndef EAOperators_HPP_INCLUDED
#define EAOperators_HPP_INCLUDED
#include "Individual.hpp"
using namespace std;
//class EAOperators
//{
//	public:
//		EAOperators();
//	protected:

	/**
		Operadores relacionados con la selección
	**/
	 void TournamentSelection(vector<Individual> &Population, vector<Individual> &OffSpring);
	 void RouletteWhell();
	 void SUS();//Stochastic Universal Sampling
	/**
		Operadores relacionados con la cruza..
	**/
	//Binary Representation
	 void OnePointCrossOver();
	 void UniformCross(vector<Individual> &Population ,vector<Individual> &OffSpring);
	 void UniformCrossIndividual(Individual &A, Individual &B, Individual &OffSpring);
	 void NPointCrossOver();
	//Real Representation
	 void LinearCrossover();
	 void BLX(); //Blend Crossover 
	 void SBX(); //Simulated Binary Crossover
	 void UNDX(); //Unimodal Normally Distributed Crossover
	  void SPX(); //Simplex Crossover
	 void FCB(); // Fuzzy Connectivitives Based Crossover
	 void UnfairAverageCrossover();
	
	/**
		Operadores relacionados con la mutación..
	**/
	//Binary Representation
	 void BitMutation(vector<Individual> &Population, int NBitsMut);
	 void BitMutationIndividual(Individual &A, int NBitsMut);
	//Real Representation
	 void RandomMutation();
	 void NonUniformMutation();
	 void NormallyDistribuitedMutation();
	 void PolynomialMutation();
//};

#endif
