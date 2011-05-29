.. mex/mex/error.rst
   Copyright(c) André Caron, 2009-2011

``error`` -- Abort Function Execution
=====================================

Example
-------

.. code-block:: c++

   extern "C" void mexFunction
       ( int nlhs, ::mxArray * plhs[], int nrhs, const ::mxArray * prhs [] )
   try
   {
       // your extension's code here...
   }
   catch ( const std::exception& error ) {
       mex::error(error.what());
   }
   catch ( ... ) {
       mex::error("An unknown error occured, aborting!");
   }


Reference
---------

.. cpp:namespace:: mex

.. cpp:function:: void error ( const char * message )
.. cpp:function:: void error ( const std::string& message )
.. cpp:function:: void error ( const array<char_t>& message )

   Display ``message`` in the caller's standard output and abort function
   execution.  This function does not return, control is passed directly to
   the caller's environment.

   :param message: message to display in caller's standard output

   .. warning::

      From a memory management perspective, it is not wise to call this function
      at arbitrary points in your code.  The idiomatic way to use this function
      is from the extension's entry point.  See the example for details.

.. cpp:function:: void warning ( const char * message )
.. cpp:function:: void warning ( const std::string& message )
.. cpp:function:: void warning ( const array<char_t>& message )

   Display ``message`` in the caller's standard output and keep executing.

   :param message: message to display in caller's standard output
