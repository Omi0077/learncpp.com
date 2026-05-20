#pragma once

namespace Math
{
  int add(int a, int b);
}

// forward declartion that are being propogated via .h file should also be in same namespace as the identifier itself
// here forward declartion of add is in same namespace Math as in add.cpp file

// this also shows that multiple blocks of same napespace is allowed , and they can be in different or in same file too.