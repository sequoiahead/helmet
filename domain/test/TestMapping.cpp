#include <helmet/domain/Mapping.h>

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

namespace helmet {

class TestMapping: public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE( TestMapping );
		CPPUNIT_TEST( testConstructor );
		CPPUNIT_TEST( testDoMapping );
	CPPUNIT_TEST_SUITE_END();

public:
	static std::string GROUP_NAME_HOSTS;
	static std::string GROUP_NAME_ADDR;
	static Hostname HOSTNAME1;
	static Hostname HOSTNAME2;
	static Hostname HOSTNAME3;
	static IpAddress ADDR1;
	static IpAddress ADDR2;

	void setUp() {
		groupHosts = new HostsGroup(GROUP_NAME_HOSTS);
		groupAddr = new AddressGroup(GROUP_NAME_ADDR);
		mapping = new Mapping(*groupHosts, *groupAddr);

		groupHosts->add(HOSTNAME1);
		groupHosts->add(HOSTNAME2);
		groupHosts->add(HOSTNAME3);

		groupAddr->add(ADDR1);
		groupAddr->add(ADDR2);
	}

	void tearDown() {
		delete groupHosts;
		delete groupAddr;
		delete mapping;
	}

	void testConstructor() {
		CPPUNIT_ASSERT(mapping->getHostsGroup().getName() == GROUP_NAME_HOSTS);
		CPPUNIT_ASSERT(mapping->getAddressGroup().getName() == GROUP_NAME_ADDR);
	}

	void testDoMapping() {
		mapping->map(ADDR1, HOSTNAME1);
		mapping->map(ADDR1, HOSTNAME2);
		mapping->map(ADDR2, HOSTNAME3);

		mapping->map(ADDR2, HOSTNAME1);
	}

private:
	HostsGroup* groupHosts;
	AddressGroup* groupAddr;
	Mapping* mapping;
};

std::string TestMapping::GROUP_NAME_HOSTS = "group_name";
std::string TestMapping::GROUP_NAME_ADDR = "addr_name";
Hostname TestMapping::HOSTNAME1("localhost");
Hostname TestMapping::HOSTNAME2("example.net");
Hostname TestMapping::HOSTNAME3("example.org");
IpAddress TestMapping::ADDR1("192.168.0.1");
IpAddress TestMapping::ADDR2("192.168.0.2");

CPPUNIT_TEST_SUITE_REGISTRATION( TestMapping);

}
