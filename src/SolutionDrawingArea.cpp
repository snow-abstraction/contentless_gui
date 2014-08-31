
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#include "SolutionDrawingArea.h"

namespace ShapePackingGui {

 bool SolutionDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
     return true;
}

void SolutionDrawingArea::on_set_solution_drawing(
        const SolutionDrawingGrid& new_drawing) {
}

} // end of namespace
