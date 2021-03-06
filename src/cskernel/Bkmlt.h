/********************************************************************/
/* Copyright (c) 2011 DG Technologies Inc. and Yuzi Mizuno          */
/* All rights reserved.                                             */
/* Granted under the MIT license (see mg/MGCL.h for detail)         */
/********************************************************************/
// BKMLT WILL FIND FIRST INDEX AFTER IS S.T. 
//   T(ISF-1) <T(ISF)=T(ISF+1)=---=T(ISF+MLTF-1)<T(ISF+MLTF) 
//   WHERE MLTF >= MLT. 
// *** INPUT * 
//    NT        NUM OF DATA T. 
//    T(NT)     DATA SEQUENCE 
//    IS        INDEX OF T WHERE BKMLT TO START THE SEARCH 
//    MLT       INDICATES MINIMUM NUM OF MULTIPLICITY. 
// *** OUTPUT * 
//    ISF       =-1  NOT FOUND UNTIL THE END OF DATA 
//              >1   FIRST INDEX OF T ( FOUND ). ISF > IS. 
//    MLTF      VALID ONLY WHEN ISF>1, PROVIDES MULTIPLICITY OF T(ISF). 
void bkmlt_(int nt, const double *t, int is, int mlt, int *isf, int *mltf);
