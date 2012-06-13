/*
 * AddressGroup.h
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#ifndef ADDRESSGROUP_H_
#define ADDRESSGROUP_H_

#include <helmet/types.h>
#include <helmet/mapping/Group.h>

namespace helmet {

class AddressGroup: public Group<IpAddress> {
public:
	explicit AddressGroup(const std::string& name);
	virtual ~AddressGroup();
};

inline AddressGroup::AddressGroup(const std::string& name) :
		Group<IpAddress>(name) {
}

inline AddressGroup::~AddressGroup() {
}

} /* namespace helmet */
#endif /* ADDRESSGROUP_H_ */
