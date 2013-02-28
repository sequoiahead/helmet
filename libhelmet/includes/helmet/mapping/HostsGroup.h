/*
 * HostsGroup.h
 *
 *  Created on: Apr 14, 2012
 *      Author: sequoiahead
 */

#ifndef HOSTSGROUP_H_
#define HOSTSGROUP_H_

#include <helmet/types.h>
#include <helmet/mapping/Group.h>

namespace helmet {

class HostsGroup: public Group<Hostname> {
public:
	explicit HostsGroup(const std::string& name);
	virtual ~HostsGroup();
};

inline HostsGroup::HostsGroup(const std::string& name) :
		Group<Hostname>(name) {
}

inline HostsGroup::~HostsGroup() {
}

}
#endif /* HOSTSGROUP_H_ */
