// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "Session.hpp"

namespace {

    ::Engine * shared ( const char * command )
    {
        ::Engine *const session = ::engOpen(command);
        if ( session == 0 ) {
            throw (std::runtime_error("Could not start MATLAB session."));
        }
        return (session);
    }

    ::Engine * exclusive ( const char * command )
    {
        int reason = 0;
        ::Engine *const session = ::engOpenSingleUse(command, 0, &reason);
        if ( session == 0 ) {
            throw (std::runtime_error("Could not start MATLAB session."));
        }
        return (session);
    }

}

namespace mex {

    Session::Session ()
        : myBackend( ::shared(0) )
    {
    }

    Session::Session ( const exclusive_t& )
        : myBackend( ::exclusive(0) )
    {
    }

    Session::Session ( const std::string& command )
        : myBackend( ::shared(command.c_str()) )
    {
    }

    Session::Session ( const std::string& command, const exclusive_t& )
        : myBackend( ::exclusive(command.c_str()) )
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

    bool Session::visible () const
    {
        bool visible = false;
        const int result = ::engGetVisible(myBackend, &visible);
        if ( result != 0 ) {
            throw (std::exception());
        }
        return (visible);
    }

    void Session::visible ( bool visible )
    {
        const int result = ::engSetVisible(myBackend, visible);
        if ( result != 0 ) {
            throw (std::exception());
        }
    }

    void Session::put ( const std::string& name, const array_base& variable )
    {
        const int result = ::engPutVariable
            (myBackend, name.c_str(), variable.backend());
        if ( result != 0 ) {
            throw (std::exception());
        }
    }

    array_base Session::get ( const std::string& name ) const
    {
        ::mxArray *const result = ::engGetVariable(myBackend, name.c_str());
        if ( result != 0 ) {
            throw (std::exception());
        }
        return (array_base(result, claim));
    }

    void Session::eval ( const std::string& expression )
    {
        const int result = ::engEvalString(myBackend, expression.c_str());
        if ( result != 0 ) {
            throw (std::exception());
        }
    }

}
