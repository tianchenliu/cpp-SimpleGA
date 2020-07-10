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
    double p_mutation = 0.05; // Probability of mutation
    std::vector<int> chromo; // Binary representation of chromosome
    std::vector<int> idx_mut_pos; // Indices of mutation positions

protected:
    // Uniform random number generator
    // in: lb, ub; 
    // out: a <double> random number
    double UniformRandomNumber(double, double); 
     

public:
    Chromosome(int, int); // a random chromo with idx and len
    Chromosome(int, std::vector<int>); // a chromo given binary vector
    ~Chromosome();
    
    /*
    void SetDim(int n_len_input) {this -> n_len = n_len_input; };
    int GetDim() {return n_len; };
    void SetProbMutation(double p_mutation_input) {this -> p_mutation = p_mutation_input; };
    double GetProbMutation() {return p_mutation;};
    */

    std::vector<int> GetChromo() { return chromo; };    

    void Crossover(Chromosome, int); // in: another Chromosome, idx of crossover cases
    void Mutation(); // calculates idx of mutation positions

    void PrintAllInfo();
    void PrintCustomInfo();
};

#endif
