/*
 * MappingWriter.cpp
 *
 *  Created on: 28/02/2013
 *      Author: sequoiahead
 */

#include<helmet/io/MappingWriter.h>

namespace helmet {

/**
 *
 * @param path
 * @throw std::exception
 */
MappingWriter::MappingWriter(const std::string path)
		: pathHostsFile(path) {
	fileHosts.open(pathHostsFile.c_str(), std::ofstream::out);
	if (!fileHosts.good()) {
		std::ios_base::failure e(std::string("Failed to open hosts file ").append(pathHostsFile));
		throw e;
	}
}

MappingWriter::~MappingWriter() {
	fileHosts.close();
}

}
