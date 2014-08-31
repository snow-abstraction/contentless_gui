
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#include "MainWindow.h"

#include <sigc++/sigc++.h>
#include <gtkmm/filechooserdialog.h>


namespace ShapePackingGui {

MainWindow::MainWindow() :
    main_VBox(ORIENTATION_VERTICAL),
    buttons_box(ORIENTATION_HORIZONTAL),
    split_pane(ORIENTATION_VERTICAL),
    parts_frame("Parts"),
    solutions_frame("Solutions"),
    select_run_button("Select optimization run file") {

    select_run_button.signal_clicked().connect(
            sigc::mem_fun(*this,
                    &MainWindow::on_select_run_button_clicked));
    update_problem_def_signal.connect(
            sigc::mem_fun(problem_defintion_box,
                    &ProblemDefBox::on_update_problem_def));
    update_solution_drawings_signal.connect(
            sigc::mem_fun(solutions_box,
                    &SolutionsBox::on_update_solution_drawings));

    set_title("Packing Viewer");
    set_border_width(5);
    buttons_box.set_border_width(5);
    buttons_box.set_layout(BUTTONBOX_START);
    buttons_box.add(select_run_button);

    solutions_frame.add(solutions_box);
    parts_frame.add(problem_defintion_box);

    split_pane.pack1(solutions_frame, Gtk::EXPAND);
    split_pane.pack2(parts_frame, Gtk::EXPAND);

    main_VBox.pack_start(buttons_box, PACK_SHRINK, 10);
    main_VBox.pack_end(split_pane, PACK_EXPAND_WIDGET, 10);

    add(main_VBox);
    show_all_children();
}

void MainWindow::on_update_problem_def(const ProblemDef& def) {
    update_problem_def_signal.emit(def);
}

void
MainWindow::on_update_solution_drawings_def(const SolutionDrawingGrids& grids) {
    update_solution_drawings_signal.emit(grids);
}

MainWindow::RunPathSignal MainWindow::get_run_path_signal() {
    return run_path_signal;
}

void MainWindow::on_select_run_button_clicked() {
    FileChooserDialog dialog(
            "Please select an optimization run definition file",
            FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.set_select_multiple(false);
    dialog.add_button("_Cancel", RESPONSE_CANCEL);
    dialog.add_button("_Open", RESPONSE_OK);
    Glib::RefPtr<FileFilter> run_files_filter = FileFilter::create();
    run_files_filter->set_name("run files");
    run_files_filter->add_pattern("*.run");
    dialog.add_filter(run_files_filter);
    const int result = dialog.run();

    if (RESPONSE_OK == result) {
        run_path_signal.emit(dialog.get_filename());
    }
}

}
