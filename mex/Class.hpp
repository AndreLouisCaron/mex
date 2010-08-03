#ifndef _mex_Class_hpp__
#define _mex_Class_hpp__

/*!
 * @file mex/Class.hpp
 * @author Andre Caron
 */

#include "__configure__.hpp"

namespace mex {

    class Class
    {
        /* nested types. */
    public:
        typedef ::mxClassID Value;

        /* class data. */
    public:
        static const Class Unknown ();
        static const Class Cell ();
        static const Class Struct ();
        static const Class Object ();
        static const Class Char ();
        static const Class Logical ();
        static const Class Sparse ();
        static const Class Double ();
        static const Class Single ();
        static const Class Int8 ();
        static const Class Uint8 ();
        static const Class Int16 ();
        static const Class Uint16 ();
        static const Class Int32 ();
        static const Class Uint32 ();
        static const Class Int64 ();
        static const Class Uint64 ();
        static const Class Function ();

        /* class methods. */
    public:
        static Class of ( const ::mxArray * array );

        /* data. */
    private:
        Value myValue;

        /* construction. */
    private:
        Class ( Value value );

        /* methods. */
    public:
        Value value () const;

        /* operators. */
    public:
        bool operator== ( const Class& rhs ) const;
        bool operator!= ( const Class& rhs ) const;
    };

}

#endif /*  _mex_Class_hpp__ */
