#ifndef _mex_Archive_hpp__
#define _mex_Archive_hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include "__configure__.hpp"
#include "array.hpp"
#include <string>

namespace mex {

    static class read_t {} read;
    static class edit_t {} edit;
    static class write_t {} write;

    class Archive
    {
        /* data. */
    private:
        ::MATFile * myBackend;

        /* construction. */
    public:
        Archive ( const std::string& path, const read_t& );
        Archive ( const std::string& path, const edit_t& );
        Archive ( const std::string& path, const write_t& );

    private:
        Archive ( const Archive& );

    public:
        ~Archive ();

        /* operators. */
    private:
        Archive& operator= ( const Archive& );
    };

}

#endif /* _mex_Archive_hpp__ */
