.. mex/mex/isa.rst
   Copyright(c) André Caron, 2009-2011

``isa`` -- Dynamic Type Check
=============================

Example
-------

.. code-block:: c++

   // ...

Reference
---------

.. cpp:namespace:: mex

.. cpp:function:: bool isa<T> ( const mxArray * array )

   :param array: MATLAB object who'se type we want to check
   :returns: ``true`` if ``array`` contains elements of type ``T``.
