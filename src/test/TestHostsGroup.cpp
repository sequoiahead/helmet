#include "../main/state/HostsGroup.h"
#include <cppunit/ui/text/TestRunner.h>

class TestHostsGroup : public CppUnit::TestCase {
public:
	TestHostsGroup(std::string name) :
			CppUnit::TestCase(name) {
	}

	void runTest() {
		CPPUNIT_ASSERT(Complex(10, 1) == Complex(10, 1));
		CPPUNIT_ASSERT(!(Complex(1, 1) == Complex(2, 2)));
	}
};
