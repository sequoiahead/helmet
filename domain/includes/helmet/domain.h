#ifndef MODEL_H_
#define MODEL_H_

#include <string>

namespace helmet {

class MappedMixin {
public:
	inline explicit MappedMixin() :
			isMapped(false) {
	}

	inline explicit MappedMixin(bool value) :
			isMapped(value) {
	}

	inline void setMapped(bool value) {
		isMapped = value;
	}

	inline bool mapped() const {
		return isMapped;
	}

	inline ~MappedMixin() {
	}

private:
	bool isMapped;
};

class Hostname : public std::string, public MappedMixin {
public:

	inline explicit Hostname(const std::string& hostname, bool mapped = false) :
			std::string(hostname), MappedMixin(mapped) {
	}

	virtual ~Hostname() {
	}

};

class IpAddress : public std::string, public MappedMixin {
public:

	inline explicit IpAddress(const std::string& ipaddr, bool mapped = false) :
			std::string(ipaddr), MappedMixin(mapped) {
	}

	virtual ~IpAddress() {
	}

};

}  // namespace helmet

#endif /* STATE_H_ */
