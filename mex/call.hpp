#ifndef _mex_call_hpp__
#define _mex_call_hpp__

/*!
 * @file mex/call.hpp
 * @author Andre Caron
 */

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
