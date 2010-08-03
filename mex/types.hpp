#ifndef _mex_types_hpp__
#define _mex_types_hpp__

/*!
 * @file types.hpp
 * @author Andre Caron
 * 
 * @brief MATLAB base types.
 */

#include "__configure__.hpp"

namespace mex {

        // Way-to-go type safety!
    typedef ::mxClassID type_t;

        // MATLAB application binary interface...
    typedef ::mwSize size_type;
    typedef size_type size_t;
    typedef ::mxChar char_type;
    typedef char_type char_t;
    typedef ::mxLogical logical;
    typedef logical bool_t;

        // Integers of all sizes.
    typedef   signed char        int8;
    typedef unsigned char       uint8;
    typedef   signed short      int16;
    typedef unsigned short     uint16;
    typedef   signed int        int32;
    typedef unsigned int       uint32;
    typedef   signed long long  int64;
    typedef unsigned long long uint64;

    // Keep 32/64-bit check aligned with <mex.h>.
#if defined(_LP64) || defined(_WIN64)
    typedef uint64 index_t;
#else
    typedef uint32 index_t;
#endif

        // Abstract types.
    class cell;
    class object;
    class unknown;
    typedef void* function;

        // Real VS complex arrays.
    static struct complex_t {} const complex;
    static struct    real_t {} const    real;

        // Acquisition semantics.
    static struct clone_t {} const clone;
    static struct claim_t {} const claim;

}

#endif /* _mex_types_hpp__ */
