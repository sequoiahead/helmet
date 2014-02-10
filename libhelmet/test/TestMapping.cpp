#include <helmet/mapping/Mapping.h>

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

namespace helmet {

    class TestMapping : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(TestMapping);
            CPPUNIT_TEST(testConstructor);
            CPPUNIT_TEST(testCount);
            CPPUNIT_TEST(testValidity);
            CPPUNIT_TEST(testDoMapping);
            CPPUNIT_TEST(testRemove);
            CPPUNIT_TEST(testUnmappedHostnames);
        CPPUNIT_TEST_SUITE_END();

    public:
        static std::string GROUP_NAME_HOSTS;
        static std::string GROUP_NAME_ADDR;
        static Hostname HOSTNAME1;
        static Hostname HOSTNAME2;
        static Hostname HOSTNAME3;
        static Hostname HOSTNAME4;
        static IpAddress ADDR1;
        static IpAddress ADDR2;
        static IpAddress ADDR3;

        void setUp() {
            groupHosts = new HostsGroup(GROUP_NAME_HOSTS);
            groupAddr = new AddressGroup(GROUP_NAME_ADDR);
            mapping = new Mapping(*groupHosts, *groupAddr);

            groupHosts->add(HOSTNAME1);
            groupHosts->add(HOSTNAME2);
            groupHosts->add(HOSTNAME3);

            groupAddr->add(ADDR1);
            groupAddr->add(ADDR2);

            mapping->map(ADDR1, HOSTNAME1);
            mapping->map(ADDR1, HOSTNAME2);
            mapping->map(ADDR2, HOSTNAME3);
        }

        void tearDown() {
            delete mapping;
            delete groupHosts;
            delete groupAddr;
        }

        void testConstructor() {
            CPPUNIT_ASSERT(mapping->hostsGroup.name == GROUP_NAME_HOSTS);
            CPPUNIT_ASSERT(mapping->addressGroup.name == GROUP_NAME_ADDR);
        }

        void testCount() {
            CPPUNIT_ASSERT(mapping->count(ADDR1) == 2);
            CPPUNIT_ASSERT(mapping->count(ADDR2) == 1);
            CPPUNIT_ASSERT(mapping->count(ADDR3) == 0);
        }

        void testValidity() {
            CPPUNIT_ASSERT(mapping->isValid());
        }

        void testDoMapping() {
            Mapping::Hostnames addr1Map = mapping->getHostnames(ADDR1);

            for (auto host : addr1Map) {
                CPPUNIT_ASSERT(host == HOSTNAME1 || host == HOSTNAME2);
            }

            Mapping::Hostnames addr2Map = mapping->getHostnames(ADDR2);

            for (auto host : addr2Map) {
                CPPUNIT_ASSERT(host == HOSTNAME3);
            }

            bool thrown = false; //circumventing buggy CPPUNIT_ASSERT_THROW macros
            try {
                mapping->getHostnames(ADDR3);
            } catch (const std::exception& e) {
                thrown = true;
            }
            CPPUNIT_ASSERT(thrown);
        }

        void testRemove() {
            mapping->unmap(HOSTNAME1);
            mapping->unmap(HOSTNAME3);

            CPPUNIT_ASSERT(mapping->count(ADDR1) == 1);
            CPPUNIT_ASSERT(mapping->count(ADDR2) == 0);
        }

        void testUnmappedHostnames() {
            Mapping::Hostnames unmapped = mapping->getHostnamesUnmapped();
            for (auto host : unmapped) {
                CPPUNIT_ASSERT(host == HOSTNAME4);
            }
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
    Hostname TestMapping::HOSTNAME4("example.cc");
    IpAddress TestMapping::ADDR1("192.168.0.1");
    IpAddress TestMapping::ADDR2("192.168.0.2");
    IpAddress TestMapping::ADDR3("192.168.0.3");

    CPPUNIT_TEST_SUITE_REGISTRATION(TestMapping);

}
