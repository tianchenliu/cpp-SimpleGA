#include "simple_ga.h"

using namespace std;

int main()
{
    SimpleGa ga1;
    //ga1.TestChromosomeClass(); 
    //ga1.TestIndividualClass();

    ga1.InitPopulation();
    ga1.EvalPop();
    
    ga1.Selection();
    
    cout << endl;

    ga1.PrintAllInfo();

    //std::cout << "Current total # of individuals: " << ga1.counter_idv << std::endl;
    
    return 0;
}



