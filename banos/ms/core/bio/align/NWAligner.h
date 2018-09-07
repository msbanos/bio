/*
 * NWAligner.h
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_ALIGN_NWALIGNER_H_
#define BANOS_MS_CORE_BIO_ALIGN_NWALIGNER_H_

#include <sstream>

#include "banos/ms/core/Matrix.h"
#include "PairwiseAligner.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace align {

/**
 * Pairwise sequence aligner using the Needleman-Wunsch algorithm.
 */
class NWAligner : public PairwiseAligner {
public:
	/**
	 * Ctor.
	 */
	NWAligner();

	/**
	 * Destructor.
	 */
	virtual ~NWAligner();

	/**
	 * Perform an alignment.
	 * @param s1 One of the sequences to align.
	 * @param s2 The other sequence to align.
	 */
	virtual PairwiseAlignment* align(const std::string& s1, const std::string& s2);

private:
	enum Direction { UP, DIAGONAL, LEFT, STOP };

	/**
	 * Turn a string stream into its reversed string representation.
	 * @param stream The stream to process.
	 * @return The reversed string.
	 */
	static std::string* makeReversedString(const std::stringstream& stream);

	/**
	 * Compute the scoring matrix.
	 * @param s1 One of the sequences to align.
	 * @param s2 The other sequence to align.
	 */
	void computeScoringMatrix(const std::string& s1, const std::string& s2);

	/**
	 * Perform the traceback to generate the alignment.
	 * @param s1 One of the sequences to align.
	 * @param s2 The other sequence to align.
	 */
	PairwiseAlignment* traceback(const std::string& s1, const std::string& s2);

	/**
	 * Initialize the scoring and direction matrices.
	 */
	void initMatrices();

	Matrix<int>* scores;
	Matrix<Direction>* directions;
};

} /* namespace align */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_ALIGN_NWALIGNER_H_ */
