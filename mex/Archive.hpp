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
#include <vector>

namespace mex {

    static class read_t {} read;
    static class edit_t {} edit;
    static class write_t {} write;

    class Archive
    {
        /* data. */
    private:
        ::MATFile * myBackend;

        /* class methods. */
    public:
        static ::MATFile * open ( const char * path, const char * mode )
        {
            ::MATFile *const result = ::matOpen(path, mode);
            if ( result == 0 ) {
                throw (std::exception());
            }
            return (result);
        }

        /* construction. */
    public:
        Archive ( const std::string& path, const read_t& )
            : myBackend( open(path.c_str(), "r") )
        {
        }

        Archive ( const std::string& path, const edit_t& )
        : myBackend( open(path.c_str(), "u") )
        {
        }

        Archive ( const std::string& path, const write_t& )
            : myBackend( open(path.c_str(), "w") )
        {
        }

    private:
        Archive ( const Archive& );

    public:
        ~Archive ()
        {
            const int result = ::matClose(myBackend);
            if ( result != 0 )
            {
                // ...can't throw!!!
            }
        }

        /* methods. */
    public:
        const std::vector<std::string> variables () const
        {
            int count = 0;
            char ** const names = ::matGetDir(myBackend, &count);
            if ( names == 0 ) {
                throw (std::exception());
            }
            std::vector<std::string> result(names, names+count);
            ::mxFree(names);
            return (result);
        }

        void put ( const std::string& name, const array_base& variable )
        {
            const int result = ::matPutVariable
                (myBackend, name.c_str(), variable.backend());
            if ( result != 0 ) {
                throw (std::exception());
            }
        }

        array_base get ( const std::string& name ) const
        {
            ::mxArray *const result = ::matGetVariable(myBackend, name.c_str());
            if ( result != 0 ) {
                throw (std::exception());
            }
            return (array_base(result, claim));
        }

        void del ( const std::string& name )
        {
            const int result = ::matDeleteVariable(myBackend, name.c_str());
            if ( result != 0 ) {
                throw (std::exception());
            }
        }

        /* operators. */
    private:
        Archive& operator= ( const Archive& );
    };

}

#endif /* _mex_Archive_hpp__ */
