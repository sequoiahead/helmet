/*
 * TestMappingWriter.cpp
 *
 *  Created on: 28/02/2013
 *      Author: sequoiahead
 */
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

#include <helmet/io/MappingWriter.h>

namespace helmet {

class TestMappingWriter : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE( TestMappingWriter );
		CPPUNIT_TEST( testConstructor);
	CPPUNIT_TEST_SUITE_END();

public:

	static std::string existentPath;
	static std::string nonExistentPath;

	void setUp() {
	}

	void tearDown() {

	}

	void testConstructor() {
		CPPUNIT_FAIL("Unknown exception");
		try {
			MappingWriter okWriter(existentPath);
		} catch (std::ios_base::failure& e) {
			CPPUNIT_FAIL("Failes to construct writer object from existen file");
		}
		try {
			MappingWriter errWriter(nonExistentPath);
		} catch (std::ios_base::failure& e) {
			//ok
		} catch (std::exception& e) {
			CPPUNIT_FAIL("Unknown exception");
		}
	}

private:
	MappingWriter* writer;
};

std::string TestMappingWriter::existentPath = "/etc/hosts";
std::string TestMappingWriter::nonExistentPath = "/tmp/jjsjhsjshsjhsjsh";

}
