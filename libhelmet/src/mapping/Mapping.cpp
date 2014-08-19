#include <helmet/mapping/Mapping.h>

#include <algorithm>
#include <iostream>

namespace helmet {

    Mapping::Mapping(const HostsGroup& hosts, const AddressGroup& addresses)
                : addressGroup(addresses), hostsGroup(hosts), container(), enabled(false) {
        unmapped.insert(unmapped.begin(), hosts.begin(), hosts.end());
    }

    Mapping::~Mapping() {
        for (auto addr : addressGroup) {
            unmap(addr);
        }
    }

    std::size_t Mapping::count(const IpAddress& addr) const {
        size_t count;
        try {
            Hostnames hosts = getHostnames(addr);
            count = hosts.size();
        } catch (const std::exception& e) {
            count = 0;
        }
        return count;
    }

    const Mapping::Hostnames& Mapping::getHostnames(const IpAddress& addr) const {
        ContainerIteratorConst addrIt = container.find(addr);
        if (addrIt == container.end()) {
            std::exception e;
            throw e;
        }
        return addrIt->second;
    }

    const Mapping::Hostnames& Mapping::getHostnamesUnmapped() const {
        return unmapped;
    }

    void Mapping::unmap(const Hostname& host) {
        for (Container::iterator it = container.begin(); it != container.end(); it++) {
            Hostnames& list = it->second;
            HostnamesIterator hIt = std::find(list.begin(), list.end(), host);
            if (hIt != list.end()) {
                list.erase(hIt);
                unmapped.push_back(*hIt);
                break;
            }
        }
    }

    void Mapping::unmap(const IpAddress& addr) {
        if (container.find(addr) == container.end()) {
            return;
        }
        Hostnames hosts = getHostnames(addr);
        //returning all hostnames for this address to unmapped hostnames pool
        for (auto host : hosts) {
            unmapped.push_back(host);
        }
        container.erase(addr);
    }

    bool Mapping::isMapped(const Hostname& hostname) const {
        //if a host is not in unmapped hosts list then it's mapped
        return !(std::find(unmapped.begin(), unmapped.end(), hostname) == unmapped.end());
    }
    
    bool Mapping::isValid() const {
        //there must be no unmapped hosts for mapping to be valid
        return unmapped.size() <= 0;
    }

    void Mapping::doMap(const Hostname& host, const IpAddress& addr) {
        if (!hostsGroup.contains(host) || !addressGroup.contains(addr) || isMapped(host)) {
            return;
        }

        container[addr].push_back(host);
        unmapped.remove(host);
    }

} /* namespace helmet */
