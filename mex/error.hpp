#ifndef _mex_error_hpp__
#define _mex_error_hpp__

/*!
 * @file mex/error.hpp
 * @author Andre Caron
 */

#include "__configure__.hpp"
#include <string>

namespace mex {

    inline void error ( const char * message )
    {
        ::mexErrMsgTxt(message);
    }

    inline void error ( const std::string& message )
    {
        ::mexErrMsgTxt(message.c_str());
    }

    
    inline void error ( const array<char_t>& message )
    {
        error(str(message));
    }
    
    inline void warning ( const char * message )
    {
        ::mexWarnMsgTxt(message);
    }

    inline void warning ( const std::string& message )
    {
        ::mexWarnMsgTxt(message.c_str());
    }

}

#endif /* _mex_error_hpp__ */
