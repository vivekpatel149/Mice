#ifndef _TOPPING_H
#define _TOPPING_H
#include "item.h"


class Topping : public Item {
  public:
    Topping(std::string name, std::string description, double cost, double price,
              int amount);
    std::string type() override;
    int amount();
    const static int LIGHT_AMOUNT = 1;
    const static int NORMAL_AMOUNT = 2;
    const static int EXTRA_AMOUNT = 3;
    const static int DRENCHED_AMOUNT = 4;
     void _set_amount(int amount);
  private:
  
    int _amount;
};
#endif
