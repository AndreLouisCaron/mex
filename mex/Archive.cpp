// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "Archive.hpp"

namespace {

    ::MATFile * open ( const char * path, const char * mode )
    {
        ::MATFile *const result = ::matOpen(path, mode);
        if ( result == 0 ) {
            throw (std::exception());
        }
        return (result);
    }

}

namespace mex {

    Archive::Archive ( const std::string& path, const read_t& )
        : myBackend( ::open(path.c_str(), "r") )
    {
    }

    Archive::Archive ( const std::string& path, const edit_t& )
        : myBackend( ::open(path.c_str(), "u") )
    {
    }

    Archive::Archive ( const std::string& path, const write_t& )
        : myBackend( ::open(path.c_str(), "w") )
    {
    }

    Archive::~Archive ()
    {
        const int result = ::matClose(myBackend);
        if ( result != 0 )
        {
            // ...can't throw!!!
        }
    }

}
