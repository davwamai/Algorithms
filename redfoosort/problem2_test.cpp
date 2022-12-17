/// Copyright 2022 CSCE 240
//

#include "problem2.h"
#include "problem2.h" // test correct header constuction
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>


//Converts array of doubles into space-delimited string value for ease of
//printing and comparison.
//
const std::string ToString(const double kDoubles[], size_t size);


int main(int argc, char* argv[]) {
  std::cout << "Problem 2" << std::endl;
  assert(kTestVal == 'C');  // test correct header construction

// #ifdef _GLIBCXX_ALGORITHM  //TODO: remove me before giving to students
//   assert(false && "Included algorithms lib. No points!");
// #endif 

  const std::string kFileName = "problem5_doubles.txt";

  // test Max
  const double kExpected_max = 41.5;
  const double kActual_max = Max(kFileName);
  std::cout << "  Max(" << kFileName << ")" << std::endl;
  std::cout << "    Expected: " << kExpected_max << ", Actual: " << kActual_max
    << std::endl;

  // test Min
  const double kExpected_min = -71;
  const double kActual_min = Min(kFileName);
  std::cout << "  Min(" << kFileName << ")" << std::endl;
  std::cout << "    Expected: " << kExpected_min << ", Actual: " << kActual_min
    << std::endl;

  // test Min
  const double kExpected_sum = 20;
  const double kActual_sum = Sum(kFileName);
  std::cout << "  Sum(" << kFileName << ")" << std::endl;
  std::cout << "    Expected: " << kExpected_sum << ", Actual: " << kActual_sum
    << std::endl;

  // test Min
  const double kExpected_avg = 5.0;
  const double kActual_avg = Avg(kFileName);
  std::cout << "  Avg(" << kFileName << ")" << std::endl;
  std::cout << "    Expected: " << kExpected_avg << ", Actual: " << kActual_avg
    << std::endl;

  // test Sort
  const std::string kExpected_doubles = "-71 15 34.5 41.5";
  const size_t kSize = 4;
  double actual_doubles[kSize];
  Sort(kFileName, actual_doubles);
  std::cout << "  Sort(" << kFileName << ")" << std::endl;
  std::cout << "    Expected: " << kExpected_doubles
    << ", Actual: " << ToString(actual_doubles, kSize)
    << std::endl;

  return 0;
}


const std::string ToString(const double kDoubles[], size_t size) {
  std::stringstream sout;

  for (size_t i = 0; i < size; ++i) {
    sout << kDoubles[i];
    if (i != size - 1)
      sout << ' ';
  }

  return sout.str();
}
