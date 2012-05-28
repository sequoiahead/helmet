/*
 * AddressGroup.h
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#ifndef ADDRESSGROUP_H_
#define ADDRESSGROUP_H_

#include <helmet/domain.h>
#include <helmet/domain/Group.h>

namespace helmet {

class AddressGroup: public Group<IpAddress> {
public:
	explicit AddressGroup(const std::string& name) :
			Group(name) {
	}

	virtual ~AddressGroup() {
	}
};

} /* namespace helmet */
#endif /* ADDRESSGROUP_H_ */
