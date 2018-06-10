#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>

using namespace eosiosystem;
class deep: contract{

   using eosio::asset;
   using eosio::indexed_by;
   using eosio::const_mem_fun;
   using eosio::block_timestamp;

public:
    struct name_bid {
         account_name            owner;
         account_name            high_bidder;
         int64_t                 high_bid = 0; ///< negative high_bid == closed auction waiting to be claimed
         uint64_t                last_bid_time = 0;

         auto     primary_key()const { return newname;                          }
         uint64_t by_high_bid()const { return static_cast<uint64_t>(-high_bid); }
   };
   typedef eosio::multi_index< N(namebids), name_bid,
                               indexed_by<N(highbid), const_mem_fun<name_bid, uint64_t, &name_bid::by_high_bid>  >
                               >  name_bid_table;


    deep( account_name self ): contract(self){}

//    typedef multi_index<N(users), users> user_ids_table
    void setapp(account_name application){
  
    }
    // assertion failed: Configuration already exists

    void setacc(account_name user){
        require_auth(user);
//        print(configs::get().application);
        require_auth(configs::get().application);

//        eosio_assert(!ids::exists(user), "User already has an ID");
        ids::set(nextId(),user);
        print("set account");
    }

    // atomic id
    void getacc(account_name user){
        eosio_assert(ids::exists(user), "User donnot an ID");
        print("User's ID is ", ids::get(user));
    }

    // atomic id
    void removeacc(account_name user){
        require_auth(user);
        require_auth(configs::get().application);
        eosio_assert(ids::exists(user), "User donnot an ID");
        ids::set(user);
    }


private:
    typedef uint64_t id;
    struct config{
        account_name application;


        EOSLIB_SERIALIZE(config, (application));
    };

    typedef singleton<N(deep), N(config), N(deep), config> configs;
    typedef singleton<N(deep), N(ids), N(deep), id> ids;
    typedef singleton<N(deep), N(lastId), N(deep), id> lastId;

    id nextId(){
        id lid = lastId::exists() ? lastId::get()+1:0;
        lastId::set(lid);
        return lid;
    }

//    typedef multi_index<N(users), users> user_table;
};

EOSIO_ABI(deep, (restroom)(setacc)(getacc)(removeacc))