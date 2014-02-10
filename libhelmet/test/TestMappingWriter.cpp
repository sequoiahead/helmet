#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

#include <helmet/io/MappingWriter.h>

namespace helmet {

    class TestMappingWriter : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(TestMappingWriter);
        CPPUNIT_TEST(testConstructor);
        CPPUNIT_TEST(testWriter1);
        CPPUNIT_TEST_SUITE_END();

    public:

        static std::string nonWritablePath;
        static std::string writablePath;

        void setUp() {
        }

        void tearDown() {

        }

        void testConstructor() {
            CPPUNIT_ASSERT_NO_THROW( MappingWriter errWriter(nonWritablePath) );
            CPPUNIT_ASSERT_NO_THROW( MappingWriter okWriter(writablePath) );
        }

        void testWriter1() {
            HostsGroup groupHosts("Hosts1");
            AddressGroup groupAddr("Addrs1");
            Mapping mapping(groupHosts, groupAddr);

            groupHosts.add("test1.com"_h);
            groupHosts.add("test2.com"_h);
            groupHosts.add("test3.com"_h);

            groupAddr.add("192.168.0.1"_a);
            groupAddr.add("192.168.0.2"_a);

            mapping.map("192.168.0.1"_a, "test1.com"_h);
            mapping.map("192.168.0.1"_a, "test2.com"_h);
            mapping.map("192.168.0.2"_a, "test3.com"_h);

            MappingWriter writer(writablePath);
            writer.write(mapping);
            
            std::ifstream file;
            file.open(writablePath.c_str());
            auto i = 0;
            std::string line;
            while (std::getline(file, line)) {
                if (i == 1) {
                    CPPUNIT_ASSERT(line == "192.168.0.1 test1.com test2.com");
                }
                if (i == 2) {
                    CPPUNIT_ASSERT(line == "192.168.0.2 test3.com");
                }
                i++;
            }
            CPPUNIT_ASSERT(i == 3);
            file.close();
        }

    private:
        MappingWriter* writer;
    };

    std::string TestMappingWriter::nonWritablePath = "/etc/hosts";
    std::string TestMappingWriter::writablePath = "/tmp/jjsjhsjshsjhsjsh";

    CPPUNIT_TEST_SUITE_REGISTRATION(TestMappingWriter);

}
