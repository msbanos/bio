/*
 * string.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "string.h"

namespace banos {
namespace ms {
namespace core {
namespace utils {
namespace string {

/**
 * Get the Hamming distance between to strings.
 * @param s1 A string.
 * @param s2 Another string.
 * @return The Hamming distance between s1 and s2.
 */
size_t hamming(const std::string& s1, const std::string& s2) {
	size_t distance = 0;

	for (auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end(), it2 != s2.end(); ++it1, ++it2) {
		if (*it1 != *it2)  distance++;
	}

    return distance;
}

} /* string */
} /* utils */
} /* core */
} /* ms */
} /* banos */


