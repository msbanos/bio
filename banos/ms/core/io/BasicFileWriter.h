/*
 * BasicFileWriter.h
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_IO_BASICFILEWRITER_H_
#define BANOS_MS_CORE_IO_BASICFILEWRITER_H_

#include "FileWriter.h"

namespace banos {
namespace ms {
namespace core {
namespace io {

/**
 * Basic writer to write raw strings to file.
 */
class BasicFileWriter : public FileWriter<std::string> {
public:
	/**
	 * Ctor.
	 * @param file The file to write.
	 */
	BasicFileWriter(const std::string& file);

	/**
	 * Destructor.
	 */
	virtual ~BasicFileWriter();

	/**
	 * Write a string to file.
	 * @param item The string to be written.
	 */
	virtual void write(const std::string* const item);

	/**
	 * Write a string to file.
	 * @param item The string to be written.
	 */
	virtual void write(const std::string& item);
};

} /* namespace io */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_IO_BASICFILEWRITER_H_ */
