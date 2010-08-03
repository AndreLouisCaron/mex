#ifndef _mex_hpp__
#define _mex_hpp__

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
#include "exist.hpp"
#include "flipdim.hpp"
#include "mkdir.hpp"
#include "permute.hpp"

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
