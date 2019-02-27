#include "mns.h"
#include "map"



void insert(const HostName& host, const IPAddress& ip){
    if(my_map.count(host) != 0) {
        my_map.insert(host, ip);
    } else {
        return; //behöver felhantering här
    }
}

bool remove(const HostName& host) {
    if(my_map.count(host) != 0) {
        my_map.erase(host);
    } else {
        return NON_EXISTING_ADDRESS;
    }
}

IPAddress lookup(const HostName&) const {
    if(my_map.count(host) != 0) {
        return my_map.find(host);
    } else {
        return NON_EXISTING_ADDRESS;
    }

}