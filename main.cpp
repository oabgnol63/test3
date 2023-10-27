#include "interface.cpp"

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
   while(1)
   {
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
   _loop = interface(_cs, _it, _ord);
   if(_loop == 0 || _loop ==2) return 0;
   }
}