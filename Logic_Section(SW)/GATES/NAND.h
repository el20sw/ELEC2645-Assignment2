#ifndef NAND_H
#define NAND_H

#include "NOT.h"
#include "AND.h"
#include "GATE.h" 

class NAND : virtual public AND, virtual public NOT {
  public:
    void inputNAND();
    void set_inputNAND(bool input1, bool input2);
    bool operateNAND();
    void outputNAND();
    bool get_outputNAND();

  private:
    bool _input;
    bool _input1;
    bool _input2;
    bool _output;
    int output;
};

#endif

