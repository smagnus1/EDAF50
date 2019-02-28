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

void VNS::insert(const HostName& host, const IPAddress& ip){
    pairs.push_back(make_pair(host, ip));
}

bool VNS::remove(const HostName& host) {
    auto pos = find_if(pairs.begin(), pairs.end(), host);
    if(pos == pairs.end()) {
        return false;
    }

    pairs.erase(pos);
    return true;
}

IPAddress VNS::lookup(const HostName& host) const {
    auto pos = find_if(pairs.begin(), pairs.end(), host); //niklas skriver annorlunda hmm
    if(pos == pairs.end()) {
        return NON_EXISTING_ADDRESS;
    }
    return pos->second;
}