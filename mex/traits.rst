.. mex/mex/traits.rst
   Copyright(c) André Caron, 2009-2011

``traits`` -- Compile-type Type Information
===========================================

Example
-------

.. code-block:: c++

   // ...

Reference
---------

.. cpp:namespace:: mex

.. cpp:class:: common_traits<T,U>

   .. cpp:type:: value_type
   .. cpp:type:: pointer
   .. cpp:type:: const T * const_pointer

   .. cpp:member:: static const type_t type_code

   .. cpp:function:: static mxArray * check ( mxArray * array )
   .. cpp:function:: static const mxArray * check ( const mxArray * array )

.. cpp:class:: numeric_traits<T,U>

   .. cpp:function:: static mxArray * matrix ( size_t m, size_t n, const real_t& )
   .. cpp:function:: static mxArray * matrix ( size_t m, size_t n, const complex_t& )
   .. cpp:function:: static mxArray * array ( int ndim, const int * dims, const real_t& )
   .. cpp:function:: static mxArray * array ( int ndim, const int * dims, const complex_t& )

.. cpp:class:: traits<T>

.. cpp:class:: traits<char_t>

   .. cpp:function:: static mxArray * matrix ( size_t m, size_t n )

.. cpp:class:: traits<double>

   .. cpp:function:: static mxArray * matrix ( size_t m, size_t n, const real_t& )
   .. cpp:function:: static mxArray * matrix ( size_t m, size_t n, const complex_t& )

.. cpp:class:: traits<logical>

   .. cpp:function:: static mxArray * create ( size_t m, size_t n )
