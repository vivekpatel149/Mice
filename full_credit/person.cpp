#include"person.h"

Person::Person(std::string _name, std::string _phone, std::string _Id)
     : name{_name}, phone{_phone}, Id{_Id} { }
Person::~Person() { }
 std::string Person::get_name(){return name;}
 std::string Person::get_phone(){return phone;}
 //std::string Person::type(){return types;}
 std::string Person::get_id(){return Id;}
