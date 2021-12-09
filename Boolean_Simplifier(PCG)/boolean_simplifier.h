#ifndef BOOLEAN_SIMPLIFIER_H
#define BOOLEAN_SIMPLIFIER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "testing_simplifier.h"

// delcaring functions
void booleanSimplifierSubMenu (void);
void printSubMenu (void);
std::string selectMenuItem (void);

void simplifyExpression (void);
bool validateExpression (std::string);
int countOccurences (std::string, std::string);
int findLeastPrecedentOperator (std::string);
std::string iterativeSimplification (std::string);
std::string checkForSimplifications (std::string);

std::string doubleNegationLaw (std::string);
std::string zeroAndUnitLaws (std::string);
std::string idempotenceAndComplementLaws (std::string);
std::string commutativeLaws (std::string);
std::string distributiveLaws (std::string);
std::string absorptionLaws (std::string);
std::string deMorganLaws (std::string);
std::string inverseDeMorganLaws (std::string);

#endif