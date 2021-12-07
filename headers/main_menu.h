#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include <regex>

#include "common.h"
#include "../Logic_Section(SW)/logic_sub_section.h"

void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
void logic_sub_menu();
//void scott_sub_menu();
//void pablo_sub_menu();

#endif