/*
 * HostsGroup.h
 *
 *  Created on: Apr 14, 2012
 *      Author: sequoiahead
 */

#ifndef HOSTSGROUP_H_
#define HOSTSGROUP_H_

#include "domain.h"
#include <string>
#include <list>
#include <iterator>

namespace helmet {

class HostsGroup {
public:
	typedef std::list<Hostname> HostnamesList;
	typedef HostnamesList::const_iterator HostnameListIteratorConst;

	HostsGroup();
	~HostsGroup();

	const std::string& getName() const;
	void addHostname(const Hostname& name);
	void removeHostname(const Hostname& name);
	const HostnameListIteratorConst getIterator() const;

private:
	std::string name;
	HostnamesList hostnames;
};

}

#endif /* HOSTSGROUP_H_ */
