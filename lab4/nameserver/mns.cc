#include <iostream>
#include <vector>
#include <algorithm>

#include "mns.h"


/*
* Insert a name/address pair. Does not check if the name
* or address already exists.
*/
void MNS::insert(const HostName& host, const IPAddress& ip){
    my_map[host] = ip; 
}

/*
* Remove the pair with the specified host name. Returns true
* if the host name existed and the pair was removed, false
* otherwise.
*/
bool MNS::remove(const HostName& host) {
    if(my_map.count(host) != 0) {
        auto pos = my_map.find(host);
        my_map.erase(pos);
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
IPAddress MNS::lookup(const HostName& host) const {
    if(my_map.count(host) != 0) {
        auto pos = my_map.find(host);
        return pos->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}