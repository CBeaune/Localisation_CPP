#include <eigen3/Eigen/Dense>
#include <math.h>

using Eigen::MatrixXd;

// Set the parameters which have the "Determined by student" comment to tune
//the Kalman filter. Do not modify anything else in this file.

//Uncertainty on initial position of the robot.
float sigmaX     = 0.1;         // Determined by student
float sigmaY     = 0.1;         // Determined by student
float sigmaTheta = 0.1*M_PI/180 ;   // Determined by student



//MatrixXd m(3,3);
//m(0,0)=1;

MatrixXd m(2,2);
m(0,0) = 3;
m(1,0) = 2.5;
m(0,1) = -1;
m(1,1) = m(1,0) + m(0,1);
