#include "testing_simplifier.h"

// function that calls all tests
// modify the parameters of each function to test them
void runAllTests (void){
  testDoubleNegationLaw ("!!(!!!a.!b)", "(!a.!b)");
  testZeroAndUnitLaws ("(a.0)", "0");
  testIdempotenceAndComplementLaws ("(a+!a)", "1");
  testCommutativeLaws ("(b.a)", "(a.b)");
  testDistributiveLaws ("((a.b)+(a.c))", "((b+c).a)");
  // to test absorptionLaws make sure operands are in alphabetical order (ie. ((a+b).a) and not (a.(a+b)) )
  // this is done by commutativeLaws function, which is normally called before absorptionLaws function
  testAbsorptionLaws ("((a+b).a)", "a");
  testDeMorganLaws ("(!a.!b)", "!(a+b)");
  testInverseDeMorganLaws ("!(a.b)", "(!a+!b)");
}

// ****************************************

// function to test doubleNegationLaw function for a given expression
void testDoubleNegationLaw (std::string expression, std::string expectedResult) {

  std::string testResult = doubleNegationLaw (expression);

  if (testResult == expectedResult) {
    std::cout << "\nTest successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}

// ****************************************

// function to test zeoAndUnitLaws function for a given expression
void testZeroAndUnitLaws (std::string expression, std::string expectedResult) {

  std::string testResult = zeroAndUnitLaws (expression);
    
  if (testResult == expectedResult) {
    std::cout << "Test successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}

// ****************************************

// function to test idempotenceAndComplementLaws function for a given expression
void testIdempotenceAndComplementLaws (std::string expression, std::string expectedResult) {

  std::string testResult = idempotenceAndComplementLaws (expression);
  
  if (testResult == expectedResult) {
    std::cout << "Test successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}

// ****************************************

// function to test commutativeLaws function for a given expression
void testCommutativeLaws (std::string expression, std::string expectedResult) {

  std::string testResult = commutativeLaws (expression);
    
  if (testResult == expectedResult) {
    std::cout << "Test successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}
    
// ****************************************

// function to test distributiveLaws function for a given expression
void testDistributiveLaws (std::string expression, std::string expectedResult) {

  std::string testResult = distributiveLaws (expression);
  
  if (testResult == expectedResult) {
    std::cout << "Test successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}
    
// ****************************************

// function to test absorptionLaws function for a given expression
void testAbsorptionLaws (std::string expression, std::string expectedResult) {

  std::string testResult = absorptionLaws (expression);

  if (testResult == expectedResult) {
    std::cout << "Test successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}

// ****************************************

// function to test deMorganLaws function for a given expression
void testDeMorganLaws (std::string expression, std::string expectedResult) {

  std::string testResult = deMorganLaws (expression);
    
  if (testResult == expectedResult) {
    std::cout << "Test successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}

// ****************************************

// function to test inverseDeMorganLaws function for a given expression
void testInverseDeMorganLaws (std::string expression, std::string expectedResult) {

  std::string testResult = inverseDeMorganLaws (expression);
    
  if (testResult == expectedResult) {
    std::cout << "Test successful. Result for the simplification of " << expression << " = " << testResult << ".\n";
  } else {
    std::cout << "Test unsuccessful. Expected result for the simplification of " << expression << " = " << expectedResult << ". Obtained result " << expression << " = " << testResult << ".\n";
  }
}