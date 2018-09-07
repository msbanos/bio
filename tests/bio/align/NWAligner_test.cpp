/*
 * NWAligner_test.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "banos/ms/core/bio/align/NWAligner.h"

#define BOOST_TEST_MODULE NWAligner_test
#include <boost/test/included/unit_test.hpp>

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace align {

/**
 * Test for align where the sequences are a perfect match.
 */
BOOST_AUTO_TEST_CASE(test_align_PerfectMatch) {
	const std::string SEQ("GTCGTCGGTTGCA");

	NWAligner aligner;
	PairwiseAlignment* alignment = aligner.align(SEQ, SEQ);

	BOOST_CHECK(SEQ == *alignment->getSequence1());
	BOOST_CHECK(SEQ == *alignment->getSequence2());

	const std::string& midline = *alignment->getMidline();
	BOOST_CHECK(SEQ.length() == midline.length());

	for (auto it = midline.begin(); it != midline.end(); ++it) {
		BOOST_CHECK(PairwiseAlignment::MIDLINE_MATCH == *it);
	}

	BOOST_CHECK(1 == alignment->getHomology());
	BOOST_CHECK(alignment->getScore());
	BOOST_CHECK(!alignment->hasGap());

	delete alignment;
}

/**
 * Test for align where there is a mismatch between the sequences.
 */
BOOST_AUTO_TEST_CASE(test_align_Mismatch) {
	const std::string SEQ1("GTCGTCGGTTGCA");
	const std::string SEQ2("GTCGTCAGTTGCA");

	NWAligner aligner;
	PairwiseAlignment* alignment = aligner.align(SEQ1, SEQ2);

	BOOST_CHECK(SEQ1 == *alignment->getSequence1());
	BOOST_CHECK(SEQ2 == *alignment->getSequence2());

	const std::string& midline = *alignment->getMidline();
	BOOST_CHECK(SEQ1.length() == midline.length());

	// 6M 1MM 6M
	for (size_t i = 0; i < 6; i++) {
		BOOST_CHECK(PairwiseAlignment::MIDLINE_MATCH == midline[i]);
	}

	BOOST_CHECK(PairwiseAlignment::MIDLINE_MISMATCH == midline[6]);

	for (size_t i = 7; i < midline.length(); i++) {
		BOOST_CHECK(PairwiseAlignment::MIDLINE_MATCH == midline[i]);
	}

	BOOST_CHECK(12.0 / 13.0 == alignment->getHomology());
	BOOST_CHECK(alignment->getScore());
	BOOST_CHECK(!alignment->hasGap());

	delete alignment;
}

/**
 * Test for align where there is an insertion in the first sequence.
 */
BOOST_AUTO_TEST_CASE(test_align_Insertion) {
	const std::string SEQ1("GTCGTCGAGTTGCA");
	const std::string SEQ2("GTCGTCGGTTGCA");

	NWAligner aligner;
	PairwiseAlignment* alignment = aligner.align(SEQ1, SEQ2);

	BOOST_CHECK(SEQ1 == *alignment->getSequence1());
	// 7M 1I 6M
	BOOST_CHECK(SEQ2.length() + 1 == alignment->getSequence2()->length());
	const std::string& aligned2 = *alignment->getSequence2();
	BOOST_CHECK(SEQ2.substr(0, 7) == aligned2.substr(0, 7));
	BOOST_CHECK(PairwiseAlignment::SEQUENCE_GAP == aligned2[7]);
	BOOST_CHECK(SEQ2.substr(8) == aligned2.substr(9));

	const std::string& midline = *alignment->getMidline();
	BOOST_CHECK(SEQ1.length() == midline.length());

	// 7M 1I 6M
	for (size_t i = 0; i < 7; i++) {
		BOOST_CHECK(PairwiseAlignment::MIDLINE_MATCH == midline[i]);
	}

	BOOST_CHECK(PairwiseAlignment::MIDLINE_GAP == midline[7]);

	for (size_t i = 8; i < midline.length(); i++) {
		BOOST_CHECK(PairwiseAlignment::MIDLINE_MATCH == midline[i]);
	}

	BOOST_CHECK(13.0 / 14.0 == alignment->getHomology());
	BOOST_CHECK(alignment->getScore());
	BOOST_CHECK(alignment->hasGap());

	delete alignment;
}

/**
 * Test for align where there is an deletion in the first sequence.
 */
BOOST_AUTO_TEST_CASE(test_align_Deletion) {
	const std::string SEQ1("GTCGTCGGTTGCA");
	const std::string SEQ2("GTCGTCGAGTTGCA");

	NWAligner aligner;
	PairwiseAlignment* alignment = aligner.align(SEQ1, SEQ2);

	// 7M 1I 6M
	BOOST_CHECK(SEQ1.length() + 1 == alignment->getSequence1()->length());
	const std::string& aligned1 = *alignment->getSequence1();
	BOOST_CHECK(SEQ1.substr(0, 7) == aligned1.substr(0, 7));
	BOOST_CHECK(PairwiseAlignment::SEQUENCE_GAP == aligned1[7]);
	BOOST_CHECK(SEQ1.substr(8) == aligned1.substr(9));

	BOOST_CHECK(SEQ2 == *alignment->getSequence2());

	const std::string& midline = *alignment->getMidline();
	BOOST_CHECK(SEQ2.length() == midline.length());

	// 7M 1I 6M
	for (size_t i = 0; i < 7; i++) {
		BOOST_CHECK(PairwiseAlignment::MIDLINE_MATCH == midline[i]);
	}

	BOOST_CHECK(PairwiseAlignment::MIDLINE_GAP == midline[7]);

	for (size_t i = 8; i < midline.length(); i++) {
		BOOST_CHECK(PairwiseAlignment::MIDLINE_MATCH == midline[i]);
	}

	BOOST_CHECK(13.0 / 14.0 == alignment->getHomology());
	BOOST_CHECK(alignment->getScore());
	BOOST_CHECK(alignment->hasGap());

	delete alignment;
}

} /* namespace align */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
