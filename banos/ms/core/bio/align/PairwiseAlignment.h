/*
 * PairwiseAlignment.h
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_ALIGN_PAIRWISEALIGNMENT_H_
#define BANOS_MS_CORE_BIO_ALIGN_PAIRWISEALIGNMENT_H_

#include <string>

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace align {

/**
 * Base definition for a pairwise alignment.
 */
class PairwiseAlignment {
public:
	const static char SEQUENCE_GAP;
	const static char MIDLINE_MATCH;
	const static char MIDLINE_MISMATCH;
	const static char MIDLINE_GAP;

	/**
	 * Default ctor.
	 */
	PairwiseAlignment();

	/**
	 * Destructor.
	 */
	virtual ~PairwiseAlignment();

	/**
	 * Get the first aligned sequence.
	 * @return The sequence.
	 */
	const std::string* getSequence1() const;

	/**
	 * Set the first aligned sequence.
	 * NOTE: this will be treated as a managed resource.
	 * @param seq The sequence.
	 */
	void setSequence1(const std::string* const seq);

	/**
	 * Get the second aligned sequence.
	 * @return The sequence.
	 */
	const std::string* getSequence2() const;

	/**
	 * Set the second aligned sequence.
	 * NOTE: this will be treated as a managed resource.
	 * @param seq The sequence.
	 */
	void setSequence2(const std::string* const seq);

	/**
	 * Get the midline.
	 * @return The midline.
	 */
	const std::string* getMidline() const;

	/**
	 * Set the midline.
	 * NOTE: this will be treated as a managed resource.
	 * @param midline The midline.
	 */
	void setMidline(const std::string* const midline);

	/**
	 * Get the alignment homology.
	 * @return The homology.
	 */
	double getHomology() const;

	/**
	 * Set the alignment homology.
	 * @param homology The homology.
	 */
	void setHomolgy(const double homology);

	/**
	 * Get the alignment score.
	 * @return The score.
	 */
	double getScore() const;

	/**
	 * Set the alignment score.
	 * @param score The score.
	 */
	void setScore(const double score);

	/**
	 * Get the alignment start index (1-based) in the first sequence.
	 * @return The start index.
	 */
	size_t getStart1() const;

	/**
	 * Set the alignment start index (1-based) for the first sequence.
	 * @param start The start index.
	 */
	void setStart1(const size_t start);

	/**
	 * Get the alignment start index (1-based) in the second sequence.
	 * @return The start index.
	 */
	size_t getStart2() const;

	/**
	 * Set the alignment start index (1-based) for the second sequence.
	 * @param start The start index.
	 */
	void setStart2(const size_t start);

	/**
	 * Get the alignment end index (1-based) in the first sequence.
	 * @return The end index.
	 */
	size_t getEnd1() const;

	/**
	 * Set the alignment end index (1-based) for the first sequence.
	 * @param end The end index.
	 */
	void setEnd1(const size_t end);

	/**
	 * Get the alignment end index (1-based) in the second sequence.
	 * @return The end index.
	 */
	size_t getEnd2() const;

	/**
	 * Set the alignment end index (1-based) for the second sequence.
	 * @param end The end index.
	 */
	void setEnd2(const size_t end);

	/**
	 * Flag to indicate if the alignment contains a gap.
	 * @return True if a gap exists; otherwise false.
	 */
	bool hasGap() const;

	/**
	 * Set whether or not the alignment contains a gap.
	 * @param hasGap Indicator of if a gap exists (true).
	 */
	void setHasGap(const bool hasGap);

private:
	const std::string* seq1, * seq2, * midline;
	double homology, score;
	size_t start1, end1, start2, end2;
	bool gapped;
};

} /* namespace align */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_ALIGN_PAIRWISEALIGNMENT_H_ */
