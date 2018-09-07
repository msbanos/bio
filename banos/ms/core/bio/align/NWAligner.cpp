/*
 * NWAligner.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "NWAligner.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace align {

// Note that these are the NCBI defaults, which are different from EMBOSS
const int MATCH_SCORE = 2;
const int MISMATCH_SCORE = -3;
const int GAP_OPEN_PENALTY = 5;
const int GAP_EXTENSION_PENALTY = 2;

NWAligner::NWAligner() : scores(NULL), directions(NULL) { }

NWAligner::~NWAligner() { }

PairwiseAlignment* NWAligner::align(const std::string& s1, const std::string& s2) {
	scores = new Matrix<int>(s1.length() + 1, s2.length() + 1, 0);
	directions = new Matrix<Direction>(s1.length() + 1, s2.length() + 1, STOP);

	initMatrices();
	computeScoringMatrix(s1, s2);
	PairwiseAlignment* alignment = traceback(s1, s2);

	delete scores;
	delete directions;

	return alignment;
}

void NWAligner::computeScoringMatrix(const std::string& s1, const std::string& s2) {
	int diagScore, s1Score, s2Score, lastDiagScore, lastS1Score, lastS2Score;
	bool inS1Gap, inS2Gap;

	for (size_t row = 2; row <= s1.length() + 1; row++) {
		lastDiagScore = scores->at(row - 1, 1);
		lastS1Score = scores->at(row, 1);
		inS1Gap = false;
		inS2Gap = directions->at(row - 1, 2) == UP;

		for (size_t col = 2; col <= s2.length() + 1; col++) {
			lastS2Score = scores->at(row - 1, col);

			diagScore = lastDiagScore + ((s1[row - 2] == s2[col - 2]) ? MATCH_SCORE : MISMATCH_SCORE);
			s1Score = lastS1Score - ((!inS1Gap) ? GAP_OPEN_PENALTY : GAP_EXTENSION_PENALTY);
			s2Score = lastS2Score - ((!inS2Gap) ? GAP_OPEN_PENALTY : GAP_EXTENSION_PENALTY);

			if (diagScore >= s1Score && diagScore >= s2Score) {
				lastS1Score = scores->at(row, col) = diagScore;
				directions->at(row, col) = DIAGONAL;
				inS1Gap = inS2Gap = false;
			} else if (s1Score >= s2Score) {
				lastS1Score = scores->at(row, col) = s1Score;
				directions->at(row, col) = LEFT;
				inS1Gap = true;
				inS2Gap = false;
			} else {
				lastS1Score = scores->at(row, col) = s2Score;
				directions->at(row, col) = UP;
				inS1Gap = false;
				inS2Gap = true;
			}

			lastDiagScore = lastS2Score;
		}
	}
}

PairwiseAlignment* NWAligner::traceback(const std::string& s1, const std::string& s2) {
	std::stringstream aligned1, aligned2, midline;
	bool gapped = false;

	size_t row = s1.length() + 1;
	size_t col = s2.length() + 1;
	Direction dir = directions->at(row, col);

	size_t matchCount = 0;
	while (dir != STOP) {
		switch (dir) {
		case DIAGONAL:
			aligned1 << s1[row - 2];
			aligned2 << s2[col - 2];

			if (s1[row - 2] == s2[col - 2]) {
				midline << PairwiseAlignment::MIDLINE_MATCH;
				matchCount++;
			} else {
				midline << PairwiseAlignment::MIDLINE_MISMATCH;
			}

			row--;
			col--;
			break;
		case UP:	// s2 gap
			aligned1 << s1[row - 2];
			aligned2 << PairwiseAlignment::SEQUENCE_GAP;
			midline << PairwiseAlignment::MIDLINE_GAP;
			row--;
			gapped = true;
			break;
		case LEFT:	// s1 gap
			aligned1 << PairwiseAlignment::SEQUENCE_GAP;
			aligned2 << s2[col - 2];
			midline << PairwiseAlignment::MIDLINE_GAP;
			col--;
			gapped = true;
			break;
		}

		dir = directions->at(row, col);
	}

	PairwiseAlignment* alignment = new PairwiseAlignment();
	alignment->setSequence1(makeReversedString(aligned1));
	alignment->setSequence2(makeReversedString(aligned2));
	alignment->setMidline(makeReversedString(midline));
	alignment->setHomolgy(static_cast<double>(matchCount) / alignment->getSequence1()->length());
	alignment->setScore(scores->at(scores->getNumberOfRows(), scores->getNumberOfColumns()));
	alignment->setHasGap(gapped);

	return alignment;
}

std::string* NWAligner::makeReversedString(const std::stringstream& stream) {
	std::string temp(stream.str());

	return new std::string(temp.rbegin(), temp.rend());
}

void NWAligner::initMatrices() {
	int lastScore = scores->at(1, 2) = -GAP_OPEN_PENALTY;
	directions->at(1, 2) = LEFT;
	for (size_t col = 3; col <= scores->getNumberOfColumns(); col++) {
		lastScore = scores->at(1, col) = lastScore - GAP_EXTENSION_PENALTY;
		directions->at(1, col) = LEFT;
	}

	lastScore = scores->at(2, 1) = -GAP_OPEN_PENALTY;
	directions->at(2, 1) = UP;
	for (size_t row = 3; row <= scores->getNumberOfRows(); row++) {
		lastScore = scores->at(row, 1) = lastScore - GAP_EXTENSION_PENALTY;
		directions->at(row, 1) = UP;
	}
}

} /* namespace align */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
