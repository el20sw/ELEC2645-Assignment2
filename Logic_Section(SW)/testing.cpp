#include "testing.h"

//test AND gate
bool test_AND(int a, int b, int expected) {
  LOGIC testAND;
  std::cout << "AND(" << a << "," << b << ") = ";
  testAND.set_inputAND(a, b);
  testAND.operateAND();
  int val = testAND.get_outputAND();
  
  if (val == expected) {
    std::cout << val << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << val << " (expecting " << expected << ").\n";
    return false;
  }
}

int run_AND_tests() {
  std::cout << "\nTesting AND gate...\n" << std::endl;
  int passed = 0;
  if (test_AND(0, 0, 0)) passed ++;
  if (test_AND(0, 1, 0)) passed ++;
  if (test_AND(1, 0, 0)) passed ++;
  if (test_AND(1, 1, 1)) passed ++;
  std::cout << "\nAND gate passed " << passed << " tests.\n";
  return passed;
}

//test OR gate
bool test_OR(int a, int b, int expected) {
  LOGIC testOR;
  std::cout << "OR(" << a << "," << b << ") = ";
  testOR.set_inputOR(a, b);
  testOR.operateOR();
  int val = testOR.get_outputOR();
  
  if (val == expected) {
    std::cout << val << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << val << " (expecting " << expected << ").\n";
    return false;
  }
}

int run_OR_tests() {
  std::cout << "\nTesting OR gate...\n" << std::endl;
  int passed = 0;
  if (test_OR(0, 0, 0)) passed ++;
  if (test_OR(0, 1, 1)) passed ++;
  if (test_OR(1, 0, 1)) passed ++;
  if (test_OR(1, 1, 1)) passed ++;
  std::cout << "\nOR gate passed " << passed << " tests.\n";
  return passed;
}

//test XOR gate
bool test_XOR(int a, int b, int expected) {
  LOGIC testXOR;
  std::cout << "XOR(" << a << "," << b << ") = ";
  testXOR.set_inputXOR(a, b);
  testXOR.operateXOR();
  int val = testXOR.get_outputXOR();
  
  if (val == expected) {
    std::cout << val << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << val << " (expecting " << expected << ").\n";
    return false;
  }
}

int run_XOR_tests() {
  std::cout << "\nTesting XOR gate...\n" << std::endl;
  int passed = 0;
  if (test_XOR(0, 0, 0)) passed ++;
  if (test_XOR(0, 1, 1)) passed ++;
  if (test_XOR(1, 0, 1)) passed ++;
  if (test_XOR(1, 1, 0)) passed ++;
  std::cout << "\nXOR gate passed " << passed << " tests.\n";
  return passed;
}

//test NOR gate
bool test_NOR(int a, int b, int expected) {
  LOGIC testNOR;
  std::cout << "NOR(" << a << "," << b << ") = ";
  testNOR.set_inputNOR(a, b);
  testNOR.operateNOR();
  int val = testNOR.get_outputNOR();
  
  if (val == expected) {
    std::cout << val << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << val << " (expecting " << expected << ").\n";
    return false;
  }
}

int run_NOR_tests() {
  std::cout << "\nTesting NOR gate...\n" << std::endl;
  int passed = 0;
  if (test_NOR(0, 0, 1)) passed ++;
  if (test_NOR(0, 1, 0)) passed ++;
  if (test_NOR(1, 0, 0)) passed ++;
  if (test_NOR(1, 1, 0)) passed ++;
  std::cout << "\nNOR gate passed " << passed << " tests.\n";
  return passed;
}

//test XNOR gate
bool test_XNOR(int a, int b, int expected) {
  LOGIC testXNOR;
  std::cout << "XNOR(" << a << "," << b << ") = ";
  testXNOR.set_inputXNOR(a, b);
  testXNOR.operateXNOR();
  int val = testXNOR.get_outputXNOR();
  
  if (val == expected) {
    std::cout << val << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << val << " (expecting " << expected << ").\n";
    return false;
  }
}

int run_XNOR_tests() {
  std::cout << "\nTesting XNOR gate...\n" << std::endl;
  int passed = 0;
  if (test_XNOR(0, 0, 1)) passed ++;
  if (test_XNOR(0, 1, 0)) passed ++;
  if (test_XNOR(1, 0, 0)) passed ++;
  if (test_XNOR(1, 1, 1)) passed ++;
  std::cout << "\nXNOR gate passed " << passed << " tests.\n";
  return passed;
}

//test NOT gate
bool test_NOT(int a, int expected) {
  LOGIC testNOT;
  std::cout << "NOT(" << a << ") = ";
  testNOT.set_inputNOT(a);
  testNOT.operateNOT();
  int val = testNOT.get_outputNOT();
  
  if (val == expected) {
    std::cout << val << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << val << " (expecting " << expected << ").\n";
    return false;
  }
}

int run_NOT_tests() {
  std::cout << "\nTesting NOT gate...\n" << std::endl;
  int passed = 0;
  if (test_NOT(0, 1)) passed ++;
  if (test_NOT(1, 0)) passed ++;
  std::cout << "\nNOT gate passed " << passed << " tests.\n";
  return passed;
}

//test NAND gate
bool test_NAND(int a, int b, int expected) {
  LOGIC testNAND;
  std::cout << "NAND(" << a << "," << b << ") = ";
  testNAND.set_inputNAND(a, b);
  testNAND.operateNAND();
  int val = testNAND.get_outputNAND();
  
  if (val == expected) {
    std::cout << val << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << val << " (expecting " << expected << ").\n";
    return false;
  }
}

int run_NAND_tests() {
  std::cout << "\nTesting NAND gate...\n" << std::endl;
  int passed = 0;
  if (test_NAND(0, 0, 1)) passed ++;
  if (test_NAND(0, 1, 1)) passed ++;
  if (test_NAND(1, 0, 1)) passed ++;
  if (test_NAND(1, 1, 0)) passed ++;
  std::cout << "\nNAND gate passed " << passed << " tests.\n";
  return passed;
}

//test half_adder
bool test_half_adder(bool a, bool b, bool expected_sum, bool expected_carry_out) {
  bool sum, carry_out;
  std::cout << "Half-adder(" << a << "+" << b << ") = ";
  half_adder(a, b, sum, carry_out);

  if (sum == expected_sum && carry_out == expected_carry_out) {
    std::cout << sum  << ", " << carry_out << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << sum << ", " << carry_out << " (expecting " << expected_sum << ", " << expected_carry_out << ").\n";
    return false; 
  }
}

int run_half_adder_tests() {
  std::cout << "\nTesting Half-Adder...\n" << std::endl;
  int passed = 0;
  if (test_half_adder(0, 0, 0, 0)) passed ++;
  if (test_half_adder(0, 1, 1, 0)) passed ++;
  if (test_half_adder(1, 0, 1, 0)) passed ++;
  if (test_half_adder(1, 1, 0, 1)) passed ++;
  std::cout << "\nHalf-Adder passed " << passed << " tests.\n";
  return passed;
}

//test full-adder
bool test_full_adder(bool carry_in, bool a, bool b, bool expected_sum, bool expected_carry_out) {
  bool sum, carry_out;
  std::cout << "Full-adder(" << carry_in << "+" << a << "+" << b << ") = ";
  full_adder(a, b, carry_in, sum, carry_out);

  if (sum == expected_sum && carry_out == expected_carry_out) {
    std::cout << sum  << ", " << carry_out << " : passed\n";
    return true;
  } else {
    std::cout << "FAILED! " << sum << ", " << carry_out << " (expecting " << expected_sum << ", " << expected_carry_out << ").\n";
    return false; 
  }
}

int run_full_adder_tests() {
  std::cout << "\nTesting Full-Adder...\n" << std::endl;
  int passed = 0;
  if (test_full_adder(0, 0, 0, 0, 0)) passed++;
  if (test_full_adder(0, 0, 1, 1, 0)) passed++;
  if (test_full_adder(0, 1, 0, 1, 0)) passed++;
  if (test_full_adder(0, 1, 1, 0, 1)) passed++;
  if (test_full_adder(1, 0, 0, 1, 0)) passed++;
  if (test_full_adder(1, 0, 1, 0, 1)) passed++;
  if (test_full_adder(1, 1, 0, 0, 1)) passed++;
  if (test_full_adder(1, 1, 1, 1, 1)) passed++;
  std::cout << "\nFull-Adder passed " << passed << " tests.\n";
  return passed;
}

void run_tests() {
  std::cout << "\n>>> Logic Gate and Tool Testing <<<\n" << std::endl;
  run_AND_tests();
  run_OR_tests();
  run_XOR_tests();
  run_NOR_tests();
  run_XNOR_tests();
  run_NOT_tests();
  run_NAND_tests();
  run_half_adder_tests();
  run_full_adder_tests();
  return;
}