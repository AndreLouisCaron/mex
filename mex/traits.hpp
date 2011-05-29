#ifndef _mex_traits_hpp__
#define _mex_traits_hpp__

// Copyright(c) Andre Caron, 2009-2011
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "types.hpp"
#include <exception>

namespace mex {

    template<typename T, type_t U>
    struct common_traits
    {
        typedef T value_type;
        typedef T * pointer;
        typedef const T * const_pointer;
        static const type_t type_code = U;

        static ::mxArray * check ( ::mxArray * array )
        {
            if ( array == 0 ) {
                throw (std::invalid_argument("MATLAB: invalid class"));
            }
            if ( ::mxGetClassID(array) != type_code ) {
                throw (std::bad_cast());
            }
            return (array);
        }

        static const ::mxArray * check ( const ::mxArray * array )
        {
            if ( array == 0 ) {
                throw (std::invalid_argument("MATLAB: invalid class"));
            }
            if ( ::mxGetClassID(array) != type_code ) {
                throw (std::bad_cast());
            }
            return (array);
        }
    };

    template<typename T, type_t U>
    struct numeric_traits :
        public common_traits< T, U >
    {
        static ::mxArray * matrix ( size_t m, size_t n, const real_t& )
        {
            ::mxArray *const result = ::mxCreateNumericMatrix
                (m, n, type_code, mxREAL);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }

        static ::mxArray * matrix ( size_t m, size_t n, const complex_t& )
        {
            ::mxArray *const result = ::mxCreateNumericMatrix
                (m, n, type_code, mxCOMPLEX);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }

        static ::mxArray * array ( int ndim, const int * dims, const real_t& )
        {
            ::mxArray *const result = ::mxCreateNumericArray
                (ndim, dims, type_code, mxREAL);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }

        static ::mxArray * array
            ( int ndim, const int * dims, const complex_t& )
        {
            ::mxArray *const result = ::mxCreateNumericArray
                (ndim, dims, type_code, mxCOMPLEX);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }
    };

    template<typename T> struct traits;

    template<> struct traits< char_t > :
        public common_traits< char_t, mxCHAR_CLASS >
    {
        static ::mxArray * matrix ( size_t m, size_t n )
        {
            const size_t dims[] = { m, n };
            ::mxArray *const result = ::mxCreateCharArray(2, dims);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }
    };

    template<> struct traits< double > :
        public common_traits< double, mxDOUBLE_CLASS >
    {
        static ::mxArray * matrix ( size_t m, size_t n, const real_t& )
        {
            ::mxArray *const result = ::mxCreateDoubleMatrix(m, n, mxREAL);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }

        static ::mxArray * matrix ( size_t m, size_t n, const complex_t& )
        {
            ::mxArray *const result = ::mxCreateDoubleMatrix(m, n, mxCOMPLEX);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }
    };

    template<> struct traits< logical > :
        public common_traits< bool, mxLOGICAL_CLASS >
    {
        static ::mxArray * create ( size_t m, size_t n )
        {
            ::mxArray *const result = ::mxCreateLogicalMatrix(m, n);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }
    };

    template<> struct traits< float > :
        public numeric_traits< float, mxSINGLE_CLASS >
    {
    };

    template<> struct traits< function > :
        public common_traits< function, mxFUNCTION_CLASS >
    {
    };

    template<> struct traits< unknown > :
        public common_traits< unknown, mxUNKNOWN_CLASS >
    {
    };

    template<> struct traits< object > :
        public common_traits< object, mxOBJECT_CLASS >
    {
    };

    template<> struct traits< int8 > :
        public numeric_traits< int8, mxINT8_CLASS >
    {
    };

    template<> struct traits< uint8 > :
        public numeric_traits< uint8, mxUINT8_CLASS >
    {
    };

    template<> struct traits< int16 > :
        public numeric_traits< int16, mxINT16_CLASS >
    {
    };

    template<> struct traits< uint16 > :
        public numeric_traits< uint16, mxUINT16_CLASS >
    {
    };

    template<> struct traits< int32 > :
        public numeric_traits< int32, mxINT32_CLASS >
    {
    };

    template<> struct traits< uint32 > :
        public numeric_traits< uint32, mxUINT32_CLASS >
    {
    };

    template<> struct traits< int64 > :
        public numeric_traits< int64, mxINT64_CLASS >
    {
    };

    template<> struct traits< uint64 > :
        public numeric_traits< uint64, mxUINT64_CLASS >
    {
    };

}

#endif /* _mex_traits_hpp__ */
