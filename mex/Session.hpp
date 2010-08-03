#ifndef _mex_Session_hpp__
#define _mex_Session_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "array.hpp"
#include <exception>
#include <string>

namespace mex {

    static struct exclusive_t {} exclusive;

    class Session
    {
        /* data. */
    private:
        ::Engine * myBackend;

        /* construction. */
    public:
        Session ();
        Session ( const exclusive_t& );
        Session ( const std::string& command );
        Session ( const std::string& command, const exclusive_t& );

    private:
        Session ( const Session& );

    public:
        ~Session ();

        /* methods. */
    public:
        bool visible () const;
        void visible ( bool visible );

        void put ( const std::string& name, const array_base& variable );
        array_base get ( const std::string& name ) const;

        void eval ( const std::string& expression );

        /* operators. */
    private:
        Session& operator= ( const Session& );
    };

}

#endif /* _mex_Session_hpp__ */
