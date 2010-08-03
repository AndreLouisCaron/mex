// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "Session.hpp"

namespace {

    ::Engine * start ( const char * command )
    {
        ::Engine *const session = ::engOpen(command);
        if ( session == 0 ) {
            throw (std::runtime_error("Could not start MATLAB session."));
        }
        return (session);
    }

}

namespace mex {

    Session::Session ()
        : myBackend( ::start(0) )
    {
    }

    Session::Session ( const std::string& command )
        : myBackend( ::start(command.c_str()) )
    {
    }

    Session::~Session ()
    {
        const int result = ::engClose(myBackend);
        if ( result != 0 )
        {
            // ...can't throw!!!
        }
    }

}
