CPPFLAGS = -std=c++14 -O3 -Wall -c -fmessage-length=0 -MMD -MP
TESTFLAGS = -std=c++14 -O3
VERSION = 0.1.0
ROOT_DIR = banos/ms/core
INSTALL_DIR = bin/$(VERSION)
TEST_DIR = tests

OBJECTS = $(ROOT_DIR)/io/FileReader.o $(ROOT_DIR)/bio/SequenceRecord.o $(ROOT_DIR)/bio/io/FastaReader.o \
	$(ROOT_DIR)/io/FileWriter.o $(ROOT_DIR)/bio/io/FastaWriter.o $(ROOT_DIR)/io/BasicFileReader.o \
	$(ROOT_DIR)/io/BasicFileWriter.o $(ROOT_DIR)/bio/io/FastqReaderBase.o $(ROOT_DIR)/bio/io/FastqReader.o \
	$(ROOT_DIR)/bio/io/FastqWriter.o

.PHONY: all
all: $(OBJECTS)

$(OBJECTS): %.o: %.h
$(OBJECTS): %.o: %.cpp
	g++ $(CPPFLAGS) -I. -MF"$*.d" -MT"$*.d" -o $@ $<

.PHONY: clean
clean:
	find . -type f -name '*.o' -not -path "./bin/*" -delete
	find . -type f -name '*.d' -not -path "./bin/*" -delete
	rm -rf $(INSTALL_DIR)/*
	find . -executable -type f -not -path "./bin/*" -delete

.PHONY: install
install:
	mkdir -p $(INSTALL_DIR)
	find . -type f -name '*.o' -not -path "./bin/*" -exec cp --parents {} $(INSTALL_DIR) \;
	find . -type f -name '*.h' -not -path "./bin/*" -exec cp --parents {} $(INSTALL_DIR) \;

TESTS = $(TEST_DIR)/bio/SequenceRecord_test $(TEST_DIR)/bio/io/FastaReader_test $(TEST_DIR)/bio/io/FastaWriter_test \
	$(TEST_DIR)/io/BasicFileReader_test $(TEST_DIR)/bio/io/FastqReader_test $(TEST_DIR)/bio/io/FastqWriter_test

$(TESTS): %: %.cpp
test: $(TESTS)
	for TEST in $(TESTS); do \
		$$TEST; \
	done

SEQ_RECORD_TEST_DEPS = $(ROOT_DIR)/bio/SequenceRecord.o
$(TEST_DIR)/bio/SequenceRecord_test: $(SEQ_RECORD_TEST_DEPS)
	g++ $(TESTFLAGS) -I. $(SEQ_RECORD_TEST_DEPS) -o $@ -lboost_unit_test_framework $@.cpp

FASTA_READER_TEST_DEPS = $(ROOT_DIR)/io/FileReader.o $(ROOT_DIR)/bio/SequenceRecord.o $(ROOT_DIR)/bio/io/FastaReader.o
$(TEST_DIR)/bio/io/FastaReader_test: $(FASTA_READER_TEST_DEPS)
	g++ $(TESTFLAGS) -I. $(FASTA_READER_TEST_DEPS) -o $@ -lboost_unit_test_framework $@.cpp

FASTA_WRITER_TEST_DEPS = $(ROOT_DIR)/bio/SequenceRecord.o $(ROOT_DIR)/io/FileReader.o $(ROOT_DIR)/bio/io/FastaReader.o \
	$(ROOT_DIR)/io/FileWriter.o $(ROOT_DIR)/bio/io/FastaWriter.o
$(TEST_DIR)/bio/io/FastaWriter_test: $(FASTA_WRITER_TEST_DEPS)
	g++ $(TESTFLAGS) -I. $(FASTA_WRITER_TEST_DEPS) -o $@ -lboost_unit_test_framework $@.cpp

BASIC_FILE_READER_TEST_DEPS = $(ROOT_DIR)/io/FileReader.o $(ROOT_DIR)/io/BasicFileReader.o
$(TEST_DIR)/io/BasicFileReader_test: $(BASIC_FILE_READER_TEST_DEPS)
	g++ $(TESTFLAGS) -I. $(BASIC_FILE_READER_TEST_DEPS) -o $@ -lboost_unit_test_framework $@.cpp

FASTQ_READER_TEST_DEPS = $(ROOT_DIR)/io/FileReader.o $(ROOT_DIR)/bio/SequenceRecord.o $(ROOT_DIR)/bio/io/FastqReader.o
$(TEST_DIR)/bio/io/FastqReader_test: $(FASTQ_READER_TEST_DEPS)
	g++ $(TESTFLAGS) -I. $(FASTQ_READER_TEST_DEPS) -o $@ -lboost_unit_test_framework $@.cpp

FASTQ_WRITER_TEST_DEPS = $(ROOT_DIR)/bio/SequenceRecord.o $(ROOT_DIR)/io/FileReader.o $(ROOT_DIR)/bio/io/FastqReader.o \
	$(ROOT_DIR)/io/FileWriter.o $(ROOT_DIR)/bio/io/FastqWriter.o
$(TEST_DIR)/bio/io/FastqWriter_test: $(FASTQ_WRITER_TEST_DEPS)
	g++ $(TESTFLAGS) -I. $(FASTQ_WRITER_TEST_DEPS) -o $@ -lboost_unit_test_framework $@.cpp
