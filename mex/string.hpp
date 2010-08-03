#ifndef _mex_string_hpp__
#define _mex_string_hpp__

/*!
 * @file mex/string.hpp
 * @author Andre Caron
 */

#include "__configure__.hpp"
#include "array.hpp"
#include <string>
#include <exception>

namespace mex {

    inline std::string str ( const ::mxArray * value )
    {
        char * data = ::mxArrayToString(value);
        if ( data == 0 ) {
            throw (std::bad_alloc());
        }
        const std::string result(data);
        ::mxFree(data);
        return (result);
    }

    inline std::string str ( const array< char_t >& value )
    {
        return (str(value.backend()));
    }
    
    inline array< char_t > str ( const char * value )
    {
        ::mxArray *const result = ::mxCreateString(value);
        if ( result == 0 ) {
            throw (std::bad_alloc());
        }
        return (array< char_t >(result, claim()));
    }
    
    inline array< char_t > str ( const std::string& value )
    {
        return (str(value.c_str()));
    }

}

#endif /* _mex_string_hpp__ */
