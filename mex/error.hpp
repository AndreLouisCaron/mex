#ifndef _mex_error_hpp__
#define _mex_error_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

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
        error(string(message));
    }

    inline void warning ( const char * message )
    {
        ::mexWarnMsgTxt(message);
    }

    inline void warning ( const std::string& message )
    {
        ::mexWarnMsgTxt(message.c_str());
    }

    inline void warning ( const array<char_t>& message )
    {
        warning(string(message));
    }
}

#endif /* _mex_error_hpp__ */
