#include "item.h"

vector<item> _it;
int item::i_num = 0;

item::item(string name, int quant, float price)
{
    this->name = name;
    this->quantities = quant;
    this->i_num ++;
    this->id = iPrefix + to_string(this->i_num);
    this->price = price;
}

void item::set_quantities(int n)
{
    this->quantities = n;
}

int item::get_quantities()
{
    return this->quantities;
}

string item::get_name()
{
    return this->name;
}

bool item::new_item()
{
    string _name;
    cout << "Insert item name: "; cin.ignore() ; getline(cin,_name);
    for(auto x : _it)
        if(x.get_name() == _name) 
        {
            cout << "Already exits\n";
            return false;
        }
    this->name = _name;
    cout << "Insert item quantities: "; cin >> this->quantities;
    this->i_num++;
    this->id = iPrefix + to_string(this->i_num);
    cout << "Insert price: "; cin >> this->price;
    return true;
}

void item::list_item()
{
    cout << this->id << " \t " << this->name << " \t\t " << this->price << "\t " << this->quantities << "\t" <<endl;
    cout << "------------------------------------------\n";
}

float item::get_price()
{
    return this->price;
}