#ifndef _mex_exception_hpp__
#define _mex_exception_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "array.hpp"
#include "string.hpp"
#include <exception>

namespace mex {

    class exception :
        public std::exception
    {
      std::string myMessage;

    public:
      explicit exception ( const ::mxArray * backend ) throw()
        : myMessage(string(::mxGetField(backend, 0, "message")))
      {
      }

    public:
      virtual const char * what () const throw() {
        return (myMessage.c_str());
      }
    };

}

#endif /* _mex_error_hpp__ */
