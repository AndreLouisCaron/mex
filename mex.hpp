#ifndef _mex_hpp__
#define _mex_hpp__

#include "mex/allocator.hpp"
#include "mex/array.hpp"
#include "mex/call.hpp"
#include "mex/Class.hpp"
#include "mex/error.hpp"
#include "mex/exception.hpp"
#include "mex/string.hpp"
#include "mex/types.hpp"

namespace mex {
    
    array<char_t> exception_id ( const ::mxArray * exception )
    {
        ::mxArray *const result =
            ::mxGetProperty(exception, 0, "identifier");
        if ( result == 0 ) {
            return (str("MATLAB:no-identifier"));
        }
        return (array<char_t>(result, claim()));
    }
    
    array<char_t> exception_message ( const ::mxArray * exception )
    {
        ::mxArray *const result =
            ::mxGetProperty(exception, 0, "message");
        if ( result == 0 ) {
            return (str("MATLAB:no-identifier"));
        }
        return (array<char_t>(result, claim()));
    }
    
    template<typename T>
    array<T> permute ( const array<T>& A, const array<double>& order )
    {
            // Prepare to call MATLAB.
        ::mxArray * prhs[] = {
            A.backend(), order.backend()
        }; const int nrhs = 2;
        ::mxArray * plhs[] = {
            0
        }; const int nlhs = 1;
        
            // Invoke MATLAB.
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, "permute");
        if ( result != 0 ) {
            //const array<char_t> message = exception_message(result);
            //throw (std::exception(str(message).c_str()));
            throw (std::exception("permute"));
        }
        
            // Return results.
        return (mex::array<T>(plhs[0], claim()));
    }
    
    template<typename T>
    array<T> flipdim ( const array<T>& A, const array<double>& dimension )
    {
            // Prepare to call MATLAB.
        ::mxArray * prhs[] = {
            A.backend(), dimension.backend()
        }; const int nrhs = 2;
        ::mxArray * plhs[] = {
            0
        }; const int nlhs = 1;
        
            // Invoke MATLAB.
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, "flipdim");
        if ( result != 0 ) {
            //const array<char_t> message = exception_message(result);
            //throw (std::exception(str(message).c_str()));
            throw (std::exception("flipdim"));
        }
        
            // Return results.
        return (mex::array<T>(plhs[0], claim()));
    }
    

    void mkdir ( const array<char_t>& root )
    {
            // Prepare to call MATLAB
        ::mxArray* prhs[] = {
            root.backend()
        }; const int nrhs = 1;
        ::mxArray* plhs[] = {
            0
        }; const int nlhs = 0;
        
          // Invoke MATLAB.
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, "mkdir");
        if ( result != 0 ) {
            throw (std::exception("mkdir"));
        }
    }
    
    double exist ( const array<char_t>& root )
    {
            // Prepare to call MATLAB
        ::mxArray* prhs[] = {
            root.backend()
        }; const int nrhs = 1;
        ::mxArray* plhs[] = {
            0
        }; const int nlhs = 1;
        
            // Invoke MATLAB.
        const ::mxArray * result =
            ::mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, "exist");
        if ( result != 0 ) {
            throw (std::exception("exist"));
        }
        
            // Returns (scalar) result.
        const mex::array<double> _(plhs[0], claim()); return (_(0));
    }
}

#endif /* _mex_hpp__ */
