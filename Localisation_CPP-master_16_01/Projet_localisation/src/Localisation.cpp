#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/LU>
#include <math.h>
#include<iostream>
#include "DefineVariance.h"

using Eigen::MatrixXd;
using namespace std;



int main(){

    MatrixXd Pinit(3,3) ;
           Pinit.topLeftCorner(3,3) = MatrixXd::Zero(3, 3);
           Pinit(0,0) = sigmaX*sigmaX ;
           Pinit(1,1) = sigmaY*sigmaY ;
           Pinit(2,2) = sigmaTheta*sigmaTheta ;
           std::cout<<Pinit<<std::endl;

    MatrixXd Qgamma(2,2);
    Qgamma.topLeftCorner(2,2) = MatrixXd::Zero(2, 2);
    Qgamma(0,0) = QgammaX ;
    Qgamma(1,1) = QgammaY ;

    MatrixXd Qwheels(2,2);
    Qwheels.topLeftCorner(2,2) = MatrixXd::Zero(2, 2);
    Qwheels(0,0) = sigmaTuning*sigmaTuning ;
    Qwheels(1,1) = sigmaTuning*sigmaTuning;



     MatrixXd jointToCartesian(2,2);
     jointToCartesian(0,0) = rwheel/2 ;
     jointToCartesian(0,1) = rwheel/2 ;
     jointToCartesian(1,0) = rwheel/trackGauge ;
     jointToCartesian(1,1) = -rwheel/trackGauge ;
     //cout<<jointToCartesian<<endl;

//     MatrixXd jointToCartesianFaux(2,2);
//     jointToCartesian(0,0) = rwheel/2 ;
//     jointToCartesian(0,1) = rwheel/2 ;
//     jointToCartesian(1,0) = rwheel/trackGauge ;
//     jointToCartesian(1,1) = -rwheel/trackGauge ;



    MatrixXd cartesianToJoint = jointToCartesian.inverse() ;
    //cout<<cartesianToJoint<<endl;

    MatrixXd Qbeta(2,2);
    Qbeta=jointToCartesian*Qwheels*jointToCartesian.transpose();

    MatrixXd Qalpha(2,2);
    Qalpha.topLeftCorner(2,2)=MatrixXd::Zero(2,2);

    MatrixXd mSensors(3,2);
    mSensors(0,0)=0;
    mSensors(0,1)=0;
    mSensors(1,0)=50;
    mSensors(1,1)=-50;
    mSensors(2,0)=1;
    mSensors(2,1)=1;

    //TODO : Define the mahaThreshold 'DefineVariance.m'


    return 0;
}
