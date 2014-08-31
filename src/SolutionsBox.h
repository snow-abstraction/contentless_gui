
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef SOLUTIONSBOX_H_
#define SOLUTIONSBOX_H_

#include "common_defs.h"
#include "SolutionDrawingArea.h"
#include <gtkmm-3.0/gtkmm/scale.h>
#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm-3.0/gtkmm/aspectframe.h>

namespace ShapePackingGui {

class SolutionsBox: public Box {
public:
    using UpdateSolutionSignal = sigc::signal<void, const SolutionDrawingGrid&>;
    using UpdateSolutionIndexSignal = sigc::signal<void, int>;
    SolutionsBox();
    virtual ~SolutionsBox() {}
    void on_update_solution_drawings(
            const SolutionDrawingGrids& new_sol_drawings);
    void on_shape_solution_selection_changed();
    UpdateSolutionSignal get_update_problem_def_signal();
    UpdateSolutionIndexSignal get_update_shape_index_signal();
protected:
    void emit_current_or_empty_solution();
    Glib::RefPtr<Adjustment> adjustment;
    Scale solution_selector;
    AspectFrame sol_frame;
    UpdateSolutionSignal update_solution_signal;
    SolutionDrawingArea sol_drawing;
    SolutionDrawingGrids sol_drawings;
};

}

#endif /* SOLUTIONSBOX_H_ */
