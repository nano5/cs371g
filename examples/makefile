# http://stackoverflow.com/questions/31176997/what-does-clang-check-do-without-analyze-option

FILES :=                    \
    Hello                   \
    UnitTests3              \
    Coverage1               \
    Coverage2               \
    Coverage3               \
    Exceptions              \
    Exceptions2             \
    Exceptions3             \
    Types                   \
    Operators               \
    Variables               \
    Arguments               \
    Returns                 \
    Iteration               \
    InitializerList         \
    Auto                    \
    Initializations         \
    Lambdas

CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread

ifeq ($(CC), clang)
    CLANG-CHECK := clang-check
    CXX         := clang++
else
    CXX         := g++-4.8
endif

%.app: %.c++
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
ifeq ($(CC), clang)
	-$(CLANG-CHECK) -extra-arg=-std=c++11          $< --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze $< --
endif

%.c++x: %.app
	./$<

clean:
	rm -f *.app
	rm -f *.plist

test: $(FILES:=.c++x)
