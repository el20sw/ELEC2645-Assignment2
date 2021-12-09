#include "Headers/main_menu.h"

void main_menu() {
  do {
    choice_logic = 0;
    print_main_menu();
    int input = get_user_input();
    choice_main = input;
    select_menu_item(input);
  } while (choice_main != 3);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 3;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);

    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {
      input = std::stoi(input_string);
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      logic_sub_menu();
      break;
    case 2:
      boolean_simplifier_sub_menu();
      break;
    case 3:
      exit(1);
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n>> Main Menu\n";
  std::cout << "\n----------- Select An Option ------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Logic Gates and Tools\t\t\t|\n";
  std::cout << "|\t2. Boolean Expression Simplifier\t|\n";
  std::cout << "|\t3. Exit Program\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-----------------------------------------\n";
}

void logic_sub_menu() {
  logic_gate_menu();
}

void boolean_simplifier_sub_menu() {
  booleanSimplifierSubMenu ();
}