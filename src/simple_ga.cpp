#include "simple_ga.h"

SimpleGa::SimpleGa(){}
SimpleGa::~SimpleGa(){}

double SimpleGa::UniformRandomNumber(double lb, double ub) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine 
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> U_Distr(lb, ub);
    return U_Distr(gen);
}

void SimpleGa::SetProblemProperty(std::function<double (std::vector<double>)> fitness_in, int n_pop_in, int n_vars_in, std::vector<double> lb_in, std::vector<double> ub_in, double k_precision_in, int n_max_in) {
    counter_idv = 0;
    this->fitness = fitness_in;
    this->n_pop = n_pop_in;
    
    this->n_vars = n_vars_in; // dim of variables = number of chromos
    this->lb = lb_in; // a <double> vector for lower bounds
    this->ub = ub_in; // a <double> vector for upper bounds
    this->k_precision = k_precision_in;
    this->n_max = n_max_in;

    k_increment.resize(n_vars, 0.);
    n_genes.resize(n_vars, 0);

    for (int i=0; i<n_vars; i++) {
        double n_val = (ub[i] - lb[i]) / k_precision;
        n_genes[i] = int(floor(log2(n_val))) + 1;
        k_increment[i] = (ub[i] - lb[i]) / double(pow(2, n_genes[i]));
    }

    k_pct_selection = 0.5;
    n_kept_idv = int(k_pct_selection * n_pop);

    flag_stop = false;
    
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
        pop_next.push_back(GenerateIndividual(counter_idv));
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
    idv.val_fitness = fitness(val_var_idv);
}

void SimpleGa::EvalPop() {
    pop.clear();
    val_pop.clear();
    pop = pop_next;
    pop_next.clear();
    
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

    for (int i=0; i<n_kept_idv; i++) {
        int idx_kept_idv = int(val_pop[i][0]);
        pop_next.push_back(pop[idx_kept_idv]);
    }
}

void SimpleGa::CrossoverMutation() {
    for (int i=0; i < n_pop-n_kept_idv; i++) {
        int idx1 = int(floor(UniformRandomNumber(0., 1.) * n_kept_idv));
        int idx2 = int(floor(UniformRandomNumber(0., 1.) * n_kept_idv));

        Individual idv1 = pop_next[idx1];
        Individual idv2 = pop_next[idx2];

        std::vector<Chromosome> new_chromos;

        for (int idx_chr=0; idx_chr<n_vars; idx_chr++) {
            Chromosome chr1 = idv1.chromos[idx_chr];
            Chromosome chr2 = idv2.chromos[idx_chr];
            chr1.Crossover(chr2, 1);
            chr1.Mutation();
            new_chromos.push_back(chr1);
        }

        Individual child_idv(counter_idv, new_chromos);
        EvalIdv(child_idv);
        pop_next.push_back(child_idv);
        counter_idv++;
    }    
}

void SimpleGa::CheckStop() {
    if (counter_idv > n_max) {
        flag_stop = true;
    }
}

void SimpleGa::Run() {
    InitPopulation();
    while (!flag_stop) {
        EvalPop();
        Selection();
        CrossoverMutation();
        CheckStop();
        PrintStepInfo();
    }
    PrintResults();
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

void SimpleGa::PrintStepInfo() {
    std::cout << "One loop done. Largest id: " << counter_idv << std::endl;
}

void SimpleGa::PrintResults() {
    std::cout << "Best 5 individuals: " << std::endl;
    for (int i=0; i<5; i++) {
        pop_next[i].PrintAllInfo();
        std::cout << std::endl;
    }
}