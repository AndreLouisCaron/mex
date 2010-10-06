#ifndef _mex_imread_hpp__
#define _mex_imread_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "string.hpp"
#include "types.hpp"
#include "error.hpp"

namespace mex {

    inline array<uint8> imread ( const array< char_t >& path )
    {
        ::mxArray * prhs[] = {
            path.backend(),
        }; const int nrhs = 1;
        ::mxArray * plhs[] = {
            0,
        }; const int nlhs = 1;
        
        call(nlhs, plhs, nrhs, prhs, "imread");
        return (mex::array<uint8>(plhs[0], claim));
    }

    inline array<uint8> imread ( const std::string& path )
    {
        return (imread(string(path)));
    }

}

#endif /* _mex_imread_hpp__ */
