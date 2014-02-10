#include <helmet/io/MappingWriter.h>
#include <iostream>

namespace helmet {

/**
 *
 * @param path
 * @throw std::exception
 */
MappingWriter::MappingWriter(const std::string path)
		: pathHostsFile(path) {
}

void MappingWriter::write(const Mapping& mapping) {
    fileHosts.open(pathHostsFile.c_str(), std::ofstream::out);
    if (!fileHosts.good()) {
            std::ios_base::failure e(std::string("Failed to open hosts file ").append(pathHostsFile));
            throw e;
    }
    
    fileHosts << "#mapping " << mapping.hostsGroup.name;
    fileHosts << " to " << mapping.addressGroup.name << '\n';
    for (auto addr: mapping.addressGroup) {
        fileHosts << addr;
        for (auto host: mapping.getHostnames(addr)) {
            fileHosts << " " << host;
        }
        fileHosts << '\n';
    }
    
    fileHosts.close();
}

MappingWriter::~MappingWriter() {
}

}
