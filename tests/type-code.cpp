
#include <mex.hpp>

namespace {

    const char usage[] = "TYPE-CODE extract external interface type code.";

}

extern "C" void mexFunction
    ( int nlhs, ::mxArray * plhs[], int nrhs, const ::mxArray * prhs [] )
try
{
    if ( nrhs != 1 ) {
        throw (std::exception("Expecting a single argument."));
    }
    if ( mex::isa<mex::object>(prhs[0]) ) {
        mex::warning("object");
    }
    if ( mex::isa<mex::function>(prhs[0]) ) {
        mex::warning("function");
    }
    if ( mex::isa<mex::unknown>(prhs[0]) ) {
        mex::warning("unknown");
    }
}
catch ( const std::exception& error ) {
    mex::error(error.what());
}
catch ( ... ) {
    mex::error("Sorry, something unexpected happened, aborting!");
}
