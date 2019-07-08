#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <array>

//================================//
// reflecting_boundary_conditions //
//================================//
/// apply reflecting boundary conditions
// ghost zones are literally a reflection of the non-ghost zones
// call with:
//     reflecting_boundary_conditions<nx,nghost>(conservative);
template<int nx, int nghost>
void reflecting_boundary_conditions(array<array<double,nx>,3>& inout){ //extract the address (only need to change the variable; no need to assign it to a pointer)
 for(int i=0; i<nghost; i++){
//   for(int j=0; j<3; j++){
//    inout[0][i] = inout[0][2*nghost-1-i];
//    inout[0][nx-1-i] = inout[0][nx-2*nghost+i];

    //particle density, nx, nghost are counted from 1; cell is counted from 0
    inout[0][i] = inout[0][2*nghost-i-1];
    inout[0][nx-i-1] = inout[0][nx-2*nghost+i];
    //momentum flux
    inout[1][i] = -inout[1][2*nghost-i-1];
    inout[1][nx-i-1] = -inout[1][nx-2*nghost+i];
    //energy density
    inout[2][i] = inout[2][2*nghost-i-1];
    inout[2][nx-i-1] = inout[2][nx-2*nghost+i];

   //};
 }; // YOU NEED TO IMPLEMENT THIS
}

#endif
