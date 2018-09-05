/*
 * SequenceRecord_test.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: mike
 */

#define BOOST_TEST_MODULE SequenceRecord_test
#include <boost/test/included/unit_test.hpp>

#include "banos/ms/core/bio/SequenceRecord.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {

/**
 * Test for left trimming a record when it does not have a quality string.
 */
BOOST_AUTO_TEST_CASE(test_ltrim_no_qualities) {
	SequenceRecord record("id", "AGT");

	record.ltrim(2);

	BOOST_CHECK(record.getSequence() == "T");
}

/**
 * Test for left trimming a record when it has a quality string.
 */
BOOST_AUTO_TEST_CASE(test_ltrim_with_qualities) {
	SequenceRecord record("id", "AGT", "HAB");

	record.ltrim(2);

	BOOST_CHECK(record.getSequence() == "T");
	BOOST_CHECK(record.getQualityScores() == "B");
}

/**
 * Test for left trimming a record when the number of bases to trim is greater than the length of the sequence.
 */
BOOST_AUTO_TEST_CASE(test_ltrim_length_greater_than_sequence) {
	SequenceRecord record("id", "A", "H");

	record.ltrim(5);

	BOOST_CHECK(record.getSequence() == "");
	BOOST_CHECK(record.getQualityScores() == "");
}

/**
 * Basic test for checking the equality of 2 records.
 */
BOOST_AUTO_TEST_CASE(test_equals) {
	SequenceRecord record1("id", "A", "H");
	SequenceRecord record2("id1", "A", "H");
	SequenceRecord record3("id", "AA", "H");
	SequenceRecord record4("id", "A", "HH");

	BOOST_CHECK(record1 == record1);
	BOOST_CHECK(!(record1 == record2));
	BOOST_CHECK(!(record1 == record3));
	BOOST_CHECK(!(record1 == record4));
}

} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
