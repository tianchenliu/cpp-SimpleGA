#include "simple_ga.h"

using namespace std;

int main()
{
    SimpleGa ga1;
    Fitness fit1;
    //ga1.TestChromosomeClass();
    //ga1.TestIndividualClass();
    ga1.InitPopulation();
    ga1.Evaluation(fit1);

    for (int i=10; i<20; i++) {
        ga1.pop_gen_prev[i].PrintIndividualInfo();
        cout << ga1.pop_gen_val_prev[i] << endl;
    }

    
    
    return 0;
}



