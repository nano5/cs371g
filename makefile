clean:
	cd examples; make clean
	@echo
	cd exercises; make clean
	@echo
	cd collatz; make clean

config:
	git config -l

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/cs371g.git
	git push -u origin master

pull:
	make clean
	@echo
	git pull
	git status

push:
	make clean
	@echo
	git add .travis.yml
	git add examples
	git add exercises
	git add collatz
	git add makefile
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -r -t -u -v --delete             \
    --include "Hello.c++"                   \
    --include "Assertions.c++"              \
    --include "UnitTests1.c++"              \
    --include "UnitTests2.c++"              \
    --include "UnitTests3.c++"              \
    --include "Coverage1.c++"               \
    --include "Coverage2.c++"               \
    --include "Coverage3.c++"               \
    --include "Exceptions.c++"              \
    --include "Exceptions2.c++"             \
    --include "Exceptions3.c++"             \
    --include "Types.c++"                   \
    --include "Operators.c++"               \
    --include "Variables.c++"               \
    --include "Arguments.c++"               \
    --include "Returns.c++"                 \
    --include "Iteration.c++"               \
    --include "InitializerList.c++"         \
    --include "Auto.c++"                    \
    --include "Initializations.c++"         \
    --include "Functions.c++"               \
    --exclude "*"                           \
    ../../examples/c++/ examples
	@rsync -r -t -u -v --delete             \
    --include "IsPrime1.c++"                \
    --include "IsPrime1.h"                  \
    --include "IsPrime2.c++"                \
    --include "IsPrime2.h"                  \
    --include "StrCmp.c++"                  \
    --include "StrCmp.h"                    \
    --include "Equal.c++"                   \
    --include "Equal.h"                     \
    --include "Incr.c++"                    \
    --include "Incr.h"                      \
    --include "Copy.c++"                    \
    --include "Copy.h"                      \
    --include "Fill.c++"                    \
    --include "Fill.h"                      \
    --include "Pair.c++"                    \
    --include "Pair.h"                      \
    --include "AllOf.c++"                   \
    --include "AllOf.h"                     \
    --include "Stack.c++"                   \
    --exclude "*"                           \
    ../../exercises/c++/ exercises
	@rsync -r -t -u -v --delete             \
    --include "Collatz.c++"                 \
    --include "Collatz.h"                   \
    --include "RunCollatz.c++"              \
    --include "RunCollatz.in"               \
    --include "RunCollatz.out"              \
    --include "TestCollatz.c++"             \
    --include "TestCollatz.out"             \
    --exclude "*"                           \
    ../../projects/c++/collatz/ collatz

test:
	make clean
	@echo
	cd examples; make test
	@echo
	cd exercises; make test
	@echo
	cd collatz; make test
