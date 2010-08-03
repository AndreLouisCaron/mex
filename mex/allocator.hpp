#ifndef _mex_allocator_hpp__
#define _mex_allocator_hpp__

/*!
 * @file mex/allocator.hpp
 * @author Andre Caron
 */

#include "__configure__.hpp"
#include <memory>
#include "types.hpp"

namespace mex {

    template<typename T>
    struct allocator :
        private std::allocator<T>
    {
        template<typename U>
        struct rebind
        {
            typedef allocator<U> other;
        };

        using std::allocator<T>::value_type;
        using std::allocator<T>::pointer;
        using std::allocator<T>::reference;
        using std::allocator<T>::const_pointer;
        using std::allocator<T>::const_reference;
        using std::allocator<T>::difference_type;

        typedef mex::size_type size_type;

        allocator () {}
        allocator ( const allocator& ) {}
        template<typename U>
        allocator ( const allocator<U>& ) {}
        ~allocator () {}

        using std::allocator<T>::address;
        using std::allocator<T>::construct;
        using std::allocator<T>::destroy;

        size_type max_size () const
        {
            return (static_cast<size_type>(std::allocator<T>::size_type()));
        }

        pointer allocate ( size_type n, const void * hint=0 )
        {
            void *const location =
                ::mxRealloc(const_cast<void*>(hint), n*sizeof(T));
            if ( location == 0 ) {
                throw (std::bad_alloc());
            }
            return (reinterpret_cast<T*>(location));
        }

        void deallocate ( pointer p, size_type n )
        {
            ::mxFree(p);
        }
    };

}

#endif /* _mex_allocator_hpp__ */
