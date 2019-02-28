#ifndef VNS_H
#define VNS_H

#include <nameserverinterface.h>
#include <string>
#include <vector>

class VNS : public NameServerInterface {
    public:
        void insert(const HostName&, const IPAddress&) = 0;
        bool remove(const HostName&) = 0;
        IPAddress lookup(const HostName&) const = 0;
    private:
        std::vector<std::pair<HostName, IPAddress>> pairs;
};

#endif