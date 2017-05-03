#include <iostream>
#include <string>
#include "Hausdorff.hpp"
using namespace std;
 string verbose()
{
   string message = "";
   message += "--h --help print this summary and exit\n";
   message += "--p power of the formula (default 1 as the paper)\n";
   message += "--r the filename of reference points\n";
   message += "--n Normalize the sets by the reference points provided\n";
   message += "--s the filename of data approximations, alternativelly this can be calculated as \" cat file | ./HD --r reference.txt  \"  \n";
   message += "Example:\n  echo -e \"2 2 \n\" | ./HD --r reference.txt";
   return message;
}

int main(int argc, char *argv[])
{

  if(argc<2)
         {
	    
	    cout << "Unknown Argument.."<<endl;
	    cout << verbose();
	    exit(0);
	 }

   double p = 1;
   bool Normalize = false;
   string filenamePareto="", filenameSet="";
   for(int i = 1; i < argc ; i++)
    	{
		string Terminal(argv[i]);
		if( Terminal == "--h")
			cout << verbose<<endl;
		else if(Terminal == "--r" )
			filenamePareto = string(argv[++i]);
		else if(Terminal == "--s" )
			filenameSet = string(argv[++i]);
		else if(Terminal == "--p" )
			p = atof(argv[++i]);
		else if(Terminal == "--n" )
			Normalize = true;
		else
		{
		   cout << "Unknown Argument...";
		   exit(0);
		}

	}
  
   if(filenamePareto.empty()) {cout << "Reference points are needed"; exit(0);}



   Average_Hausdorff A_H_Obj;   
   A_H_Obj.setNormalize(Normalize);
   cout << A_H_Obj.do_Metric_Hausdorff(filenamePareto, filenameSet, p) << endl;
   
   return 0;
}
