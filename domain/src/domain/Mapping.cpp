/*
 * Mapping.cpp
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#include <helmet/domain/Mapping.h>
#include <algorithm>

namespace helmet {

void Mapping::remove(Hostname& host) {
	for (Iterator it = container.begin(); it != container.end(); ++it ) {
		if ((*it).second == host) {
			host.setMapped(false);
			container.erase(it);
		}
	}
}

void Mapping::remove(IpAddress& addr) {
	std::pair<Iterator, Iterator> its = container.equal_range(addr);
	for (Iterator it = its.first; it != its.second; ++it) {
		const_cast<Hostname&>(it->second).setMapped(false);
	}
	container.erase(addr);
	addr.setMapped(false);
}

void Mapping::doMap(Hostname& host, IpAddress& addr) {
	if (!hosts.contains(host) || !addrs.contains(addr)) {
		return;
	}
	host.setMapped(true);
	addr.setMapped(true);
	container.insert(std::make_pair(host, addr));
}

} /* namespace helmet */
