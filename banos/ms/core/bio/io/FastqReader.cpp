/*
 * FastqReader.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#include "FastqReader.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

FastqReader::FastqReader(const std::string& file) : FastqReaderBase(file) { }

FastqReader::~FastqReader() { }

SequenceRecord* FastqReader::makeRecord() {
	return new SequenceRecord(id.substr(1), sequence, qualities);
}

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
