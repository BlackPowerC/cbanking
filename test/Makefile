PERSISTENCE_TEST = ./run_persistence_tests
UTIL_TEST = ./run_utils_tests

all:
	make util_test
	make pertistence_test

pertistence_test: $(PERSISTENCE_TEST)
	make -f $(PERSISTENCE_TEST) > /tmp/0.txt

util_test: $(UTIL_TEST)
	make -f $(UTIL_TEST) > /tmp/0.txt