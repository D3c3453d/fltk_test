#include "misc/window.h"
#include "misc/graph.h"
#include "misc/gui.h"

int main() {

  Graph_lib::Window win{800, 600, "Scrollable Window"};

  for (int i = 0; i < 30; ++i) {
    Graph_lib::Button btn = Graph_lib::Button(Graph_lib::Point{10, 30 * i}, 100, 30, "Button " + std::to_string(i), nullptr);
    win.attach(btn);
  }

  return Graph_lib::gui_main();
}
