/*
 * SequenceRecord.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: mike
 */

#include "SequenceRecord.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {

SequenceRecord::SequenceRecord(const std::string& id, const std::string& seq) : id(id), seq(seq)  { }

SequenceRecord::SequenceRecord(const std::string& id, const std::string& seq, const std::string& quals)
	: id(id), seq(seq), quals(quals) { }

SequenceRecord::~SequenceRecord() { }

const std::string& SequenceRecord::getId() const {
	return id;
}

const std::string& SequenceRecord::getSequence() const {
	return seq;
}

const std::string& SequenceRecord::getQualityScores() const {
	return quals;
}

void SequenceRecord::ltrim(const unsigned int length) {
	seq.erase(0, length);
	quals.erase(0, length);
}

size_t SequenceRecord::length() const {
	return seq.length();
}

void SequenceRecord::setId(const std::string& id) {
	this->id = id;
}

bool SequenceRecord::operator ==(const SequenceRecord& other) const {
	return id == other.id && seq == other.seq && quals == other.quals;
}

} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
