#include"serving.h"
using namespace std;
Serving::Serving(Containerss contain, vector<Scoop> scoops, vector<Topping> toppings): container{contain}, scoop{scoops}, topping{toppings}{}

string Serving::get_serving()
{
   string s_choice = "Container:  "+container.name()+"  " +to_string(container.price())+"\n";
   for(int i=0;i<scoop.size();i++)
   {
    s_choice =s_choice+  "Scoop:  "+ scoop[i].name() +"  "+to_string(scoop[i].price())+"\n";
   }   
   for(int i=0;i<topping.size();i++)
  {
    s_choice =s_choice+ "Topping:  "+ topping[i].name()+" " +to_string(topping[i].price())+"\n";
  }   
  
  s_choice = s_choice+  "Your Total for Serving is $ "+ to_string(serving_total())+"\n";
  return s_choice;

}

bool Serving::serving_consume()
{
 bool con = true;
 container.consume(1);if(container.quantity() >= 0){ con = true;} else { con = false; return con;}
 for(int i=0;i<scoop.size();i++)
  {cout<<to_string(scoop[i].quantity())<<endl; scoop[i].consume(1); cout<<"\n"<<to_string(scoop[i].quantity())<<endl;if(scoop[i].quantity() >=0){ con = true;} else { con = false; return con;}}
 for(int i=0;i<topping.size();i++){ int amount=topping[i].amount();cout<<"\n"<<to_string(topping[i].quantity())<<endl; topping[i].consume(amount);cout<<"\n"<<to_string(topping[i].quantity())<<endl; if(topping[i].quantity() >=0){ con = true;} else { con = false; return con;}}
 return con;
}

double Serving::serving_total()
{
double total_price = container.price();
  for(int i=0;i<scoop.size();i++)
  {
   total_price += scoop[i].price();
  }   
  for(int i=0;i<topping.size();i++)
  {
   int amount=topping[i].amount();
   total_price += (topping[i].price()*((double) amount));
  }
  return total_price;
}


double Serving::serving_cost()
{
double total_cost = container.cost();
  for(int i=0;i<scoop.size();i++)
  {
   total_cost += scoop[i].cost();
  }   
  for(int i=0;i<topping.size();i++)
  {
   total_cost += topping[i].cost();
  }
  return total_cost;
}
