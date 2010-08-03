#ifndef _mex_reference_hpp__
#define _mex_reference_hpp__

/*!
 * @file mex/reference.hpp
 * @author Andre Caron
 */

#include <algorithm>
#include <iostream>

namespace mex {

    template<typename T, typename U=void(*)(T)>
    class reference
    {
        /* nested types. */
    private:
        typedef reference<T,U> self;
        typedef const self * link;

        /* data. */
    private:
        T myBackend;
        U myCleanup;
        mutable link myNxt;
        mutable link myPrv;

        /* construction. */
    public:
        reference ( U cleanup=U() )
            : myBackend(),
              myCleanup(cleanup),
              myNxt(0), myPrv(0)
        {
            myNxt = myPrv = this;
        }

        reference ( T backend, U cleanup=U() )
            : myBackend(backend),
              myCleanup(cleanup),
              myNxt(0), myPrv(0)
        {
            myNxt = myPrv = this;
        }

        reference ( const self& rhs )
            : myBackend(rhs.myBackend),
              myCleanup(rhs.myCleanup),
              myNxt(0), myPrv(0)
        {
            myNxt = &rhs; myPrv = rhs.myPrv;
            rhs.myPrv = rhs.myPrv->myNxt = this;
        }

        ~reference ()
        {
            if ( myNxt == this ) {
                myCleanup(myBackend);
            }
                // Detach.
            else {
                myNxt->myPrv = myPrv;
                myPrv->myNxt = myNxt;
            }
        }

        /* methods. */
    public:
        T backend () const
        {
            return (myBackend);
        }

        void swap ( self& rhs )
        {
        using std::swap;
            swap(myBackend, rhs.myBackend);
            swap(myCleanup, rhs.myCleanup);
            if ( myNxt == this ) {
                myNxt = rhs.myNxt; rhs.myNxt = &rhs;
                myPrv = rhs.myPrv; rhs.myPrv = &rhs;
            }
            else if ( rhs.myNxt == &rhs ) {
                rhs.myNxt = myNxt; myNxt = this;
                rhs.myPrv = myPrv; myPrv = this;
            }
            else {
                swap(myNxt, rhs.myNxt);
                swap(myPrv, rhs.myPrv);
            }
        }

        /* operators. */
    public:
        self& operator= ( self rhs ) {
            swap(rhs); return (*this);
        }

        operator T () const { return (backend()); }
    };

}

#endif /* _mex_reference_hpp__ */
