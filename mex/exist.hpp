#ifndef _mex_exist_hpp__
#define _mex_exist_hpp__

// Copyright(c) Andre Caron, 2009-2011
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "array.hpp"

namespace mex {

    double exist ( const array<char_t>& symbol )
    {
        ::mxArray* prhs[] = {
            symbol.backend(),
        }; const int nrhs = 1;
        ::mxArray* plhs[] = {
            0,
        }; const int nlhs = 1;
        
        call(nlhs, plhs, nrhs, plhs, "exist");
        
        const mex::array<double> _(plhs[0], claim); return (_(0));
    }

}

#endif /* _mex_exist_hpp__ */
