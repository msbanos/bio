/*
 * astar.h
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_SEARCH_ASTAR_H_
#define BANOS_MS_CORE_SEARCH_ASTAR_H_

#include <algorithm>
#include <queue>
#include <unordered_set>

namespace banos {
namespace ms {
namespace core {
namespace search {
namespace astar {

/**
 * A search state node.
 */
class Node {
public:
	/**
	 * Ctor.
	 */
	Node();

	/**
	 * Destructor.
	 */
	virtual ~Node();

	/**
	 * Get the fitness score.
	 * @return The node fitness.
	 */
	virtual double getFitness() const = 0;

	/**
	 * Determine if node is a solution.
	 * @return True if the node represents a solution state; otherwise false.
	 */
	virtual bool isEndNode() const = 0;
};

/**
 * Search next state generator.
 * @type N The search node class.
 */
template <class N>
class NodeGenerator {
public:
	/**
	 * Ctor.
	 */
	NodeGenerator()  { }

	/**
	 * Destructor.
	 */
	virtual ~NodeGenerator()  { }

	/**
	 * Generate the next possible states.
	 * @param nodes The set of nodes to populate representing the next possible states.
	 * @param node The node to generate the set of possible next states for.
	 */
	virtual void next(std::unordered_set<const N*>& nodes, const N* const node) const {
		if (node->isEndNode())  return;

		generateNextNodes(nodes, node);
	}

protected:
	/**
	 * Generate the next possible states.
	 * @param nodes The set of nodes to populate representing the next possible states.
	 * @param node The node to generate the set of possible next states for.
	 */
	virtual void generateNextNodes(std::unordered_set<const N*>& nodes, const N* const node) const = 0;
};


/**
 * Comparator class to use for state prioritization.
 * @type N The search node type.
 */
template <class N>
class __NodeComparator {
public:
	/**
	 * Comparator method.
	 * @param lhs A node to be compared.
	 * @param rhs Another node to be compared.
	 */
	bool operator() (const N* lhs, const N* rhs) const {
		return lhs->getFitness() > rhs->getFitness();
	}
};


/**
 * Perform the search.
 * @param start The search start state.
 * @param generator The next-state node generator.
 * @return The search solution state.
 * @type N The search node type.
 */
template <class N>
const N* search(const N* const start, const NodeGenerator<N>* const generator) {
	std::priority_queue<const N*, std::vector<const N*>, __NodeComparator<N>> nodes;
	nodes.push(start);

	std::unordered_set<const N*> next;
	while (!nodes.empty()) {
		auto current = nodes.top();
		nodes.pop();

		if (current->isEndNode()) {
			while (!nodes.empty()) {
				delete nodes.top();
				nodes.pop();
			}

			return current;
		}

		next.clear();
		generator->next(next, current);
		for (auto it = next.begin(); it != next.end(); ++it) {
			nodes.push(*it);
		}

		if (current != start)  delete current;
	}

	return NULL;
}

} /* namespace astar */
} /* namespace search */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_SEARCH_ASTAR_H_ */
