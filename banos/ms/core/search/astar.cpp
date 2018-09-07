/*
 * astar.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "astar.h"

namespace banos {
namespace ms {
namespace core {
namespace search {
namespace astar {

Node::Node()  { }

Node::~Node()  { }

bool __NodeComparator::operator() (const Node* lhs, const Node* rhs) const {
	return lhs->getFitness() > rhs->getFitness();
}

} /* namespace astar */
} /* namespace search */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

