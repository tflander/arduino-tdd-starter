.PHONY: test src all clean

all: src

test:
	$(MAKE) -C test

src: test
	$(MAKE) -C src

clean:
	$(MAKE) -C test clean
	$(MAKE) -C src clean