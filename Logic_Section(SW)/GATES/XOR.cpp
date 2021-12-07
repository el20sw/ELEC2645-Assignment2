#include "XOR.h"

void XOR::inputXOR() {
  std::string input1_string, input2_string;
  int input1, input2;
  bool input1_test = false;
  bool input2_test = false;

  do {
    std::cout << "\nEnter input A: ";
    std::cin >> input1_string;
    input1_test = input_test(input1_string);
    if (input1_test == true) {
      input1 = std::stoi(input1_string);
    }
  } while (input1_test == false);
  
  do {
    std::cout << "\nEnter input B: ";
    std::cin >> input2_string;
    input2_test = input_test(input2_string);
    if (input2_test == true) {
      input2 = std::stoi(input2_string);
    }
  } while (input2_test == false);
  
  _input1 = (bool)input1;
  _input2 = (bool)input2;
}

bool XOR::operateXOR() {
  return _output = _input1 ^ _input2;
}

void XOR::outputXOR() {
  int output = (int)_output;
  std::cout << "\n" << (int)_input1 << " XOR " << (int)_input2 << " = " << output << std::endl;
}

void XOR::set_inputXOR(bool input1, bool input2) {
  _input1 = input1;
  _input2 = input2;
}

bool XOR::get_outputXOR() {
  return _output;
}