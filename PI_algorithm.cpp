#include <iostream>
#include "PI_algorithm.h"
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

PI_algorithm::PI_algorithm(int num_states1, int num_actions1, MatrixXd* Transitions1, MatrixXd Rewards_mat1, double gamma1, int max_iter1) {
	num_states = num_states1;
	num_actions = num_actions1;
	max_iter = max_iter1;
	gamma = gamma1;
	Transitions = Transitions1;
	Rewards_mat = Rewards_mat1;
	Value.setZero(num_states1, 1);
	Policy.setZero(num_states1, 1);

	cout << "\nNanay! PI_algorithm initialized\n" <<endl;
};

void PI_algorithm::implement_PI(){
	cout << "Policy Iteration algorithm started." << endl;
	MatrixXd Policy_transition(num_states, num_states);
	MatrixXd Action_cost2go(num_states, num_actions);
	MatrixXd reward_vec(num_states, 1);
	MatrixXi Policy_old(num_states, 1);
	MatrixXd Value_old(num_states, 1);
	RowVector2<Index> argmax{};
	bool checkConvergence_PI;
	bool checkConvergence_VI;

	Policy_old = Policy;
	for (int iter = 0; iter < max_iter; iter++) {
		cout << Policy.transpose() << endl;
		// Constructing closed-loop transition for fixed policy
		for (int i = 0; i < num_states; i++) {
			int action = Policy(i, 0);
			Policy_transition.block(i, 0, 1, num_states) = Transitions[action].block(i, 0, 1, num_states);
			reward_vec(i, 0) = Rewards_mat(i, action); 
			}

		// policy evaluation:
		Value_old = Value;
		for (int VI_iter = 0; VI_iter < max_iter; VI_iter++) {
		Value = reward_vec + gamma * Policy_transition.transpose() * Value;
		
		checkConvergence_VI = ((Value - Value_old).norm() < 1e-3);
		Value_old = Value;
			if (checkConvergence_VI){
				break;
			}
			
		}
		// Finding new policy through 1-step policy improvement.
		for (int j = 0; j < num_actions; j++) {
			Action_cost2go.block(0, j, num_states, 1) = gamma * Transitions[j].transpose() * Value;
			}
		Action_cost2go = Action_cost2go + Rewards_mat;
		for (int i = 0; i < num_states; i++) {
			Action_cost2go.block(i, 0, 1, num_actions).maxCoeff(&argmax.x(), &argmax.y());
			Policy(i, 0) = argmax(0, 1);
			}

			

		checkConvergence_PI = Policy.isApprox(Policy_old);
			if (checkConvergence_PI){
				cout << Policy.transpose() << endl;
				cout << "Policy Iteration algorithm converged." << endl;
				cout << "Policy mu(xi)=" << endl;
				cout << Policy.transpose() << endl;
				cout << "Optimal Value V(xi)=" << endl;
				cout << Value.transpose() << endl;
				break;
			}
		Policy_old = Policy;

	}
	
};