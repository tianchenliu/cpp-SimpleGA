#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <iostream> 
#include <vector>
#include <random>
#include <cmath>

//#include <Eigen/Dense>
//typedef Eigen::VectorXi Chromosome;

class Chromosome
{
private:
    int id;
public:
    int n_len; // Number of genes
    double p_mutation; // Probability of mutation
    std::vector<int> chromo; // Binary representation of chromosome
    std::vector<int> idx_mut_pos; // Indices of mutation positions

protected:
    // Uniform random number generator
    // in: lb, ub; 
    // out: a <double> random number
    double GenerateRandomNumber(double, double); 
     

public:
    Chromosome();
    Chromosome(int, int);
    Chromosome(int, int, double); // in: id, n_len, p_mutation
    Chromosome(int, std::vector<int>);
    ~Chromosome();
    
    void SetDim(int n_len_input) {this -> n_len = n_len_input; };
    int GetDim() {return n_len; };
    void SetProbMutation(double p_mutation_input) {this -> p_mutation = p_mutation_input; };
    double GetProbMutation() {return p_mutation;};
    std::vector<int> GetChromo() { return chromo; };    

    void GenerateChromo(); // in: n_len
    void Crossover(Chromosome, int); // in: another Chromosome, idx of crossover cases
    void Mutation(); // calculates idx of mutation positions

    void PrintChromo();
    void PrintMutationPositions();
};

#endif
