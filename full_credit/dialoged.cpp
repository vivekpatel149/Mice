#include"dialoged.h"

Dialoged::Dialoged(std::string type,std::string message): _type{type}
{
    
    int container = 0;
   
  
      Gtk::Dialog *dialog = new Gtk::Dialog();
      dialog->set_title(message);
        
      // Inputing the name of the item
      Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);
    
      Gtk::Label *l_name = Gtk::manage (new Gtk::Label("NAME:"));
      l_name->set_width_chars(30);
      b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

      Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
      e_name->set_max_length(50);
      b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
      dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);

    //Asking for the description of the item 
    Gtk::HBox *b_description = Gtk::manage (new Gtk::HBox);
    Gtk::Label *l_description = Gtk::manage (new Gtk::Label("Describe the Item"));
    l_description->set_width_chars(30);
    b_description->pack_start(*l_description, Gtk::PACK_SHRINK);
   
    //Input description
   
    Gtk::Entry *e_describe =Gtk::manage (new Gtk::Entry{});
    e_describe->set_max_length(400);
    b_description->pack_start(*e_describe, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_description, Gtk::PACK_SHRINK);
    
    //Asking for cost of the item
    Gtk::HBox *b_cost = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_cost = Gtk::manage (new Gtk::Label("Cost "));
    l_cost->set_width_chars(30);
    b_cost->pack_start(*l_cost, Gtk::PACK_SHRINK);

    Gtk::Entry *e_cost = Gtk::manage (new Gtk::Entry{});
    e_cost->set_max_length(50);
    b_cost->pack_start(*e_cost, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_cost, Gtk::PACK_SHRINK);
   
    //Asking for Price of the item
    Gtk::HBox *b_price = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_price = Gtk::manage (new Gtk::Label("Price "));
    l_price->set_width_chars(30);
    b_price->pack_start(*l_price, Gtk::PACK_SHRINK);

    Gtk::Entry *e_price = Gtk::manage (new Gtk::Entry{});
    e_price->set_max_length(50);
    b_price->pack_start(*e_price, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_price, Gtk::PACK_SHRINK);
   
    //If type is containner 
    Gtk::HBox *b_max_scoop = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_max_scoop = Gtk::manage (new Gtk::Label("Max Scoop in Container:"));
    l_max_scoop->set_width_chars(30);
    b_max_scoop->pack_start(*l_max_scoop, Gtk::PACK_SHRINK);

    Gtk::Entry *e_max_scoop = Gtk::manage (new Gtk::Entry{});
    e_max_scoop->set_max_length(50);
    b_max_scoop->pack_start(*e_max_scoop, Gtk::PACK_SHRINK);
    if(type == "Container")
    {
      dialog->get_vbox()->pack_start(*b_max_scoop, Gtk::PACK_SHRINK);
      container = 1;
    }
    
    // Buttons for Gui
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);
    dialog->show_all();
    int results = 0;
   while(!results)
    {
        
       if(dialog->run() == 1) 
       {
          name = e_name->get_text();
          description = e_describe->get_text();
          std::string coste = e_cost->get_text();
          std::string pricee = e_price->get_text();
          std::string max_scoop;
          if(container == 1)
          {
            max_scoop = e_max_scoop->get_text();
          }
          try 
          {
            price = std::stod(pricee);
            results =1;
          }
          catch (...)
          {
            e_price->set_text("**Invalid Format***");
            // Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"**INVALID FORMAT**\n!!!Please try AGAIN"});
           // message->run();
           //  message->close();
           results = 0;
          }
          if( name == "" || name == "**Name cannot be NULL***" )
          {
             e_name->set_text("**Name cannot be NULL***");
             results = 0;
          }  
          if(description == "" || description == "**Please Describe the Item**")
          {
             e_describe->set_text("**Please Describe the Item**");
            // Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"**INVALID FORMAT**\n!!!Please try AGAIN"});
            //   message->run();
            //     message->close();
            results = 0;
          }
          try
          {
              cost = std::stod(coste);
           }
          catch (...)
          {
             e_cost->set_text("**INVALID COST FORMAT**");
           // Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"**INVALID FORMAT**\n!!!Please try AGAIN"});
           //  message->run();
           //  message->close();
            results = 0;
          }
          if(type == "Container")
          {
              try
              {
                 max_scoops = std::stod(max_scoop);
              }
              catch (...)
              {
                   e_max_scoop->set_text("**INVALID MAX SCOOP*");
                    // Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"**INVALID FORMAT**\n!!!Please try AGAIN"});
        // m essage->run();
        //  message->close();
                 results = 0;
              }
           }
           if(results == 1)
          {
             dialog->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
          }    
       }
       else// if(dialog->run() == 0)
        {
          results = 1; 
          dialog->close();
          while (Gtk::Main::events_pending())  Gtk::Main::iteration();
          break;
        }
   }
}

std::string Dialoged::get_name(){return name;}
std::string Dialoged::get_description(){return description;}
double Dialoged::get_cost(){return cost;}
double Dialoged::get_price(){return price;}
int Dialoged::get_max_scoop(){return max_scoops;}

