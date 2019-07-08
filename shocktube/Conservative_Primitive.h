#ifndef CON2PRIM_H
#define CON2PRIM_H

#include <array>

//===============//
// get_primitive //
//===============//
// given conservative variables, return primitive variables
// call with:
//     primitive = get_primitive<nx>(conservative, eos);
template<int nx>
array<array<double,nx>,3> get_primitive(const array<array<double,nx>,3>& conservative,
					const EOS& eos){ //define eos
  array<array<double,nx>,3> primitive;

  // density
  for(int i=0; i<nx; i++)
    primitive[0][i] = conservative[0][i]; // IMPLEMENT ME

  // velocity
  for(int i=0; i<nx; i++)
    primitive[1][i] = conservative[1][i] / conservative[0][i];// IMPLEMENT ME

  // pressure
  array<double,nx> internal_energy_density;
  for(int i=0; i<nx; i++)
    internal_energy_density[i] = conservative[2][i] / conservative[0][i]- 1./2. * pow((conservative[1][i]/conservative[0][i]),2);// IMPLEMENT ME
  primitive[2] = eos.pressure<nx>(conservative[0],internal_energy_density); //see EOS definition of function

  return primitive;
}

//==================//
// get_conservative //
//==================//
// given primitive variables, return conservative variables
// call with:
//     conservative = get_conservative<nx>(primitive, eos);
template<int nx>
array<array<double,nx>,3> get_conservative(const array<array<double,nx>,3>& primitive,
					   const EOS& eos){
  array<array<double,nx>,3> conservative;

  // density
  for(int i=0; i<nx; i++)
    conservative[0][i] = primitive[0][i];//IMPLEMENT ME

  // momentum density
  for(int i=0; i<nx; i++)
    conservative[1][i] = primitive[0][i] * primitive[1][i];// IMPLEMENT ME

  // total energy density
  array<double,nx> internal_energy_density = eos.internal_energy_density<nx>(primitive[0],primitive[2]);// IMPLEMENT ME
  for(int i=0; i<nx; i++)
    conservative[2][i] = primitive[0][i] * (internal_energy_density[i] + 1./2. * pow(primitive[1][i],2));//IMPLEMENT ME

  return conservative;
}


#endif
