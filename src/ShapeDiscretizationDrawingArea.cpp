
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'


#include "ShapeDiscretizationDrawingArea.h"

namespace ShapePackingGui {

void ShapeDiscretizationDrawingArea::update_discretization() {

}

void ShapeDiscretizationDrawingArea::on_set_shape_spec(D2ShapeSpecSPtr current_spec) {
    if (set_shape_spec(current_spec)) {
        update_discretization();
    }
}

bool ShapeDiscretizationDrawingArea::set_shape_spec(D2ShapeSpecSPtr current_spec) {
    bool has_set_spec(false);
    if (spec != current_spec) {
        spec = current_spec;
        has_set_spec = true;
    }
    return has_set_spec;
}

void ShapeDiscretizationDrawingArea::on_set_grid_division_and_shape_spec(
        const XYInt current_grid_division, D2ShapeSpecSPtr current_spec) {

}

bool ShapeDiscretizationDrawingArea::on_draw(
        const Cairo::RefPtr<Cairo::Context>& cr) {
    return true;
}

}

