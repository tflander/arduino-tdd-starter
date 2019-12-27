GTEST_CFLAGS=`pkg-config --cflags gtest_main gmock`
GTEST_LIBS=`pkg-config --libs gtest_main gmock`
CFLAGS=${GTEST_CFLAGS} -I../mock -I../src
CXXFLAGS=${CFLAGS}

.PHONY: clean

check: testdefault.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIBS)
	./check

clean:
	rm -f *.o
	rm -f check
	rm -f check.exe