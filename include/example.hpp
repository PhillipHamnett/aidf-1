#include <eosio/eosio.hpp>

class [[eosio::contract("example")]] example : public eosio::contract {
  public:
    using eosio::contract::contract;

    [[eosio::action]] void hi(eosio::name nm);
    [[eosio::action]] void sendmoney(eosio::name nm);
    [[eosio::action]] void add(eosio::name nm, int age);
    [[eosio::action]] void modify(eosio::name, int age);
    [[eosio::action]] void remove(eosio::name);
};
