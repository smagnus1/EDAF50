#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"
#include <vector>


//error on HNS, maybe delcare size in here somewhere?

class HNS : public NameServerInterface {
     public:
        HNS(const int size);

        void insert(const HostName&, const IPAddress&);
        bool remove(const HostName&);
        IPAddress lookup(const HostName&) const;
    private:
        //not sure if correct, took from vns and added one more vector
        std::vector<std::vector<std::pair<HostName, IPAddress>>> table;
        //std::vector<std::pair<HostName, IPAddress>> vectorAt(const HostName& host);

        int hashKey(const HostName& input) const; 
};


#endif