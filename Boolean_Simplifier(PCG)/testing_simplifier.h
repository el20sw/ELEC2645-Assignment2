#ifndef TESTING_SIMPLIFIER_H
#define TESTING_SIMPLIFIER_H

#include <iostream>
#include <string>

#include "boolean_simplifier.h"

// declaring functions
void runAllTests (void);
void testDoubleNegationLaw (std::string, std::string);
void testZeroAndUnitLaws (std::string, std::string);
void testIdempotenceAndComplementLaws (std::string, std::string);
void testCommutativeLaws (std::string, std::string);
void testDistributiveLaws (std::string, std::string);
void testAbsorptionLaws (std::string, std::string);
void testDeMorganLaws (std::string, std::string);
void testInverseDeMorganLaws (std::string, std::string);

#endif