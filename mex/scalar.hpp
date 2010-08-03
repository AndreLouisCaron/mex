#ifndef _mex_scalar_hpp__
#define _mex_scalar_hpp__

#include "__configure__.hpp"
#include "array.hpp"

namespace mex {

    template<typename T> array<T> scalar ( const T& value )
    {
        array<T> result(1, 1); result(0) = value; return(result);
    }

}

#endif /* _mex_scalar_hpp__ */
