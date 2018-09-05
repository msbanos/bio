/*
 * FastaReader_test.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: mike
 */

#define BOOST_TEST_MODULE FastaReader_test
#include <boost/test/included/unit_test.hpp>

#include "banos/ms/core/bio/io/FastaReader.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

BOOST_AUTO_TEST_CASE(test_read) {
	FastaReader<SequenceRecord> reader("tests/resources/FastaReader.fasta");

	SequenceRecord* record;

	record = reader.read();
	BOOST_CHECK(record->getId() == "read1");
	BOOST_CHECK(record->getSequence() == "AAAACCCC");
	BOOST_CHECK(record->getQualityScores() == "");
	delete record;

	record = reader.read();
	BOOST_CHECK(record->getId() == "read2");
	BOOST_CHECK(record->getSequence() == "TGCATGCTAAT");
	BOOST_CHECK(record->getQualityScores() == "");
	delete record;

	record = reader.read();
	BOOST_CHECK(record == NULL);
}

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
