#ifndef HOSTSGROUP_H_
#define HOSTSGROUP_H_

#include "domain.h"
#include <list>

namespace helmet {

class HostsGroupMapping {
public:
	explicit HostsGroupMapping(const IpAddress&);

	void addHostname(const Hostname&);
	void removeHostname(const Hostname&);

	const std::list<Hostname>& getHostnames() const;
	const IpAddress& getIpAddress() const;

	virtual ~HostsGroupMapping();
private:
	IpAddress ipAddress;
	std::list<Hostname> hostnames;
};

} /* namespace helmet */
#endif /* HOSTSGROUP_H_ */
