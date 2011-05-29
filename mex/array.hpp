#ifndef _mex_array_hpp__
#define _mex_array_hpp__

// Copyright(c) Andre Caron, 2009-2011
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "types.hpp"
#include "traits.hpp"
#include <algorithm>
#include <exception>
#include <typeinfo>

namespace mex {

    inline size_t numel ( const ::mxArray * backend )
    {
        return (::mxGetNumberOfElements(backend));
    }

    class array_base
    {
        /* nested types. */
    public:
        typedef mex::size_t size_type;
        typedef void * pointer;
        typedef const void * const_pointer;

        /* data. */
    private:
        ::mxArray * myBackend;

        /* construction. */
    public:
        array_base ( ::mxArray * backend, const claim_t& )
            : myBackend(backend)
        {
        }

        array_base ( const ::mxArray * backend, const clone_t& )
        : myBackend(::mxDuplicateArray(backend))
        {
        }

        array_base ( const array_base& other )
            : myBackend(::mxDuplicateArray(other.backend()))
        {
        }

        ~array_base ()
        {
            ::mxDestroyArray(myBackend);
        }

        /* methods. */
    protected:
        void swap ( array_base& other )
        {
            std::swap(myBackend, other.myBackend);
        }

    public:
        ::mxArray * backend () const
        {
            return (myBackend);
        }

        ::mxArray * release ()
        {
            ::mxArray * backend = myBackend; myBackend = 0; return (backend);
        }

        bool empty () const
        {
            return (::mxIsEmpty(myBackend));
        }

        size_type dims () const
        {
            return (::mxGetNumberOfDimensions(myBackend));
        }

        size_type dim ( size_type i ) const
        {
            return (::mxGetDimensions(myBackend)[i]);
        }

        size_type numel () const
        {
            return (::mxGetNumberOfElements(myBackend));
        }

        size_type elsiz () const
        {
            return (::mxGetElementSize(myBackend));
        }

        size_type M () const
        {
            return (::mxGetM(myBackend));
        }

        size_type N () const
        {
            return (::mxGetN(myBackend));
        }

        bool is ( const char * klass ) const
        {
            return (::mxIsClass(myBackend, klass));
        }

        pointer data ()
        {
            return (::mxGetData(myBackend));
        }

        const_pointer data () const
        {
            return (::mxGetData(myBackend));
        }

        size_type offset ( int nsubs, ::mwIndex * subs ) const
        {
            return (::mxCalcSingleSubscript(myBackend, nsubs, subs));
        }

        size_type offset ( size_type i ) const
        {
            ::mwIndex subs[] = { i };
            return (offset(1, subs));
        }

        size_type offset ( size_type i, size_type j ) const
        {
            ::mwIndex subs[] = { i, j };
            return (offset(2, subs));
        }

        size_type offset ( size_type i, size_type j, size_type k ) const
        {
            ::mwIndex subs[] = { i, j, k };
            return (offset(3, subs));
        }

        /* operators. */
    private:
        array_base& operator= ( const array_base& other );
    };

    template<typename T>
    class array :
        public array_base
    {
        /* nested types. */
    public:
        typedef traits<T> traits_type;
        typedef typename traits_type::value_type    value_type;
        typedef typename traits_type::pointer       pointer;
        typedef typename traits_type::const_pointer const_pointer;

        typedef pointer iterator;
        typedef const_pointer const_iterator;

        /* construction. */
    public:
        array ( size_type m, size_type n )
            : array_base(traits_type::matrix(m, n, real), claim)
        {
        }

        array ( size_type m, size_type n, const real_t& )
            : array_base(traits_type::matrix(m, n, real), claim)
        {
        }

        array ( size_type m, size_type n, const complex_t& )
            : array_base(traits_type::matrix(m, n, complex), claim)
        {
        }

        array ( const ::mxArray * backend, const clone_t& )
            : array_base(traits_type::check(backend), clone)
        {
        }

        array ( ::mxArray * backend, const claim_t& )
            : array_base(traits_type::check(backend), claim)
        {
        }

        array ( const array<T>& other )
            : array_base(::mxDuplicateArray(other.backend()), claim)
        {
        }

        /* methods. */
    public:
        void swap ( array<T> & other )
        {
            other.array_base::swap(*this);
        }

        pointer data ()
        {
            return (reinterpret_cast<pointer>(array_base::data()));
        }

        const_pointer data () const
        {
            return (reinterpret_cast<const_pointer>(array_base::data()));
        }

        iterator begin ()
        {
            return (reinterpret_cast<iterator>(array_base::data()));
        }

        const_iterator begin () const
        {
            return (reinterpret_cast<const_iterator>(array_base::data()));
        }

        iterator end ()
        {
            return (begin() + numel());
        }

        const_iterator end () const
        {
            return (begin() + numel());
        }

        /* operators. */
    public:
        array<T>& operator= ( const array<T>& other )
        {
            array<T> copy(other); copy.swap(*this); return (*this);
        }

        value_type& operator() ( size_type i )
        {
            return (data()[offset(i)]);
        }

        value_type& operator() ( size_type i, size_type j )
        {
            return (data()[offset(i,j)]);
        }

        value_type& operator() ( size_type i, size_type j, size_type k )
        {
            return (data()[offset(i,j,k)]);
        }

        value_type operator() ( size_type i ) const
        {
            return (data()[offset(i)]);
        }

        value_type operator() ( size_type i, size_type j ) const
        {
            return (data()[offset(i,j)]);
        }

        value_type operator() ( size_type i, size_type j, size_type k ) const
        {
            return (data()[offset(i,j,k)]);
        }
    };

}

#endif /* _mex_array_hpp__ */
