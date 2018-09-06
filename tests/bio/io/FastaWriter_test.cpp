/*
 * FastaWriter_test.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#include "banos/ms/core/bio/io/FastaWriter.h"

#define BOOST_TEST_MODULE FastaWriter_test
#include <boost/test/included/unit_test.hpp>

#include "banos/ms/core/bio/io/FastaReader.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

BOOST_AUTO_TEST_CASE(test_write) {
	const std::string FILE("FastaWriter.fasta");
	const std::string READ_NAME("MyRead");
	const std::string SEQUENCE("gcgagtctag");

	const SequenceRecord record(READ_NAME, SEQUENCE);

	FastaWriter writer(FILE);
	writer.write(&record);
	writer.close();

	FastaReader<SequenceRecord> reader(FILE);
	SequenceRecord* observed = reader.read();

	BOOST_CHECK(observed->getId() == READ_NAME);
	BOOST_CHECK(observed->getSequence() == SEQUENCE);
	BOOST_CHECK(observed->getQualityScores() == "");
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
