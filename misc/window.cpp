#include "gui.h"

namespace Graph_lib {

Window::Window(int ww, int hh, const std::string& title) : Fl_Window{ww, hh, title.c_str()}, w{ww}, h{hh} { init(); }

Window::Window(Point xy, int ww, int hh, const std::string& title)
    : Fl_Window{xy.x, xy.y, ww, hh, title.c_str()}, w{ww}, h{hh}
{
  init();
}

void Window::init() {
  scroll = new Fl_Scroll(0, 0, w, h);  // Create scrollable area
  scroll->type(Fl_Scroll::BOTH);       // Enable both horizontal and vertical scrolling
  scroll->box(FL_NO_BOX);              // Remove border to blend with the window
  this->resizable(scroll);             // Make scroll resizable with the window
  this->begin();                       // Begin adding widgets
  this->add(scroll);                   // Add scroll to the window
  this->end();                         // Stop adding widgets
  show();                              // Show the window
}

//----------------------------------------------------

void Window::draw()
{
  Fl_Window::draw();
  for (unsigned int i = 0; i < shapes.size(); ++i)
    shapes[i]->draw();
}

void Window::attach(Widget& w) {
  scroll->begin();        // Begin adding widgets to the scrollable area
  w.attach(*this);        // Let Widget create and attach its FLTK representation
  scroll->end();          // Stop adding widgets
}

void Window::detach(Widget& w) 
{ 
  w.hide(); 
  // w.clean_pointer();
}

void Window::attach(Shape& s) {
  shapes.push_back(&s);
}

void Window::detach(Shape& s)
{
  for (unsigned int i = shapes.size(); 0 < i; --i)  // guess last attached will be first released
    if (shapes[i - 1] == &s)
      shapes.erase(shapes.begin() + (i - 1));  // &shapes[i-1]);
}

void Window::put_on_top(Shape& s)
{
  detach(s);
  attach(s);
}

int gui_main () { return Fl::run(); }

}  // namespace Graph_lib
