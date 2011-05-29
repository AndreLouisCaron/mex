.. mex/mex/call.rst
   Copyright(c) André Caron, 2009-2011

``call`` -- Invoke MATLAB Functions
===================================

Example
-------

.. code-block:: c++

   // ...

Reference
---------

.. cpp:namespace:: mex

.. cpp:function:: void call ( const char * function )
.. cpp:function:: void call ( const std::string& function )
.. cpp:function:: void call ( const array<char_t>& function )

   Call a no-argument, no return value function by name.

   :param function: function name

.. cpp:function:: void call ( int nlhs, mxArray ** plhs, int nrhs, mxArray ** prhs, const char * function )
.. cpp:function:: void call ( int nlhs, mxArray ** plhs, int nrhs, mxArray ** prhs, const std::string& function )
.. cpp:function:: void call ( int nlhs, mxArray ** plhs, int nrhs, mxArray ** prhs, const array<char_t>& function )

   Call a multiple argument, multiple return value function by name.

   :param nlhs: number of arguments
   :param plhs: arguments
   :param nrhs: number of return values
   :param prhs: return values
   :param function: function name
