
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#include <fstream>
#include <assert.h>

#include "OptimizationRunSelector.h"

namespace ShapePackingGui {

void
OptimizationRunSelector::set_run_path_and_update(const std::string & path) {
    SolutionDrawingGrids grids;
    update_sol_drawings_signal.emit(grids);

    /*
    using namespace std;
    std::ifstream file(path);
    try {
        if (file.good()) {
            SolutionDrawingGrids grids;
            update_sol_drawings_signal.emit(grids);

        }
    } catch (...) {
        //TODO: send signal for error msg dialog to appear
        throw;
    }
    */
}

UpdateProblemDefSignal
OptimizationRunSelector::get_update_problem_def_signal() {
    return update_problem_def_signal;
}

UpdateSolutionDrawingsSignal
OptimizationRunSelector::get_update_solution_drawings_signal() {
    return update_sol_drawings_signal;
}

} // end of namespace

