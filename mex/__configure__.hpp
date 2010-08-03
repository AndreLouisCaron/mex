#ifndef _mex_configure__hpp__
#define _mex_configure__hpp__

// Copyright(c) Andre Caron, 2009-2010
//
// This document is covered by the Artistic License 2.0 (Open Source Initiative
// approved license). A copy of the license should have been provided alongside
// this software package (see "license.rtf"). If not, the license is available
// online at "http://www.opensource.org/licenses/artistic-license-2.0.php".

#include <mex.h>

#ifdef _MSC_VER
#   pragma comment ( lib, "libeng.lib" )
//#   pragma comment ( lib, "libfixedpoint.lib" )
#   pragma comment ( lib, "libmat.lib" )
#   pragma comment ( lib, "libmex.lib" )
//#   pragma comment ( lib, "libmwblas.lib" )
//#   pragma comment ( lib, "libmwblascompat32.lib" )
//#   pragma comment ( lib, "libmwlapack.lib" )
//#   pragma comment ( lib, "libmwmathutil.lib" )
//#   pragma comment ( lib, "libmwservices.lib" )
//#   pragma comment ( lib, "libut.lib" )
#   pragma comment ( lib, "libmx.lib" )
//#   pragma comment ( lib, "mclmcr.lib" )
//#   pragma comment ( lib, "mclmcrrt.lib" )
#endif

#endif /* _mex_configure__hpp__ */
