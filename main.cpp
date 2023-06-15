#include <iostream>
#include <Eigen/Dense>
#include "PI_algorithm.h"

using namespace std;
using namespace Eigen;


int main() {

// Define transition matrices for each decision/action 
// Here we have 4 states and 3 possible actions per state
int num_states = 5;
int num_actions = 3;
int max_iter = 1e4;
// Define transition matrices,
// Indexed by the corresponding decision i
// We randomize, for the sake of this example
MatrixXd C = MatrixXd::Constant(num_states, num_states, 1.);
MatrixXd* Transitions = new MatrixXd[num_actions];
for (int i = 0; i < num_actions; i++) {
	Transitions[i] = MatrixXd::Random(num_states, num_states) + C;
	// Normalize the rows of these transition matrices
	// Remember, in MDPs, rows of P are probabilities and must add to 1
	for (int j = 0; j < num_states; j++){
		double normalizer = Transitions[i].block(j, 0, 1, num_states).sum();
		Transitions[i].block(j, 0, 1, num_states) = Transitions[i].block(j, 0, 1, num_states) / normalizer;
	}
	cout << "For action " << i << " The transition matrix P:\n" << Transitions[i] << endl;
}

// Rewards matrix (state, action)
MatrixXd Rewards_mat = MatrixXd::Constant(num_states, num_actions, 1.) + MatrixXd::Random(num_states, num_actions);

// Discound factor
double gamma = 0.95;

PI_algorithm PI(num_states, num_actions, Transitions, Rewards_mat, gamma, max_iter);
PI.implement_PI();
return 0;
}