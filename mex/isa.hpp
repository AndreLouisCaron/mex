#ifndef _mex_isa_hpp__
#define _mex_isa_hpp__

// Copyright(c) Andre Caron, 2009-2011
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

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
