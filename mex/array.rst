.. mex/mex/array.rst
   Copyright(c) André Caron, 2009-2011

``array`` -- ND Array
=====================

Example
-------

.. code-block:: c++

   // ...

Reference
---------

.. cpp:namespace:: mex

.. cpp:function:: size_t numel ( const mxArray * backend )

.. cpp:class:: array_base

   .. cpp:type:: mex::size_t size_type
   .. cpp:type:: void * pointer
   .. cpp:type:: const void * const_pointer

   .. cpp:function:: array_base ( mxArray * backend, const claim_t& )
   .. cpp:function:: array_base ( const mxArray * backend, const clone_t& )
   .. cpp:function:: array_base ( const array_base& other )
   .. cpp:function:: ~array_base ()

   .. cpp:function:: void swap ( array_base& other )
   .. cpp:function:: mxArray * backend () const
   .. cpp:function:: mxArray * release ()
   .. cpp:function:: bool empty () const
   .. cpp:function:: size_type dims () const
   .. cpp:function:: size_type dim ( size_type i ) const
   .. cpp:function:: size_type numel () const
   .. cpp:function:: size_type elsiz () const
   .. cpp:function:: size_type M () const
   .. cpp:function:: size_type N () const
   .. cpp:function:: bool is ( const char * klass ) const
   .. cpp:function:: pointer data ()
   .. cpp:function:: const_pointer data () const
   .. cpp:function:: size_type offset(int nsubs, mwIndex * subs) const
   .. cpp:function:: size_type offset(size_type i) const
   .. cpp:function:: size_type offset(size_type i,size_type j) const
   .. cpp:function:: size_type offset(size_type i,size_type j,size_type k) const

.. cpp:class:: array

   .. cpp:type:: traits<T> traits_type
   .. cpp:type:: typename traits_type::value_type    value_type
   .. cpp:type:: typename traits_type::pointer       pointer
   .. cpp:type:: typename traits_type::const_pointer const_pointer
   .. cpp:type:: pointer iterator
   .. cpp:type:: const_pointer const_iterator

   .. cpp:function:: array ( size_type m, size_type n )
   .. cpp:function:: array ( size_type m, size_type n, const real_t& )
   .. cpp:function:: array ( size_type m, size_type n, const complex_t& )
   .. cpp:function:: array ( const mxArray * backend, const clone_t& )
   .. cpp:function:: array ( mxArray * backend, const claim_t& )
   .. cpp:function:: array ( const array<T>& other )

   .. cpp:function:: void swap ( array<T> & other )
   .. cpp:function:: pointer data ()
   .. cpp:function:: const_pointer data () const
   .. cpp:function:: iterator begin ()
   .. cpp:function:: const_iterator begin () const
   .. cpp:function:: iterator end ()
   .. cpp:function:: const_iterator end () const
   .. cpp:function:: array<T>& operator= ( const array<T>& other )
   .. cpp:function:: value_type& operator()(size_type i)
   .. cpp:function:: value_type& operator()(size_type i,size_type j)
   .. cpp:function:: value_type& operator()(size_type i,size_type j,size_type k)
   .. cpp:function:: value_type operator()(size_type i) const
   .. cpp:function:: value_type operator()(size_type i,size_type j) const
   .. cpp:function:: value_type operator()(size_type i,size_type j,size_type k) const

.. cpp:function:: void swap<T> ( array<T>& lhs, array<T>& rhs )

   Global swap method, for argument-dependant lookup.
