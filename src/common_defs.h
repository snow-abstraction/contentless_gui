
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef COMMON_DEFS_H_
#define COMMON_DEFS_H_

#include <sigc++/sigc++.h>
#include <memory>

namespace Gtk {}

namespace ShapePackingGui {
using namespace Gtk;

// dummy structs for contentless version
struct BoolGrid {};
struct D2ShapeSpec {};
struct ProblemDef {};
struct Solution {};
struct XYInt {};
struct SolutionDrawingGrid {};
struct SolutionDrawingGrids {};

using D2ShapeSpecSPtr = std::shared_ptr<const D2ShapeSpec>;
using UpdateProblemDefSignal = sigc::signal<void, const ProblemDef&>;
using UpdateSolutionDrawingsSignal  = sigc::signal<void, const SolutionDrawingGrids&>;

}


#endif /* COMMON_DEFS_H_ */
