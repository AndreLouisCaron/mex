#ifndef _mex_traits_hpp__
#define _mex_traits_hpp__

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
        static ::mxArray * matrix
            ( size_t m, size_t n, complexity_t complexity=real )
        {
            ::mxArray *const result = ::mxCreateNumericMatrix
                (m, n, type_code, complexity);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }

        static ::mxArray * array
            ( int ndim, const int * dims, complexity_t complexity=real )
        {
            ::mxArray *const result = ::mxCreateNumericArray
                (ndim, dims, type_code, complexity);
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
        static ::mxArray * matrix
            ( size_t m, size_t n, complexity_t complexity=real )
        {
            ::mxArray *const result = ::mxCreateDoubleMatrix
                (m, n, complex? mxCOMPLEX : mxREAL);
            if ( result == 0 ) {
                throw (std::bad_alloc());
            }
            return (result);
        }
    };

    template<> struct traits< logical > :
        public common_traits< double, mxLOGICAL_CLASS >
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

    template<> struct traits< function > :
        public common_traits< function, mxFUNCTION_CLASS >
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

    template<> struct traits< int32 > :
        public numeric_traits< int32, mxINT32_CLASS >
    {
    };

    template<> struct traits< uint32 > :
        public numeric_traits< uint32, mxUINT32_CLASS >
    {
    };

}

#endif /* _mex_traits_hpp__ */
