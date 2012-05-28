/*
 * Mapping.h
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#ifndef MAPPING_H_
#define MAPPING_H_

#include <helmet/domain/HostsGroup.h>
#include <helmet/domain/AddressGroup.h>

#include <map>

namespace helmet {

class Mapping {
public:

	typedef std::multimap<const IpAddress, const Hostname> Container;
	typedef Container::const_iterator IteratorConst;
	typedef Container::iterator Iterator;

	inline explicit Mapping(const HostsGroup& hosts, const AddressGroup& addresses) :
			hosts(hosts), addrs(addresses), container() {
	}

	inline virtual ~Mapping() {
	}

	inline void map(Hostname& host, IpAddress& addr) {
		doMap(host, addr);
	}

	inline void map(IpAddress& addr, Hostname& host) {
		doMap(host, addr);
	}

	inline std::pair<IteratorConst,IteratorConst> getMap(const IpAddress& addr) const {
		return container.equal_range(addr);
	}

	inline const AddressGroup& getAddressGroup() {
		return addrs;
	}

	inline const HostsGroup& getHostsGroup() {
		return hosts;
	}

	void remove(IpAddress& addr);

	void remove(Hostname& host);

private:

	void doMap(Hostname& host, IpAddress& addr);

	HostsGroup hosts;
	AddressGroup addrs;
	Container container;
};

} /* namespace helmet */
#endif /* MAPPING_H_ */
