/*
 * FastqReader.h
 *
 *  Created on: Sep 6, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_IO_FASTQREADER_H_
#define BANOS_MS_CORE_BIO_IO_FASTQREADER_H_

#include "FastqReaderBase.h"
#include "banos/ms/core/bio/SequenceRecord.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

/**
 * Basic FASTQ reader.
 */
class FastqReader : public FastqReaderBase<SequenceRecord> {
public:
	/**
	 * Ctor.
	 * @param file The name of the file to parse.
	 */
	FastqReader(const std::string& file);

	/**
	 * Destructor.
	 */
	virtual ~FastqReader();

protected:
	/**
	 * Make a new record.
	 * @return The new record.
	 */
	virtual SequenceRecord* makeRecord();
};

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_IO_FASTQREADER_H_ */
