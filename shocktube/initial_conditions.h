#ifndef INITIAL_H
#define INITIAL_H

#include <cassert>
#include <array>
using namespace std;
double poison = 0./0.; //result of NaN

//========================//
// set_initial_conditions //
//========================//
// set the initial conditions given left and right shocktube values
// call with:
//     primitive = set_initial_conditions<nx>(rhoL, rhoR, vxL, vxR, pressL, pressR);
template<int nx>
array<array<double,nx>,3> set_initial_conditions(double rhoL, double rhoR,
						 double vxL, double vxR,
						 double pressL, double pressR){

  array<array<double,nx>,3> primitive;

  // set left and right states
  // if left of middle use left values
  // if right of middle use right values
  for(int i=0; i<nx; i++){
    primitive[0][i] = (i<nx/2 ? rhoL : rhoR);//0;//IMPLEMENT ME
    primitive[1][i] = (i<nx/2 ? vxL : vxR);//0;//IMPLEMENT ME
    primitive[2][i] = (i<nx/2 ? pressL : pressR);//0;//IMPLEMENT ME
  }

  return primitive; //only local variable
} //input 3 nx sized list and then return a 3 x nx array with their initial condition

#endif
