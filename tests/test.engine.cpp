// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include <mex.hpp>
#include <exception>
#include <iostream>

int main ( int, char ** )
try
{
    std::cerr
        << "Starting MATLAB..." << std::flush;
    const mex::Session _;
    std::cerr << "  [OK!]" << std::endl;
}
catch ( const std::exception& error )
{
    std::cerr
        << "  [FAILED!]" << std::endl
        << "  (( " << error.what() << " ))" << std::endl;
    return (EXIT_FAILURE);
}
catch ( ... )
{
    std::cerr
        << "  [FAILED!]" << std::endl
        << "  (( unknown exception. ))" << std::endl;
    return (EXIT_FAILURE);
}
