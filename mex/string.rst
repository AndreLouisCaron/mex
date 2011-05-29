.. mex/mex/string.rst
   Copyright(c) André Caron, 2009-2011

``string`` -- Managing Text
===========================

Example
-------

.. code-block:: c++

   // ...

Reference
---------

.. cpp:namespace:: mex

.. cpp:function:: std::string string ( const mxArray * value )
.. cpp:function:: std::string string ( const array<char_t>& value )

   Convert a MATLAB string to a regular string.

   :param value: text to convert to a regular string.

.. cpp:function:: array< char_t > string ( const char * value )
.. cpp:function:: array< char_t > string ( const std::string& value )

   Convert a regular string to a MATLAB string.

   :param value: text to convert to a MATLAB string
