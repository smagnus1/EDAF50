#include "hns.h"

#include <functional>
#include <algorithm>


using namespace std;

HNS::HNS(const int size) {
    vector<vector<pair<HostName, IPAddress>>> table(size, vector<pair<HostName, IPAddress>>());
}  


void HNS::insert(const HostName& host, const IPAddress& ip){
    table.at(hashKey(host)).push_back(make_pair(host, ip));
}

bool HNS::remove(const HostName& host) {

    auto hash = hashKey(host);
    auto thisVector = table.at(hash);

    auto pos = find_if(thisVector.begin(), thisVector.end(), 
        [host](const pair<HostName, IPAddress> &thisPair) {
                return thisPair.first == host; //boolean 
        });    

    if(pos == thisVector.end()) {
        return false;
    }
    thisVector.erase(pos);
    return true;
    //return thisVector.erase(pos); ?
}

IPAddress HNS::lookup(const HostName &host) const {
    
    auto hash = hashKey(host); //compile error here if I have lookup(...) const, can't figure out why
    auto thisVector = table.at(hash);
    
    auto pos = find_if(thisVector.begin(), thisVector.end(), 
        [host](const pair<HostName, IPAddress> &thisPair) {
                return thisPair.first == host; //boolean 
        });

    if(pos == thisVector.end()) {
        return NON_EXISTING_ADDRESS;
    }
    return pos->second;
}

//https://en.cppreference.com/w/cpp/string/basic_string/hash
int HNS::hashKey(const HostName& host) const {
    std::hash<std::string> hashOf;
    return hashOf(host);
}

// vector<pair<HostName, IPAddress>> HNS::vectorAt(vector<vector<pair<HostName, IPAddress>>> table, size_t hash) {
//     return hashTable.at(hash);
// }

