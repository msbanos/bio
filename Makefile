CPPFLAGS = -std=c++14 -O3 -Wall -c -fmessage-length=0 -MMD -MP
TESTFLAGS = -std=c++14 -O3
VERSION = 0.1.0
ROOT_DIR = banos/ms/core
INSTALL_DIR = bin/$(VERSION)
TEST_DIR = tests

OBJECTS = 

.PHONY: all
all: $(OBJECTS)

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

TESTS = 

$(TESTS): %: %.cpp
test: $(TESTS)
	for TEST in $(TESTS); do \
		$$TEST; \
	done
