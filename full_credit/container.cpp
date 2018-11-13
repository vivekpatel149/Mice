#include "container.h"

Containerss::Containerss(std::string name, std::string description, double cost, double price,
              int max_scoops)
          : Item(name, description, cost, price), _max_scoops{max_scoops} { }
std::string Containerss::type() {return "Container";}
int Containerss::max_scoops() {return _max_scoops;}
