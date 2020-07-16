#include "simple_ga.h"

int main()
{
    SimpleGa ga1;
    //ga1.TestChromosomeClass(); 
    //ga1.TestIndividualClass();

    ga1.InitPopulation();
    
    while (!ga1.flag_stop) {
        ga1.EvalPop();
        ga1.Selection();
        ga1.CrossoverMutation();
        ga1.CheckStop();
        //ga1.PrintStepInfo();
        std::cout << "One loop done. Largest id: " << ga1.counter_idv << std::endl;
    }
    ga1.PrintResults();
    
    return 0;
}
