/*
 * SequenceRecord.h
 *
 *  Created on: Sep 5, 2018
 *      Author: mike
 */

#ifndef BANOS_MS_CORE_BIO_SEQUENCERECORD_H_
#define BANOS_MS_CORE_BIO_SEQUENCERECORD_H_

#include <string>

namespace banos {
namespace ms {
namespace core {
namespace bio {

/**
 * A sequencing read record.
 */
class SequenceRecord {
public:
	/**
	 * Ctor.
	 * @param id The record id.
	 * @param seq The record sequence.
	 */
	SequenceRecord(const std::string& id, const std::string& seq);

	/**
	 * Ctor.
	 * @param id The record id.
	 * @param seq The record sequence.
	 * @param quals The new quality string.
	 */
	SequenceRecord(const std::string& id, const std::string& seq, const std::string& quals);

	/**
	 * Destructor.
	 */
	virtual ~SequenceRecord();

	/**
	 * Get the id.
	 * @return The id.
	 */
	virtual const std::string& getId() const;

	/**
	 * Get the sequence.
	 * @return The sequence.
	 */
	const std::string& getSequence() const;

	/**
	 * Get the quality string.
	 * @return The quality string.
	 */
	const std::string& getQualityScores() const;

	/**
	 * Trim the 5' end.
	 * @param length The number of bases to trim.
	 */
	void ltrim(const unsigned int length);

	/**
	 * Get the sequence length.
	 * @return The length.
	 */
	size_t length() const;

	/**
	 * Check if two records are equivalent.
	 * @param other The other record to compare to this one.
	 * @return True if both records represent the same thing; otherwise false.
	 */
	virtual bool operator ==(const SequenceRecord& other) const;

protected:
	/**
	 * Set the record id.
	 * @param id The new record id.
	 */
	void setId(const std::string& id);

private:
	std::string id;
	std::string seq;
	std::string quals;
};

} /* namespace bio */
} /* namespace core */
} /* namespace ms */
} /* namespace banos */

#endif /* BANOS_MS_CORE_BIO_SEQUENCERECORD_H_ */
