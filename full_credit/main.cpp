#include"windows.h"
#include<iostream>
#include<gtkmm.h>
#include"emporium.h"
#include"manager.h"
#include"customer.h"
#include"server.h"
#include"create.h"
using namespace std;
int it_is_server(vector<Server> manage);
int choose_role();
int it_is_manager(vector<Manager> manage);
int it_is_customer(vector<Customer> customer,Emporium &empo);
int it_is_owner(vector<Owner> manage);

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "edu.uta.project.ice");
  Emporium empo{};
  empo.get_data();
  bool choice = true;
  while(choice)
  {
   int role = choose_role();
   if(role == 0)
   {
      Gtk::MessageDialog *message = Gtk::manage(new Gtk::MessageDialog{"THANKYOU FOR VISITING MAV'S ICREAM EMPORIUM\nHAVE A GREAT DAY:):):):)"});
       message->run();
       message->close(); 
       choice = false;
   }
   else if(role == 4)
   {
     int  position = it_is_owner(empo.get_owner());
      if(position == -1)
      {
        choice = true;
      }
      else 
      {
        empo.get_data();
        cout <<"\nThe position of the owner is "<<to_string(position)<<"  "<<(empo.get_manager())[position].get_name()<<endl;
        Windows win(empo, "owner", position);
        win.set_title("Mav's Ice CREAM EMPORIUM OWNER WINDOW");
        app->run(win);
      }
   }
   else if( role == 1)
   {
      int  position = it_is_manager(empo.get_manager());
      if(position == -1)
      {
        choice = true;
      }
      else 
      {
        empo.get_data();
        cout <<"\nThe position of the manager is "<<to_string(position)<<"  "<<(empo.get_manager())[position].get_name()<<endl;
        Windows win(empo, "manager", position);
        win.set_title("Mav's Ice CREAM EMPORIUM MANAGER WINDOW");
        app->run(win);
      }
   }
   else if( role == 2)
   {
      int  position = it_is_server(empo.get_server());
      if(position == -1)
      {
        choice = true;
      }
      else 
      {
        empo.get_data();
        cout <<"\nThe position of the server is "<<to_string(position)<<"  "<<(empo.get_server())[position].get_name()<<endl;
        Windows win(empo, "server", position);
        win.set_title("Mav's Ice CREAM EMPORIUM SERVER WINDOW");
        app->run(win);
      }
   }
   else if( role == 3)
   {
      int  position = it_is_customer(empo.get_customer(), empo);
      if(position == -1)
      {
        choice = true;
      }
      else if(position == -2) 
      {
        empo.get_data();
        cout <<"\nThe position of the customer is "<<to_string(position)<<"  "<<(empo.get_customer())[position].get_name()<<endl;
        Windows win(empo, "customer", (empo.get_customer().size()-1));
        win.set_title("Mav's Ice CREAM EMPORIUM CUSTOMER WINDOW");
        app->run(win);
      }
      else if(position == -3)
      {
        Windows win(empo, "customer", (empo.get_customer().size()-1));
        win.set_title("Mav's Ice CREAM EMPORIUM CUSTOMER WINDOW");
        app->run(win);
      }
      else 
      {
        Windows win(empo, "customer", position);
        win.set_title("Mav's Ice CREAM EMPORIUM CUSTOMER WINDOW");
        app->run(win);
      }
   }
  
  }
  return 0;
}

int choose_role()
{
 Gtk::Dialog *dialog= Gtk::manage(new Gtk::Dialog());
  dialog->set_default_size(200,100);
  dialog->set_title("Mav's Ice CREAM EMPORIUM Person ROLE");
  dialog->add_button("Exit",0);
  dialog->add_button("Owner",4);
  dialog->add_button("MANAGER",1);
  dialog->add_button("SERVER",2);
  dialog->add_button("CUSTOMER",3);
  dialog->show_all();
  int result = dialog->run();
    
  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
  return result;
}
int it_is_owner(vector<Owner> manage)
{  bool choice = true;
   while(choice)
   {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("OWNER LOGIN");
    
    
    // Inputing the name of the item
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("OWNER ID:"));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

    //Asking for the phone of the item 
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("OWNER LOGIN_PASS"));
    l_phone->set_width_chars(30);
    b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
    e_phone->set_max_length(50);
    e_phone->set_invisible_char('*');
    e_phone->set_visibility(false);
    b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
   
    dialog->add_button("PREVIOUS MENU", 0);
    dialog->add_button("CONTINUE",1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    if(result == 1)
    {
      string id = e_name->get_text();
      string pass = e_phone->get_text();
      for(int i = 0;i<manage.size();i++)
      { 
          string ID = manage[i].get_id();
          string Pass = manage[i].get_pass();
          cout << ID<<" :: ID  "<<Pass<<" ::PASS  "<<manage[i].get_phone()<<"::phone"<<manage[i].get_name()<<"\n"<<endl ;
          if(id == ID && pass == Pass)
           { return i;choice = false; break;} 
       }
       Gtk::MessageDialog *message = Gtk::manage(new Gtk::MessageDialog{"**Login ERROR!!!! Try Again**"});
       message->run();
       message->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    }
    else {choice = false;return -1;}
   }
}
int it_is_manager(vector<Manager> manage)
{  bool choice = true;
   while(choice)
   {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("MANAGER LOGIN");
    
    
    // Inputing the name of the item
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("MANAGER ID:"));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

    //Asking for the phone of the item 
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("MANAGER LOGIN_PASS"));
    l_phone->set_width_chars(30);
    b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
    e_phone->set_max_length(50);
    e_phone->set_invisible_char('*');
    e_phone->set_visibility(false);
    b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
   
    dialog->add_button("PREVIOUS MENU", 0);
    dialog->add_button("CONTINUE",1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    if(result == 1)
    {
      string id = e_name->get_text();
      string pass = e_phone->get_text();
      for(int i = 0;i<manage.size();i++)
      { 
          string ID = manage[i].get_id();
          string Pass = manage[i].get_pass();
          cout << ID<<" :: ID  "<<Pass<<" ::PASS  "<<manage[i].get_phone()<<"::phone"<<manage[i].get_name()<<"\n"<<endl ;
          if(id == ID && pass == Pass)
           { return i;choice = false; break;} 
       }
       Gtk::MessageDialog *message = Gtk::manage(new Gtk::MessageDialog{"**Login ERROR!!!! Try Again**"});
       message->run();
       message->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    }
    else {choice = false;return -1;}
   }
}

int it_is_server(vector<Server> manage)
{

 bool choice = true;
   while(choice)
   {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("SERVER LOGIN");
    
    
    // Inputing the name of the item
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("SERVER ID:"));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

    //Asking for the phone of the item 
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("SERVER LOGIN_PASS"));
    l_phone->set_width_chars(30);
    b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
    e_phone->set_max_length(50);
    e_phone->set_invisible_char('*');
    e_phone->set_visibility(false);
    b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
   
    dialog->add_button("PREVIOUS MENU", 0);
    dialog->add_button("CONTINUE",1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    if(result == 1)
    {
      string id = e_name->get_text();
      string pass = e_phone->get_text();
      for(int i = 0;i<manage.size();i++)
      {
          string ID = manage[i].get_id();
          string Pass = manage[i].get_pass();
          cout << "\n"<<ID<<" :: ID  "<<Pass<<" ::PASS  "<<manage[i].get_phone()<<"::phone"<<manage[i].get_name()<<endl ;
          if(id == manage[i].get_id() && pass == manage[i].get_pass())
           { return i; choice = false;break;} 
       }
       Gtk::MessageDialog *message = Gtk::manage(new Gtk::MessageDialog{"**Login ERROR!!!! Try Again**"});
       message->run();
       message->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    }
    else {choice = false;return -1;}
   }

}

int it_is_customer(vector<Customer> customer, Emporium &empo)
{ 
  int result;
  bool choice = true;
  bool choices =true;
  while(choice)
  {
  choices = true;
  Gtk::Dialog *dialog= Gtk::manage(new Gtk::Dialog());
  dialog->set_default_size(200,100);
  dialog->set_title("Mav's Ice CREAM EMPORIUM CUSTOMER AREA");
  dialog->add_button("PREVIOUS MENU",0);
  dialog->add_button("NEW CUSTOMER",2);
  dialog->add_button("OLD CUSTOMER",1);
  dialog->add_button("CONTINUE AS A GUEST",3);
  dialog->show_all();
  int result = dialog->run();
    
  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
   if(result==0){choice = false; return -1;}
   else if(result ==1)
   {
      while(choices)
     {
      Gtk::Dialog *dialog = new Gtk::Dialog();
      dialog->set_title("Mav's Ice CREAM EMPORIUM CUSTOMER INFO");
    
    
      // Inputing the name of the item
      Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
      Gtk::Label *l_name = Gtk::manage (new Gtk::Label("CUSTOMER NAME:"));
      l_name->set_width_chars(30);
      b_name->pack_start(*l_name, Gtk::PACK_SHRINK);
 
      Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
      e_name->set_max_length(50);
      b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
      dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

      //Asking for the phone of the item 
      Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);
   
      Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("CUSTOMER PHONE:"));
      l_phone->set_width_chars(30);
      b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);
 
      Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
      e_phone->set_max_length(50);
      b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
      dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
   
      dialog->add_button("PREVIOUS MENU", 0);
      dialog->add_button("CONTINUE",1);
      dialog->show_all();
      int result = dialog->run();
    
      dialog->close();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
      if(result == 1)
      {
        string id = e_name->get_text();
        string pass = e_phone->get_text();
        for(int i = 0;i<customer.size();i++)
        {
             string ID = customer[i].get_name();
          string Pass = customer[i].get_phone();
          cout << "\n"<<ID<<" :: ID  "<<Pass<<" ::PASS  "<<endl ;
         
            if(id == customer[i].get_name() && pass == customer[i].get_phone())
             { return i; choice = false;choices =false;break;} 
        } 
        Gtk::MessageDialog *message = Gtk::manage(new Gtk::MessageDialog{"**Login ERROR!!!! Try Again**"});
        message->run();
        message->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
      }
      else {choices = false;}
    }
   }
   else if(result == 2)
   {
     Create create{empo};
     Customer custom= create.create_new_customer();
     empo.update_customer(custom);
     if(custom.get_name() == "")
     {
       Customer customs{"guest","guest","customer"};
       empo.update_customer(customs);
       return -3;
     }
     choice = false;return -2;
  }
   else if(result == 3) 
   {
      Customer customs{"guest","guest","customer"};
      empo.update_customer(customs);
     choice = false;
     return -3;
   }
  }
}

