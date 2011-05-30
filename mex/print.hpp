#ifndef _mex_print_hpp__
#define _mex_print_hpp__

// Copyright(c) Andre Caron, 2009-2011
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "string.hpp"

namespace mex {

    inline void print ( const char * message )
    {
	::mexPrintf(message);
    }

    inline void print ( const std::string& message )
    {
	print(message.c_str());
    }

    inline void print ( const array<char_t>& message )
    {
	print(string(message));
    }

}

#endif /* _mex_print_hpp__ */
