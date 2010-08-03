#ifndef _mex_isa_hpp__
#define _mex_isa_hpp__

#include "__configure__.hpp"
#include "traits.hpp"

namespace mex {

    template<typename T>
    bool isa ( const ::mxArray * array )
    {
        return ((array != 0) && (::mxGetClassID(array) == traits<T>::type_code));
    }

}

#endif /* _mex_isa_hpp__ */
