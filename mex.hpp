#ifndef _mex_hpp__
#define _mex_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

    // core wrappers.
#include "mex/allocator.hpp"
#include "mex/array.hpp"
#include "mex/call.hpp"
#include "mex/error.hpp"
#include "mex/exception.hpp"
#include "mex/isa.hpp"
#include "mex/string.hpp"
#include "mex/types.hpp"
#include "mex/Session.hpp"
#include "mex/Archive.hpp"

    // functions.
#include "mex/exist.hpp"
#include "mex/flipdim.hpp"
#include "mex/mkdir.hpp"
#include "mex/permute.hpp"
#include "mex/imread.hpp"
#include "mex/cast.hpp"
#include "mex/rgb2gray.hpp"
#include "mex/im2double.hpp"

namespace mex {

    template<typename T>
    T scalar ( const ::mxArray * value )
    {
        const array<T> A(value, clone);
        if ( A.numel() != 1 ) {
            throw (std::exception("Not a scalar value."));
        }
        return (A(0));
    }

}

#endif /* _mex_hpp__ */
