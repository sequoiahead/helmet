#ifndef TYPES_H_
#define TYPES_H_

#include <string>

namespace helmet {

class Hostname : public std::string {
public:
	explicit Hostname(const std::string& hostname);
};

class IpAddress : public std::string {
public:
	explicit IpAddress(const std::string& ipaddr);
};

inline Hostname::Hostname(const std::string& hostname) :
		std::string(hostname) {
}

inline IpAddress::IpAddress(const std::string& ipaddr) :
		std::string(ipaddr) {
}

}  // namespace helmet

#endif /* TYPES_H_ */
