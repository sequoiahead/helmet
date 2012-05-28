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

	typedef std::multimap<const IpAddress&, const Hostname&> Container;
	typedef Container::const_iterator IteratorConst;

	Mapping(const HostsGroup& hosts, const AddressGroup& addresses);
	virtual ~Mapping();

	inline void map(const Hostname& host, const IpAddress& address) {
		container.insert(std::pair<const IpAddress&, const Hostname&>(host, address));
	}

	void remove(const Hostname& host);
	void remove(const IpAddress& address);

	inline std::pair<IteratorConst,IteratorConst> getMap(const IpAddress& address) const {
		return container.equal_range(address);
	}

private:

	HostsGroup hosts;
	AddressGroup addresses;
	Container container;
};

} /* namespace helmet */
#endif /* MAPPING_H_ */
