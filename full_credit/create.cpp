#include"create.h"
using namespace std;
Create::Create(Emporium& _empo):empo{_empo},scoops{empo.get_scoop()}, toppings{empo.get_topping()}, containers{empo.get_container()}{}

Manager Create::create_new_manager()
{
  int perfect = 1;
  string phone,name,id;
  int done =0;
  while(perfect)
  {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("CREATE NEW MANAGER");
    
    
    // Inputing the name of the item
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("MANAGER NAME:"));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

    //Asking for the phone of the item 
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("MANAGER PHONE NUMBER"));
    l_phone->set_width_chars(30);
    b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
    e_phone->set_max_length(50);
    b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
   
    //Asking for the MAnager ID
    
    Gtk::HBox *b_id = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_id = Gtk::manage (new Gtk::Label("MANAGER NEW ID"));
    l_id->set_width_chars(30);
    b_id->pack_start(*l_id, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_id = Gtk::manage (new Gtk::Entry{});
    e_id->set_max_length(50);
    b_id->pack_start(*e_id, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_id, Gtk::PACK_SHRINK);
     
    dialog->add_button("Cancel", 0);
    dialog->add_button("ADD MANAGER",1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    if(result == 0)
    {
         perfect = 0;break;
    }
    else
    {
      name = e_name->get_text();
      phone = e_phone->get_text();
      id = e_id->get_text();
      if(name == "" || phone == "" || id == "")
       {
          Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"**INVALID FORMAT**\n!!!Please Fill ALL THE Details"});
          message->run();
          message->close();
          while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
          perfect = 1;
       }     
       else {perfect = 0;done = 1;}
    }
  }
  if(done ==1)
  {
   Manager manage{name,phone,id};
   manage.generate_login();
   empo.update_manager(manage);
   return manage;
  }
  else {Manager managed{"","",""}; return managed;}
}


Server Create::create_new_server()
{
  int perfect = 1;
  string phone,name,id;
  int done =0;
  while(perfect)
  {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("CREATE NEW SERVER");
    
    
    // Inputing the name of the item
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("SERVER NAME:"));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

    //Asking for the phone of the item 
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("SERVER PHONE NUMBER"));
    l_phone->set_width_chars(30);
    b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
    e_phone->set_max_length(50);
    b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
   
    //Asking for the SERVER ID
    
    Gtk::HBox *b_id = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_id = Gtk::manage (new Gtk::Label("SERVER NEW ID"));
    l_id->set_width_chars(30);
    b_id->pack_start(*l_id, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_id = Gtk::manage (new Gtk::Entry{});
    e_id->set_max_length(50);
    b_id->pack_start(*e_id, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_id, Gtk::PACK_SHRINK);
     
    dialog->add_button("Cancel", 0);
    dialog->add_button("ADD SERVER",1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    if(result == 0)
    {
         perfect = 0;break;
    }
    else
    {
      name = e_name->get_text();
      phone = e_phone->get_text();
      id = e_id->get_text();
      if(name == "" || phone == "" || id == "")
       {
          Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"**INVALID FORMAT**\n!!!Please Fill ALL THE Details"});
          message->run();
          message->close();
          while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
          perfect = 1;
       }     
       else {perfect = 0;done = 1;}
    }
  }
  if(done ==1)
  {
   Server manage{name,phone,id};
   manage.genrate_login();
   empo.update_server(manage);
   return manage;
  }
  else {Server managed{"","",""}; return managed;}
}


Customer Create::create_new_customer()
{
  int perfect = 1;
  string phone,name,id;
  int done =0;
  while(perfect)
  {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("CREATE NEW CUSTOMER");
    
    
    // Inputing the name of the item
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("Customer NAME:"));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

    //Asking for the phone of the item 
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);
   
    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("Customer PHONE NUMBER"));
    l_phone->set_width_chars(30);
    b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);
 
    Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
    e_phone->set_max_length(50);
    b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
   
     
    dialog->add_button("Cancel", 0);
    dialog->add_button("ADD Customer",1);
    dialog->show_all();
    int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    if(result == 0)
    {
         perfect = 0;break;
    }
    else
    {
      name = e_name->get_text();
      phone = e_phone->get_text();
      id = "customer";
      if(name == "" || phone == "" || id == "")
       {
          Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"**INVALID FORMAT**\n!!!Please Fill ALL THE Details"});
       message->run();
       message->close();
         while (Gtk::Main::events_pending())  Gtk::Main::iteration(); perfect = 1;
       }     
       else {perfect = 0;done = 1;}
    }
  }
  if(done ==1)
  {
   Customer manage{name,phone,id};
   empo.update_customer(manage);
   return manage;
  }
  else {Customer managed{"","",""}; return managed;}
}

void Create::create_new_order()
{
}
