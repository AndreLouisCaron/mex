.. mex/mex/exception.rst
   Copyright(c) André Caron, 2009-2011

``exception`` -- Error Propagation
==================================

Example
-------

.. code-block:: c++

   namespace mex {

     void call ( const char * function )
     {
       const ::mxArray * result =
           ::mexCallMATLABWithTrap(0, 0, 0, 0, function);
       if ( result != 0 ) {
         throw (mex::exception(result));
       }
     }

   }

Reference
---------

.. cpp:namespace:: mex

.. cpp:class:: exception

   This class specialized ``std::exception``.  It wraps a MATLAB exception
   object.  It allows intercepting exceptions raised by :cpp:func:`call` and
   propagating them back to the extension's entry point for use in a call to
   :cpp:func:`error`, translating it to a new MATLAB exception object in the
   caller's execution context.

   .. cpp:function:: exception ( const mxArray * backend )

      :param backend: MATLAB exception object

   .. cpp:function:: const char * what () const

      :returns: A null-terminated ASCII string with a description of the error.
