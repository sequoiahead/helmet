#include <helmet/domain/HostsGroupMapping.h>

namespace helmet {

HostsGroupMapping::HostsGroupMapping(const IpAddress& ipAddr)
	: ipAddress(ipAddr), hostnames() {
}

void HostsGroupMapping::addHostname(const Hostname& hostname) {
	hostnames.push_back(hostname);
}

void HostsGroupMapping::removeHostname(const Hostname& hostname) {
	hostnames.remove(hostname);
}

const std::list<Hostname>& HostsGroupMapping::getHostnames() const {
	return hostnames;
}

const IpAddress& HostsGroupMapping::getIpAddress() const {
	return ipAddress;
}

HostsGroupMapping::~HostsGroupMapping() {
}

} /* namespace helmet */
