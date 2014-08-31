
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#include "SolutionsBox.h"
#include "gtkmm-3.0/gtkmm/adjustment.h"

namespace ShapePackingGui {

SolutionsBox::SolutionsBox() :
       Box(ORIENTATION_VERTICAL),
       adjustment(
               Adjustment::create(0.0, 0.0, 5.0, 1.0, 1.0, 1.0)),
       solution_selector(adjustment, ORIENTATION_HORIZONTAL),
       sol_frame("Solution", ALIGN_CENTER, ALIGN_CENTER, 1.0, false) {

    solution_selector.set_digits(0);
    solution_selector.set_value_pos(POS_TOP);
    solution_selector.set_draw_value();
    solution_selector.signal_value_changed().connect(sigc::mem_fun(this,
            &SolutionsBox::on_shape_solution_selection_changed));

    //  set minimum size for the frame
    sol_frame.set_size_request(100, 100);
    sol_frame.add(sol_drawing);

    pack_start(sol_frame, PACK_EXPAND_WIDGET);
    pack_end(solution_selector, PACK_SHRINK, 10);
    update_solution_signal.connect(sigc::mem_fun(sol_drawing,
            &SolutionDrawingArea::on_set_solution_drawing));
    show_all_children();
}

void SolutionsBox::on_update_solution_drawings(
    const SolutionDrawingGrids& new_sol_drawings) {
    sol_drawings = new_sol_drawings;

    const double value = 0.0;
    const double lower = 0.0;
    const double upper = 5.0;
    const double step_inc = 1.0;
    const double page_inc = 1.0;
    const double page_size = 1.0;
    adjustment->configure(value, lower, upper, step_inc, page_inc, page_size);
    emit_current_or_empty_solution();
}

void SolutionsBox::emit_current_or_empty_solution() {
}

void SolutionsBox::on_shape_solution_selection_changed() {
    emit_current_or_empty_solution();
}


}

