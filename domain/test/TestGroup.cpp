#include <helmet/domain/HostsGroup.h>

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

namespace helmet {

class TestGroup: public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE( TestGroup );
		CPPUNIT_TEST( testConstructor );
		CPPUNIT_TEST( testAddRemove );
		CPPUNIT_TEST( testDoubleAdd );
	CPPUNIT_TEST_SUITE_END();

public:
	static std::string GROUP_NAME;
	static Hostname HOSTNAME1;
	static Hostname HOSTNAME2;
	static Hostname HOSTNAME3;

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
		group->add(HOSTNAME1);
		group->add(HOSTNAME2);

		CPPUNIT_ASSERT(!group->empty());

		for (HostsGroup::IteratorConst it = group->begin(); it != group->end(); it++) {
			CPPUNIT_ASSERT(*it == HOSTNAME1 || *it == HOSTNAME2);
		}

		group->remove(HOSTNAME1);

		CPPUNIT_ASSERT(*group->begin() == HOSTNAME2);

		group->remove(HOSTNAME2);

		CPPUNIT_ASSERT(group->empty());
	}

	void testDoubleAdd() {
		group->add(HOSTNAME1);
		group->add(HOSTNAME2);
		group->add(HOSTNAME2);

		CPPUNIT_ASSERT(group->contains(HOSTNAME1));
		CPPUNIT_ASSERT(group->contains(HOSTNAME2));
		CPPUNIT_ASSERT(!group->contains(HOSTNAME3));

		CPPUNIT_ASSERT(group->size() == 2);
	}

private:
	HostsGroup* group;
};

std::string TestGroup::GROUP_NAME = "group_name";
Hostname TestGroup::HOSTNAME1("localhost");
Hostname TestGroup::HOSTNAME2("example.net");
Hostname TestGroup::HOSTNAME3("example.org");

CPPUNIT_TEST_SUITE_REGISTRATION( TestGroup);

}
