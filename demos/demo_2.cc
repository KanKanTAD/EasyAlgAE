//
// Created by v_fantnzeng on 2021/3/2.
//
#include <easy_alg_ae.hpp>
#include <iostream>

int main(void) {
  alg_ae::SP_Graph graph(480, 640);
  alg_ae::BaseCircle c{10, 10, 10};
  std::cout<< "c_id:{0}" << c.id() << std::endl;
  _getch();
  return 0;
}
