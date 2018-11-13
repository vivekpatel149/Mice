#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include"person.h"
class Customer: public Person
{
  public:
  Customer(std::string _name, std::string _phone,std::string _Id);
  //std::string type() override;
  void add_total(double _total);
  double total_order();
  
  private:
  double total;
  std::string name;
  std::string phone;
  std::string id;
  //std::string types;
  
};
#endif
