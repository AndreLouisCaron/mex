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
    typedef unsigned char uint8;
    typedef signed char int8;
    typedef unsigned int uint32;
    typedef signed int int32;

        // Abstract types.
    class cell;
    class object;
    typedef void* function;

        // Real VS complex arrays.
    typedef ::mxComplexity complexity_t;
    static struct complex_t {
        operator complexity_t () const { return (mxCOMPLEX); }
    } const complex;
    static struct real_t {
        operator complexity_t () const { return (mxREAL); }
    } const real;

        // Acquisition semantics.
    static struct proxy_t {} const proxy;
    static struct owner_t {} const owner;

}

#endif /* _mex_types_hpp__ */
