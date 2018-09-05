/*
 * FastaReader.h
 *
 *  Created on: Sep 5, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_IO_FASTAREADER_H_
#define BANOS_MS_CORE_BIO_IO_FASTAREADER_H_

#include <sstream>
#include <type_traits>

#include "banos/ms/core/bio/SequenceRecord.h"
#include "banos/ms/core/io/FileReader.h"

namespace banos {
namespace ms {
namespace core {
namespace bio {
namespace io {

/**
 * Fasta file reader.
 * @type T The type to read.
 */
template <class T>
class FastaReader : public core::io::FileReader<T> {
	static_assert(std::is_base_of<SequenceRecord, T>::value, "T must inherit from SequenceRecord");

public:
	static const char HEADER_DELIM = '>';

	/**
	 * Ctor.
	 * @param file The name of the file to parse.
	 */
	FastaReader(const std::string& file) : core::io::FileReader<T>(file) { }

	/**
	 * Destructor.
	 */
	virtual ~FastaReader() { }

	/**
	 * Read the next record from file.
	 * @return The next record from file.
	 */
	T* read() {
		if (id.empty()) {
			if (!core::io::FileReader<T>::readLine(id))  return NULL;
		} else {
			seqStream.str("");
		}

		while (core::io::FileReader<T>::readLine(sequence)) {
			if (sequence[0] == HEADER_DELIM) {
				break;
			}

			seqStream << sequence;
		}

		T* record = new T(id.substr(1), seqStream.str());

		if (sequence[0] == HEADER_DELIM) {
			std::swap(id, sequence);
		} else {
			id.clear();
		}

		return record;
	}

private:
	std::string id, sequence;
	std::stringstream seqStream;
};

} /* namespace io */
} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_IO_FASTAREADER_H_ */
