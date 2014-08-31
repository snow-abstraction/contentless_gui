
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#include <sigc++/sigc++.h>
#include <gtkmm/application.h>

#include "MainWindow.h"
#include "OptimizationRunSelector.h"

int main(int argc, char *argv[]) {
    using namespace ShapePackingGui;

    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,
            "shape.optimization.run.gui", Gio::APPLICATION_NON_UNIQUE);
    OptimizationRunSelector model;
    MainWindow window;

    model.get_update_problem_def_signal().connect(
            sigc::mem_fun(window, &MainWindow::on_update_problem_def));
    model.get_update_solution_drawings_signal().connect(
            sigc::mem_fun(window,
                          &MainWindow::on_update_solution_drawings_def));
    window.get_run_path_signal().connect(
            sigc::mem_fun(model,
                          &OptimizationRunSelector::set_run_path_and_update));
    return app->run(window);
}
