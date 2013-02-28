/*
 * Writer.h
 *
 *  Created on: 27/02/2013
 *      Author: sequoiahead
 */

#ifndef MAPPINGWRITER_H_
#define MAPPINGWRITER_H_

#include <string>
#include <fstream>

#include <helmet/mapping/Mapping.h>

namespace helmet {

class MappingWriter {
public:
	explicit MappingWriter(const std::string);
	~MappingWriter();

	void write(const Mapping&);

private:
	std::string pathHostsFile;
	std::ofstream fileHosts;
};

}

#endif /* MAPPINGWRITER_H_ */
