
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef SHAPETEXTDESC_H_
#define SHAPETEXTDESC_H_

#include <gtkmm-3.0/gtkmm/textview.h>
#include <gtkmm-3.0/gtkmm/scrolledwindow.h>
#include <gtkmm-3.0/gtkmm/frame.h>

#include "common_defs.h"

namespace ShapePackingGui {

class ShapeTextDesc: public ScrolledWindow {
public:
    ShapeTextDesc();
    virtual ~ShapeTextDesc() {}
    void on_set_shape(D2ShapeSpecSPtr);
protected:
    Frame text_repr_frame;
    Glib::RefPtr<TextBuffer> text_buffer;
    TextView text_view;
};

}

#endif /* SHAPETEXTDESC_H_ */
