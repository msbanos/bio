/*
 * PairwiseAlignment.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "PairwiseAlignment.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace align {

const char PairwiseAlignment::SEQUENCE_GAP = '-';
const char PairwiseAlignment::MIDLINE_MATCH = '|';
const char PairwiseAlignment::MIDLINE_MISMATCH = '.';
const char PairwiseAlignment::MIDLINE_GAP = ' ';

PairwiseAlignment::PairwiseAlignment() : seq1(NULL), seq2(NULL), midline(NULL), homology(-1), score(0.0), start1(0),
		end1(0), start2(0), end2(0), gapped(false) { }

PairwiseAlignment::~PairwiseAlignment() {
	if (seq1)  delete seq1;
	if (seq2)  delete seq2;
	if (midline)  delete midline;
}

const std::string* PairwiseAlignment::getSequence1() const {
	return seq1;
}

void PairwiseAlignment::setSequence1(const std::string* const seq) {
	seq1 = seq;
}

const std::string* PairwiseAlignment::getSequence2() const {
	return seq2;
}

void PairwiseAlignment::setSequence2(const std::string* const seq) {
	seq2 = seq;
}

const std::string* PairwiseAlignment::getMidline() const {
	return midline;
}

void PairwiseAlignment::setMidline(const std::string* const midline) {
	this->midline = midline;
}

double PairwiseAlignment::getHomology() const {
	return homology;
}

void PairwiseAlignment::setHomolgy(const double homology) {
	this->homology = homology;
}

double PairwiseAlignment::getScore() const {
	return score;
}

void PairwiseAlignment::setScore(const double score) {
	this->score = score;
}

size_t PairwiseAlignment::getStart1() const {
	return start1;
}

void PairwiseAlignment::setStart1(const size_t start){
	start1 = start;
}

size_t PairwiseAlignment::getStart2() const {
	return start2;
}

void PairwiseAlignment::setStart2(const size_t start) {
	start2 = start;
}

size_t PairwiseAlignment::getEnd1() const {
	return end1;
}

void PairwiseAlignment::setEnd1(const size_t end) {
	end1 = end;
}

size_t PairwiseAlignment::getEnd2() const {
	return end2;
}

void PairwiseAlignment::setEnd2(const size_t end) {
	end2 = end;
}

bool PairwiseAlignment::hasGap() const  { return gapped; }

void PairwiseAlignment::setHasGap(const bool hasGap) {
	gapped = hasGap;
}

} /* namespace align */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
