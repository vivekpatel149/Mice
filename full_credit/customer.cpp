#include"customer.h"

Customer::Customer(std::string _name, std::string _phone,std::string _Id): Person(_name , _phone , _Id), name{_name}, phone{_phone}, id{_Id}, total{0}{}

 void Customer::add_total(double _total){total +=_total;}
 double Customer::total_order(){return total;}
 //std::string Customer::type() override{return "customer";}

