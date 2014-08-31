
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef OPTIMIZATION_RUN_SELECTOR_H_
#define OPTIMIZATION_RUN_SELECTOR_H_

#include <string>
#include <vector>
#include "common_defs.h"

namespace ShapePackingGui {

class OptimizationRunSelector {
public:
    void set_run_path_and_update(const std::string& path);
    UpdateProblemDefSignal get_update_problem_def_signal();
    UpdateSolutionDrawingsSignal get_update_solution_drawings_signal();
private:
     UpdateProblemDefSignal update_problem_def_signal;
     UpdateSolutionDrawingsSignal update_sol_drawings_signal;
};

}

#endif /* RUN_SELECTOR_H_ */
