/*
 * FileWriter.h
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_IO_FILEWRITER_H_
#define BANOS_MS_CORE_IO_FILEWRITER_H_

#include <fstream>

namespace banos {
namespace ms {
namespace core {
namespace io {

/**
 * Base class for writing to file.
 * @type T The type to write.
 */
template <class T>
class FileWriter {
public:
	/**
	 * Ctor.
	 * @param file The file to write.
	 */
	FileWriter(const std::string& file) : stream(file) { }

	/**
	 * Destructor.
	 */
	virtual ~FileWriter() {
		close();
	}

	/**
	 * Close the file handle.
	 */
	void close() {
		stream.close();
	}

	/**
	 * Write an item to file.
	 * @param item The item to be written.
	 */
	virtual void write(const T* const item) = 0;

	/**
	 * Write a series of items to file.
	 * @param first An iterator to the first item to be written (inclusive).
	 * @param last An iterator to the last item to be written (exclusive).
	 */
	template <class InputIterator>
	void writeSeries(InputIterator first, InputIterator last) {
		while (first != last) {
			write(*first++);
		}
	}

protected:
	/**
	 * Write a line to file.
	 * @param line The string to be written as an individual line.
	 */
	void writeLine(const std::string& line) {
		stream << line << '\n';
	}

private:
	std::ofstream stream;
};

} /* namespace io */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_IO_FILEWRITER_H_ */
