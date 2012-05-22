#include <domain/HostsGroupMapping.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

namespace helmet {

class TestHostsGroup: public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE( TestHostsGroup );
		CPPUNIT_TEST( testConstructor );
		CPPUNIT_TEST( testAddRemove );
	CPPUNIT_TEST_SUITE_END();

public:
	static IpAddress IP_ADDR;
	static Hostname HOSTNAME1;
	static Hostname HOSTNAME2;

	void setUp() {
		group = new HostsGroupMapping(IP_ADDR);
	}

	void tearDown() {
		delete group;
	}

	void testConstructor() {
		CPPUNIT_ASSERT(group->getIpAddress() == IP_ADDR);
	}

	void testAddRemove() {
		group->addHostname(HOSTNAME1);
		group->addHostname(HOSTNAME2);

		CPPUNIT_ASSERT(group->getHostnames().front() == HOSTNAME1);
		CPPUNIT_ASSERT(group->getHostnames().back() == HOSTNAME2);

		group->removeHostname(HOSTNAME1);

		CPPUNIT_ASSERT(group->getHostnames().front() == HOSTNAME2);
		CPPUNIT_ASSERT(group->getHostnames().back() == HOSTNAME2);

		group->removeHostname(HOSTNAME2);

		CPPUNIT_ASSERT(group->getHostnames().empty());
	}

private:
	HostsGroupMapping* group;
};

IpAddress TestHostsGroup::IP_ADDR = "127.0.0.1";
Hostname TestHostsGroup::HOSTNAME1 = "localhost";
Hostname TestHostsGroup::HOSTNAME2 = "example.net";

CPPUNIT_TEST_SUITE_REGISTRATION( TestHostsGroup);

}
