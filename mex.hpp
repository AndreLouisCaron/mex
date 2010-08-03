#ifndef _mex_hpp__
#define _mex_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

    // core wrappers.
#include "mex/allocator.hpp"
#include "mex/array.hpp"
#include "mex/call.hpp"
#include "mex/Class.hpp"
#include "mex/error.hpp"
#include "mex/exception.hpp"
#include "mex/isa.hpp"
#include "mex/string.hpp"
#include "mex/types.hpp"

    // functions.
#include "mex/exist.hpp"
#include "mex/flipdim.hpp"
#include "mex/mkdir.hpp"
#include "mex/permute.hpp"

namespace mex {
    
    array<char_t> exception_id ( const ::mxArray * exception )
    {
        ::mxArray *const result =
            ::mxGetProperty(exception, 0, "identifier");
        if ( result == 0 ) {
            return (string("MATLAB:no-identifier"));
        }
        return (array<char_t>(result, claim));
    }
    
    array<char_t> exception_message ( const ::mxArray * exception )
    {
        ::mxArray *const result =
            ::mxGetProperty(exception, 0, "message");
        if ( result == 0 ) {
            return (string("MATLAB:no-identifier"));
        }
        return (array<char_t>(result, claim));
    }

}

#endif /* _mex_hpp__ */
