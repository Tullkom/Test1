OBJS=$(patsubst %.c, %.o, $(filter-out %_test.c, $(wildcard *.c)))
TESTS=$(OBJS:.o=_test)
RUN_TESTS=$(OBJS:.o=_run_test)

.DEFAULT_GOAL := all

.PHONY: all
all: $(OBJS) $(TESTS) $(RUN_TESTS)

.PHONY: build_objs 
build_objs: $(OBJS)

$(OBJS): %.o: %.c
	clang -g -c $< -o $@

.PHONY: build_tests 
build_tests: $(TESTS)

$(TESTS): %_test: %_test.c %.o
	clang -g -c $*_test.c -o $*_test.o
	clang $*_test.o $*.o -o $*_test -static

.PHONY: run_tests
run_tests: $(RUN_TESTS)

$(RUN_TESTS): %_run_test: %_test
	./$*_test

INTERMEDIATE_TEST_OBJS := $(OBJS:.o=_test.o)

.PHONY: clean
clean: 
	rm -f $(TESTS) $(INTERMEDIATE_TEST_OBJS)
	rm -f $(OBJS)

FORMAT_FILES=$(OBJS:%.o=format_%)
$(FORMAT_FILES): format_%:
	clang-format -i $*.h $*.c $*_test.c

format_all: $(FORMAT_FILES)

CHECK_FORMAT=$(OBJS:%.o=check_format_%)
$(CHECK_FORMAT): check_format_%:
	clang-format --dry-run -Werror $*.h $*.c $*_test.c

check_format_all: $(CHECK_FORMAT)
