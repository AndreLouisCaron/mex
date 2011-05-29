#ifndef _mex_call_hpp__
#define _mex_call_hpp__

// Copyright(c) Andre Caron, 2009-2011
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "error.hpp"
#include "exception.hpp"
#include "string.hpp"

namespace mex {

    inline void call ( const char * function )
    {
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(0, 0, 0, 0, function);
        if ( result != 0 )
        {
            const std::string identifier =
                string(exception_id(result));
            const std::string description =
                string(exception_message(result));
            const std::string message =
                identifier + ": " + description;
            throw (std::exception(message.c_str()));
        }
    }

    inline void call ( const std::string& function )
    {
        call(function.c_str());
    }

    inline void call ( const array<char_t>& function )
    {
        call(string(function));
    }

    inline void call ( int nlhs, ::mxArray * plhs[],
        int nrhs, ::mxArray * prhs[], const char * function )
    {
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, function);
        if ( result != 0 )
        {
            const std::string identifier =
                string(exception_id(result));
            const std::string description =
                string(exception_message(result));
            const std::string message =
                identifier + ": " + description;
            throw (std::exception(message.c_str()));
        }
    }

    inline void call ( int nlhs, ::mxArray * plhs[],
        int nrhs, ::mxArray * prhs[], const std::string& function )
    {
        call(nlhs, plhs, nrhs, prhs, function.c_str());
    }

    inline void call ( int nlhs, ::mxArray * plhs[],
        int nrhs, ::mxArray * prhs[], const array<char_t>& function )
    {
        call(nlhs, plhs, nrhs, prhs, string(function));
    }

}

#endif /* _mex_call_hpp__ */
