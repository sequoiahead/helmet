/*
 * Mapping.h
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#ifndef MAPPING_H_
#define MAPPING_H_

#include <helmet/domain/HostsGroup.h>
#include <helmet/domain/AddressGroup.h>

namespace helmet {

class Mapping {
public:

	Mapping(const HostsGroup& hosts, const AddressGroup& addresses);
	virtual ~Mapping();

	void map(const Hostname& host, const IpAddress& address);

private:
	HostsGroup hosts;
	AddressGroup addresses;
};

} /* namespace helmet */
#endif /* MAPPING_H_ */
