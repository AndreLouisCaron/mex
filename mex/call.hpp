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

    void call ( const char * function );

    void call ( const std::string& function );

    void call ( const array<char_t>& function );

    void call ( int nlhs, ::mxArray * plhs,
        int nrhs, const ::mxArray * prhs, const char * function );

    void call ( int nlhs, ::mxArray * plhs,
        int nrhs, const ::mxArray * prhs, const std::string& function );

    void call ( int nlhs, ::mxArray * plhs[],
        int nrhs, ::mxArray * prhs[], const array<char_t>& function );

}

#endif /* _mex_call_hpp__ */
