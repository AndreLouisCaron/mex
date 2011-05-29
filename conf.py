# -*- coding: utf-8 -*-

extensions = ['sphinx.ext.pngmath']
templates_path = ['doc/templates']
source_suffix = '.rst'

master_doc = 'index'
project = u'mex++'
copyright = u'2011, André Caron'

version = '0.1'
release = '0.1.0'

exclude_patterns = ['.build']
add_function_parentheses = True
add_module_names = True
pygments_style = 'sphinx'

html_theme = 'nature'
html_short_title = 'mex++'
html_static_path = ['doc/static']
htmlhelp_basename = 'mexdoc'
