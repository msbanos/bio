/*
 * FastaWriter.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#include "FastaWriter.h"

#include "FastaReader.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

FastaWriter::FastaWriter(const std::string& file) : FileWriter(file) { }

FastaWriter::~FastaWriter() { }

void FastaWriter::write(const SequenceRecord* const record) {
	writeLine(FastaReader<SequenceRecord>::HEADER_DELIM + record->getId());
	writeLine(record->getSequence());
}

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
