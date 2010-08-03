#ifndef _mex_exception_hpp__
#define _mex_exception_hpp__

/*!
 * @file mex/exception.hpp
 * @author Andre Caron
 */

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
        : myMessage(str(::mxGetField(backend, 0, "message")))
      {
      }

    public:
      virtual const char * what () const throw() {
        return (myMessage.c_str());
      }
    };

}

#endif /* _mex_error_hpp__ */
