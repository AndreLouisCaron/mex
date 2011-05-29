.. mex/mex/allocator.rst
   Copyright(c) André Caron, 2009-2011

``allocator`` -- Memory Management
==================================

The MATLAB external interfaces has a custom memory manager for extension
functions.  However, the ``mxAlloc()``, ``mxCalloc()`` ``mxRealloc()``, and
``mxFree()`` functions are not designed to fit into C++ library containers.  If
you wish to allocate memory using these functions but keep the feel of the
standard library containers, this class allows you to do just that.

The standard library makes it somewhat impractical to use custom allocators,
especially for string management.  It is not recommend to use it, because it
isn't necessary.  MATLAB's memory manager is designed to allow you to write code
full of memory leaks by cleaning up all memory blocks allocated with
``mxAlloc()`` *et al.* after your extension returns.  This is really convenient
when using the raw external interfaces API because it is horribly difficult to
write correct programs using those tools directly.  However, this library is
designed from the ground up using `RAII`_ and does all it can to release memory
automatically exactly when you stop using it.

This class was written in an early draft of the library and is left here for
completeness, but the library's author does not use it.

Example
-------

Allocation of a ``std::vector<int>`` instance and use MATLAB's memory manager:

.. code-block:: c++

   #include <mex.hpp>
   #include <vector>
   int main ( int, char ** )
   {
     // `v` will use MATLAB's memory manager instead
     // of ``operator new`` and ``operator delete``.
     std::vector< int, mex::allocator<int> > v;
   }

Reference
---------

.. cpp:namespace:: mex

.. cpp:class:: allocator<T>

   Standard-compliant memory `allocator`_ implementation for MATLAB extensions.
   Refer to the C++ standard library vendor's documentation for a description of
   what this class and each of its members do.  This class defines no extra
   methods apart from those required by the allocator interface.

.. _`RAII`: http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization
.. _`allocator`: http://www.sgi.com/tech/stl/Allocators.html
