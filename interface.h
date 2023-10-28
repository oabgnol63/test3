#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once

#include "customer.h"
#include "stdlib.h"
#include <fstream>
#include <string.h>

#define _url "/root/Bao/cpp/copy2/input.txt"
extern vector<item> _it;
extern vector<customer> _cs;
extern vector<order> _ord;
string get_line(int,string, int );
class Interface
{
    private:
    customer *cTemp = new customer;
    item *iTemp = new item;
    order *oTemp = new order;
    string *item_name = new string;
    string *con = new string;
    int *item_num = new int;
    long long *ctm_id = new long long;
    pair<string,int> *p = new pair<string,int>;
    vector<pair<string,int>> *vTemp = new vector<pair<string,int>>;
    bool *_continue = new bool;
    float _total = 0;
    public:
    Interface(){};
    ~Interface();
    void new_customer(vector<customer> *);
    void new_item(vector<item> *);
    void list_all_customer(vector<customer>);
    void list_all_item(vector<item>);
    void list_all_order(vector<order>);
    void make_new_order(vector<item> *, vector<order> *, vector<customer> *);
    order* check_by_id(vector<order>);

};


#endif