/*
 * HostsGroup.h
 *
 *  Created on: Apr 14, 2012
 *      Author: sequoiahead
 */

#ifndef HOSTSGROUP_H_
#define HOSTSGROUP_H_

#include <helmet/domain.h>

#include <string>
#include <list>
#include <iterator>

namespace helmet {

class HostsGroup {
public:
	typedef std::list<Hostname> List;
	typedef List::const_iterator IteratorConst;

	explicit HostsGroup(const std::string name);
	~HostsGroup();

	std::string getName() const;
	void addHostname(const Hostname hostname);
	void removeHostname(const Hostname hostname);
	IteratorConst begin() const;
	const IteratorConst end() const;
	bool empty() const;
	std::size_t size() const;

private:
	std::string name;
	List hostnames;
};

}

#endif /* HOSTSGROUP_H_ */
