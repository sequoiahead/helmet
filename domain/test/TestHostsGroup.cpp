#include <helmet/domain/HostsGroup.h>

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

namespace helmet {

class TestHostsGroup: public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE( TestHostsGroup );
		CPPUNIT_TEST( testConstructor );
		CPPUNIT_TEST( testAddRemove );
		CPPUNIT_TEST( testDoubleAdd );
	CPPUNIT_TEST_SUITE_END();

public:
	static std::string GROUP_NAME;
	static Hostname HOSTNAME1;
	static Hostname HOSTNAME2;

	void setUp() {
		group = new HostsGroup(GROUP_NAME);
	}

	void tearDown() {
		delete group;
	}

	void testConstructor() {
		CPPUNIT_ASSERT(group->getName() == GROUP_NAME);
		CPPUNIT_ASSERT(group->empty());
	}

	void testAddRemove() {
		group->addHostname(HOSTNAME1);
		group->addHostname(HOSTNAME2);

		CPPUNIT_ASSERT(!group->empty());

		for (HostsGroup::IteratorConst it = group->begin(); it != group->end(); it++) {
			CPPUNIT_ASSERT(*it == HOSTNAME1 || *it == HOSTNAME2);
		}

		group->removeHostname(HOSTNAME1);

		CPPUNIT_ASSERT(*group->begin() == HOSTNAME2);

		group->removeHostname(HOSTNAME2);

		CPPUNIT_ASSERT(group->empty());
	}

	void testDoubleAdd() {
		group->addHostname(HOSTNAME1);
		group->addHostname(HOSTNAME2);
		group->addHostname(HOSTNAME2);

		CPPUNIT_ASSERT(group->size() == 2);
	}

private:
	HostsGroup* group;
};

Hostname TestHostsGroup::GROUP_NAME = "group_name";
Hostname TestHostsGroup::HOSTNAME1 = "localhost";
Hostname TestHostsGroup::HOSTNAME2 = "example.net";

CPPUNIT_TEST_SUITE_REGISTRATION( TestHostsGroup);

}
