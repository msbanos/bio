/*
 * FastqWriter.h
 *
 *  Created on: Sep 7, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_IO_FASTQWRITER_H_
#define BANOS_MS_CORE_BIO_IO_FASTQWRITER_H_

#include "banos/ms/core/io/FileWriter.h"
#include "banos/ms/core/bio/SequenceRecord.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

/**
 * FastQ format file writer.
 */
class FastqWriter : public core::io::FileWriter<SequenceRecord> {
public:
	static const char HEADER_DELIM = '@';

	/**
	 * Ctor.
	 * @param file The file to write.
	 */
	FastqWriter(const std::string& file);

	/**
	 * Destructor.
	 */
	virtual ~FastqWriter();

	/**
	 * Write a record to file.
	 * @param record The record to be written.
	 */
	virtual void write(const SequenceRecord* const record);
};

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_IO_FASTQWRITER_H_ */
