/*
 * Matrix.h
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_MATRIX_H_
#define BANOS_MS_CORE_MATRIX_H_

#include <stdexcept>
#include <string>
#include <vector>

namespace banos {
namespace ms {
namespace core {

/**
 * A matrix.
 */
template<class T>
class Matrix {
public:
	/**
	 * Ctor.
	 * @param rows The number of rows.
	 * @param cols The number of columns.
	 */
	Matrix(const size_t rows, const size_t cols) : rows(rows), cols(cols), matrix(rows * cols) { }

	/**
	 * Ctor.
	 * @param rows The number of rows.
	 * @param cols The number of columns.
	 * @parm def The default value.
	 */
	Matrix(const size_t rows, const size_t cols, const T& def) :
		rows(rows), cols(cols), matrix(rows * cols, def) { }

	/**
	 * Destructor.
	 */
	virtual ~Matrix() { }

	/**
	 * Access an item at a given location.
	 * @param row The row to access (1-based).
	 * @param col The column to access (1-based).
	 */
	T& at(size_t row, size_t col) {
		if (row > rows)
			throw std::out_of_range(std::to_string(row) +
					" greater than number of rows in matrix (" + std::to_string(rows) + ")");

		if (col > cols)
					throw std::out_of_range(std::to_string(col) +
							" greater than number of columns in matrix (" +
							std::to_string(cols) + ")");

		return matrix[((row - 1) * cols) + col - 1];
	}

	/**
	 * Get the number of rows.
	 * @return The number of rows.
	 */
	size_t getNumberOfRows() const {
		return rows;
	}

	/**
	 * Get the number of columns.
	 * @return The number of columns.
	 */
	size_t getNumberOfColumns() const {
		return cols;
	}

	/**
	 * Get the index of the largest item.
	 * @return The largest item index (1-based; row, col).
	 */
	std::pair<size_t, size_t> getLargestLocation() const {
		size_t maxIndex = 0;
		T max = matrix[0];

		for (size_t index = 1; index < matrix.size(); index++) {
			if (matrix[index] > max) {
				maxIndex = index;
				max = matrix[index];
			}
		}

		size_t row = (maxIndex / cols) + 1;
		size_t col = maxIndex + 1 - ((row - 1) * cols);

		return std::pair<size_t, size_t>(row, col);
	}

	/**
	 * Resize the matrix.
	 * NOTE: Data will be left in an undertimed state.
	 * @param rows The number of rows in the resized matrix.
	 * @param cols The number of columns in the resized matrix.
	 */
	void resize(const size_t rows, const size_t cols) {
		if (rows * cols > matrix.size()) {
			matrix.resize(rows * cols);
		}

		this->rows = rows;
		this->cols = cols;
	}

	/**
	 * Fill every cell in the matrix with the supplied value.
	 * @param value The value to fill the matrix with.
	 */
	void fill(const T& value) {
		std::fill(matrix.begin(), matrix.end(), value);
	}

private:
	size_t rows, cols;
	std::vector<T> matrix;
};

} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_MATRIX_H_ */
