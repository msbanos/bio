/*
 * PairwiseAligner.h
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_ALIGN_PAIRWISEALIGNER_H_
#define BANOS_MS_CORE_BIO_ALIGN_PAIRWISEALIGNER_H_

#include "PairwiseAlignment.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace align {

/**
 * Base definition for a pairwise sequence aligner.
 */
class PairwiseAligner {
public:
	/**
	 * Default ctor.
	 */
	PairwiseAligner();

	/**
	 * Destructor.
	 */
	virtual ~PairwiseAligner();

	/**
	 * Perform an alignment.
	 * @param s1 One of the sequences to align.
	 * @param s2 The other sequence to align.
	 */
	virtual PairwiseAlignment* align(const std::string& s1, const std::string& s2) = 0;

	/**
	 * Perform an alignment against the target sequence.
	 * @param query The sequence to alignt to the target.
	 */
	virtual PairwiseAlignment* align(const std::string& query);

	/**
	 * Set the target sequence.
	 * @param target The new target sequence.
	 */
	virtual void setTargetSequence(const std::string* target);

protected:
	const std::string* target;
};

} /* namespace align */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_ALIGN_PAIRWISEALIGNER_H_ */
