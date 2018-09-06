/*
 * BasicFileReader.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#include "BasicFileReader.h"

namespace banos {
namespace ms {
namespace core {
namespace io {

BasicFileReader::BasicFileReader(const std::string& file) : FileReader<std::string>(file) { }

BasicFileReader::~BasicFileReader() { }

std::string* BasicFileReader::read() {
	std::string* line = new std::string();

	if (readLine(*line)) {
		return line;
	}

	delete line;

	return NULL;
}

} /* namespace io */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
