.. mex/mex/scalar.rst
   Copyright(c) André Caron, 2009-2011

``scalar`` -- Operations on Scalars
===================================

Example
-------

.. code-block:: c++

   // ...

Reference
---------

.. cpp:namespace:: mex

.. cpp:function:: array<T> scalar<T> ( T value )

   Create a MATLAB scalar (1-by-1 matrix).

   :param value: scalar numeric value to insert as sole element of a matrix
   :returns: a MATLAB matrix object with a single element

.. cpp:function:: T scalar ( const mxArray * value )

   Access a MATLAB scalar value.  MATLAB scalars are 1-by-1 matrices.

   :param value: 1-by-1 MATLAB matrix object with elements of type ``T``
   :returns: a scalar value of type ``T``
