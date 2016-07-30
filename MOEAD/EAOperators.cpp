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
		UniformCrossIndividual(Population[Index1], Population[Index2], OffSpring[i] );	
	}
}
void UniformCrossIndividual(Individual &A, Individual &B, Individual &OffSpring)
{
		for(int D = 0; D < A.getDimension(); D++)
		{
			for(int bit = 0; bit < A.DecisionVariables[D].size() ; bit++)
			{
				double RandomNumber = rand()/(RAND_MAX + 1);
				if(RandomNumber < 0.5 )
					OffSpring.DecisionVariables[D][bit] = A.DecisionVariables[D][bit]; 		
				else
					OffSpring.DecisionVariables[D][bit] = B.DecisionVariables[D][bit]; 		
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
	
	}
}
void BitMutationIndividual(Individual &A, int NBitsMut)
{
		for(int D = 0; D < A.getDimension() ; D++)
		{
			int ChangedBits = 0;
                 	while( ChangedBits < NBitsMut)
                 	{
				int LocusBit = 	rand()% A.DecisionVariables[D].size(); 
			        if( A.DecisionVariables[D][LocusBit])
					A.DecisionVariables[D][LocusBit] = false;
				else
					A.DecisionVariables[D][LocusBit] = true;
			        
				ChangedBits++;
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

