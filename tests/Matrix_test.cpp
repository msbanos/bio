/*
 * Matrix_test.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#include "banos/ms/core/Matrix.h"

#define BOOST_TEST_MODULE Matrix_test
#include <boost/test/included/unit_test.hpp>

namespace banos {
namespace ms {
namespace core {

/**
 * Test for at to make sure values get set/retrieved correctly.
 */
BOOST_AUTO_TEST_CASE(test_at) {
	const size_t ROWS = 2;
	const size_t COLS = 3;

	Matrix<int> matrix(ROWS, COLS);

	BOOST_CHECK(ROWS == matrix.getNumberOfRows());
	BOOST_CHECK(COLS == matrix.getNumberOfColumns());

	int i = 1;
	for (size_t row = 1; row <= ROWS; row++) {
		for (size_t col = 1; col <= COLS; col++) {
			matrix.at(row, col) = i++;
		}
	}

	i = 1;
	for (size_t row = 1; row <= ROWS; row++) {
		for (size_t col = 1; col <= COLS; col++) {
			BOOST_CHECK(i++ == matrix.at(row, col));
		}
	}
}

/**
 * Basic test for getLargestLocation.
 */
BOOST_AUTO_TEST_CASE(test_getLargestLocation) {
	const size_t ROWS = 5;
	const size_t COLS = 10;
	const size_t MAX_ROW = 3;
	const size_t MAX_COL = 6;

	Matrix<int> matrix(ROWS, COLS);

	int i = 1;
	for (size_t row = 1; row <= ROWS; row++) {
		for (size_t col = 1; col <= COLS; col++) {
			matrix.at(row, col) = i++;
		}
	}

	matrix.at(MAX_ROW, MAX_COL) = i * 2;

	const auto EXP = std::pair<size_t, size_t>(MAX_ROW, MAX_COL);
	const auto OBS = matrix.getLargestLocation();
	BOOST_CHECK(EXP.first == OBS.first);
	BOOST_CHECK(EXP.second == OBS.second);
}

/**
 * Basic test for resize.
 */
BOOST_AUTO_TEST_CASE(test_resize) {
	const size_t ROWS = 5;
	const size_t COLS = 10;

	Matrix<int> matrix(ROWS, COLS);
	matrix.resize(ROWS + 1, COLS + 1);

	BOOST_CHECK(ROWS + 1 == matrix.getNumberOfRows());
	BOOST_CHECK(COLS + 1 == matrix.getNumberOfColumns());
}

/**
 * Basic test for fill.
 */
BOOST_AUTO_TEST_CASE(test_fill) {
	const int NEW_VALUE = 2;

	Matrix<int> matrix(3, 2, NEW_VALUE - 1);
	matrix.fill(NEW_VALUE);

	for (size_t row = 1; row <= matrix.getNumberOfRows(); row++) {
		for (size_t col = 1; col <= matrix.getNumberOfColumns(); col++) {
			BOOST_CHECK(NEW_VALUE == matrix.at(row, col));
		}
	}
}

} /* namespace core */
} /* namespace ms */
} /* namespace banos */
