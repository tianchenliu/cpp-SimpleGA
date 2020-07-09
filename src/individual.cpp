#include "individual.h"

Individual::Individual()
{
}

Individual::Individual(int id, int n_vars, std::vector<double> lb, std::vector<double> ub, double k_precision = 1e-4)
{
    this->id = id;
    this->n_vars = n_vars;
    this->lb = lb;
    this->ub = ub;
    this->k_precision = k_precision;
    GenerateIndividual();
    FindValues();
}

Individual::~Individual()
{
}

void Individual::GenerateIndividual() {
    for (int i=0; i<n_vars; i++) {
        double n_val = (ub[i] - lb[i]) / k_precision;
        int n_genes = int(floor(log2(n_val))) + 1;
        n_genes_per_chromo.push_back(n_genes);
        Chromosome chr(i, n_genes);
        chromos.push_back(chr);
    }
}

void Individual::FindValues() {
    for (int i=0; i<n_vars; i++) {
        int n_genes = n_genes_per_chromo[i];
        std::vector<int> chromo = chromos[i].GetChromo();
        double h = (ub[i] - lb[i]) / double(pow(2, n_genes));
        double true_value = lb[i];
        for (int idx_gene = 0; idx_gene < n_genes; idx_gene++) {
            if (chromo[idx_gene] == 1) {
                double current_h = h * pow(2, n_genes-1-idx_gene);
                true_value += current_h;
                //std::cout << true_value << " "; 
            }
        }
        true_values.push_back(true_value); 
    }
}

void Individual::PrintIndividual() {
    std::cout << "Individual " << id << ":" << "# of vars: " << n_vars << std::endl;
    /*
    std::cout << "# of chromos: " << n_genes_per_chromo.size() << std::endl;
    
    std::cout << "# of genes per chromo: ";
    for (int i=0; i<n_genes_per_chromo.size(); i++) {
        std::cout << n_genes_per_chromo[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Chromos: " << std::endl;
    for (int i=0; i<n_vars; i++) {
        chromos[i].PrintChromo();
    }
    std::cout << std::endl;
    
    */
    std::cout << "True values of chromos: ";
    for (int i=0; i<true_values.size(); i++) {
        std::cout << true_values[i] << " ";
    }
    std::cout << std::endl;
}

void Individual::PrintIndividualInfo() {
    std::cout << "Individual " << id << ": "; //# of vars: " << n_vars << std::endl;
    std::cout << "True values of chromos: ";
    for (int i=0; i<true_values.size(); i++) {
        std::cout << true_values[i] << " ";
    }
    std::cout << std::endl;
}