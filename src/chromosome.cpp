#include "chromosome.h"

Chromosome::Chromosome()
{
    id = 0;
    n_len = 20;
    p_mutation = 0.05;
    GenerateChromo();
}

Chromosome::Chromosome(int id_input, int n_len_input)
{
    id = id_input;
    n_len = n_len_input;
    p_mutation = 0.05;
    GenerateChromo();
}

Chromosome::Chromosome(int id_input, int n_len_input, double p_mutation_input)
{
    id = id_input;
    n_len = n_len_input;
    p_mutation = p_mutation_input;
    GenerateChromo();
}

Chromosome::Chromosome(int id_input, std::vector<int> chromo_input)
{
    id = id_input;
    n_len = chromo_input.size();
    p_mutation = 0.05;
    chromo = chromo_input;
}

Chromosome::~Chromosome()
{
}

double Chromosome::GenerateRandomNumber(double lb = 0., double ub=1.) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine 
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> U_Distr(lb, ub);
    return U_Distr(gen);
}

void Chromosome::GenerateChromo() {
    //Eigen::VectorXi chr(this->n_len);
    std::vector<int> chr(n_len, 1);

    for (int i=0; i<n_len; i++) {
        //chr(i) = round(dis(gen));
        chr[i] = round(GenerateRandomNumber());
    }
    chromo = chr;
}

void Chromosome::Crossover(Chromosome c2, int idx_case = 0) {
    switch (idx_case)
    {
    case 1:
    {
        int idx_pt_crossover = int(round(GenerateRandomNumber(0.3, 0.7)*(this->n_len)));
        std::cout << idx_pt_crossover << std::endl;
        for (int i=idx_pt_crossover; i < this->n_len; i++) {
            this->chromo[i] = c2.chromo[i];
        }
        break;
    }       
    default:
    {
        for (int i=1; i < this->n_len; i+=2) {
            this->chromo[i] = c2.chromo[i];
        }
        break;
    }      
    }
}

void Chromosome::Mutation() {  
    bool if_mut;

    for (int i=0; i<n_len; i++) {
        if_mut = (GenerateRandomNumber() < p_mutation);
        if (if_mut) {
            chromo[i] ^= 1; // XOR
            idx_mut_pos.push_back(i);
        }
    }
}

void Chromosome::PrintChromo() {
    std::cout << "Chromosome " << id << ": " << std::endl;
    for (int i=0; i<n_len; i++) {
        std::cout << chromo[i] << " ";
    }
    std::cout << std::endl;
}

void Chromosome::PrintMutationPositions() {
    std::cout << "Mutation positions: ";
    if (idx_mut_pos.size() != 0) {
        for (int i=0; i<idx_mut_pos.size(); i++) {
            std::cout << idx_mut_pos[i] << " ";
        }
    }
    else {
        std::cout << "None.";
    }

    std::cout << std::endl; 
}