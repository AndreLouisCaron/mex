#ifndef _mex_session_hpp__
#define _mex_session_hpp__

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

    class session
    {
        /* data. */
    private:
        ::Engine * myBackend;

        /* class methods. */
    private:
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

        /* construction. */
    public:
        session ()
            : myBackend( shared(0) )
        {
        }

        session ( const exclusive_t& )
            : myBackend( exclusive(0) )
        {
        }

        session ( const std::string& command )
            : myBackend( shared(command.c_str()) )
        {
        }

        session ( const std::string& command, const exclusive_t& )
            : myBackend( exclusive(command.c_str()) )
        {
        }

    private:
        session ( const session& );

    public:
        ~session ()
        {
            const int result = ::engClose(myBackend);
            if ( result != 0 )
            {
                // ...can't throw!!!
            }
        }

        /* methods. */
    public:
        bool visible () const
        {
            bool visible = false;
            const int result = ::engGetVisible(myBackend, &visible);
            if ( result != 0 ) {
                throw (std::exception());
            }
            return (visible);
        }

        void visible ( bool visible )
        {
            const int result = ::engSetVisible(myBackend, visible);
            if ( result != 0 ) {
                throw (std::exception());
            }
        }

        void put ( const std::string& name, const array_base& variable )
        {
            const int result = ::engPutVariable
                (myBackend, name.c_str(), variable.backend());
            if ( result != 0 ) {
                throw (std::exception());
            }
        }

        array_base get ( const std::string& name ) const
        {
            ::mxArray *const result = ::engGetVariable(myBackend, name.c_str());
            if ( result != 0 ) {
                throw (std::exception());
            }
            return (array_base(result, claim));
        }

        void eval ( const std::string& expression )
        {
            const int result = ::engEvalString(myBackend, expression.c_str());
            if ( result != 0 ) {
                throw (std::exception());
            }
        }

        /* operators. */
    private:
        session& operator= ( const session& );
    };

}

#endif /* _mex_session_hpp__ */
