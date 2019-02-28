#include "umns.h"


/*
* Insert a name/address pair. Does not check if the name
* or address already exists.
*/
void UMNS::insert(const HostName& host, const IPAddress& ip){
    map.insert({host, ip}); 
}

/*
* Remove the pair with the specified host name. Returns true
* if the host name existed and the pair was removed, false
* otherwise.
*/
bool UMNS::remove(const HostName& host) {
    if(map.count(host) != 0) {
        auto pos = map.find(host);
        map.erase(pos);
        return true;
    } else {
        return false;
    }
}

/*
* Find the IP address for the specified host name. Returns
* NON_EXISTING_ADDRESS if the host name wasn't in the name
* server.
*/
IPAddress UMNS::lookup(const HostName& host) const {
    if(map.count(host) != 0) {
        auto pos = map.find(host);
        return pos->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}