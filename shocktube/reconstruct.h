#ifndef RECONSTRUCT_H
#define RECONSTRUCT_H

#include <array>

//================================//
// piecewise_constant_reconstruct //
//================================//
// this should get the values at the left (0) and right (1) side of each cell
// This is trivial for piecewise constant, but not so trivial for higher-order schemes.
// call with:
//     conservativeLR = piecewise_constant_reconstruct<nx>(conservative);
template<int nx>
array< array< array<double,nx-1>, 3>,2> piecewise_constant_reconstruct(array< array<double,nx>,3>& conservative){ //declare the format of output

  array< array< array<double,nx-1>,3>,2> conservativeLR; //declare the output

  for(int v=0; v<3; v++){
    for(int i=0; i<nx-1; i++){ //number of cells is nx-1
      conservativeLR[0][v][i] = conservative[v][i];// IMPLEMENT ME
      conservativeLR[1][v][i] = conservative[v][i+1];// IMPLEMENT ME
    }
  }

  return conservativeLR;
}

#endif
