#ifndef LOGIC_SUB_SECTION_H
#define LOGIC_SUB_SECTION_H

#include <iostream>
#include <regex>

#include "../headers/common.h"
#include "LOGIC.h"
#include "TOOLS.h"
#include "testing.h"

//declare functions
void logic_gate_menu();
void print_logic_menu();
int logic_menu_selection();
void select_logic_menu_item(int input);
void go_back_to_logic_menu();
void menu_AND();
void menu_OR();
void menu_XOR();
void menu_NOR();
void menu_XNOR();
void menu_NOT();
void menu_NAND();
bool is_integer(std::string num);

void menu_TOOLS();
void print_tools_menu();
int tools_menu_selection();
void select_tool_item(int input);
void go_back_to_tools_menu();
void half_adder_tool();
void full_adder_tool();

void menu_TESTS();

#endif