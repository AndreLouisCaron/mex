#ifndef _mex_cast_hpp__
#define _mex_cast_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "array.hpp"

namespace mex {

    template<typename T>
    array<float> single ( const array<T>& A )
    {
        ::mxArray * prhs[] = {
            A.backend(),
        }; const int nrhs = 1;
        ::mxArray * plhs[] = {
            0
        }; const int nlhs = 1;
        
        call(nlhs, plhs, nrhs, prhs, "single");
        return (mex::array<float>(plhs[0], claim));
    }

}

#endif /* _mex_cast_hpp__ */
