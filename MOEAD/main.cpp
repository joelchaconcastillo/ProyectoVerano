#include <iostream>
#include "Measures.hpp"
#include "MOEAD.hpp"
using namespace std;

int main()
{
	
  /*  NSGAII ObjNSGAII(SizePool, ProbCross, NBitsMut, ObjBenchmark, TotalGenerations, "Summary.txt");*/
    double ProbCross= 0.5;
    int SizePool = 200, NBitsMut =1, TotalGenerations =200; 
    Benchmark ObjBenchmark(SCH1);
	MOEAD ObjMOEAD(SizePool, ProbCross, NBitsMut, ObjBenchmark, TotalGenerations);
    ObjMOEAD.Run();
    //NSGAII ObjNSGAII(SizePool, ProbCross, NBitsMut, ObjBenchmark, TotalGenerations, "Summary.txt");	
    return 0;
}
