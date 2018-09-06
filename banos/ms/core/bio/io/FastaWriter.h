/*
 * FastaWriter.h
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_IO_FASTAWRITER_H_
#define BANOS_MS_CORE_BIO_IO_FASTAWRITER_H_

#include "banos/ms/core/io/FileWriter.h"
#include "banos/ms/core/bio/SequenceRecord.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

/**
 * Fasta file writer.
 */
class FastaWriter : public core::io::FileWriter<SequenceRecord> {
public:
	/**
	 * Ctor.
	 * @param file The file to write.
	 */
	FastaWriter(const std::string& file);

	/**
	 * Destructor.
	 */
	virtual ~FastaWriter();

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

#endif /* BANOS_MS_CORE_BIO_IO_FASTAWRITER_H_ */
