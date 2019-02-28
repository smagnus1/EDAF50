// Implement a class VNS (vector name server) that uses an unsorted vector to store the
// name/address pairs. Use the find if algorithm to search for a host name. The third
// parameter to the algorithm should be a lambda.
// This implementation is clearly inefficient. A sorted vector would be a good alternative,
// but not for a name server with many insertions and deletions.

#include "vns.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
* Insert a name/address pair. Does not check if the name
* or address already exists.
*/
void VNS::insert(const HostName& host, const IPAddress& ip){
    pairs.push_back(make_pair(host, ip));
}


/*
* Remove the pair with the specified host name. Returns true
* if the host name existed and the pair was removed, false
* otherwise.
*/
bool VNS::remove(const HostName& host) {
  
    auto pos = find_if(pairs.begin(), pairs.end(), 
        [host](const pair<HostName, IPAddress> &thisPair) {
                return thisPair.first == host; //boolean 
        });

    if(pos == pairs.end()) {
        return false;
    }
    pairs.erase(pos); //is there need for error "Item was not erased"?
    return true;
}


/*
* Find the IP address for the specified host name. Returns
* NON_EXISTING_ADDRESS if the host name wasn't in the name
* server.
*/
IPAddress VNS::lookup(const HostName& host) const {
    
    auto pos = find_if(pairs.begin(), pairs.end(), 
        [host](const pair<HostName, IPAddress> &thisPair) {
                return thisPair.first == host; //boolean 
        });

    if(pos == pairs.end()) {
        return NON_EXISTING_ADDRESS;
    }
    return pos->second;
}