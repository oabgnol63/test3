#ifndef ITEM_H
#define ITEM_H
#pragma once

#include <iostream>
#include <vector>
#define iPrefix "Item_no_"

using namespace std;

class item
{
    protected:
        string id,name;
        int quantities;
        static int i_num;
        float price;
    public:
        item(){};
        item(string,int,float);
        int get_quantities();
        void list_item();
        void set_quantities(int);
        bool new_item();
        string get_name();
        float get_price();
};

vector<item> _it;
#endif