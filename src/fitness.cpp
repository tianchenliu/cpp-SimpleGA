#include "fitness.h"

Fitness::Fitness()
{
  n_obj = 1;
}

Fitness::~Fitness()
{
}

double Fitness::FitnessEval1(Individual idv) {
  std::vector<double> x = idv.GetValues();
  double fval = pow(x[0] - 0.5, 2) + pow(x[1] - 0.5, 2);
  return fval;
}
