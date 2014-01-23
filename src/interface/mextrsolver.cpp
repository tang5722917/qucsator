#include <string>
#include <qucs-core/qucs_interface.h>
#include "mextrsolver.h"

using namespace qucs;

// function to display messages
void mextrsolvermessage(int level, const char* warningmsg, ...)
{
    // we don't use level, it is just there to match the prototype
    // for the function in e_trsolver
    (void) level;

    //mexWarnMsgIdAndTxt("MATLAB:trsolver", warningmsg);

    mexPrintf("%s\n", warningmsg);
}

mextrsolver::mextrsolver()
{
    //ctor
    //thetrsolver = NULL;
}

mextrsolver::~mextrsolver()
{
    //dtor
}

void mextrsolver::printx()
{
    qtr.printSolution ();
}

int mextrsolver::prepare_netlist(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    char *input_buf;
    double *outpointer;
    int notopened;

    /* check for proper number of arguments */
    if(nrhs!=3)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "Three inputs required.");
    else if(nlhs > 1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");

    /* 3rd input must be a string (first two are used for the class interface) */
    if ( mxIsChar(prhs[2]) != 1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotString",
                           "Input must be a string containing the file name.");

    /* input must be a row vector */
    if (mxGetM(prhs[2])!=1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotVector",
                           "Input must be a row vector.");

    /* copy the string data from prhs[2] into a C string input_ buf.    */
    input_buf = mxArrayToString (prhs[2]);

    // call the prepare_netlist method with the input
    notopened = qtr.prepare_netlist (input_buf);

    // get the pointer to the e_trsolver analysis
    qtr.getETR ();

    if (qtr.getIsInitialised ())
    {
        notopened = 0;
    }
    else
    {
        // make the message function mextrsolvermessage
        qtr.messagefcn = &mextrsolvermessage;
    }

    plhs[0] = mxCreateDoubleMatrix( (mwSize)(1), (mwSize)(1), mxREAL);
    // get a pointer to the start of the actual output data array
    outpointer = mxGetPr(plhs[0]);
    outpointer[0] = (double)(notopened);

    // free the char array as we are done with it
    mxFree(input_buf);

    if (notopened)
    {
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotVector",
                           "File could not be opened, or no transient analysis present.");
    }

    return notopened;
}

// solves the circuit at a specified time point
int mextrsolver::stepsolve_sync(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

    /* check for proper number of arguments */
    if(nrhs!=3)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "One input required.");
    else if(nlhs > 1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");

    /* input must be a scalar */
    if ((mxGetM(prhs[2])!=1) | (mxGetN(prhs[2])!=1))
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotVector",
                           "Input must be a scalar.");


    double synctime = mxGetScalar(prhs[2]);

    qtr.stepsolve_sync(synctime);

    return 0;
}


void mextrsolver::acceptstep_sync(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* check for proper number of arguments */
    if(nrhs!=2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "No input required.");
    else if(nlhs > 0)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");


    qtr.acceptstep_sync();
}


// solves the circuit at a specified time point
int mextrsolver::stepsolve_async(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

    /* check for proper number of arguments */
    if(nrhs!=3)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "One input required.");
    else if(nlhs > 1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");

    /* input must be a scalar */
    if ((mxGetM(prhs[2])!=1) | (mxGetN(prhs[2])!=1))
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotVector",
                           "Input must be a scalar.");


    double synctime = mxGetScalar(prhs[2]);

    qtr.stepsolve_async(synctime);

    return 0;
}


void mextrsolver::acceptstep_async(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* check for proper number of arguments */
    if(nrhs!=2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "No input required.");
    else if(nlhs > 0)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");


    qtr.acceptstep_async();
}

void mextrsolver::rejectstep_async(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* check for proper number of arguments */
    if(nrhs!=2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "No input required.");
    else if(nlhs > 0)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");


    qtr.rejectstep_async();
}

// gets the last solution calculated by the solver
int mextrsolver::getsolution(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double * outpointer;
    int xN, xM, status = 0;

    /* check for proper number of arguments */
    if(nrhs!=2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "No input required.");
    else if(nlhs > 2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");


    xN = qtr.getN();
    xM = qtr.getM();

    //mexPrintf("%d %d\n", xN, xM);

    if (xN <= 0)
    {
        mexErrMsgIdAndTxt( "MATLAB:trsolver:nosolution",
                           "There zero nodes in the circuit.");
    }

    // copy the solution
    plhs[0] = mxCreateDoubleMatrix( (mwSize)(xN+xM), (mwSize)(1), mxREAL);

    // get a pointer to the start of the actual output data array
    outpointer = mxGetPr(plhs[0]);

    // copy the data into the array
    qtr.getsolution(outpointer);

    // copy the number of nodal voltages and branch currents
    plhs[1] = mxCreateDoubleMatrix( (mwSize)(1), (mwSize)(2), mxREAL);

    // get a pointer to the start of the actual output data array
    outpointer = mxGetPr(plhs[1]);

    // copy the data into the array
    outpointer[0] = (double)xN;
    outpointer[1] = (double)xM;

    return status;
}

void mextrsolver::init_sync(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

    double start;

    /* check for proper number of arguments */
    if(nrhs!=3)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "One input required.");
    else if(nlhs > 0)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");

    /* input must be a scalar */
    if ((mxGetM(prhs[2])!=1) | (mxGetN(prhs[2])!=1))
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotVector",
                           "Input must be a scalar.");


    start = mxGetScalar(prhs[2]);

    qtr.init(start, 1e-6, ETR_MODE_SYNC);
}

void mextrsolver::init_async(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double start, firstdelta;

    /* check for proper number of arguments */
    if(nrhs!=4)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "Two inputs required.");
    else if(nlhs > 0)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");

    /* input must be a scalar */
    if ((mxGetM(prhs[2])!=1) | (mxGetN(prhs[2])!=1))
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotVector",
                           "Input 1 must be a scalar.");


    start = mxGetScalar(prhs[2]);

    /* input must be a scalar */
    if ((mxGetM(prhs[3])!=1) | (mxGetN(prhs[3])!=1))
        mexErrMsgIdAndTxt( "MATLAB:trsolver:inputNotVector",
                           "Input 2 must be a scalar.");


    firstdelta = mxGetScalar(prhs[3]);

    qtr.init(start, firstdelta, ETR_MODE_ASYNC);
}


// gets the last solution calculated by the solver
int mextrsolver::getN(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double * outpointer;

    /* check for proper number of arguments */
    if(nrhs!=2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "No input required.");
    else if(nlhs > 1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");


    int xN = qtr.getN();

    // copy the solution
    plhs[0] = mxCreateDoubleMatrix( (mwSize)(1), (mwSize)(1), mxREAL);

    // get a pointer to the start of the actual output data array
    outpointer = mxGetPr(plhs[0]);

    // copy the data into the array
    outpointer[0] = (double)xN;
}


int mextrsolver::getM(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double * outpointer;

    /* check for proper number of arguments */
    if(nrhs!=2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "No input required.");
    else if(nlhs > 1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");


    int xM = qtr.getM();

    // copy the solution
    plhs[0] = mxCreateDoubleMatrix( (mwSize)(1), (mwSize)(1), mxREAL);

    // get a pointer to the start of the actual output data array
    outpointer = mxGetPr(plhs[0]);

    // copy the data into the array
    outpointer[0] = (double)xM;

}

void mextrsolver::getJac(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double * outpointer;

    /* check for proper number of arguments */
    if(nrhs!=2)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:invalidNumInputs",
                           "No input required.");
    else if(nlhs > 1)
        mexErrMsgIdAndTxt( "MATLAB:trsolver:maxlhs",
                           "Too many output arguments.");

    int jrows = qtr.getJacRows();
    int jcols = qtr.getJacCols();

    // copy the solution
    plhs[0] = mxCreateDoubleMatrix( (mwSize)(jrows), (mwSize)(jcols), mxREAL);

    // get a pointer to the start of the actual output data array
    outpointer = mxGetPr(plhs[0]);

    // copy the jacobian matrix data into the matlab matrix
    for(int c = 0; c < jcols; c++)
    {
        for(int r = 0; r < jrows; r++)
        {
            outpointer[(c*jrows)+r] = (double)qtr.getJacData(r, c);
        }
    }

}
