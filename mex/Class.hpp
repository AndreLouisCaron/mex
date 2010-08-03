#ifndef _mex_Class_hpp__
#define _mex_Class_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

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
