#include "boolean_simplifier.h"

void booleanSimplifierSubMenu (void) {
  printSubMenu ();
  std::cout << "\nSelected item: ";
  std::string menuSelection;
  std::cin >> menuSelection;

  while (menuSelection != "1" and menuSelection != "2") {
    std::cout << "\nInput error! Thisis not a valid menu item.\n";
    std::cout << "\nSelected item: ";
    std::cin >> menuSelection;
  }

  while (menuSelection == "1") {
    
  }
}

// ****************************************

void printSubMenu (void) {
  std::cout << "\n----- Boolean Expression Simplifier Menu -----\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Boolean Expression Simplifier\t\t\t|\n";
  std::cout << "|\t2. Exit\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-----------------------------------------\n";
}

// ****************************************

// main function
void simplifyExpression (void) {
  
  std::cout << "Welcome to the Boolean Expression Simplifier!\n";

  // initialise variables
  std::string menuSelection = "1";
	bool error;
  std::string expression;

  while (menuSelection == "1") {
    
    error = true;           // error set to true to loop through program at least once
    
    while (error) {         // while input is invalid, as for new input
      std::cout << "\nPlease enter the boolean expression you would like to simplify: ";
      std::cin >> expression;
      error = validateExpression (expression);
    }

    // call function to simplify expression
    std::string simplifiedExpression = iterativeSimplification (expression);
    
    if (simplifiedExpression == expression) {
      std::cout << "\nThe expression " << expression << " can not be simplified any further.\n";
    } else {
      std::cout << "\nA simplified version of " << expression << " would be " << simplifiedExpression;
    }
 /*
    std::string input;
    std::cout << "\n\nWould you like to simplify another expression? (Y/N): ";
    std::cin >> input;

    // while input is invalid, as for new input
    while ((input != "Y" & input != "y") & (input != "N" & input != "n")) {
      std::cout << "\nInput error!\n\nWould you like to simplify another expression? (Y/N): ";
      std::cin >> input;
    }

    if (input == "N" | input == "n") {
      repeat = false;      // exit program
    }
    */
  }
}

// ****************************************

// function to check that operators and brackets have been used appropriately in the input expression
bool validateExpression (std::string expression) {

  // initialise variables
  bool error = true;
  
  int count1 = countOccurences (expression, ".") + countOccurences (expression, "+");
  int count2 = countOccurences (expression, "(");
  int count3 = countOccurences (expression, ")");

  // if number of '(' equals number of ')', there is at least one operator, and a pair of brackets was used for every operator, error flag set to false
  if (count1 > 0 & count2 == count3 & count1 == count2) {
    error = false;
  } else if (count1 == 0) {
    std::cout << "\nInput error! No operator found, please make sure your expression is written in boolean ('NOT', 'AND' and 'OR' should be written as '!', '.' and '+' respectively).\n";
  } else if (count2 != count3) {
    std::cout << "\nInput error! Number of open brackets does not match number of closed brackets.\n";
  } else if (count1 < count2) {
    std::cout << "\nInput error! Excessive number of brackets used.\n";
  } else if (count1 != count2) {
    std::cout << "\nInput error! Please make use of brackets to determine order of precedence (there should be a pair of '()' brackets for each '.'/'+' operator).\n";
  }
  
  return error;
}

// ****************************************

// function to count the number of times a sub-string appears in a string
int countOccurences (std::string thisString, std::string subString) {

  //initialise variables
  int count = 0;
  int i = thisString.find(subString);
  
  while (i != -1){
    count ++;
    thisString.erase(i, subString.length()); // sub-string is erased so it is not counted twice
    i = thisString.find(subString);          // check for another occurence of the sub-string
  }
  
  return count;
}

// ****************************************

// function to find least precedent operator and return its position
int findLeastPrecedentOperator (std::string expression) {

  // initialise variables
  int index = 0;
  int count = 0;

  // iterate through string until the number of '(' is equal to the number of ')' -1
  // eg. for ((a.b) + (c.(d.e))) the operator we are looking for is the '+', where the num of '(' = 2 and ')' == 1
  while (index < expression.length()) {
    if (expression[index] == '(') {                          
      count ++;     // if '(' found, increase counter
    } else if (expression[index] == ')') {
      count --;     // if ')' found, decrease counter
    } else if ((expression[index] == '.' | expression[index] == '+') & (count == 1)) {
      return index; // if operator found and counter == 1 return that position
    }
    index ++;       // increment counter
  }
  
  return -1;        // if operator not found in these conditions, return -1
}

// ****************************************

// function that iterates through itself until the highest precedent operator is found
std::string iterativeSimplification (std::string expression) {

  // initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;

  // operands are the values inside the brackets, at either side of the operator
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // if either operand contains an operator, that operator is of higher precendence than the current one
  if (operandA.find(".") != -1 | operandA.find("+") != -1) {
    operandA = iterativeSimplification (operandA);
  }
  if (operandB.find(".") != -1 | operandB.find("+") != -1) {
    operandB = iterativeSimplification (operandB);
  }

  // update new operands into the expression
  expression = expression.substr(0, openBracketPos +1) + operandA + thisOperator + operandB + ")";

  // call function to carry out actual simplifications
  std::string newExpression = checkForSimplifications (expression);

  return newExpression;   // return simplified expression
}

// ****************************************

// function to call every function related to simplification
std::string checkForSimplifications (std::string expression) {

  // call each function to check if any simplifications can be made
  // if the returned expression contains no operators, no further simplifications can be carried out on it
  expression = doubleNegationLaw (expression);
  if (expression.find(".") != -1 | expression.find("+") != -1) {
    expression = zeroAndUnitLaws (expression);
  } if (expression.find(".") != -1 | expression.find("+") != -1) {
    expression = idempotenceAndComplementLaws (expression);
  } if (expression.find(".") != -1 | expression.find("+") != -1) {
    expression = commutativeLaws (expression);
  } if (expression.find(".") != -1 | expression.find("+") != -1) {
    expression = distributiveLaws (expression);
  } if (expression.find(".") != -1 | expression.find("+") != -1) {
    expression = absorptionLaws (expression);
  } if (expression.find(".") != -1 | expression.find("+") != -1) {
    expression = deMorganLaws (expression);
  }
  
  return expression;   // return simplified expression
}

// ****************************************

// function to simplify double negations
std::string doubleNegationLaw (std::string expression) {

  //initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  std::string negated = "";
  int count = 0;

  // remove all '!' of the beginning and keep a count of them
  while (operandA[0] == '!') {
    operandA.erase(0, 1);
    count ++;
  }

  // if that count is odd, put one '!' back at the beginning
  if (count % 2 == 1) {
    operandA.insert(0, "!");
  }

  // reset variables and repeat for the other operand
  negated = "";
  count = 0;
  
  while (operandB[0] == '!') {
    operandB.erase(0, 1);
    count ++;
  }

  if (count % 2 == 1) {
    operandB.insert(0, "!");
  }

  // update new operands into the expression
  expression = expression.substr(0, openBracketPos +1) + operandA + thisOperator + operandB + ")";

  // reset variables and repeat for the whole expression (ie. !!(a+b) = (a+b) )
  negated = "";
  count = 0;
  
  while (expression[0] == '!') {
    expression.erase(0, 1);
    count ++;
  }

  if (count % 2 == 1) {
    expression.insert(0, "!");
  }
  
  return expression;   // return simplified expression
}

// ****************************************

// function to simplify zero and unit expressions
std::string zeroAndUnitLaws (std::string expression) {

  // initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // convert !0 into 1 and !1 into 0 for both operands
  if (operandA == "!1") {
    operandA = "0";
  } else if (operandA == "!0") {
    operandA = "1";
  }

  if (operandB == "!1") {
    operandB = "0";
  } else if (operandB == "!0") {
    operandB = "1";
  }

  // if its an AND operation and one of the operands = 0, return 0
  // eg. a AND 0 = 0
  // if its an AND operation and on of the operands = 1, return the other operand
  // eg. a AND 1 = a
  if (thisOperator == '.') {
    if (operandA == "0" | operandB == "0") {
      return "0";
    } else if (operandA == "1") {
      return operandB;
    } else if (operandB == "1") {
      return operandA;
    }
  } else {
    if (operandA == "1" | operandB == "1") {
      return "1";
    } else if (operandA == "0") {
      return operandB;
    } else if (operandB == "0") {
      return operandA;
    }
  }
    
  return expression;   // if no simplifications made, return expression as received
}

// ****************************************

// function to simplify idempotence and complement expressions
std::string idempotenceAndComplementLaws (std::string expression) {

  // initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // if both operands are equal, return the operand
  // eg. a AND a = a // a OR a = a
  // if operands are complements of each other, return 0 for AND operations and 1 for OR operations
  // eg. a AND !a = 0 // a OR !a = 1
  if (operandA == operandB) {
    return operandA;
  } else if (operandA == "!" + operandB | "!" + operandA == operandB) {
    if (thisOperator == '.') {
      return "0";
    } else {
      return "1";
    }
  }
  
  return expression;   // if no simplifications made, return expression as received
}

// ****************************************

// function to re-order operand alphabetically for easier calculations further down
std::string commutativeLaws (std::string expression) {

  //initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // make use of vectors to sort operands alphabetically
  std::vector<std::string> thisVector = {operandA, operandB};
  sort(thisVector.begin(), thisVector.end());

  // return expression in new order
  if (expression[0] == '!') {
    return "!(" + thisVector[0] + thisOperator + thisVector[1] + ")";
  } else {
    return "(" + thisVector[0] + thisOperator + thisVector[1] + ")";
  }
  
  return expression;   // if no simplifications made, return expression as received
}

// ****************************************

// function to simplify distributive expressions (ie. (a.b)+(a.c) = a.(b+c) )
std::string distributiveLaws (std::string expression) {

  // initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // distributive expressions only occur if both operands contain a sub-operation 
  if ((operandA.find(".") != -1 | operandA.find("+") != -1) & (operandB.find(".") != -1 | operandB.find("+") != -1)) {

    // if operandA starts with a '!', expand using De Morgan's Theorem so appropriate simplification is easier
    // eg. !(a.b) = (!a+!b)
    if (operandA[0] == '!') {
      operandA = inverseDeMorganLaws(operandA);
    }
    
    // split operandA into its operator and operands
    int subOperatorAPos = findLeastPrecedentOperator (operandA);
    int subOpenBracketAPos = operandA.find("(");
    int subClosedBracketAPos = operandA.length() -1;
  
    char subOperatorA = operandA[subOperatorAPos];
    std::string subOperandC = operandA.substr(subOpenBracketAPos +1, subOperatorAPos - (subOpenBracketAPos +1));
    std::string subOperandD = operandA.substr(subOperatorAPos +1, subClosedBracketAPos - (subOperatorAPos +1));

    // make use of arrays so a loop can be used for the comparisons
    std::string arrayA[2] = {subOperandC, subOperandD};

    

    // repeat process for operandB
    if (operandB[0] == '!') {
      operandB = inverseDeMorganLaws(operandB);
    }

    int subOperatorBPos = findLeastPrecedentOperator (operandB);
    int subOpenBracketBPos = operandB.find("(");
    int subClosedBracketBPos = operandB.length() -1;
  
    char subOperatorB = operandB[subOperatorBPos];
    std::string subOperandE = operandB.substr(subOpenBracketBPos +1, subOperatorBPos - (subOpenBracketBPos +1));
    std::string subOperandF = operandB.substr(subOperatorBPos +1, subClosedBracketBPos - (subOperatorBPos +1));

    std::string arrayB[2] = {subOperandE, subOperandF};



    // iterate through both arrays and compare sub-operands against each other
    // to simplify distributive expressions, the sub-operators must be the same
    // eg. (a.b)+(a.c) = a.(b+c) 
    // also, if all the operators are equal and two sub-operands are complements of each other, 
    // if the operators are AND, return 0, if the operators are OR, return 1
    // eg. (a.b).(!a.c) = a.b.!a.c = 0 as (a AND !a) = 0
    // eg. (a+b)+(!a+c) = a+b+!a+c = 1 as (a OR !a) = 1
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if ((arrayA[i] == arrayB[j]) & (subOperatorA == subOperatorB)) {
          return "((" + arrayA[1-i] + thisOperator + arrayB[1-j] + ")" + subOperatorA + arrayA[i] + ")";
        } else if (("!" + arrayA[i] == arrayB[j] | arrayA[i] == "!" + arrayB[j]) & (subOperatorA == thisOperator & subOperatorB == thisOperator)) {
          if (thisOperator == '.') {
            return "0";
          } else {
            return "1";
          }
        }
      }
    }
  }

  // update expression with new operands
  expression = expression.substr(0, openBracketPos +1) + operandA + thisOperator + operandB + ")";
  
  return expression;   // return expression
}

// ****************************************

// function to simplify absorption expressions (ie. a.(a+b) = a)
std::string absorptionLaws (std::string expression) {

  // initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // asbsoprtion expressions only occur if at least one operand contains a sub-operation
  // since operands are ordered alphabetically and '(' comes before any letters in ASCII code,
  // we only need to examine operandA
  if (operandA.find(".") != -1 | operandA.find("+") != -1) {

    // if operandA starts with a '!', expand using De Morgan's Theorem so appropriate simplification is easier
    // eg. !(a.b) = (!a+!b)
    if (operandA[0] == '!') {
      operandA = inverseDeMorganLaws(operandA);
    }

    // split operandA into its operator and operands
    int subOperatorAPos = findLeastPrecedentOperator (operandA);
    int subOpenBracketAPos = operandA.find("(");
    int subClosedBracketAPos = operandA.length() -1;
  
    char subOperatorA = operandA[subOperatorAPos];
    std::string subOperandC = operandA.substr(subOpenBracketAPos +1, subOperatorAPos - (subOpenBracketAPos +1));
    std::string subOperandD = operandA.substr(subOperatorAPos +1, subClosedBracketAPos - (subOperatorAPos +1));

    // if any of the sub-operands matches operandB, 
    // if both operators are equal, return operandA
    // eg. a.(a.b) = a.b
    // else if operators are different, return operandB
    // eg. a.(a+b) = a

    // else if any of the sub-operands are complements of each other
    // if both operators are equal, return 0 if they are AND, and 1 if OR
    // eg. a.(!a.b) = a.!a.b = 0 // a+(!a+b) = a+!a+b = 1
    // else if operators are different, (operandB thisOperator operandC/D (depending on which one is not the complement))
    // eg. a+(!a.b) = a+b // a.(!a+b) = a.b
    if (subOperandC == operandB | subOperandD == operandB) {
      if (subOperatorA == thisOperator) {
        return operandA;
      } else {
        return operandB;
      }
    } else if (("!" + subOperandC == operandB) | ("!" + subOperandD == operandB) | (subOperandC == "!" + operandB) | (subOperandD == "!" + operandB)) {
      if (subOperatorA == thisOperator) {
        if (thisOperator == '.') {
          return "0";
        } else {
          return "1";
        }
      } else {
        if ("!" + subOperandC == operandB | subOperandC == "!" + operandB) {
          return "(" + operandB + thisOperator + subOperandD + ")";
        } else {
          return "(" + operandB + thisOperator + subOperandC + ")";
        }
      }
    }
  }
  
  return expression;   // if no simplifications made, return expression as received
}

// ****************************************

// function to simplify expressions using De Morgan's Theorem
std::string deMorganLaws (std::string expression) {

  // initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // if both operands are inverted
  // invert the whole expression and swap the operator (AND for OR and vice versa)
  // eg. (!a.!b) = !(a+b) // (!a+!b) = !(a.b)
  if (operandA[0] == '!' & operandB[0] == '!') {
    operandA.erase(0, 1);
    operandB.erase(0, 1);
    if (thisOperator == '.') {
      if (expression[0] == '!') {
        return "(" + operandA + "+" + operandB + ")";
      } else {
        return "!(" + operandA + "+" + operandB + ")";
      }
    } else {
      if (expression[0] == '!') {
        return "(" + operandA + "." + operandB + ")";
      } else {
        return "!(" + operandA + "." + operandB + ")";
      }
    }
  }
  
  return expression;   // if no simplifications made, return expression as received
}

// ****************************************

// function to expand expressions using De Morgan's Theorem
// opposite to previous function
// only used in distributive and absorption simplification
std::string inverseDeMorganLaws (std::string expression) {

  // initialise variables
  int operatorPos = findLeastPrecedentOperator (expression);
  int openBracketPos = expression.find("(");
  int closedBracketPos = expression.length() -1;
  
  char thisOperator = expression[operatorPos];
  std::string operandA = expression.substr(openBracketPos +1, operatorPos - (openBracketPos +1));
  std::string operandB = expression.substr(operatorPos +1, closedBracketPos - (operatorPos +1));

  // if the expression is inverted
  // invert both operands and swap the operator (AND for OR and vice versa)
  // eg. !(a+b) = (!a.!b) // !(a.b) = (!a+!b)
  if (expression[0] == '!') {
    if (operandA[0] == '!') {
      operandA.erase(0, 1);
    } else {
      operandA.insert(0, "!");
    }
    
    if (operandB[0] == '!') {
      operandB.erase(0, 1);
    } else {
      operandB.insert(0, "!");
    }
    
    if (thisOperator == '.') {
      return "(" + operandA + "+" + operandB + ")";
    } else {
      return "(" + operandA + "." + operandB + ")";
    }
  }
  
  return expression;   // if no simplifications made, return expression as received
}