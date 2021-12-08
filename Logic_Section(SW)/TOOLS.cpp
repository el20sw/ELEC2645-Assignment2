#include "TOOLS.h"


// Function to get two boolean inputs
void get_two_input(bool &inputA, bool &inputB) {
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
  
  inputA = (bool)input1;
  inputB = (bool)input2;
}

// Function to get boolean value for carry in
void get_carry_in(bool &carry_in) {
  std::string carry_in_string;
  int carry_in_int;
  bool carry_in_test = false;

  do {
    std::cout << "\nEnter carry in: ";
    std::cin >> carry_in_string;
    carry_in_test = input_test(carry_in_string);
    if (carry_in_test == true) {
      carry_in_int = std::stoi(carry_in_string);
    }
  } while (carry_in_test == false);
  
  carry_in = (bool)carry_in_int;
}

// Function to simulate half-adder
void half_adder(bool inputA, bool inputB, bool &sum, bool &carry_out) {
  LOGIC foo;

  foo.set_inputXOR(inputA, inputB);
  foo.operateXOR();
  sum = foo.get_outputXOR();
  
  foo.set_inputAND(inputA, inputB);
  foo.operateAND();
  carry_out = foo.get_outputAND();
}

// Function to simulate full-adder
void full_adder(bool carry_in, bool inputA, bool inputB, bool &sum, bool &carry_out) {
  bool A_xor_B, A_and_B, temp;

  LOGIC foo;

  foo.set_inputXOR(inputA, inputB);
  foo.operateXOR();
  A_xor_B = foo.get_outputXOR();

  foo.set_inputAND(inputA, inputB);
  foo.operateAND();
  A_and_B = foo.get_outputAND();

  foo.set_inputXOR(A_xor_B, carry_in);
  foo.operateXOR();
  sum = foo.get_outputXOR();

  foo.set_inputAND(carry_in, A_xor_B);
  foo.operateAND();
  temp = foo.get_outputAND();
  
  foo.set_inputOR(A_and_B, temp);
  foo.operateOR();
  carry_out = foo.get_outputOR();
}