#include "LOGIC.h"

void LOGIC::AND() {
  LOGIC foo;
  foo.inputAND();
  foo.operateAND();
  foo.outputAND();
}

void LOGIC::OR() {
  LOGIC foo;
  foo.inputOR();
  foo.operateOR();
  foo.outputOR();
}

void LOGIC::NOT() {
  LOGIC foo;
  foo.inputNOT();
  foo.operateNOT();
  foo.outputNOT();
}

void LOGIC::XOR() {
  LOGIC foo;
  foo.inputXOR();
  foo.operateXOR();
  foo.outputXOR();
}

void LOGIC::NOR() {
  LOGIC foo;
  foo.inputNOR();
  foo.operateNOR();
  foo.outputNOR();
}

void LOGIC::XNOR() {
  LOGIC foo;
  foo.inputXNOR();
  foo.operateXNOR();
  foo.outputXNOR();
}

void LOGIC::NAND() {
  LOGIC foo;
  foo.inputNAND();
  foo.operateNAND();
  foo.outputNAND();
}
