#ifndef _mex_mkdir_hpp__
#define _mex_mkdir_hpp__

#include "array.hpp"

namespace mex {

    void mkdir ( const array<char_t>& root )
    {
            // Prepare to call MATLAB
        ::mxArray* prhs[] = {
            root.backend()
        }; const int nrhs = 1;
        ::mxArray* plhs[] = {
            0
        }; const int nlhs = 0;
        
          // Invoke MATLAB.
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, "mkdir");
        if ( result != 0 ) {
            throw (std::exception("mkdir"));
        }
    }

}

#endif /* _mex_mkdir_hpp__ */
