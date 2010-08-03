#ifndef _mex_permute_hpp__
#define _mex_permute_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "array.hpp"

namespace mex {

    template<typename T>
    array<T> permute ( const array<T>& A, const array<double>& order )
    {
            // Prepare to call MATLAB.
        ::mxArray * prhs[] = {
            A.backend(), order.backend()
        }; const int nrhs = 2;
        ::mxArray * plhs[] = {
            0
        }; const int nlhs = 1;
        
            // Invoke MATLAB.
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, "permute");
        if ( result != 0 ) {
            //const array<char_t> message = exception_message(result);
            //throw (std::exception(str(message).c_str()));
            throw (std::exception("permute"));
        }
        
            // Return results.
        return (mex::array<T>(plhs[0], owner));
    }

}

#endif /* _mex_permute_hpp__ */
