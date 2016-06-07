# http://stackoverflow.com/questions/31176997/what-does-clang-check-do-without-analyze-option

FILES :=          \
    IsPrime1

CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread

ifeq ($(CC), clang)
    CLANG-CHECK := clang-check
    CXX         := clang++
else
    CXX         := g++-4.8
    GCOV        := gcov-4.8
    GCOVFLAGS   := -fprofile-arcs -ftest-coverage
endif

%.app: %.c++
ifeq ($(CC), clang)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          $< --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze $< --
else
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) $< -o $@ $(LDFLAGS)
endif

%.c++x: %.app
	./$<
ifeq ($(CC), gcc)
	$(GCOV) -b ./$(<:.app=.c++) | grep -A 5 "File '$(<:.app=.c++)'"
endif

clean:
	rm -f *.app
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist

test: $(FILES:=.c++x)
