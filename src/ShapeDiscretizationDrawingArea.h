
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'


#ifndef SHAPEDISCRETIZATIONDRAWINGAREA_H_
#define SHAPEDISCRETIZATIONDRAWINGAREA_H_

#include "ShapeDiscretizationDrawingArea.h"

#include "common_defs.h"

#include <gtkmm-3.0/gtkmm/drawingarea.h>

namespace ShapePackingGui {
/*
 * The class ShapeDiscretizationDrawingArea draws the discretization
 * of a shape by filling in the grid squares if covers and the overlaying
 * a line drawing of the shape.
 */
class ShapeDiscretizationDrawingArea: public DrawingArea {
public:
    virtual ~ShapeDiscretizationDrawingArea() {}
    void on_set_shape_spec(D2ShapeSpecSPtr);
    void on_set_grid_division(const XYInt); // not yet implemented
    void on_set_grid_division_and_shape_spec(const XYInt,
            D2ShapeSpecSPtr);
    bool set_shape_spec(D2ShapeSpecSPtr current_spec);
protected:
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
private:
    // TODO: do discretization in separate thread?
    void update_discretization();
    XYInt grid_division{};
    BoolGrid discretization;
    D2ShapeSpecSPtr spec;
};

}



#endif /* SHAPEDISCRETIZATIONDRAWINGAREA_H_ */
