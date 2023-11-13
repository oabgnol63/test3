#include "interface.h"

int main()
{
   int _loop;
   item *a = new item("black king bar",100,500000);
   _it.push_back(*a);
   a = new item("orchil malevolance",100,600000);
   _it.push_back(*a);
   a = new item("divine rapier",100,1000000);
   _it.push_back(*a);
   a = new item("maelstrom",100,750000);
   _it.push_back(*a);
   customer *b = new customer("nguyen van a","TMA","911");
   _cs.push_back(*b);
   delete a; a = NULL;
   delete b; b = NULL;
   int _choice = 0;
   while(1)
   {
      Interface *_inter = new Interface;
      cout << "=============MENU==============\n";
      cout << "1/ New customer\n";
      cout << "2/ New item\n";
      cout << "3/ List all customers\n";
      cout << "4/ List all items\n";
      cout << "5/ List all orders\n";
      cout << "6/ Make a new order\n";
      cout << "7/ Check order by customer's ID\n";
      cout << "0/ Exit\n";
      cout << "===============================\n";
      cout << "Select a function: "; cin >> _choice;
      switch(_choice)
      {
         case 1:
            system("clear");
            _inter->new_customer(&_cs);
            delete _inter; _inter = NULL;
            break;
         case 2:
            system("clear");
            _inter->new_item(&_it);
            delete _inter; _inter = NULL;
            break;
         case 3:
            system("clear");
            _inter->list_all_customer(_cs);
            delete _inter; _inter = NULL;
            break;
         case 4:
            system("clear");
            _inter->list_all_item(_it);
            delete _inter; _inter = NULL;
            break;
         case 5:
            system("clear");
            _inter->list_all_order(_ord);
            delete _inter; _inter = NULL;
            break;
         case 6:
         {
            system("clear");
            _inter->make_new_order(&_it, &_ord, &_cs);
            delete _inter; _inter = NULL;
            break;
         }
         case 7:
         {
             system("clear");
            order *tmp = _inter->check_by_id(_ord);
            delete _inter; _inter = NULL;
            break;
         }
         case 0:
            return 0;
         default:
            return 0;
      }
   }
}