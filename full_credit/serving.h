#ifndef _SERVING_H
#define _SERVING_H
#include<vector>
#include"container.h"
#include"scoop.h"
#include"topping.h"
#include<string>
#include<iostream>
using namespace std;
class Serving
{
 public:
 Serving(Containerss contain, vector<Scoop> scoops, vector<Topping> toppings);
 //Serving() {}
 string get_serving();
 double serving_total();
 double serving_cost();
 bool serving_consume();
 private:
 Containerss container;
 vector<Scoop> scoop;
 vector<Topping> topping;
};

#endif
