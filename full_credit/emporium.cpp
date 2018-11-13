#include"emporium.h"

using namespace std;

//Emporium::Emporium(){}
vector<Scoop> Emporium::get_scoop(){return scoop;}
vector<Topping> Emporium::get_topping(){return topping;}
vector<Containerss> Emporium::get_container(){return container;}
vector<Server> Emporium::get_server(){return server;}
vector<Customer> Emporium::get_customer(){return customer;}
vector<Order> Emporium::get_order(){return order;}
vector<Manager> Emporium::get_manager(){return manager;}
vector<Owner> Emporium::get_owner(){return owner;}
void Emporium::get_data()
{
 container.clear();
 fstream file;
 int c =0;
 string line;
 string name="",description="",cost = "0",price = "0",quantity="0",max_scoop="0",phone="",id="";
 
 //Getting Conatiner data
 file.open("Container.txt", ios_base::in);
 while(getline(file,line))
 {

  if(c == 0){name = line; c++;}
  else if(c == 1){description = line;c++;}
  else if(c == 2){cost = line;c++;}
  else if(c == 3){price = line;c++;}
  else if(c == 4){max_scoop = line;c++;}
  else if(c == 5)
  {
    quantity = line;
 //   cout<<"name "<<name<<"  descrip   "<<description<<"  cost "<<cost<<"  price "<<price<<"  quantity  "<<quantity<<"  maxscoop "<<max_scoop<<"\n"<<endl;
    try{ double coste = std::stod(cost);
    double pricee = std::stod(price);
    int max_scoope = std::stoi(max_scoop);
    int quantitye = std::stoi(quantity);
    
    Containerss contain{name,description,coste, pricee,max_scoope};
    contain.restock(quantitye);
    container.push_back(contain);
    
    }
    catch(...)
    {cerr<<"Input Mismatch Exception"<<endl;}
    c =0;
  }
 }
 file.close();
 
 // getting Scoop data
 scoop.clear();
 file.open("Scoop.txt", ios_base::in);
 while(getline(file,line))
 {
   if(c == 0){name = line;c++;}
   else if(c == 1){description = line;c++;}
   else if(c == 2){cost = line;c++;}
   else if(c == 3){price = line;c++;}
   else if(c == 4)
   {
      quantity = line;
 //cout<<"name "<<name<<"  descrip   "<<description<<"  cost "<<cost<<"  price "<<price<<"  quantity  "<<quantity<<"\n"<<endl;
       double coste = std::stod(cost);
    double pricee = std::stod(price);
      int quantitye = std::stoi(quantity);
      Scoop contain{name,description,coste, pricee};
      contain.restock(quantitye);
      scoop.push_back(contain);
      c =0;
    }
 }
 file.close();
 manager.clear();
 // getting manager data
 file.open("Manager.txt", ios_base::in);
 c=0;
 while(getline(file,line))
 {
   if(c == 0){name = line;c++;}
   else if(c == 1){phone = line;c++;}
   else if(c == 2){id = line;c++;}
   else if(c == 3)
   {
     price = line;
     cout<<"name "<<name<<"   phone"<<phone<<"    id"<<id<<"   pass"<<price<<"\n"<<endl;
     Manager manage{name,phone,id};
     manage.set_login(price);
     manager.push_back(manage);
     c = 0;
   }
  }
 file.close();
 
 // getting topping data
 topping.clear();
 file.open("Topping.txt", ios_base::in);
 while(getline(file,line))
 {
   if(c == 0){name = line;c++;}
   else if(c == 1){description = line;c++;}
   else if(c == 2){cost = line;c++;}
   else if(c == 3){price = line;c++;}
   else if(c == 4)
   {
     quantity = line;
     //cout<<"name "<<name<<"  descrip   "<<description<<"  cost "<<cost<<"  price "<<price<<"  quantity  "<<quantity<<"\n"<<endl;
         double coste = std::stod(cost);
         double pricee = std::stod(price);
     
     
     
      int quantitye = std::stoi(quantity);
      Topping contain{name,description,coste, pricee,4};
      contain.restock(quantitye);
      topping.push_back(contain);
      c =0;
    }
 }
 file.close();
 server.clear();
 //Getting server data
 file.open("Server.txt", ios_base::in);
 string salary="whats wrong",ord;
 while(getline(file,line))
 {
   
   if(c == 0){name = line;c++;}
   else if(c == 1){phone = line;c++;}
   else if(c == 2){id = line;c++;}
   else if(c == 3){price = line;c++;}
   else if(c == 4){salary = line;c++;}
   else if(c == 5)
   {
    //cout<<"name "<<name<<"   phone"<<phone<<"    id"<<id<<"   pass"<<price<<"   salary  "<<salary<<"\n"<<endl;
     ord = line;
     Server manage{name,phone,id};
     manage.set_login(price);
     manage.set_salary(std::stod(salary));
     manage.set_order(std::stoi(ord));
     server.push_back(manage);
     c = 0;
   }
  }
 file.close();
 customer.clear();
 //getting customer data
 file.open("Customer.txt", ios_base::in);
 while(getline(file,line))
 {
   if(c == 0){ Customer manage{name,phone,id};
     customer.push_back(manage);name = line;if(line !=""){c++;}}
   else if(c == 1)
   { if(line !=""){c = 0;}
     id= "customer";
     phone = line;
    //cout<<"CUSTOMER_name "<<name<<"   phone"<<phone<<"    id"<<id<<"\n"<<endl;
    }
  }
 file.close();
 owner.clear();
 file.open("Owner.txt", ios_base::in);
 c=0;
 while(getline(file,line))
 {
   if(c == 0){name = line;c++;}
   else if(c == 1){phone = line;c++;}
   else if(c == 2){id = line;c++;}
   else if(c == 3)
   {
     price = line;
     cout<<"name "<<name<<"   phone"<<phone<<"    id"<<id<<"   pass"<<price<<"\n"<<endl;
     Owner manage{name,phone,id};
     manage.set_login(price);
     owner.push_back(manage);
     c = 0;
   }
  }
 file.close();
 
}
void Emporium::fill_data()
{
  fstream file;
  try
  {
    //filling conatiner data
        file.open("Container.txt",ios_base::out);
        string line="";
        cout<<line;
        file.close();
    //filing scoop data
        file.open("Scoop.txt",ios_base::out);
        line="";
        cout<<line;
        file.close();
//filling topping data
    
     file.open("Topping.txt",ios_base::out);
     line="";
     cout<<line;
     file.close();
    //filling Manager data
    
     file.open("Manager.txt",ios_base::out);
     line="";
     cout<<line;
     file.close();
    //filling Customer data
    file.open("Customer.txt",ios_base::out);
    line="";
    cout<<line;
    file.close();
    //filling Server data
     file.open("Server.txt",ios_base::out);
     line="";
     cout<<line;
     file.close();
    
  }
  catch(...)
  {
    cerr<<"File not found"<<endl;
  }
}
void Emporium::update_order(Order orders)
{
 order.push_back(orders);
}
void Emporium::update_server(Server servers)
{
 server.push_back(servers);
 fstream file; 
 file.open("Server.txt",ios_base::app);
        string line;
        line=servers.get_name()+"\n";
        file<<line;
        line=servers.get_phone()+"\n";
        file<<line;
        line=servers.get_id()+"\n";
        file<<line;
        line=servers.get_pass()+"\n";
        file<<line;
        line=to_string(servers.salaryi())+"\n";
        file<<line;
        line = to_string(servers.orders())+"\n";
        file<<line;
  file.close();
 
}
void Emporium::update_topping(Topping toppings)
{
 topping.push_back(toppings);
 fstream file;
 file.open("Topping.txt",ios_base::app);
        string line;
        line=toppings.name()+"\n";
        file<<line;
        line=toppings.description()+"\n";
        file<<line;
        line = to_string(toppings.cost())+"\n";
        file<<line;
        line = to_string(toppings.price())+"\n";
        file<<line;
        line = to_string(toppings.quantity())+"\n";
        file<<line;
    file.close();
 
}
void Emporium::update_scoop(Scoop scoops)
{
 scoop.push_back(scoops);
 fstream file;
 file.open("Scoop.txt",ios_base::app);
        string line;
        line=scoops.name()+"\n";
        file<<line;
        line=scoops.description()+"\n";
        file<<line;
        line = to_string(scoops.cost())+"\n";
        file<<line;
        line = to_string(scoops.price())+"\n";
        file<<line;
        line = to_string(scoops.quantity())+"\n";
        file<<line;
    file.close();
}
void Emporium::update_customer(Customer customers)
{
 customer.push_back(customers);
 fstream file; 
 file.open("Customer.txt",ios_base::app);
        string line;
        line=customers.get_name()+"\n";
        file<<line;
        line=customers.get_phone()+"\n";
        file<<line;
  file.close();
 
}
void Emporium::update_container(Containerss containers)
{

 container.push_back(containers);
 fstream file;
 file.open("Container.txt",ios_base::app);
        string line;
        line=containers.name()+"\n";
        file<<line;
        line=containers.description()+"\n";
        file<<line;
        line = to_string(containers.cost())+"\n";
        file<<line;
        line = to_string(containers.price())+"\n";
        file<<line;
        line = to_string(containers.max_scoops())+"\n";
        file<<line;
        line = to_string(containers.quantity())+"\n";
        file<<line;
    file.close();
}
void Emporium::update_manager(Manager managers)
{
 manager.push_back(managers);
 fstream file; 
 file.open("Manager.txt",ios_base::app);
        string line;
        line=managers.get_name()+"\n";
        file<<line;
        line=managers.get_phone()+"\n";
        file<<line;
        line=managers.get_id()+"\n";
        file<<line;
        line=managers.get_pass()+"\n";
        file<<line;
  file.close();
}


