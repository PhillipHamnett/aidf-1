#ifndef MYTABLE
#define MYTABLE
#include <eosio/eosio.hpp>

class [[eosio::table("mytable"), eosio::contract("example")]] mytable {
  public:
    eosio::name username;
    int age;
  public:
    //mytable(){}
    //mytable(eosio::name x, int y){
    //  username = x;
    //  age = y;
    //}
    //~mytable(){}

    void set_name(eosio::name x){username = x;}
    void set_age(int y){age = y;}
    eosio::name get_name(){return username;}
    int get_age(){return age;}

    uint64_t primary_key() const { return username.value; }
};

typedef eosio::multi_index< "mytable"_n, mytable > my_multiindex_table;

#endif
