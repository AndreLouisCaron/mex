#ifndef _mex_string_hpp__
#define _mex_string_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "array.hpp"
#include <exception>
#include <string>

namespace mex {

    inline std::string string ( const ::mxArray * value )
    {
        char * data = ::mxArrayToString(value);
        if ( data == 0 ) {
            throw (std::bad_alloc());
        }
        const std::string result(data);
        ::mxFree(data);
        return (result);
    }

    inline std::string string ( const array< char_t >& value )
    {
        return (string(value.backend()));
    }
    
    inline array< char_t > string ( const char * value )
    {
        ::mxArray *const result = ::mxCreateString(value);
        if ( result == 0 ) {
            throw (std::bad_alloc());
        }
        return (array< char_t >(result, claim));
    }
    
    inline array< char_t > string ( const std::string& value )
    {
        return (string(value.c_str()));
    }

}

#endif /* _mex_string_hpp__ */
