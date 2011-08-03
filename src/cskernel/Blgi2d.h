/********************************************************************/
/* Copyright (c) 2011 DG Technologies Inc. and Yuzi Mizuno          */
/* All rights reserved.                                             */
/* Granted under the MIT license (see mg/MGCL.h for detail)         */
/********************************************************************/
// BLGI2D IS SURFACE VERSION OF BLGINT, I.E. 
//   1. RETURNS THE B-COEFFICIENTS IN ROW-WISE 
//   2. CAN BE USED REPEATEDLY BY INPUTTING Q AND IFLAG=1. 
//  BLGI2D  PRODUCES THE B-SPLINE COEFF.S  RCOEF  OF THE SPLINE OF ORDER 
//   K  WITH KNOTS  T(I), I=1,..., N + K , WHICH TAKES ON THE VALUE 
//   P(I,M) AT     TAU(I), I=1,..., N . 
// ******  I N P U T  ****** 
//  IFLAG.....SPECIFIES BLGI2D TO PRODUCE Q FROM TAU(DATA POINT) AND 
//        T(KNOT) -- IFLAG=2 --, OR Q CAN BE UTILIZED BECAUSE 
//        THE PREVIOUS CALL OF BLGI2D PRODUCED THEM AND THIS CALL IS 
//        THE SECOND CALL WITH THE SAME KNOT AND DATA POINT 
//                -- IFLAG=1 --  . 
//  TAU(N)..ARRAY OF LENGTH  N , CONTAINING DATA POINT ABSCISSAE. 
//    A S S U M P T I O N . . .  TAU  IS STRICTLY INCREASING 
//  P(IP,M)...CORRESPONDING ARRAY OF LENGTH  N , CONTAINING DATA POINT 
//       ORDINATES 
//  T(N+K)...KNOT SEQUENCE, OF LENGTH  N+K 
//  N.....NUMBER OF DATA POINTS AND DIMENSION OF SPLINE SPACE 
//  K.....ORDER OF SPLINE 
//  M...NUMBER OF DATA SET(OR SPACE DIMENSION OF POINTS P) 
//  IP....ROW DIMENSION OF THE VARIABLE P 
//  IRC...ROW DIMENSION OF THE VARIABLE RCOEF 
// ******  O U T P U T  ****** 
//  Q.....ARRAY OF SIZE  (2*K-1)*N , CONTAINING THE TRIANGULAR FACTORIZ- 
//       ATION OF THE COEFFICIENT MATRIX OF THE LINEAR SYSTEM FOR THE B- 
//        COEFFICIENTS OF THE SPLINE INTERPOLANT. 
//           THE B-COEFFS FOR THE INTERPOLANT OF AN ADDITIONAL DATA SET 
//        (TAU(I),HTAU(I)), I=1,...,N  WITH THE SAME DATA ABSCISSAE CAN 
//        BE OBTAINED WITHOUT GOING THROUGH ALL THE CALCULATIONS IN THIS 
//       ROUTINE, SIMPLY BY LOADING  HTAU  INTO  RCOEF  AND THEN EXECUT- 
//        ING THE    CALL B1BSLV ( Q, 2*K-1, N, K-1, K-1, RCOEF ) 
//  RCOEF(IRC,N)..THE B-COEFFICIENTS OF THE INTERPOLANT. COEFFICIENTS ARE 
//       STORED IN ROW-WISE OF LENGTH  N. 
//  IFLAG.....AN INTEGER INDICATING SUCCESS (= 1)  OR FAILURE (= 2) 
//       THE LINEAR SYSTEM TO BE SOLVED IS (THEORETICALLY) INVERTIBLE IF 
//        AND ONLY IF 
//              T(I) .LT. TAU(I) .LT. TAU(I+K),    ALL I. 
//        VIOLATION OF THIS CONDITION IS CERTAIN TO LEAD TO  IFLAG = 2 . 
//
// ****** WORK ARRAY ****** 
// WORK(N).....OF LENGTH N 
//
// ******  M E T H O D  ****** 
//    THE I-TH EQUATION OF THE LINEAR SYSTEM  A*RCOEF = B  FOR THE B-CO- 
// EFFS OF THE INTERPOLANT ENFORCES INTERPOLATION AT  TAU(I), I=1,...,N. 
//  HENCE,  B(I) = P(I), ALL I, AND     A  IS A BAND MATRIX WITH  2K-1 
//   BANDS (IF IT IS INVERTIBLE). 
//    THE MATRIX  A  IS GENERATED ROW BY ROW AND STORED, DIAGONAL BY DI- 
//  AGONAL, IN THE  R O W S  OF THE ARRAY  Q, WITH THE MAIN DIAGONAL GO- 
//  ING INTO ROW  K .  SEE COMMENTS IN THE PROGRAM BELOW. 
//     THE BANDED SYSTEM IS THEN SOLVED BY A CALL TO  B1BFAC (WHICH CON- 
//  STRUCTS THE TRIANGULAR FACTORIZATION FOR  A  AND STORES IT AGAIN IN 
//   Q ), FOLLOWED BY A CALL TO  B1BSLV (WHICH THEN OBTAINS THE SOLUTION 
//   RCOEF  BY SUBSTITUTION). 
//    B1BFAC  DOES NO PIVOTING, SINCE THE TOTAL POSITIVITY OF THE MATRIX  
//  A  MAKES THIS UNNECESSARY. 
void blgi2d_(int *iflag, const double *tau, const double *p, 
	const double *t, int k, int n, int m, int ip, 
	int irc, double *work, double *q, double *rcoef);
