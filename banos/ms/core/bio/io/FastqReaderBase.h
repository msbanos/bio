/*
 * FastqReaderBase.h
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_IO_FASTQREADERBASE_H_
#define BANOS_MS_CORE_BIO_IO_FASTQREADERBASE_H_

#include "banos/ms/core/io/FileReader.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

/**
 * Base class for reading FASTQ files.
 */
template<class T>
class FastqReaderBase : public core::io::FileReader<T> {
public:
	/**
	 * Ctor.
	 * @param file The name of the file to parse.
	 */
	FastqReaderBase(const std::string& file) : core::io::FileReader<T>(file) { }

	/**
	 * Destructor.
	 */
	virtual ~FastqReaderBase() { }

	/**
	 * Read the next record from file.
	 * @return The next record from file.
	 */
	virtual T* read() {
		if (!core::io::FileReader<T>::readLine(id) || !id.length())  return NULL;

		core::io::FileReader<T>::readLine(sequence);
		core::io::FileReader<T>::readLine(comment);
		core::io::FileReader<T>::readLine(qualities);

		return makeRecord();
	}

protected:
	/**
	 * Make a new record.
	 * @return The new record.
	 */
	virtual T* makeRecord() = 0;

	std::string id, sequence, qualities, comment;
};

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_IO_FASTQREADERBASE_H_ */
