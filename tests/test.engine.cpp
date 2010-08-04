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
        // Connect to open MATLAB session, or initiate one.
    std::cerr
        << "Starting MATLAB..." << std::flush;
    const mex::Session _;
    std::cerr << "  [OK!]" << std::endl;
    
        // Load requested archive.
    std::cerr
        << "Loading archive..." << std::flush;
    const mex::Archive archive("archive.mat", mex::read);
    std::cerr << "  [OK!]" << std::endl;
    
        // List archive contents.
    const std::vector<std::string> variables = archive.variables();
    std::copy(variables.begin(), variables.end(),
        std::ostream_iterator<std::string>(std::cout, "\n"));
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
