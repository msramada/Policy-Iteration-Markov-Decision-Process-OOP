#pragma once
#include <Eigen/Dense>
using namespace Eigen;

class PI_algorithm {
public:
	PI_algorithm(int num_states1, int num_actions1, MatrixXd* Transitions1, MatrixXd Rewards_mat1, double gamma1, int max_iter1);
	int num_states;
	int num_actions;
	int max_iter;
	MatrixXd* Transitions;
	MatrixXd Value;
	MatrixXd Rewards_mat;
	MatrixXi Policy;
	double gamma;
	void implement_PI();
};

