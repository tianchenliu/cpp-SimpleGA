#include "simple_ga.h"

using namespace std;

int main()
{
    SimpleGa ga1;
    Fitness fit1;
    ga1.TestChromosomeClass();
    //ga1.TestIndividualClass();
    
    //ga1.InitPopulation();
    //ga1.Evaluation(fit1);

    //for (int i=0; i<ga1.n_pop; i++) {
    //    ga1.pop_gen_prev[i].PrintIndividualInfo();
    //    cout << ga1.val_pop_gen_prev[i][1] << endl;
    //}
    //cout << endl;
    
    //ga1.Selection();
    //for (int i=0; i<10; i++) { ga1.pop_gen_now[i].PrintIndividualInfo(); }
    //cout << endl;

    
    
    return 0;
}



