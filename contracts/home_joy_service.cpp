#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>

using namespace eosio;
class deep: eoshome{

   using eosio::asset;
   using eosio::indexed_by;
   using eosio::const_mem_fun;
   using eosio::block_timestamp;

public:
    struct auto_purchaser {
         account_name            auto_purchaser_ai;
         list<account>           monitors
         uint64_t                uid = 0; ///< negative high_bid == closed auction waiting to be claimed
       
         auto     primary_key()const { return auto_purchaser_ai;                          }
         uint64_t by_uid()const { return static_cast<uint64_t>(-uid); }
   };
   typedef eosio::multi_index< N(owner_ai), owner_ai,
                               indexed_by<N(owner_ai), const_mem_fun<owner_ai, uint64_t, &name_bid::by_high_bid>  >
                               >  name_bid_table;


    deep( account_name self ): eoshome(self){}

//    typedef multi_index<N(users), users> user_ids_table
   void ready_container(account_name washing_monitor_account){
        eosio.assert(pet_monitor_account == this.pet_monitor_account)
        print('auto_purchase', eosio)
    }

   void auto_buy_pet_food(account_name pet_monitor_account){
        eosio.assert(pet_monitor_account == this.pet_monitor_account)
        if()
        print('auto_purchase', eosio)
    }
    // assertion failed: Configuration already exists

    void authorize_monitors(account_name owner, list<account_name> monitor){
        require_auth(user);
//        print(configs::get().application);
        require_auth(configs::get().application);

//        eosio_assert(!ids::exists(user), "User already has an ID");
        ids::set(nextId(),user);
        print("set account");
    }

    void unauthorize_monitors(account_name owner, list<account_name> monitor){
        require_auth(user);
//        print(configs::get().application);
        require_auth(configs::get().application);
//        eosio_assert(!ids::exists(user), "User already has an ID");
        ids::set(nextId(),user);
        print("set account");
    }


private:

    typedef singleton<N(deep), N(ownerwashpower), N(ownerpetfood), N(ownerdapper),config> configs;
   typedef multi_index<N(users), users> user_table;
};

EOSIO_ABI(auto_purchaser, (auto_buy_washing_power)(auto_buy_pet_food)(authorize_monitors)(unauthorize_monitors))