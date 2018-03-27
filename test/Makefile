PERSISTENCE_TEST = ./run_persistence_tests
UTIL_TEST = ./run_utils_tests

all:
	make util_test > /tmp/0.txt
	make pertistence_test > /tmp/0.txt

pertistence_test: $(PERSISTENCE_TEST)
	make -f $(PERSISTENCE_TEST)

util_test: $(UTIL_TEST)
	make -f $(UTIL_TEST)