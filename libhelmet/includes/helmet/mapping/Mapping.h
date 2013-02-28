/*
 * Mapping.h
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#ifndef MAPPING_H_
#define MAPPING_H_

#include <helmet/mapping/HostsGroup.h>
#include <helmet/mapping/AddressGroup.h>

#include <map>
#include <list>
#include <exception>

namespace helmet {

class Mapping {
public:
	typedef std::list<Hostname> Hostnames;
	typedef Hostnames::const_iterator HostnamesIteratorConst;
	typedef Hostnames::iterator HostnamesIterator;
	typedef std::pair<HostnamesIteratorConst, HostnamesIteratorConst> HostnamesIteratorConstPair;

	explicit Mapping(const HostsGroup& hosts, const AddressGroup& addresses);
	virtual ~Mapping();

	void map(const Hostname& host, const IpAddress& addr);
	void map(const IpAddress& addr, const Hostname& host);

	/**
	 * @throw std::exception
	 */
	HostnamesIteratorConstPair getHostnames(const IpAddress& addr) const;
	HostnamesIteratorConstPair getHostnamesUnmapped() const;
	std::size_t count(const IpAddress& addr) const;

	void unmap(const IpAddress& addr);
	void unmap(const Hostname& host);
	bool isMapped(const Hostname& hostname) const;

	const HostsGroup& getHostsGroup() const;
	const AddressGroup& getAddressGroup() const;

private:
	typedef std::map<const IpAddress, Hostnames> Container;
	typedef Container::const_iterator ContainerIteratorConst;

	void doMap(const Hostname& host, const IpAddress& addr);

	const AddressGroup& addressGroup;
	const HostsGroup& hostsGroup;
	Hostnames unmapped;
	Container container;
};

inline void Mapping::map(const Hostname& host, const IpAddress& addr) {
	doMap(host, addr);
}

inline void Mapping::map(const IpAddress& addr, const Hostname& host) {
	doMap(host, addr);
}

inline const HostsGroup& Mapping::getHostsGroup() const {
	return hostsGroup;
}

inline const AddressGroup& Mapping::getAddressGroup() const {
	return addressGroup;
}

} /* namespace helmet */
#endif /* MAPPING_H_ */
