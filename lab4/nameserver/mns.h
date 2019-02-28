#ifndef MNS_H
#define MNS_H

#include "nameserverinterface.h"
#include "map";  

class MNS {
public: 
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
private:
    std::map<HostName, IPAddress> my_map;
};

#endif