#ifndef HELMET_TYPES_H_
#define HELMET_TYPES_H_

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

inline IpAddress operator"" _a(const char* str, size_t n) {
    return IpAddress(str);
}

inline Hostname operator"" _h(const char* str, size_t n) {
    return Hostname(str);
}

}  // namespace helmet

#endif /* HELMET_TYPES_H_ */
