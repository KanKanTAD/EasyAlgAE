#include "easy_alg_ae.hpp"
#include <iostream>

int main(void) {
  alg_ae::SP_Graph graph;

  alg_ae::BaseCircle c{120.0f, 120.0f, 14.0f, 0xff0000};
  graph.push_back(c);
  graph.show();
  _getch();
  return 0;
}