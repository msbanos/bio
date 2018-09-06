/*
 * FastqReader_test.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#include "banos/ms/core/bio/io/FastqReader.h"

#define BOOST_TEST_MODULE FastqReaderTest
#include <boost/test/included/unit_test.hpp>

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

BOOST_AUTO_TEST_CASE(test_read) {
	FastqReader reader("tests/resources/FastqReader.fastq");

	SequenceRecord* record;

	record = reader.read();
	BOOST_CHECK(record->getId() == "read1");
	BOOST_CHECK(record->getSequence() == "AAAACCCC");
	BOOST_CHECK(record->getQualityScores() == "HHHBCBBA");
	delete record;

	record = reader.read();
	BOOST_CHECK(record->getId() == "read2");
	BOOST_CHECK(record->getSequence() == "TGCATGCT");
	BOOST_CHECK(record->getQualityScores() == "AABCABCH");
	delete record;

	record = reader.read();
	BOOST_CHECK(record == NULL);
}

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
