/*
 * string.h
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_UTILS_STRING_H_
#define BANOS_MS_CORE_UTILS_STRING_H_

#include <string>

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
size_t hamming(const std::string& s1, const std::string& s2);

} /* string */
} /* utils */
} /* core */
} /* ms */
} /* banos */

#endif /* BANOS_MS_CORE_UTILS_STRING_H_ */
