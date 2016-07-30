#include <iostream>
#include "Individual.hpp"
#include "EAOperators.hpp"
//EAOperators::EAOperators()
//{
//
//}
/**
        Operadores relacionados con la selección
**/
void TournamentSelection(vector<Individual> &Population, vector<Individual> &OffSpring)
{

	for(int i = 0; i < Population.size(); i++)
	{
		int Index1 = rand()%Population.size();	
		int Index2 = rand()%Population.size();
		//Se escoge al individuo con mayor aptitud..	
		if( Population[Index1].getEvaluationMethod() > Population[Index2].getEvaluationMethod()  )
		{
		 	OffSpring[i] = Population[Index1];		
		}
		else
		{
			OffSpring[i] = Population[Index2];
		}

	}


}
void RouletteWhell()
{

}
void SUS()
{

}
/**
        Operadores relacionados con la cruza..
**/
//Binary Representation
void OnePointCrossOver()
{

}
void UniformCross(vector<Individual> &Population ,vector<Individual> &OffSpring)
{
	for(int i = 0; i < Population.size(); i++)
	{	
		int Index1 = rand()%Population.size();	
		int Index2 = rand()%Population.size();	
		for(int D = 0; D < Population[i].getDimension(); D++)
		{
			for(int bit = 0; bit < OffSpring[i].DecisionVariables[D].size() ; bit++)
			{
				double RandomNumber = rand()/(RAND_MAX + 1);
				if(RandomNumber < 0.5 )
					OffSpring[i].DecisionVariables[D][bit] = Population[Index1].DecisionVariables[D][bit]; 		
				else
					OffSpring[i].DecisionVariables[D][bit] = Population[Index2].DecisionVariables[D][bit]; 		
			}
		}
	}
}
void NPointCrossOver()
{

}
//Real Representation
void LinearCrossover()
{

}
void BLX()
{

}
void SBX()
{

}
void UNDX()
{

}
void SPX()
{

}
void FCB()
{
} 
void UnfairAverageCrossover()
{

}

/**
        Operadores relacionados con la mutación..
**/
//Binary Representation
void BitMutation(vector<Individual> &Population, int NBitsMut)
{
	for(int i = 0; i < Population.size(); i++)
	{
		for(int D = 0; D < Population[i].getDimension() ; D++)
		{
			int ChangedBits = 0;
                 	while( ChangedBits < NBitsMut)
                 	{
				int LocusBit = 	rand()% Population[i].DecisionVariables[D].size(); 
			        if( Population[i].DecisionVariables[D][LocusBit])
					Population[i].DecisionVariables[D][LocusBit] = false;
				else
					Population[i].DecisionVariables[D][LocusBit] = true;
			        
				ChangedBits++;
		 	}
		 	
		 }
	}
}
//Real Representation
void RandomMutation()
{

}
void NonUniformMutation()
{

}
void NormallyDistribuitedMutation()
{

}
void PolynomialMutation()
{
//
}

