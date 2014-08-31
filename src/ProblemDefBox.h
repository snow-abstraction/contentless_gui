
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'


#ifndef PROBLEMDEFBOX_H_
#define PROBLEMDEFBOX_H_

#include "common_defs.h"
#include "ProblemDefViewers.h"
#include <gtkmm-3.0/gtkmm/scale.h>
#include <gtkmm-3.0/gtkmm/box.h>

namespace ShapePackingGui {

class ProblemDefBox: public Box {
public:
    using UpdateProblemDefSignal = sigc::signal<void, const ProblemDef&>;
    using UpdateShapeIndexSignal = sigc::signal<void, int>;
    ProblemDefBox();
    virtual ~ProblemDefBox() {}
    void on_update_problem_def(const ProblemDef & new_prob);
    void on_shape_selection_changed();
    UpdateProblemDefSignal get_update_problem_def_signal();
    UpdateShapeIndexSignal get_update_shape_index_signal();
protected:
    Glib::RefPtr<Adjustment> adjustment;
    ProblemDefViewers viewers;
    // TODO better with some even more discrete selector, radio buttons?
    // maybe more part selection to the side, with a list of parts
    Scale shape_selector;
    UpdateProblemDefSignal update_problem_def_signal;
    UpdateShapeIndexSignal update_shape_index_signal;
};

}


#endif /* PROBLEMDEFBOX_H_ */
