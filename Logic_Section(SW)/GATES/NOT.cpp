#include "NOT.h"

void NOT::inputNOT() {
  std::string input1_string;
  int input1;
  bool input1_test = false;

  do {
    std::cout << "\nEnter input: ";
    std::cin >> input1_string;
    input1_test = input_test(input1_string);
    if (input1_test == true) {
      input1 = std::stoi(input1_string);
    }
  } while (input1_test == false);

  _input1 = (bool)input1;
}

bool NOT::operateNOT() {
  return _output = !_input1;
}

void NOT::outputNOT() {
  int output = (int)_output;
  std::cout << "\nNOT " << _input1 << " = " << output << std::endl;
}

void NOT::set_inputNOT(bool input) {
  _input1 = input;
}

bool NOT::get_outputNOT() {
  return _output;
}