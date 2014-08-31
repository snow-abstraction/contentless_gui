
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'


#include "ShapeTextDesc.h"

namespace ShapePackingGui {

ShapeTextDesc::ShapeTextDesc() {
    text_buffer = TextBuffer::create();
    text_buffer->set_text("");
    text_view.set_editable(false);
    text_view.set_wrap_mode(WRAP_NONE);
    text_view.set_buffer(text_buffer);
    set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
    add(text_view);
}

void ShapeTextDesc::on_set_shape(D2ShapeSpecSPtr spec) {
    const std::string text_representation("testing 123.");
    text_buffer->set_text(text_representation.c_str(),
            text_representation.c_str() + text_representation.size());
    text_view.set_buffer(text_buffer);
}

}


