/*
 * HostsGroup.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: sequoiahead
 */

#include <helmet/domain/HostsGroup.h>

namespace helmet {

HostsGroup::HostsGroup(const std::string name)
		: name(name), hostnames() {
}

HostsGroup::~HostsGroup() {
}

void HostsGroup::addHostname(const Hostname hostname) {
	hostnames.push_back(hostname);
}

void HostsGroup::removeHostname(const Hostname hostname) {
	hostnames.remove(hostname);
}

HostsGroup::IteratorConst HostsGroup::begin() const {
	return hostnames.begin();
}

const HostsGroup::IteratorConst HostsGroup::end() const {
	return hostnames.end();
}

bool HostsGroup::empty() const {
	return hostnames.empty();
}

std::size_t HostsGroup::size() const {
	return hostnames.size();
}

std::string HostsGroup::getName() const {
	return name;
}

}
