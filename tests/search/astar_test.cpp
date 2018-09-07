/*
 * astar_test.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "banos/ms/core/search/astar.h"

#define BOOST_TEST_MODULE astar_test
#include <boost/test/included/unit_test.hpp>

namespace banos {
namespace ms {
namespace core {
namespace search {
namespace astar {

const size_t STOP_FITNESS = 10;

class TestNode : public Node {
public:
	TestNode(const size_t value) : value(value)  { }

	virtual double getFitness() const  { return value; }

	virtual bool isEndNode() const  { return value >= STOP_FITNESS; }

private:
	size_t value;
};


class TestGenerator : public NodeGenerator<TestNode> {
public:
	TestGenerator()  { }

	virtual ~TestGenerator()  { }

protected:
	virtual void generateNextNodes(std::unordered_set<const TestNode*>& nodes, const TestNode* const node) const {
		if (node->getFitness() >= STOP_FITNESS)  return;

		for (size_t i = 1; i <= 3; i++) {
			nodes.insert(new TestNode(node->getFitness() + i));
		}
	}
};

/**
 * Basic test for performing a search.
 */
BOOST_AUTO_TEST_CASE(test_search) {
	TestNode start(1);
	TestGenerator generator;

	const TestNode* end = search(&start, &generator);

	BOOST_CHECK(STOP_FITNESS <= end->getFitness());

	delete end;
}

} /* namespace astar */
} /* namespace search */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
