/*
 * string_test.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "banos/ms/core/utils/string.h"

#define BOOST_TEST_MODULE string_test
#include <boost/test/included/unit_test.hpp>

namespace banos {
namespace ms {
namespace core {
namespace utils {
namespace string {

/**
 * Test of computing distance when the same string is used for both params.
 */
BOOST_AUTO_TEST_CASE(test_hamming_SameString) {
    const std::string S("jjasfd");

    BOOST_CHECK(!hamming(S, S));
}

/**
 * Test of computing distance when there multiple differences in the input strings.
 */
BOOST_AUTO_TEST_CASE(test_hamming_MultipleDiffs) {
    BOOST_CHECK(2 == hamming("TEST", "NEXT"));
}

} /* string */
} /* utils */
} /* core */
} /* ms */
} /* banos */
