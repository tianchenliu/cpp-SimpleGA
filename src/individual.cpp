#include "individual.h"

Individual::Individual(int id, std::vector<Chromosome> chromos_input) {
    this->id = id;
    this->chromos = chromos_input;
    this->n_chromos = chromos.size();
}

Individual::~Individual()
{
}

void Individual::PrintAllInfo() {
    std::cout << "Individual " << id << std::endl;
    
    std::cout << "Chromos: " << std::endl;
    for (int i=0; i<n_chromos; i++) {
        chromos[i].PrintChromo();
    }
    std::cout << std::endl;
}

