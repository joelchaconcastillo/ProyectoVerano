/**
	Author: Joel Chacón Castillo
**/
#include <iostream>
#include "Benchmark.hpp"
#include "EvolutiveAlgorithm.hpp"
#include "EAOperators.hpp"
EvolutiveAlgorithm::EvolutiveAlgorithm()
{
	srand(time(NULL));	
}
void EvolutiveAlgorithm::Reproduction()
{

}
void EvolutiveAlgorithm::Generation()
{
	Selection();
	Recombination();
	Mutation();
	Improvement();
	Evaluation();
}
void EvolutiveAlgorithm::Run()
{
	InitializePopulation();	
	for(CurrentGeneration = 0; CurrentGeneration  < this->NumberGenerations; CurrentGeneration++)
	{
		Generation();	
	}
	cout << this->Population<<endl;
}
/**
	Description: Inicializar a la población.
**/
void EvolutiveAlgorithm::InitializePopulation()
{
	this->Population.resize(this->SizePopulation);	
	this->OffSpring.resize(this->SizePopulation);
	for(int i = 0; i < this->SizePopulation; i++)
	{
		this->Population[i].setVariableRepresentation(BINARY_ENCODE);
		this->Population[i].InitializeIndividual(this->ObjBenchmark);
	}
}
void EvolutiveAlgorithm::Selection()
{
	TournamentSelection(this->Population, this->OffSpring);
	this->Population = this->OffSpring;
}
void EvolutiveAlgorithm::Recombination()
{
	UniformCross( this->Population ,this->OffSpring);	
	this->Population = this->OffSpring;
}
void EvolutiveAlgorithm::Mutation()
{
	BitMutation(this->Population, this->NBitsMut);
}
void EvolutiveAlgorithm::Evaluation()
{
        for(int i = 0; i < this->SizePopulation; i++)
        {   
                this->Population[i].EvalIndividual();
        }   
}
/**
	Se implementan heurísticas y/o búsquedas locales
**/
void EvolutiveAlgorithm::Improvement()
{

}
/**
	Sobrecarga de los operadores..
**/

ostream & operator << ( ostream &out,vector<Individual> Pool)
{
    for(int i = 0; i < Pool.size(); i++)
    {   
        for(int j = 0; j < Pool[i].getObjectives().getNumberObjectives() ; j++)
         out << Pool[i].getObjectives().SpaceObjectives[j].Fitness<<" ";
         out << endl;
    }   
    return out;
}
ostream & operator << ( ostream &out,vector<double> data)
{
    for(int i = 0; i < data.size(); i++)
    {   
        out << data << endl;
    }   
    return out;
}
vector<Individual> operator+(vector<Individual> PoolA, vector<Individual> PoolB )
{
    vector<Individual> C;
    for(int i=0 ; i < PoolA.size(); i++ )
        C.push_back(PoolA[i]);
    for(int i = 0; i < PoolB.size(); i++)
        C.push_back(PoolB[i]);
    return C;
}
