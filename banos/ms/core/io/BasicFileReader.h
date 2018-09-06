/*
 * BasicFileReader.h
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_IO_BASICFILEREADER_H_
#define BANOS_MS_CORE_IO_BASICFILEREADER_H_

#include "FileReader.h"

namespace banos {
namespace ms {
namespace core {
namespace io {

/**
 * Basic class for reading one line of a file at a time.
 */
class BasicFileReader : public FileReader<std::string> {
public:
	/**
	 * Ctor.
	 * @param file The name of the file to parse.
	 */
	BasicFileReader(const std::string& file);

	/**
	 * Destructor.
	 */
	virtual ~BasicFileReader();

	/**
	 * Read the next line from file.
	 * @return The next line from file.
	 */
	virtual std::string* read();
};

} /* namespace io */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_IO_BASICFILEREADER_H_ */
