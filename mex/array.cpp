// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "array.hpp"

namespace mex {

    array_base::array_base ( ::mxArray * backend, const claim_t& )
        : myBackend(backend)
    {
    }

    array_base::array_base ( const ::mxArray * backend, const clone_t& )
        : myBackend(::mxDuplicateArray(backend))
    {
    }

    array_base::array_base ( const array_base& other )
        : myBackend(::mxDuplicateArray(other.backend()))
    {
    }

    array_base::~array_base ()
    {
        ::mxDestroyArray(myBackend);
    }

    ::mxArray * array_base::backend () const
    {
        return (myBackend);
    }

    ::mxArray * array_base::release ()
    {
        ::mxArray * backend = myBackend; myBackend = 0; return (backend);
    }

    bool array_base::empty () const
    {
        return (::mxIsEmpty(myBackend));
    }

    array_base::size_type array_base::dims () const
    {
        return (::mxGetNumberOfDimensions(myBackend));
    }

    array_base::size_type array_base::dim ( size_type i ) const
    {
        return (::mxGetDimensions(myBackend)[i]);
    }

    array_base::size_type array_base::numel () const
    {
        return (::mxGetNumberOfElements(myBackend));
    }

    array_base::size_type array_base::elsiz () const
    {
        return (::mxGetElementSize(myBackend));
    }

    array_base::size_type array_base::M () const
    {
        return (::mxGetM(myBackend));
    }

    array_base::size_type array_base::N () const
    {
        return (::mxGetN(myBackend));
    }

    bool array_base::is ( const char * klass ) const
    {
        return (::mxIsClass(myBackend, klass));
    }

    array_base::pointer array_base::data ()
    {
        return (::mxGetData(myBackend));
    }

    array_base::const_pointer array_base::data () const
    {
        return (::mxGetData(myBackend));
    }

    array_base::size_type array_base::offset ( int nsubs, mwIndex * subs ) const
    {
        return (::mxCalcSingleSubscript(myBackend, nsubs, subs));
    }

    array_base::size_type array_base::offset ( size_type i ) const
    {
        ::mwIndex subs[] = { i };
        return (offset(1, subs));
    }

    array_base::size_type array_base::offset ( size_type i, size_type j ) const
    {
        ::mwIndex subs[] = { i, j };
        return (offset(2, subs));
    }

    array_base::size_type array_base::offset
        ( size_type i , size_type j, size_type k ) const
    {
        ::mwIndex subs[] = { i, j, k };
        return (offset(3, subs));
    }

}
