/*
 * BasicFileReader_test.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#include "banos/ms/core/io/BasicFileReader.h"

#define BOOST_TEST_MODULE BasicFileReaderTest
#include <boost/test/included/unit_test.hpp>

namespace banos {
namespace ms {
namespace core {
namespace io {

BOOST_AUTO_TEST_CASE(test_read) {
	BasicFileReader reader("tests/resources/BasicFileReader.txt");

	std::string* record;

	record = reader.read();
	BOOST_CHECK(*record == "line1");
	delete record;

	record = reader.read();
	BOOST_CHECK(*record == "line2");
	delete record;

	record = reader.read();
	BOOST_CHECK(*record == "");
	delete record;

	record = reader.read();
	BOOST_CHECK(record == NULL);
}

} /* namespace io */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
