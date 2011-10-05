#include "HostsGroup.h"

namespace helmet {

HostsGroup::HostsGroup(const IpAddress& ipAddr)
	: ipAddress(ipAddr) {
}

HostsGroup::~HostsGroup() {
}

} /* namespace helmet */
