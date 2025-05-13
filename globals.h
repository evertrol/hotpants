#ifndef GLOBALS_H
#define GLOBALS_H

typedef struct
{
   int       x0,y0;       /* origin of stamp in region coords*/
   int       x,y;         /* center of stamp in region coords*/
   int       nx,ny;       /* size of stamp */
   int       *xss;        /* x location of test substamp centers */
   int       *yss;        /* y location of test substamp centers */
   int       nss;         /* number of detected substamps, 1 .. nss     */
   int       sscnt;       /* represents which nss to use,  0 .. nss - 1 */
   double    **vectors;   /* contains convolved image data */
   double    *krefArea;   /* contains kernel substamp data */
   double    **mat;       /* fitting matrices */
   double    *scprod;     /* kernel sum solution */
   double    sum;         /* sum of fabs, for sigma use in check_stamps */
   double    mean;
   double    median;
   double    mode;        /* sky estimate */
   double    sd;
   double    fwhm;
   double    lfwhm;
   double    chi2;        /* residual in kernel fitting */
   double    norm;        /* kernel sum */
   double    diff;        /* (norm - mean_ksum) * sqrt(sum) */
} stamp_struct;

/* GLOBAL VARS POSSIBLY SET ON COMMAND LINE */
extern char      *template, *image, *outim;

extern float     tUThresh, tUKThresh, tLThresh, tGain, tRdnoise, iUThresh, iUKThresh, iLThresh, iGain, iRdnoise;
extern char      *tNoiseIm, *iNoiseIm, *tMaskIm, *iMaskIm, *kernelImIn, *kernelImOut, *outMask;
extern float     tPedestal, iPedestal;
extern int       hwKernel;
extern float     kerFitThresh, scaleFitThresh, minFracGoodStamps;
extern float     kfSpreadMask1, kfSpreadMask2;
extern int       gdXmin, gdXmax, gdYmin, gdYmax;
extern int       nRegX, nRegY;
extern char      *regFile;
extern char      *regKeyWord;
extern int       numRegKeyWord;
extern int       nStampY, nStampX, useFullSS;
extern int       nKSStamps, hwKSStamp;
extern char      *sstampFile;
extern int       findSSC;
extern int       kerOrder, bgOrder;
extern float     statSig, kerSigReject, kerFracMask;
extern char      *forceConvolve, *photNormalize, *figMerit;
extern int       sameConv, rescaleOK;
extern float     fillVal, fillValNoise;
extern char      *effFile, *noiseImage, *sigmaImage, *convImage;
extern int       doSum, inclNoiseImage, inclSigmaImage, inclConvImage, noClobber;
extern int       doKerInfo, outShort, outNShort;
extern float     outBzero, outBscale, outNiBzero, outNiBscale;
extern int       convolveVariance;
extern int       usePCA, fwKernelPCA;
extern float     **PCA;

/* GLOBAL VARS NOT SET ON COMMAND LINE */
extern int       ngauss, *deg_fixe;
extern float     *sigma_gauss;

extern int       rPixX, rPixY;
extern int       nStamps, nS, nCompKer, nC;

extern int       nComp, nCompBG, nBGVectors, nCompTotal;

extern int       fwKernel, fwStamp, hwStamp, fwKSStamp, kcStep, *indx;
extern int       cmpFile;
extern float     *temp, *temp2;
extern double    *check_stack,*filter_x,*filter_y,**kernel_vec;
extern double    **wxy,*kernel_coeffs,*kernel,**check_mat,*check_vec;
extern char      version[32];

/* REGION SIZED */
extern int       *mRData;   /* bad input data mask */

/* armin */
/* a dummy varialbe to do some testing */
extern int        dummy;
/* verbose for debugging */
extern int        verbose;
/* cmp file stuff */
extern char       xyfilename[1000];
extern int        savexyflag;
extern float      *xcmp,*ycmp;
extern int        Ncmp;

#endif  // GLOBALS_H
