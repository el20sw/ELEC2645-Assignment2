#include "GATE.h"

bool input_test(std::string num) {
  if (num == "1" || num == "0") {
    return true;
  } else {
    std::cout << "\nInvalid Input!\n";
    return false;
  }
}