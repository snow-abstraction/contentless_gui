
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#include "ProblemDefViewers.h"
#include <boost/numeric/conversion/converter.hpp>


namespace ShapePackingGui {

ProblemDefViewers::ProblemDefViewers() :
        text_repr_frame("Specification", ALIGN_CENTER,
                ALIGN_CENTER, 1.0, false),
        curve_repr_frame("Drawing", ALIGN_CENTER,
                ALIGN_CENTER, 1.0, false),
        discrete_repr_frame("Discretization Example", ALIGN_CENTER,
                ALIGN_CENTER, 1.0, false) {

    set_shape_signal.connect(
            sigc::mem_fun(text_window, &ShapeTextDesc::on_set_shape));
    set_shape_signal.connect(
            sigc::mem_fun(curve_repr_frame_drawing,
                    &ShapeLinesDrawingArea::on_set_shape_spec));
    set_shape_signal.connect(
            sigc::mem_fun(discrete_repr_frame_drawing,
                    &ShapeDiscretizationDrawingArea::on_set_shape_spec));
    set_grid_division_and_shape_signal.connect(
            sigc::mem_fun(discrete_repr_frame_drawing,
                    &ShapeDiscretizationDrawingArea::on_set_grid_division_and_shape_spec));

    set_row_homogeneous(true);
    set_column_homogeneous(true);
    text_repr_frame.add(text_window);
    add(text_repr_frame);

    curve_repr_frame.add(curve_repr_frame_drawing);
    add(curve_repr_frame);

    discrete_repr_frame.add(discrete_repr_frame_drawing);
    add(discrete_repr_frame);
    show_all_children();
}

ProblemDefViewers::SetShapeSignal ProblemDefViewers::get_update_shape_signal() {
    return set_shape_signal;
}

void ProblemDefViewers::on_update_problem_def(const ProblemDef& new_problem) {
/*
    const auto& new_shapes_with_constraints =
            new_problem.shapes_with_constraints;
    ShapeSharedPtrs & shapes = problem.shapes;
    if (!new_shapes_with_constraints.empty() || !shapes.empty()) {
        shapes.clear();
        for (const auto & el : new_shapes_with_constraints) {
            shapes.push_back(std::make_shared<D2ShapeSpec>(el.shape));
        }
        if (!shapes.empty()) {
            shapes.push_back(std::make_shared<D2ShapeSpec>());
        } */
        D2ShapeSpecSPtr spec_ptr(new D2ShapeSpec);
        set_grid_division_and_shape_signal.emit(XYInt{}, spec_ptr);
        set_shape_signal.emit(spec_ptr);
    // }
}

void ProblemDefViewers::on_update_shape_index(const int shape_index) {
/* disable for contentless
    using converter = boost::numeric::converter<int, unsigned int>;
    int ub_index = converter::convert(problem.shapes.size());
  assert(0 <= shape_index && shape_index < ub_index); */
    set_shape_signal.emit(dummy);
}

}

