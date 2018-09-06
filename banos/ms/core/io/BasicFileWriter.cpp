/*
 * BasicFileWriter.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#include "BasicFileWriter.h"

namespace banos {
namespace ms {
namespace core {
namespace io {

BasicFileWriter::BasicFileWriter(const std::string& file) : FileWriter<std::string>(file) { }

BasicFileWriter::~BasicFileWriter() { }

void BasicFileWriter::write(const std::string* const item) {
	writeLine(*item);
}

void BasicFileWriter::write(const std::string& item) {
	write(&item);
}

} /* namespace io */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */
