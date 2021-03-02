//
// Created by v_fantnzeng on 2021/3/2.
//

#ifndef EASYALGAE_EASY_ALG_AE_HPP
#define EASYALGAE_EASY_ALG_AE_HPP

#include <atomic>
#include <cmath>
#include <conio.h>
#include <ctime>
#include <easyx.h>
#include <list>
#include <random>

namespace alg_ae {

class Base_;
/***********************************/

class Base_ {
  inline static std::atomic<long> g_{0};
  long id_;

public:
  Base_() : id_{Base_::gen00()} {};
  virtual long id() const { return id_; }

public:
  static long gen00() { return g_++; }
};

/*********************************************/
class SP_Graph;

struct Range;
struct Range2;
struct Rect2;
struct Pos2;
/************************************/

template <typename Ty> struct distribution_ {
  virtual Ty uniform_distribution() const = 0;
};

/************************************/
struct Range : public distribution_<float> {
  float min;
  float max;
  Range::Range(float a, float b) : min{a}, max{b} {}
  Range() : Range(0, 1) {}
  virtual float uniform_distribution() const override {
    std::mt19937 mt;
    std::uniform_real<float> u{0.0f, 1.0f};
    float p = u(mt);
    return this->min + p * (this->max - this->min);
  };
};
// struct Range2 : public distribution_<Pos2> {
//  float top;
//  float bottom;
//  float left;
//  float right;
//  Rect2 to_rect2() const;
//};
//
// struct Rect2 : public distribution_<Pos2> {
//  float top;
//  float bottom;
//  float width;
//  float height;
//  Range2 to_range2() const;
//};
//
// struct Pos2 {
//  float x;
//  float y;
//};
/*********************************************/

/**********************************************/

struct Guard {
  virtual ~Guard() {}
};

struct Drawable:public Base_ {
  virtual void draw() const = 0;
  virtual ~Drawable() {}
};
/*********************************************/

struct ColorGuard : public Guard {

  ColorGuard() {
    bk_color_ = getbkcolor();
    fill_color_ = getfillcolor();
    text_color_ = gettextcolor();
  }
  virtual ~ColorGuard() {
    setbkcolor(bk_color_);
    setfillcolor(fill_color_);
    settextcolor(text_color_);
  }

private:
  COLORREF bk_color_;
  COLORREF fill_color_;
  COLORREF text_color_;
};
/*****************************************************/

class SP_Graph {

  double width_;
  double height_;
  int flag_;
  std::list<const Drawable *> drawices_;

public:
  SP_Graph(double w, double h, int flag = 0)
      : width_(w), height_(h), flag_(flag) {
    initgraph(width_, height_, flag_);
    drawices_.clear();
  }
  SP_Graph() : SP_Graph(480, 320, 0) {}
  virtual ~SP_Graph() { closegraph(); }
  size_t draw_size() const { return drawices_.size(); }
  void push_back(const Drawable &drawer) { drawices_.push_back(&drawer); }

  void show() const {
    for (const auto &drawer : drawices_) {
      drawer->draw();
    }
  }
};

struct BaseCircle : public Drawable {
  float x;
  float y;
  float raduis;
  int color;
  BaseCircle(float x, float y, float r, int color = RED)
      : x(x), y(y), raduis(r), color(color) {}
  BaseCircle() : BaseCircle(0.0f, 0.0f, 1.0f) {}
  virtual void draw() const {
    ColorGuard g_;
    setfillcolor(color);
    circle(x, y, raduis);
  }
};

} // namespace alg_ae

#endif // EASYALGAE_EASY_ALG_AE_HPP
