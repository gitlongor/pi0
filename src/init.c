#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

extern SEXP combnBt2Rc(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP combnBtRc(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern void intTruncNormVec(int*, int*, double*, double*, double*, double*, double*);
extern void fracTruncNormVec(int*, double*, double*, double*, double*, double*, double*, int*, int*);
extern void tstatistic(double*, int*, int*, int*, int*, int*, double*, double*);

static const R_CallMethodDef callMethods[]  = {
  {"combnBt2Rc", (DL_FUNC) &combnBt2Rc, 14},
  {"combnBtRc", (DL_FUNC) &combnBtRc, 9},
  {NULL, NULL, 0}
};


static R_NativePrimitiveArgType intTruncNormVec_t[] = {
    INTSXP, INTSXP, REALSXP, REALSXP, REALSXP, REALSXP, REALSXP
};
static R_NativePrimitiveArgType fracTruncNormVec_t[] = {
    INTSXP, REALSXP, REALSXP, REALSXP, REALSXP, REALSXP, REALSXP, INTSXP, INTSXP
};
static R_NativePrimitiveArgType tstatistic_t[] = {
    REALSXP, INTSXP, INTSXP, INTSXP, INTSXP, INTSXP, REALSXP, REALSXP
};

static const R_CMethodDef cMethods[] = {
   {"intTruncNormVec", (DL_FUNC) &intTruncNormVec, 7, intTruncNormVec_t},
   {"fracTruncNormVec", (DL_FUNC) &fracTruncNormVec, 9, fracTruncNormVec_t},
  {"tstatistic", (DL_FUNC) &tstatistic, 8, tstatistic_t},
   {NULL, NULL, 0, NULL}
};


void R_init_pi0(DllInfo *info)
{
   R_registerRoutines(info, cMethods, callMethods, NULL, NULL);
   R_useDynamicSymbols(info, FALSE);
   R_forceSymbols(info, TRUE); 
}


   