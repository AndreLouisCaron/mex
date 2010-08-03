#ifndef _mex_flipdim_hpp__
#define _mex_flipdim_hpp__

#include "array.hpp"

namespace mex {

    template<typename T>
    array<T> flipdim ( const array<T>& A, const array<double>& dimension )
    {
            // Prepare to call MATLAB.
        ::mxArray * prhs[] = {
            A.backend(), dimension.backend()
        }; const int nrhs = 2;
        ::mxArray * plhs[] = {
            0
        }; const int nlhs = 1;
        
            // Invoke MATLAB.
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, "flipdim");
        if ( result != 0 ) {
            //const array<char_t> message = exception_message(result);
            //throw (std::exception(str(message).c_str()));
            throw (std::exception("flipdim"));
        }
        
            // Return results.
        return (mex::array<T>(plhs[0], owner));
    }

}

#endif /* _mex_flipdim_hpp__ */
