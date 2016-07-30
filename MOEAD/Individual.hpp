#ifndef INDIVIDUAL_HPP_INCLUDED
#define INDIVIDUAL_HPP_INCLUDED
#define BINARY_ENCODE 111
#define REAL_ENCODE 112
#include "Objectives.hpp"
using namespace std;
class Individual{
    public:
        Individual();
        void InitializeIndividual(Benchmark *ObjBenchmark);
        /**
            Se obtiene el objeto objectives el cual consta de la información
            de todas las funciones objetivo.
        **/

        /**
            Get
        **/
        inline Objectives& getObjectives(){ return ObjObjectives; }
        inline double getDistance(){return this->Distance;}
        inline double getRank(){return this->Rank;}
        inline int getNumberObjectives(){return this->NumberObjectives;}
        inline int getDimension(){return this->Dimension;}
	inline int getVariableRepresentation(){return this->VariableRepresentation;}
	double getEvaluationMethod();
	inline double getObjectiveValue(int N){ return this->ObjObjectives.SpaceObjectives[N].Fitness;}
	inline bool Dominate(Individual &Ind){ return this->ObjObjectives.Dominate(Ind.ObjObjectives);}
        /**
            Set
        **/
        inline void setRank(int Rank){ this->Rank = Rank;}
        inline void setDistance(double Distance){this->Distance = Distance;}
	inline void setVariableRepresentation(int VariableRepresentation){this->VariableRepresentation = VariableRepresentation;}
        void EvalIndividual();
        void DecodeIndividual(vector<double> & Genotype);
	
        /**
		Variable de desición para el caso encod-binary
	**/
	vector<vector<bool>> DecisionVariables;
    private:
        Objectives ObjObjectives;
        int Dimension, NumberObjectives, Rank, nbits;
	int VariableRepresentation;
        double Distance;


        double getBase10(vector<bool> &Individuo, double Min , double Max);
        int BinarytoInt(vector<bool> &Individuo);
        vector<vector<double>> Bounds;
        void setRandomBinary();
        //Generar boleanos aleatorios con una distribución bernoulli
        vector<bool>random_bool( double p  = 0.5);
	
};


#endif // INDIVIDUAL_HPP_INCLUDED
