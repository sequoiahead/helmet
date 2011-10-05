#ifndef HOSTSGROUP_H_
#define HOSTSGROUP_H_

#include "state.h"
#include <list>

namespace helmet {

class HostsGroup {
public:
	explicit HostsGroup(const IpAddress&);
	void addHostname(const Hostname);
	void removeHostname(const Hostname&);
	std::list<Hostname> getHostnames() const;
	virtual ~HostsGroup();
private:
	IpAddress ipAddress;
	std::list<Hostname> hostnames;
};

} /* namespace helmet */
#endif /* HOSTSGROUP_H_ */
