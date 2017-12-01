//
// Created by Arash on 12/1/2017.
//

#include "fx.h"
#include <vector>
#include "constants.h"

using namespace std;
//R^n -> R^m
vector <double> fx (vector <double> x){
    vector<double> y (m);

    y[0] =2*x[0]+3*x[2];
    y[1]=2*x[0]+3*x[2];

    return y;
}

//R -> R
double fx (double x){
    double y;

    y =2*x;

    return y;
}
