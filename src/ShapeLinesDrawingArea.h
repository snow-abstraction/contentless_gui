
//          Copyright Douglas W. Potter 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)'

#ifndef SHAPELINESDRAWINGAREA_H_
#define SHAPELINESDRAWINGAREA_H_

#include "common_defs.h"

#include <gtkmm-3.0/gtkmm/drawingarea.h>

namespace ShapePackingGui {
/*
 * The class ShapeLinesDrawingArea draws a line drawing of a shape by connecting
 * the points defining the shape with lines.
 */
class ShapeLinesDrawingArea: public DrawingArea {
public:
    virtual ~ShapeLinesDrawingArea() {}
    void on_set_shape_spec(D2ShapeSpecSPtr);
protected:
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    bool set_shape_spec(D2ShapeSpecSPtr current_spec);
    const D2ShapeSpecSPtr get_spec() const;
private:
    D2ShapeSpecSPtr spec;
};

}

#endif /* SHAPELINESDRAWINGAREA_H_ */
