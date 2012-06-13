/*
 * Mapping.cpp
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#include <helmet/mapping/Mapping.h>

#include <algorithm>
#include <iostream>

namespace helmet {

Mapping::Mapping(const HostsGroup& hosts, const AddressGroup& addresses) :
		addressGroup(addresses), hostsGroup(hosts), container() {
	unmapped.insert(unmapped.begin(), hosts.begin(), hosts.end());
}

Mapping::~Mapping() {
	for (AddressGroup::IteratorConst it = addressGroup.begin(); it != addressGroup.end(); it++) {
		unmap(*it);
	}
}

std::size_t Mapping::count(const IpAddress& addr) const throw() {
	size_t count;
	try {
		HostnamesIteratorConstPair pair = getHostnames(addr);
		count = std::distance(pair.first, pair.second);
	} catch (const std::exception& e) {
		count = 0;
	}
	return count;
}

Mapping::HostnamesIteratorConstPair Mapping::getHostnames(const IpAddress& addr) const throw (std::exception) {
	ContainerIteratorConst addrIt = container.find(addr);
	if (addrIt == container.end()) {
		std::exception e;
		throw e;
	}
	return std::make_pair(addrIt->second.begin(), addrIt->second.end());
}

Mapping::HostnamesIteratorConstPair Mapping::getHostnamesUnmapped() const {
	return std::make_pair(unmapped.begin(), unmapped.end());
}

void Mapping::unmap(const Hostname& host) {
	for (Container::iterator it = container.begin(); it != container.end(); it++ ) {
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
	HostnamesIteratorConstPair pair = getHostnames(addr);
	//returning all hostnames for this address to unmapped hostnames pool
	for (HostnamesIteratorConst it = pair.first; it != pair.second; it++) {
		unmapped.push_back(*it);
	}
	container.erase(addr);
}

bool Mapping::isMapped(const Hostname& hostname) const {
	//if a host is not in unmapped hosts list then it's mapped
	return !(std::find(unmapped.begin(), unmapped.end(), hostname) == unmapped.end());
}

void Mapping::doMap(const Hostname& host, const IpAddress& addr) {
	if (!hostsGroup.contains(host) || !addressGroup.contains(addr) || isMapped(host)) {
		return;
	}

	container[addr].push_back(host);
	unmapped.remove(host);
}

} /* namespace helmet */
