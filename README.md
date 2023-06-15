# Policy-Iteration-Markov-Decision-Process-OOP
Policy iteration algorithm applied on finite state and action spaces Markov decision process. This work follows the notation in https://web.stanford.edu/class/cme241/lecture_slides/david_silver_slides/MDP.pdf. However, we choose to use recursive formula, as opposed to direct inverse methods; to avoid computational prohibitiveness for large dimensional state spaces.

# Compiling the code
A Makefile is included, or you can run the following command in the terminal 
```shell
g++ main.cpp PI_algorithm.cpp PI_algorithm.h -o output | ./output
```

# Components:
## Main file:
In the main file you can find the definition of the MDP, rewards and transition dynamics.

## PI_algorithm:
The header and implementation files define a C++ class. This class has the MDP as an attribute, and the Policy Iteration: Policy Evaluation and Policy Importovement, as a method.

## Code output:
```shell
For action 0 The transition matrix P:
0.000754342    0.289299    0.104964  0.00903371    0.595949
   0.243985    0.151647    0.371851   0.0395698    0.192947
  0.0846599    0.392397    0.311173    0.159616   0.0521539
   0.352071    0.358209    0.223558     0.06413  0.00203271
   0.323135    0.412393    0.167914   0.0916355  0.00492229
For action 1 The transition matrix P:
 0.174129 0.0766018  0.280025  0.403654 0.0655904
 0.167887  0.209375  0.247355  0.229468  0.145915
 0.189397  0.149475  0.266133  0.316963 0.0780316
 0.184492  0.107956  0.159389  0.283812  0.264351
  0.35401 0.0332568  0.176053  0.314472  0.122209
For action 2 The transition matrix P:
  0.235948   0.118764   0.113748   0.278054   0.253487
  0.382632   0.120739  0.0420087   0.125126   0.329495
  0.365245   0.108929   0.248141  0.0999944   0.177691
  0.371728     0.3124  0.0209031   0.218609  0.0763609
  0.294138  0.0114209 0.00422777   0.332467   0.357746

Nanay! PI_algorithm initialized

Policy Iteration algorithm started.
0 0 0 0 0
2 0 0 1 2
2 0 0 1 2
Policy Iteration algorithm converged.
Policy mu(xi)=
2 0 0 1 2
Optimal Value V(xi)=
26.3416 18.3026 22.5042 29.8541 30.1691
```
