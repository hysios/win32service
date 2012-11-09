MOCHA      = node_modules/.bin/mocha -u tdd -R spec
TESTS      = $(shell find test -name "*.js" -type f | sort)
GYP		   = node-gyp configure build

default: all

all: 
	$(GYP)

test: all $(TESTS)
	$(MOCHA)