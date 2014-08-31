
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef SHAPESVIEWERBOX_H_
#define PROBLEM_DEF_VIEWERS_H_

#include "common_defs.h"
#include <gtkmm-3.0/gtkmm/grid.h>
#include <gtkmm-3.0/gtkmm/aspectframe.h>

#include "ShapeLinesDrawingArea.h"
#include "ShapeDiscretizationDrawingArea.h"
#include "ShapeTextDesc.h"

namespace ShapePackingGui {

class ProblemDefViewers: public Grid {
public:
    using UpdateTextDescSignal = sigc::signal<void, const std::string&>;
    using SetShapeSignal = sigc::signal<void, D2ShapeSpecSPtr>;
    using SetGridDivisionAndShapeSignal = sigc::signal<void,
            const XYInt, D2ShapeSpecSPtr >;
    ProblemDefViewers();
    virtual ~ProblemDefViewers() {}
    UpdateTextDescSignal get_update_text_desc_signal();
    SetShapeSignal get_update_shape_signal();
    void on_update_problem_def(const ProblemDef & new_problem);
    void on_update_shape_index(const int shape_index);
protected:
    AspectFrame text_repr_frame;
    ShapeTextDesc text_window;
    AspectFrame curve_repr_frame;
    ShapeLinesDrawingArea curve_repr_frame_drawing;
    AspectFrame discrete_repr_frame;
    ShapeDiscretizationDrawingArea discrete_repr_frame_drawing;
    SetShapeSignal set_shape_signal;
    SetGridDivisionAndShapeSignal set_grid_division_and_shape_signal;
    D2ShapeSpecSPtr dummy{new D2ShapeSpec{}};

};

} // end of namespace

#endif /* PROBLEM_DEF_VIEWERS_H_ */
