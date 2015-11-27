
#include "Utility.hpp"


ci::Vec2f floorv2(const ci::Vec2f& in, int len) {
  ci::Vec2f out;
  
  out.x = in.x * pow(10.0, len);
  out.x = (float)(int)(out.x);
  out.x = out.x * pow(10.0, -len);
  
  out.y = in.y * pow(10.0, len);
  out.y = (float)(int)(out.y);
  out.y = out.y * pow(10.0, -len);
  
  return out;
}

double floor2(double in, int len) {
  static double out;
  
  out = in * pow(10.0, len);
  out = (double)(int)(out);
  
  return out * pow(10.0, -len);
}