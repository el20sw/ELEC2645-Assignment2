#ifndef LOGIC_H
#define LOGIC_H

#include "GATES/AND.h"
#include "GATES/OR.h"
#include "GATES/NOT.h"
#include "GATES/XOR.h"
#include "GATES/NOR.h"
#include "GATES/XNOR.h"
#include "GATES/NAND.h"

class LOGIC : virtual public AND, virtual public OR, virtual public NOT, virtual public XOR, virtual public NOR, virtual public XNOR, virtual public NAND {
  public:
    void AND();
    void OR();
    void NOT();
    void XOR();
    void NOR();
    void XNOR();
    void NAND();
};

#endif

