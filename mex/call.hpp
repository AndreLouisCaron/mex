#ifndef _mex_call_hpp__
#define _mex_call_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "string.hpp"

namespace mex {

    inline void call ( const char * function )
    {
        ::mexCallMATLAB(0, 0, 0, 0, function);
    }

    inline void call ( const std::string& function )
    {
        ::mexCallMATLAB(0, 0, 0, 0, function.c_str());
    }

}

#endif /* _mex_call_hpp__ */
