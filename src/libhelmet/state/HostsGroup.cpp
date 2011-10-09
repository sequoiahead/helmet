#include "HostsGroup.h"

namespace helmet {

HostsGroup::HostsGroup(const IpAddress& ipAddr)
	: ipAddress(ipAddr), hostnames() {
}

void HostsGroup::addHostname(const Hostname& hostname) {
	hostnames.push_back(hostname);
}

void HostsGroup::removeHostname(const Hostname& hostname) {
	hostnames.remove(hostname);
}

const std::list<Hostname>& HostsGroup::getHostnames() const {
	return hostnames;
}

const IpAddress& HostsGroup::getIpAddress() const {
	return ipAddress;
}

HostsGroup::~HostsGroup() {
}

} /* namespace helmet */
