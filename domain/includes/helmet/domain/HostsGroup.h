/*
 * HostsGroup.h
 *
 *  Created on: Apr 14, 2012
 *      Author: sequoiahead
 */

#ifndef HOSTSGROUP_H_
#define HOSTSGROUP_H_

#include <helmet/domain.h>
#include <helmet/domain/Group.h>

namespace helmet {

class HostsGroup: public Group<Hostname> {
public:
	explicit HostsGroup(const std::string& name) :
			Group(name) {

	}

	virtual ~HostsGroup() {

	}
};

}

#endif /* HOSTSGROUP_H_ */
