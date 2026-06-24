#include <iostream>

struct Point3d{
  double x{0.0};
  double y{0.0};
  double z{0.0};
};

Point3d getZeroPoint(){
  return Point3d{0.0, 0.0, 0.0}; // this temp object is destroyed after being copied to caller
}