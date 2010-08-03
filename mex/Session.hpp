#ifndef _mex_Session_hpp__
#define _mex_Session_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include <exception>
#include <string>

namespace mex {

    class Session
    {
        /* data. */
    private:
        ::Engine * myBackend;

        /* construction. */
    public:
        Session ();
        Session ( const std::string& command );

    private:
        Session ( const Session& );

    public:
        ~Session ();

        /* methods. */
    public:

        /* operators. */
    private:
        Session& operator= ( const Session& );
    };

}

#endif /* _mex_Session_hpp__ */
