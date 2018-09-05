/*
 * FileReader.h
 *
 *  Created on: Sep 5, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_IO_FILEREADER_H_
#define BANOS_MS_CORE_IO_FILEREADER_H_

#include <fstream>
#include <iostream>

namespace banos {
namespace ms {
namespace core {
namespace io {

/**
 * Base class for reading files.
 * @type T The type to read.
 */
template <class T>
class FileReader {
public:
	/**
	 * Ctor.
	 * @param file The name of the file to parse.
	 */
	FileReader(const std::string& file) : stream(file) {
		if (!stream.good()) {
			std::cout << "File stream for " << file << " could not be initialized." << std::endl;
			throw std::exception();
		}
	}

	/**
	 * Destructor.
	 */
	virtual ~FileReader() {
		stream.close();
	}

	/**
	 * Read the next item from file.
	 * @return The next item from file.
	 */
	virtual T* read() = 0;

protected:
	/**
	 * Read the next line from file into the destination string.
	 * @param dest The string to read into to.
	 * @returns True if a line was read without error; otherwise false.
	 */
	bool readLine(std::string& dest) {
		dest.clear();

		if (stream.eof())  return false;

		std::getline(stream, dest);

		return true;
	}

private:
	std::ifstream stream;
};

} /* namespace io */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_IO_FILEREADER_H_ */
