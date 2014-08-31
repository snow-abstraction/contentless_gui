
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'


#include "ShapeLinesDrawingArea.h"

namespace ShapePackingGui {

bool ShapeLinesDrawingArea::set_shape_spec(D2ShapeSpecSPtr current_spec) {
    bool has_set_spec(false);
    if (spec != current_spec) {
        spec = current_spec;
        has_set_spec = true;
    }
    return has_set_spec;
}

bool ShapeLinesDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    return true;
}

void ShapeLinesDrawingArea::on_set_shape_spec(D2ShapeSpecSPtr current_spec) {
}

}
