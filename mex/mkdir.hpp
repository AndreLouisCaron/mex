#ifndef _mex_mkdir_hpp__
#define _mex_mkdir_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "array.hpp"

namespace mex {

    void mkdir ( const array<char_t>& path )
    {
        ::mxArray* prhs[] = {
            path.backend(),
        }; const int nrhs = 1;
        
        call(0, 0, nrhs, prhs, "mkdir");
    }

}

#endif /* _mex_mkdir_hpp__ */
