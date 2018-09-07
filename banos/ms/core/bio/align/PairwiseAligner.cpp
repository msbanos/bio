/*
 * PairwiseAligner.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "PairwiseAligner.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace align {

PairwiseAligner::PairwiseAligner() : target(NULL) { }

PairwiseAligner::~PairwiseAligner() { }

void PairwiseAligner::setTargetSequence(const std::string* target) {
	this->target = target;
}

PairwiseAlignment* PairwiseAligner::align(const std::string& query) {
	return align(*target, query);
}

} /* namespace align */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
