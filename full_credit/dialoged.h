#ifndef _DIALOGED_H
#define _DIALOGED_H

#include<gtkmm.h>
#include<exception>

class Dialoged
{
public:
 Dialoged(std::string type,std::string message);
 std::string get_name();
 std::string get_description();
 double get_cost();
 double get_price();
 int get_max_scoop();
 
private:
 std::string name;
 std::string description;
 double cost;
 double price;
 std::string _type;
 int max_scoops;
};
#endif
