/*
 * FastqWriter.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "FastqWriter.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

FastqWriter::FastqWriter(const std::string& file) : FileWriter(file) { }

FastqWriter::~FastqWriter() { }

void FastqWriter::write(const SequenceRecord* const record) {
	writeLine(HEADER_DELIM + record->getId());
	writeLine(record->getSequence());
	writeLine("+");
	writeLine(record->getQualityScores());
}

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
