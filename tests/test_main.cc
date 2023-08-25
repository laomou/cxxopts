#include <iostream>

#include "cl/cxxopts.h"

int main(int argc, char** argv) {
  cl::opt<int> log_level(""); 
  cl::ParseCommandLineOptions(argc, argv);
  log_level = 10;
  if (log_level) {
    std::cout << log_level.getValue() << std::endl;
  }
  return 0;
}