#include <eigen3/Eigen/Dense>
#include <math.h>
#include <iostream>


using Eigen::MatrixXd;

MatrixXd EvolutionModel(MatrixXd X, MatrixXd U ){

    if(X.rows()==3 && U.rows()==2){

        MatrixXd Y(3,1);
        Y(0,0)=X(0,0)+U(0,0)*cos(X(2,0));
        Y(1,0)=X(1,0)+U(0,0)*sin(X(2,0));
        Y(2,0)=X(2,0)+U(1,0);
       return(Y) ;

    }
    else{

        std::cout<<"ERROR IN THE MATRIX DIMENSION (EvolutionModel)"<<std::endl;
    return X;
    }


}
