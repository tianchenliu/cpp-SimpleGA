#include "ga_problem.h"

using namespace std;

int main()
{
    GaProblem ga1;
    //ga1.TestChromosomeClass();
    //ga1.TestIndividualClass();
    ga1.InitPopulation();

    for (int i=10; i<20; i++) { ga1.pop_gen_prev[i].PrintIndividualInfo(); }

    
    return 0;
}



