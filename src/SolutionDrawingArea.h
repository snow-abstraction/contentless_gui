
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef SOLUTIONDRAWINGAREA_H_
#define SOLUTIONDRAWINGAREA_H_

#include "common_defs.h"
#include <gtkmm-3.0/gtkmm/drawingarea.h>

namespace ShapePackingGui {

class SolutionDrawingArea: public DrawingArea {
public:
    void on_set_solution_drawing(const SolutionDrawingGrid& drawing);
protected:
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
private:
};

}




#endif /* SOLUTIONDRAWINGAREA_H_ */
