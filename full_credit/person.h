#ifndef _PERSON_H
#define _PERSON_H
#include<string>
class Person
{
 public:
 Person(std::string _name,std::string _phone, std::string _Id);
 //Person(std::string _name,std::string _phone);
 virtual ~Person();

 std::string get_name();
 std::string get_phone();
 //virtual std::string type();
 std::string get_id();

 private:
 std::string name;
 //std::string types;
 std::string Id;
 std::string phone;
};
#endif
 
 
