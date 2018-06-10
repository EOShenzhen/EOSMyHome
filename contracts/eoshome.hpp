#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>

using namespace eosio;
class eoshome: contract{

   using eosio::asset;
   using eosio::indexed_by;
   using eosio::const_mem_fun;
   using eosio::block_timestamp;

public:
    struct eoshome {
         account_name            owner;
         account_name            homejoyai; // aggregated AI of IOTs to mnitor the
         account_name            auto_purchaser; // aggregated AI of IOTs
         uint64_t                id;
         uint64_t                token_reserved;


         auto     primary_key()const { return owner;                          }
         uint64_t by_high_bid()const { return static_cast<uint64_t>(-high_bid); }
   };
   typedef eosio::multi_index< N(owner), ,
                               indexed_by<N(highbid), const_mem_fun<name_bid, uint64_t, &name_bid::by_high_bid>  >
                               >  name_bid_table;


    eoshome( account_name self ): contract(self){}

//    typedef multi_index<N(users), users> user_ids_table
  void authorize_auto_buyer_ai(account_name owner, account auto_buyer_ai, uint64_t amt_to_guarant){
        require_auth(owner);
        require_auth(auto_buyer_ai);
        auto iter = owner.activekeylists.find(auto_buyer_ai); // find the sender by the primary key
        if(iter == activekeylists.end())  activekeylists.emplace(auto_buyer_ai, [&](auto& row){
            row.amt_to_issue = amt_to_guarant;
            row.status = "authorized";
        });
        else activekeylists.modify(iter, 0, [&](auto& row){ // found! replace it with new parameter
             row.status = "unable to authorized";
        });
    }

    // asserti
    void authorize_home_joy_ai(account_name owner, account home_joy_ai, uint64_t amt_to_guarant){
        require_auth(owner);
        require_auth(home_joy_ai);
        auto iter = owner.activekeylists.find(home_joy_ai); // find the sender by the primary key
        if(iter == activekeylists.end())  activekeylists.emplace(home_joy_ai, [&](auto& row){
            row.amt_to_issue = amt_to_guarant;
            row.status = "authorized";
        });
        else activekeylists.modify(iter, 0, [&](auto& row){ // found! replace it with new parameter
             row.status = "unable to authorized";
        });
    }

    // atomic idon failed: Configuration already exists

    string getauto_buyer_ai(account_name owner, account auto_buyer_ai){
        require_auth(owner);
        require_auth(home_joy_ai);
        auto ret = []
        auto iter = owner.activekeylists.find(home_joy_ai); // find the sender by the primary key
        if(iter == activekeylists.end())  activekeylists.emplace(home_joy_ai, [&](auto& row){
           ret = auto_buyer_ai.get_info
        });
        else activekeylists.modify(iter, 0, [&](auto& row){ // found! replace it with new parameter
             printf("No such auto_buyer_ai", auto_buyer_ai)
        });
        return ret
    }


    // atomic idon failed: Configuration already exists

    string getauto_buyer_ai(account_name owner, account auto_buyer_ai){
        require_auth(owner);
        require_auth(auto_buyer_ai);
        auto ret = []
        auto iter = owner.activekeylists.find(auto_buyer_ai); // find the sender by the primary key
        if(iter == activekeylists.end())  activekeylists.emplace(auto_buyer_ai, [&](auto& row){
           ret = auto_buyer_ai.get_info
        });
        else activekeylists.modify(iter, 0, [&](auto& row){ // found! replace it with new parameter
             printf("No such auto_buyer_ai", auto_buyer_ai)
        });
        return ret // in json format 
    }

      string gethome_joy_ai(account_name owner, account home_joy_ai){
        require_auth(owner);
        require_auth(home_joy_ai);
        auto ret = []
        auto iter = owner.activekeylists.find(home_joy_ai); // find the sender by the primary key
        if(iter == activekeylists.end())  activekeylists.emplace(home_joy_ai, [&](auto& row){
           ret = auto_buyer_ai.get_info
        });
        else activekeylists.modify(iter, 0, [&](auto& row){ // found! replace it with new parameter
             printf("No such auto_buyer_ai", auto_buyer_ai)
        });
        return ret
    }


    // atomic id
    void removehome_joy_ai(account_name user, account home_joy_ai){
        require_auth(user);
        require_auth(configs::get().application);
        eosio_assert(ids::exists(user), "home_joy_ai donnot an ID");
        ids::set(user);
    }

    // atomic id
    void removeauto_buyer_ai(account_name user, account auto_buyer_ai){
        require_auth(user);
        require_auth(configs::get().application);
        eosio_assert(ids::exists(user), "home_joy_ai donnot an ID");
        ids::set(user);
    }


private:
    typedef uint64_t id;
    struct userconfig{
        account_name application;
        account_name application;

        EOSLIB_SERIALIZE(config, (application));
    };
    typedef singleton<N(owner), N(eoshome), eoshome> eoshome;
    typedef singleton<N(owner), N(eoshome), N(auto_buyer_ai), N(auto_buyer_ai), auto_buyer_ai> auto_buyers;
    typedef singleton<N(owner), N(eoshome), N(home_joy_ai), N(home_joy_ai), home_joy_ai> home_joys;
   
    typedef singleton<N(eoshome), N(lastId), N(eoshome), id> lastId;

    id nextId(){
        id lid = lastId::exists() ? lastId::get()+1:0;
        lastId::set(lid);
        return lid;
    }

//    typedef multi_index<N(users), users> user_table;
};

EOSIO_ABI(owner, (restroom)(setacc)(getacc)(removeacc))