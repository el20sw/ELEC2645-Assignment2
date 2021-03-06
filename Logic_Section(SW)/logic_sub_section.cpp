#include "logic_sub_section.h"

// Logic Gate Menu Function
void logic_gate_menu() {
  do {
    choice_logic_tools = 0;
    print_logic_menu();
    int input = logic_menu_selection();
    choice_logic = input;
    select_logic_menu_item(input);
  } while (choice_logic != 10);
}

// Function to Print Logic Menu to Console
void print_logic_menu() {
  std::cout << "\n>> Logic Sub-Menu\n";
  std::cout << "\n----------- Select An Option ------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. AND\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t2. OR\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t3. XOR\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t4. NOR\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t5. XNOR\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t6. NOT\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t7. NAND\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t8. TOOLS\t\t\t\t\t\t\t|\n";
  std::cout << "|\t9. Run All Tests\t\t\t\t\t|\n";
  std::cout << "|\t10. Return to Main Menu\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-----------------------------------------\n";
}

// Function to get user menu selection - LOGIC main
int logic_menu_selection() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 10;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
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

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

// Function to run selected menu functions
void select_logic_menu_item(int input) {
  switch(input) {
    case 1:
      menu_AND();
      break;
    case 2:
      menu_OR();
      break;
    case 3:
      menu_XOR();
      break;
    case 4:
      menu_NOR();
      break;
    case 5:
      menu_XNOR();
      break;
    case 6:
      menu_NOT();
      break;
    case 7:
      menu_NAND();
      break;
    case 8:
      menu_TOOLS();
      break;
    case 9:
      menu_TESTS();
      break;
    case 10:
      break;
    default:
      break;
  }
}

// Function to return to previous menu
void go_back_to_logic_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to return to menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  logic_gate_menu();
}

// AND Menu option
void menu_AND() {
  std::cout << "\n>> AND Gate\n";
  LOGIC logic;
  logic.AND();
  go_back_to_logic_menu();
}

// OR Menu option
void menu_OR() {
  std::cout << "\n>> OR Gate\n";
  LOGIC logic;
  logic.OR();
  go_back_to_logic_menu();
}

// XOR Menu option
void menu_XOR() {
  std::cout << "\n>> XOR Gate\n";
  LOGIC logic;
  logic.XOR();
  go_back_to_logic_menu();
}

// NOR Menu option
void menu_NOR() {
  std::cout << "\n>> NOR Gate\n";
  LOGIC logic;
  logic.NOR();
  go_back_to_logic_menu();
}

// XNOR Menu option
void menu_XNOR() {
  std::cout << "\n>> XNOR Gate\n";
  LOGIC logic;
  logic.XNOR();
  go_back_to_logic_menu();
}

// NOT Menu option
void menu_NOT() {
  std::cout << "\n>> NOT Gate\n";
  LOGIC logic;
  logic.NOT();
  go_back_to_logic_menu();
}

// NAND Menu option
void menu_NAND() {
  std::cout << "\n>> NAND Gate\n";
  LOGIC logic;
  logic.NAND();
  go_back_to_logic_menu();
}

// TOOLS Menu option
void menu_TOOLS() {
  do {
    print_tools_menu();
    int input = tools_menu_selection();
    choice_logic_tools = input;
    select_tool_item(input);
  } while (choice_logic_tools != 3);
}

// Testing Menu option
void menu_TESTS() {
  run_tests();
  go_back_to_logic_menu();
}


// Function to print TOOLS sub-menu
void print_tools_menu() {
  std::cout << "\n>> Tools Sub-Menu\n";
  std::cout << "\n----------- Select An Option ------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Half-Adder\t\t\t\t\t\t|\n";
  std::cout << "|\t2. Full-Adder\t\t\t\t\t\t|\n";
  std::cout << "|\t3. Return to Logic Sub-Menu\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-----------------------------------------\n";
}

// Function to get user menu selection - TOOLS sub-menu
int tools_menu_selection() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 3;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
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

// Function that returns user to TOOLS sub-menu
void go_back_to_tools_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to return to menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  menu_TOOLS();
}

// Function to run selected sub-menu functions
void select_tool_item(int input) {
  switch(input) {
    case 1:
      half_adder_tool();
      break;
    case 2:
      full_adder_tool();
      break;
    case 3:
      break;
    default:
      break;
  }
}

// Half-Adder Menu option
void half_adder_tool() {
  bool inputA, inputB, sum, carry_out;

  get_two_input(inputA, inputB);
  half_adder(inputA, inputB, sum, carry_out);
  std::cout << "\nSum = " << sum << "\nCarry Out = " << carry_out << std::endl;
  go_back_to_tools_menu();
}

// Full-Adder Menu option
void full_adder_tool() {
  bool inputA, inputB, carry_in, sum, carry_out;

  get_carry_in(carry_in);
  get_two_input(inputA, inputB);
  full_adder(inputA, inputB, carry_in, sum, carry_out);
  std::cout << "\nSum = " << sum << "\nCarry Out = " << carry_out << std::endl;
  go_back_to_tools_menu();
}