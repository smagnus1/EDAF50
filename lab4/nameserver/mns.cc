#include <iostream>
#include <vector>
#include <algorithm>

#include "mns.h"


void MNS::insert(const HostName& host, const IPAddress& ip){
    my_map[host] = ip; //This assumes there is no need for error handling
}

bool MNS::remove(const HostName& host) {
    if(my_map.count(host) != 0) {
        auto pos = my_map.find(host);
        my_map.erase(pos);
        return true;
    } else {
        return false;
    }
}

IPAddress MNS::lookup(const HostName& host) const {
    if(my_map.count(host) != 0) {
        auto pos = my_map.find(host);
        return pos->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}