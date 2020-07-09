#include "simple_ga.h"

SimpleGa::SimpleGa()
{
    n_pop = 20;
    n_vars = 2; // dim of variables = number of chromos
    lb = {0., 0.}; // a <double> vector for lower bounds
    ub = {1., 1.}; // a <double> vector for upper bounds
    k_precision = 1e-4;
}

SimpleGa::~SimpleGa()
{
}

void SimpleGa::TestChromosomeClass() {
    /*
    int n;
    std::cout << "Enter n_len: ";
    std::cin >> n; 

    Chromosome c1(1, n), c2(2, n);
    
    c1.PrintChromo();
    c2.PrintChromo();

    c1.Crossover(c2, 1);
    std::cout << "After crossover: " << std::endl;
    c1.PrintChromo();

    c1.Mutation();
    c1.PrintChromo();
    c1.PrintMutationPositions();
    */

   std::vector<int> chromo_input1 = {1,0,1,0,1,1,0,0,1,0};
   Chromosome c1(1, chromo_input1);
   std::vector<int> chromo_input2 = {1,1,0,0,0,1,0,1,1,0};
   Chromosome c2(2, chromo_input2);
   
    c1.PrintChromo();
    c2.PrintChromo();

    c1.Crossover(c2, 1);
    std::cout << "After crossover: " << std::endl;
    c1.PrintChromo();

    c1.Mutation();
    c1.PrintChromo();
    c1.PrintMutationPositions();

}

void SimpleGa::TestIndividualClass() {    
    //Individual i1(1, n_vars, lb, ub, k_precision);
    //i1.FindValues();
    //i1.PrintIndividual();

    Chromosome c1(1, 14), c2(2, 14);
    std::vector<Chromosome> chromos_input;
    chromos_input.push_back(c1);
    chromos_input.push_back(c2);

    Individual i2(2, chromos_input);
    
    i2.PrintIndividual();

    /*
    std::vector<double> idv_values = i1.GetValues();
    for (int i=0; i<idv_values.size(); i++) {
        std::cout << idv_values[i] << " ";
    }
    */



}

void SimpleGa::InitPopulation() {
    for (int i=0; i<n_pop; i++) {
        Individual idv(i, n_vars, lb, ub, k_precision);
        pop_gen_prev.push_back(idv); 
    }
    counter_idv += n_pop;
}

// Evaluate fitness function value for the whole population
void SimpleGa::Evaluation(Fitness fit){
    val_pop_gen_prev.clear();
    for (int i=0; i<n_pop; i++) {
        val_pop_gen_prev.push_back({double(i), fit.FitnessEval1(pop_gen_prev[i])});
    }
}

void SimpleGa::Selection(){
    std::sort(val_pop_gen_prev.begin(), val_pop_gen_prev.end(),
    [] (const std::vector<double> &a, const std::vector<double> &b) 
    {
        return a[1] < b[1];
    });
    
    pop_gen_now.clear();
    int n_idv_kept = int(k_pct_selection * val_pop_gen_prev.size());
    
    for (int i=0; i<n_idv_kept; i++) {
        int idx_pop_gen_prev = int(val_pop_gen_prev[i][0]);
        pop_gen_now.push_back(pop_gen_prev[idx_pop_gen_prev]);
    }
}

void SimpleGa::Crossover() {

}

void SimpleGa::Mutation() {

}

bool SimpleGa::CheckStopping() {
    bool flag_stop = false;

    return flag_stop;
}

