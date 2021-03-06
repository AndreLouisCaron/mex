#ifndef _mex_scalar_hpp__
#define _mex_scalar_hpp__

// Copyright(c) Andre Caron, 2009-2011
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "array.hpp"

namespace mex {

    template<typename T> array<T> scalar ( const T& value )
    {
        array<T> result(1, 1); result(0) = value; return(result);
    }

    template<typename T>
    T scalar ( const ::mxArray * value )
    {
        if ( numel(traits<T>::check(value)) == 1 ) {
            return *static_cast<const T*>(::mxGetData(value));
        }
        throw (std::exception("Not a scalar value."));
    }


}

#endif /* _mex_scalar_hpp__ */
