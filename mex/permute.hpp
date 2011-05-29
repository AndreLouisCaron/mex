#ifndef _mex_permute_hpp__
#define _mex_permute_hpp__

// Copyright(c) Andre Caron, 2009-2011
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
        ::mxArray * prhs[] = {
            A.backend(), order.backend()
        }; const int nrhs = 2;
        ::mxArray * plhs[] = {
            0
        }; const int nlhs = 1;
        
        call(nlhs, plhs, nrhs, prhs, "permute");
        
        return (mex::array<T>(plhs[0], claim));
    }

}

#endif /* _mex_permute_hpp__ */
