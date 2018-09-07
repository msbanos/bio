/*
 * FastqWriter_test.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "banos/ms/core/bio/io/FastqWriter.h"

#define BOOST_TEST_MODULE FastaWriterTest
#include <boost/test/included/unit_test.hpp>

#include "banos/ms/core/bio/io/FastqReader.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

BOOST_AUTO_TEST_CASE(test_write) {
	const std::string FILE("FastqWriter.fastq");
	const std::string READ_NAME("MyRead");
	const std::string SEQUENCE("gcgagtctag");
	const std::string QUALITIES("HGGGGGGGGG");

	const SequenceRecord record(READ_NAME, SEQUENCE, QUALITIES);

	FastqWriter writer(FILE);
	writer.write(&record);
	writer.close();

	FastqReader reader(FILE);
	SequenceRecord* observed = reader.read();

	BOOST_CHECK(observed->getId() == READ_NAME);
	BOOST_CHECK(observed->getSequence() == SEQUENCE);
	BOOST_CHECK(observed->getQualityScores() == QUALITIES);
	delete observed;

	observed = reader.read();
	BOOST_CHECK(observed == NULL);

	std::remove(FILE.c_str());
}

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
