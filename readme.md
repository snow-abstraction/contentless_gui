contentless_gui

This little gtkmm project is the gui code from another (unreleased) project. I've striped the gui of it's content, hence the project name. For example, all the graphics code and dependencies to file parsers have been removed. I am releasing it on github under the boost license since when coding that other project I couldn't find many simple guis using gtkmm. At that time, I would have appreciated looking at source code like this (even if this code is just a hack to display some other work).

You can see what the gui looks like with content at http://snow-abstraction.tumblr.com/post/92053753151/optimally-packing-irregular-shapes

Sorry about the mixing of C++98 and C++11. 

Included are the Eclipse Luna CDT project files and the generated makefiles.

The dependencies are:
C++11
glibmm-2.4
gtkmm-3.0
sigc++-2.0
