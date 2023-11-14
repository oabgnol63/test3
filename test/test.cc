#include "gtest/gtest.h"
#include "../interface.h"


vector<customer> kh;
vector<item> vp;
vector<order> don;


class InterfaceTest : public testing::Test
{
    protected:
        Interface *_itf;
        customer *cTemp;
        item *iTemp;
        order *oTemp;
        string *item_name;
        char *con;
        int *item_num;
        long long *ctm_id;
        pair<string,int> *p;
        vector<pair<string,int>> *vTemp;
        bool *_continue;
        float _total;
        virtual void SetUp() override 
        {
            cout << "Starting Testing Phase" <<  endl;
            _itf = new Interface;
            cTemp = new customer;
            iTemp = new item;
            oTemp = new order;
            item_name = new string;
            con = new char;
            item_num = new int;
            ctm_id = new long long;
            p = new pair<string,int>;
            vTemp = new vector<pair<string,int>>;
            _continue = new bool;
            _total = 0;
            };
        
        virtual void TearDown() override 
        {
            delete item_name; item_name = NULL;
            delete item_num; item_num = NULL;
            delete ctm_id; ctm_id = NULL;
            delete p; p = NULL;
            delete con; con = NULL;
            delete vTemp; vTemp = NULL;
            delete oTemp; oTemp = NULL;    
            delete iTemp; iTemp = NULL;
            delete cTemp; cTemp = NULL;
            delete _itf; _itf = NULL;
        };
};
/**
 * @brief test constructor of customer
 * 
*/
TEST_F(InterfaceTest,customer_constructor)
{
    *cTemp = customer("bao","tma","911");
    ASSERT_NE(cTemp,nullptr);
    // valid parameters
    EXPECT_STREQ(cTemp->get_info("name").c_str(),"bao");
    EXPECT_STREQ(cTemp->get_info("address").c_str(),"tma");
    EXPECT_STREQ(cTemp->get_info("phone").c_str(),"911");
    // invalid parameters
    EXPECT_STREQ(cTemp->get_info("whatever").c_str(),"");
}

TEST_F(InterfaceTest,set_total_value)
{
    *cTemp = customer("hoang","dxc","911");
    ASSERT_NE(cTemp,nullptr);
    cTemp->set_total_spent(15000000);
    EXPECT_STREQ(cTemp->Output().c_str(),"Gold");
}

TEST_F(InterfaceTest,make_new_order)
{
   item *a = new item("black king bar",100,500000);
   vp.push_back(*a);
   a = new item("orchil malevolance",100,600000);
   vp.push_back(*a);
   a = new item("divine rapier",100,1000000);
   vp.push_back(*a);
   a = new item("maelstrom",100,750000);
   vp.push_back(*a);
   customer *b = new customer("nguyen van a","TMA","911");
   kh.push_back(*b);
   delete a; a = NULL;
   delete b; b = NULL;
   _itf->make_new_order(&vp, &don, &kh);
   EXPECT_STREQ(kh.back().get_info("name").c_str(),"bao");
   EXPECT_EQ(kh.back().get_order_list()->size(),1);
}
TEST_F(InterfaceTest,make_new_order2)
{
   item *a = new item("black king bar",100,500000);
   vp.push_back(*a);
   a = new item("orchil malevolance",100,600000);
   vp.push_back(*a);
   a = new item("divine rapier",100,1000000);
   vp.push_back(*a);
   a = new item("maelstrom",100,750000);
   vp.push_back(*a);
   customer *b = new customer("nguyen van a","TMA","911");
   kh.push_back(*b);
   delete a; a = NULL;
   delete b; b = NULL;
   _itf->make_new_order(&vp, &don, &kh);
   EXPECT_STREQ(kh.back().get_info("name").c_str(),"hoang");
   EXPECT_EQ(kh.back().get_order_list()->size(),1);
}
TEST_F(InterfaceTest,make_new_order3)
{
   item *a = new item("black king bar",100,500000);
   vp.push_back(*a);
   a = new item("orchil malevolance",100,600000);
   vp.push_back(*a);
   a = new item("divine rapier",100,1000000);
   vp.push_back(*a);
   a = new item("maelstrom",100,750000);
   vp.push_back(*a);
   customer *b = new customer("nguyen van a","TMA","911");
   kh.push_back(*b);
   delete a; a = NULL;
   delete b; b = NULL;
   _itf->make_new_order(&vp, &don, &kh);
   EXPECT_STREQ(kh.back().get_info("name").c_str(),"nam");
   EXPECT_EQ(kh.back().get_order_list()->size(),1);
}
TEST_F(InterfaceTest,make_new_order4)
{
   item *a = new item("black king bar",100,500000);
   vp.push_back(*a);
   a = new item("orchil malevolance",100,600000);
   vp.push_back(*a);
   a = new item("divine rapier",100,1000000);
   vp.push_back(*a);
   a = new item("maelstrom",100,750000);
   vp.push_back(*a);
   customer *b = new customer("nguyen van a","TMA","911");
   kh.push_back(*b);
   delete a; a = NULL;
   delete b; b = NULL;
   _itf->make_new_order(&vp, &don, &kh);
   EXPECT_STREQ(kh.back().get_info("name").c_str(),"tien");
   EXPECT_EQ(kh.back().get_order_list()->size(),1);
}

TEST_F(InterfaceTest,make_new_order5)
{
   item *a = new item("black king bar",100,500000);
   vp.push_back(*a);
   a = new item("orchil malevolance",100,600000);
   vp.push_back(*a);
   a = new item("divine rapier",100,1000000);
   vp.push_back(*a);
   a = new item("maelstrom",100,750000);
   vp.push_back(*a);
   customer *b = new customer("nguyen van a","TMA","911");
   kh.push_back(*b);
   delete a; a = NULL;
   delete b; b = NULL;
   _itf->make_new_order(&vp, &don, &kh);
   EXPECT_STREQ(kh.back().get_info("name").c_str(),"huy");
   EXPECT_EQ(kh.back().get_order_list()->size(),1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}