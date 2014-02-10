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

	explicit Mapping(const HostsGroup& hosts, const AddressGroup& addresses);
	virtual ~Mapping();

	void map(const Hostname& host, const IpAddress& addr);
	void map(const IpAddress& addr, const Hostname& host);

	/**
	 * @throw std::exception
	 */
	const Hostnames& getHostnames(const IpAddress& addr) const;
	const Hostnames& getHostnamesUnmapped() const;
	std::size_t count(const IpAddress& addr) const;

	void unmap(const IpAddress& addr);
	void unmap(const Hostname& host);
	bool isMapped(const Hostname& hostname) const;
	bool isValid() const;

	const AddressGroup& addressGroup;
	const HostsGroup& hostsGroup;

private:
	typedef std::map<const IpAddress, Hostnames> Container;
	typedef Container::const_iterator ContainerIteratorConst;

	void doMap(const Hostname& host, const IpAddress& addr);

	Hostnames unmapped;
	Container container;
};

inline void Mapping::map(const Hostname& host, const IpAddress& addr) {
	doMap(host, addr);
}

inline void Mapping::map(const IpAddress& addr, const Hostname& host) {
	doMap(host, addr);
}

} /* namespace helmet */
#endif /* MAPPING_H_ */
