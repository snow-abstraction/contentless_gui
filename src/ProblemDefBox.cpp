
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#include "ProblemDefBox.h"


namespace ShapePackingGui {

ProblemDefBox::ProblemDefBox() :
        Box(ORIENTATION_VERTICAL),
        adjustment(
                Adjustment::create(0.0, 0.0, 5.0, 1.0, 1.0, 1.0)),
        shape_selector(adjustment, ORIENTATION_HORIZONTAL) {

    shape_selector.set_digits(0);
    shape_selector.set_value_pos(POS_TOP);
    shape_selector.set_draw_value();
    shape_selector.signal_value_changed().connect(
            sigc::mem_fun(this, &ProblemDefBox::on_shape_selection_changed));

    pack_start(viewers, PACK_EXPAND_WIDGET);
    pack_end(shape_selector, PACK_SHRINK, 10);
    // TODO: really need functions like get_update_problem_def_signal() ?
    get_update_problem_def_signal().connect(
            sigc::mem_fun(viewers, &ProblemDefViewers::on_update_problem_def));
    get_update_shape_index_signal().connect(
            sigc::mem_fun(viewers, &ProblemDefViewers::on_update_shape_index));
    show_all_children();
}

ProblemDefBox::UpdateProblemDefSignal
ProblemDefBox::get_update_problem_def_signal() {
    return update_problem_def_signal;
}

ProblemDefBox::UpdateShapeIndexSignal
ProblemDefBox::get_update_shape_index_signal() {
    return update_shape_index_signal;
}

void ProblemDefBox::on_update_problem_def(const ProblemDef & new_prob) {
    const double value = 0.0;
    const double lower = 0.0;
    const double upper = 5.0;
    const double step_inc = 1.0;
    const double page_inc = 1.0;
    const double page_size = 1.0;
    adjustment->configure(value, lower, upper, step_inc, page_inc, page_size);
    update_problem_def_signal.emit(new_prob);
}

void ProblemDefBox::on_shape_selection_changed() {
    update_shape_index_signal.emit(shape_selector.get_value());
}

}


