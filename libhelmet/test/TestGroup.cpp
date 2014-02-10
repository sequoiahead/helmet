#include <helmet/mapping/HostsGroup.h>
#include <helmet/mapping/AddressGroup.h>

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

namespace helmet {

    class TestGroup : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(TestGroup);
        CPPUNIT_TEST(testConstructor);
        CPPUNIT_TEST(testAddrGroupConstructor);
        CPPUNIT_TEST(testAddRemove);
        CPPUNIT_TEST(testDoubleAdd);
        CPPUNIT_TEST_SUITE_END();

    public:
        static std::string GROUP_NAME;
        static Hostname HOSTNAME1;
        static Hostname HOSTNAME2;
        static Hostname HOSTNAME3;

        void setUp() {
            groupHosts = new HostsGroup(GROUP_NAME);
        }

        void tearDown() {
            delete groupHosts;
        }

        void testConstructor() {
            CPPUNIT_ASSERT(groupHosts->name == GROUP_NAME);
            CPPUNIT_ASSERT(groupHosts->isEmpty());
        }

        void testAddrGroupConstructor() {
            AddressGroup addrGroup(GROUP_NAME);
            CPPUNIT_ASSERT(addrGroup.name == GROUP_NAME);
            CPPUNIT_ASSERT(addrGroup.isEmpty());
        }

        void testAddRemove() {
            groupHosts->add(HOSTNAME1);
            groupHosts->add(HOSTNAME2);

            CPPUNIT_ASSERT(!groupHosts->isEmpty());

            for (HostsGroup::IteratorConst it = groupHosts->begin(); it != groupHosts->end(); it++) {
                CPPUNIT_ASSERT(*it == HOSTNAME1 || *it == HOSTNAME2);
            }

            groupHosts->remove(HOSTNAME1);

            CPPUNIT_ASSERT(*groupHosts->begin() == HOSTNAME2);

            groupHosts->remove(HOSTNAME2);

            CPPUNIT_ASSERT(groupHosts->isEmpty());
        }

        void testDoubleAdd() {
            groupHosts->add(HOSTNAME1);
            groupHosts->add(HOSTNAME2);
            groupHosts->add(HOSTNAME2);

            CPPUNIT_ASSERT(groupHosts->contains(HOSTNAME1));
            CPPUNIT_ASSERT(groupHosts->contains(HOSTNAME2));
            CPPUNIT_ASSERT(!groupHosts->contains(HOSTNAME3));

            CPPUNIT_ASSERT(groupHosts->size() == 2);
        }

    private:
        HostsGroup* groupHosts;
    };

    std::string TestGroup::GROUP_NAME = "group_name";
    Hostname TestGroup::HOSTNAME1("localhost");
    Hostname TestGroup::HOSTNAME2("example.net");
    Hostname TestGroup::HOSTNAME3("example.org");

    CPPUNIT_TEST_SUITE_REGISTRATION(TestGroup);

}
