/********************************************************************/
/* Copyright (c) 2011 DG Technologies Inc. and Yuzi Mizuno          */
/* All rights reserved.                                             */
/* Granted under the MIT license (see mg/MGCL.h for detail)         */
/********************************************************************/
// BLIP1               BLIP1 ESPECIALLY FOR BLIP 
//      BLIP1 WILL GET THE INTERSECTION NUMBER BETWEEN THE POLYGON 
//      POLYGN(I) AND THE STRAIGHT LINE F. 
// *** INPUT * 
//         POLYGN(MU+NSPAN)  : SPECIFIES POLYGON. 
//         MU                : INDICATES AT WHICH POINT OF POLYGN BLIP1 
//                             SHOULD START THE COUNTING. 
//         NSPAN             : INDICATES AT WHICH POINT OF POLYGN BLIP1 
//                             SHOULD STOP THE COUNTING. 
//         F                 : SPECIFIES THE STRAIGHT LINE. 
// *** OUTPUT * 
//         BLIP1            : NUMBER OF INTERSECTION POINT. 
int blip1_(const double *polygn, int mu, int nspan, double f){
    double d;
    int i, j, n, isnew, isold1, isold2;
    // Parameter adjustments 
    --polygn;

    n = 0;
    i = mu;
    isold2 = 0;
	d=polygn[i]-f;
    if(d<0.)
	    isold1 = -1;
    else if(d>0.)
	    isold1 = 1;
    else
	    isold1 = 0;

    for(j=1; j<=nspan; ++j){
		++i;
		d=polygn[i]-f;
		if(d<0.)
			isnew = -1;
		else if(d>0.)
			isnew = 1;
		else
			isnew = 0;
		if(isold1*isnew<=0)
			++n;
		if(isold1==0 && isnew*isold2<0)
			--n;
		isold1 = isnew;
		isold2 = isold1;
    }
    return n;
}
