#include <example.hpp>
#include <eosio/asset.hpp>
#include "mytable.hpp"

void example::hi(eosio::name nm) {
  print_f("Name : %\n",nm);
  require_recipient(nm);
}

void example::sendmoney(eosio::name nm, eosio::asset quantity){
  require_auth(_self);
  eosio::action(eosio::permission_level(_self, eosio::name("active")), "eosio.token"_n, eosio::name("transfer"), std::tuple(_self, nm, quantity, std::string("Money sent via smart contract"))).send();
}

void example::add(eosio::name nm, int age){
  my_multiindex_table table(_self, _self.value);
  table.emplace(_self, [&](auto & entry){
                entry.set_name(nm);
                entry.set_age(age);
                });
}

void example::modify(eosio::name nm, int age){
  my_multiindex_table table(_self, _self.value);
  auto iterator = table.find(nm.value);
  eosio::check(iterator != table.end(), "Can not edit an entry that does not exist");
  table.modify(iterator, _self, [&](auto & entry){
                entry.set_age(age);
                });
}

void example::remove(eosio::name nm){
  my_multiindex_table table(_self, _self.value);
  auto iterator = table.find(nm.value);
  eosio::check(iterator != table.end(), "Can not edit an entry that does not exist");
  table.erase(iterator);
}
