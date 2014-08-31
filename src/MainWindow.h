
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef MainWindow_h
#define MainWindow_h

#include "common_defs.h"

#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm-3.0/gtkmm/buttonbox.h>
#include <gtkmm-3.0/gtkmm/frame.h>
#include <gtkmm-3.0/gtkmm/paned.h>

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>

#include "ProblemDefBox.h"
#include "SolutionsBox.h"

namespace ShapePackingGui {

class MainWindow: public Window {
public:
    using RunPathSignal = sigc::signal<void, const std::string&>;
    MainWindow();
    virtual ~MainWindow() {} ;
    void on_update_problem_def(const ProblemDef& def);
    void on_update_solution_drawings_def(const SolutionDrawingGrids& grids);
    RunPathSignal get_run_path_signal();
protected:
    Box main_VBox;
    ButtonBox buttons_box;
    Paned split_pane;
    Frame parts_frame;
    ProblemDefBox problem_defintion_box;
    Frame solutions_frame;
    SolutionsBox solutions_box;
    Button select_run_button;
    RunPathSignal run_path_signal;
    UpdateProblemDefSignal update_problem_def_signal;
    UpdateSolutionDrawingsSignal update_solution_drawings_signal;
    void on_select_run_button_clicked();
};

} // end of namespace
#endif
