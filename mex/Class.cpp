/*!
 * @file mex/Class.cpp
 * @author Andre Caron
 */

#include "Class.hpp"

namespace mex {

    const Class Class::Unknown ()
    {
        return (mxUNKNOWN_CLASS);
    }

    const Class Class::Cell ()
    {
        return (mxCELL_CLASS);
    }

    const Class Class::Struct ()
    {
        return (mxSTRUCT_CLASS);
    }

    const Class Class::Object ()
    {
        return (mxOBJECT_CLASS);
    }

    const Class Class::Char ()
    {
        return (mxCHAR_CLASS);
    }

    const Class Class::Logical ()
    {
        return (mxLOGICAL_CLASS);
    }

    const Class Class::Sparse ()
    {
        return (mxSPARSE_CLASS);
    }

    const Class Class::Double ()
    {
        return (mxDOUBLE_CLASS);
    }

    const Class Class::Single ()
    {
        return (mxSINGLE_CLASS);
    }

    const Class Class::Int8 ()
    {
        return (mxINT8_CLASS);
    }

    const Class Class::Uint8 ()
    {
        return (mxUINT8_CLASS);
    }

    const Class Class::Int16 ()
    {
        return (mxINT16_CLASS);
    }

    const Class Class::Uint16 ()
    {
        return (mxUINT16_CLASS);
    }

    const Class Class::Int32 ()
    {
        return (mxINT32_CLASS);
    }

    const Class Class::Uint32 ()
    {
        return (mxUINT32_CLASS);
    }

    const Class Class::Int64 ()
    {
        return (mxINT64_CLASS);
    }

    const Class Class::Uint64 ()
    {
        return (mxUINT64_CLASS);
    }

    const Class Class::Function ()
    {
        return (mxFUNCTION_CLASS);
    }

    Class Class::of ( const ::mxArray * array )
    {
        return (::mxGetClassID(array));
    }

    Class::Class ( Value value )
        : myValue(value)
    {
    }

    Class::Value Class::value () const
    {
        return (myValue);
    }

    bool Class::operator== ( const Class& rhs ) const
    {
        return (myValue == rhs.myValue);
    }

    bool Class::operator!= ( const Class& rhs ) const
    {
        return (myValue != rhs.myValue);
    }

}
