#include "simple_ga.h"

SimpleGa::SimpleGa()
{
    SetProblemProperty();
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
   
    c1.PrintAllInfo();
    c2.PrintAllInfo();

    c1.Crossover(c2, 1);
    std::cout << "After crossover: " << std::endl;
    c1.PrintAllInfo();

    for (int i=0; i<5; i++) {
        std::cout << "Try mutation " << i+1 << ": " << std::endl;
        c1.Mutation();
        c1.PrintAllInfo();
        std::cout << std::endl;
    } 
    
}

void SimpleGa::TestIndividualClass() {    

    std::vector<int> chromo_input1 = {1,0,1,0,1,1,0,0,1,0};
    Chromosome c1(1, chromo_input1);
    std::vector<int> chromo_input2 = {1,1,0,0,0,1,0,1,1,0};
    Chromosome c2(2, chromo_input2);
    
    std::vector<Chromosome> chromos_input;
    chromos_input.push_back(c1);
    chromos_input.push_back(c2);

    Individual i2(2, chromos_input);
    
    i2.PrintAllInfo();
}

void SimpleGa::SetProblemProperty() {
    counter_idv = 0;
    n_pop = 20;
    
    n_vars = 2; // dim of variables = number of chromos
    lb = {0., 0.}; // a <double> vector for lower bounds
    ub = {1., 1.}; // a <double> vector for upper bounds
    k_precision = 1e-4;
    
    k_increment.resize(n_vars, 0.);
    n_genes.resize(n_vars, 0);

    for (int i=0; i<n_vars; i++) {
        double n_val = (ub[i] - lb[i]) / k_precision;
        n_genes[i] = int(floor(log2(n_val))) + 1;
        k_increment[i] = (ub[i] - lb[i]) / double(pow(2, n_genes[i]));
    }

    k_pct_selection = 0.5;
    n_kept_idv = int(k_pct_selection * n_pop);
}

double SimpleGa::FitnessFunc(std::vector<double> x) {
  double fval = pow(x[0] - 0.5, 2) + pow(x[1] - 0.5, 2);
  return fval;
}

Individual SimpleGa::GenerateIndividual(int id) {
    std::vector<Chromosome> chromos;
    
    for (int i=0; i<n_vars; i++) {
        Chromosome chromo(i, n_genes[i]);
        chromos.push_back(chromo);
    }   
    Individual idv(id, chromos);

    return idv; 
}

Individual SimpleGa::GenerateIndividual(int id, std::vector<Chromosome> chromos) {
    Individual idv(id, chromos);
    return idv;
}

void SimpleGa::InitPopulation() {
    for (int i=0; i<n_pop; i++) {
        pop.push_back(GenerateIndividual(counter_idv));
        counter_idv++;
    }
}

void SimpleGa::EvalIdv(Individual &idv) {
    std::vector<double> val_var_idv = lb;
    std::vector<int> c;
    for (int i=0; i<n_vars; i++) {
        c = idv.chromos[i].GetChromo();
        for (int idx_gene=0; idx_gene<n_genes[i]; idx_gene++) {
            if (c[idx_gene] == 1) {
                double current_increment = pow(2, n_genes[i]-1-idx_gene);
                val_var_idv[i] += k_increment[i] * current_increment; 
            }            
        }
    }
    idv.val_var = val_var_idv;
    idv.val_fitness = FitnessFunc(val_var_idv);
}

void SimpleGa::EvalPop() {
    for (int i=0; i<n_pop; i++) {
        EvalIdv(pop[i]);

        std::vector<double> val_idv;

        val_idv.push_back(double(i));
        val_idv.push_back(pop[i].val_fitness);
        for (int j=0; j<n_vars; j++) {
            val_idv.push_back(pop[i].val_var[j]);
        }

        val_pop.push_back(val_idv);
    }
}

void SimpleGa::Selection() {
    std::sort(val_pop.begin(), val_pop.end(),
    [] (const std::vector<double> &a, const std::vector<double> &b) 
    {
        return a[1] < b[1];
    });
    
    pop_next.clear();

    for (int i=0; i<n_kept_idv; i++) {
        int idx_kept_idv = int(val_pop[i][0]);
        pop_next.push_back(pop[idx_kept_idv]);
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


void SimpleGa::PrintAllInfo() {
    /*
    for (int i=0; i<n_vars; i++) {
        std::cout << k_increment[i] << " ";
    }
    std::cout << std::endl;

    for (int i=0; i<n_vars; i++) {
        std::cout << n_genes[i] << " ";
    }
    std::cout << std::endl;

    for (int i=0; i<n_pop; i++) {
        //pop[i].PrintAllInfo();
        std::cout << "Individual " << i << " values: " << std::endl;
        for (int j=0; j<val_pop[0].size(); j++) {
            std::cout << val_pop[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    
    for (int i=0; i<pop_next.size(); i++) {
        pop_next[i].PrintAllInfo();
        std::cout << std::endl;
    }

}