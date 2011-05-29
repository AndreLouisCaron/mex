.. mex/mex/archive.rst
   Copyright(c) André Caron, 2009-2011

``archive`` -- Persistant Storage
=================================

Example
-------

.. code-block:: c++

   #include <mex.hpp>
   #include <exception>
   #include <iostream>
   
   int main ( int, char ** )
   try
   {
         // Access an archive.
       const mex::session session;
       const mex::archive archive("archive.mat", mex::read);
       
         // List the archive variable names.
       const std::vector<std::string> variables = archive.variables();
       
         // Print each on its own line.
       std::copy(variables.begin(), variables.end(),
           std::ostream_iterator<std::string>(std::cout, "\n"));
   }
   catch ( const std::exception& error )
   {
       std::cerr
           << "  (( " << error.what() << " ))" << std::endl;
       return (EXIT_FAILURE);
   }
   catch ( ... )
   {
       std::cerr
           << "  (( unknown exception. ))" << std::endl;
       return (EXIT_FAILURE);
   }

Reference
---------

.. cpp:namespace:: mex

.. cpp:type:: read_t

   Dummy type used to select the proper :cpp:class:`archive` constructor.  Use
   the global :cpp:member:`read` when an argument of this type is required.

.. cpp:type:: edit_t

   Dummy type used to select the proper :cpp:class:`archive` constructor.  Use
   the global :cpp:member:`edit` when an argument of this type is required.

.. cpp:type:: write_t

   Dummy type used to select the proper :cpp:class:`archive` constructor.  Use
   the global :cpp:member:`write` when an argument of this type is required.

.. cpp:member:: read_t read

   Global instance of :cpp:type:`read_t`.

.. cpp:member:: edit_t edit

   Global instance of :cpp:type:`edit_t`.

.. cpp:member:: edit_t write

   Global instance of :cpp:type:`write_t`.

.. cpp:class:: archive

   .. cpp:function:: archive ( const std::string& path, const read_t& )

      Opens a MATLAB MAT-file in read-only mode.  Calls to :mat:func:`put` and
      :mat:func:`del` will fail.

   .. cpp:function:: archive ( const std::string& path, const edit_t& )

      Opens a MATLAB MAT-file in read-write mode.

   .. cpp:function:: archive ( const std::string& path, const write_t& )

      Opens a MATLAB MAT-file in write-only mode.  Calls to
      :mat:func:`variables` and :mat:func:`get` will fail.

   .. cpp:function:: ~archive ()

      Closes the MAT-file, applying any pending changes.

   .. cpp:function:: const std::vector<std::string> variables () const

      List the names of all variables in the MAT-file.

      :returns: a list of strings.

   .. cpp:function:: void put(const std::string&name, const array_base&variable)

      Define or replace a variable.

      :param name: variable name
      :param variable: variable value

   .. cpp:function:: array_base get ( const std::string& name ) const

      Access a variable stored in the MAT-file.

   .. cpp:function:: void del ( const std::string& name )

      Remove a variable from the MAT-file.

      :param name: variable name

      If the variable does not exist, no error is raised.
