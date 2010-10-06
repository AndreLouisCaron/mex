// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "call.hpp"
#include "exception.hpp"
#include "error.hpp"

namespace mex {

    void call ( const char * function )
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

    void call ( const std::string& function )
    {
        call(function.c_str());
    }

    void call ( const array<char_t>& function )
    {
        call(string(function));
    }

    void call ( int nlhs, ::mxArray * plhs[],
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

    void call ( int nlhs, ::mxArray * plhs[],
        int nrhs, ::mxArray * prhs[], const std::string& function )
    {
        call(nlhs, plhs, nrhs, prhs, function.c_str());
    }

    void call ( int nlhs, ::mxArray * plhs[],
        int nrhs, ::mxArray * prhs[], const array<char_t>& function )
    {
        call(nlhs, plhs, nrhs, prhs, string(function));
    }

}
