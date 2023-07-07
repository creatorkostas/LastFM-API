CFLAGS = -std=c++17 #-O2 #For optimazation
LDFLAGS = -lcurl -ltinyxml2

build: src/main.cpp
	g++ $(CFLAGS) -o LastFM-Api src/main.cpp $(LDFLAGS)
	
.PHONY: test clean

test: build
	./LastFM-Api

clean:
	rm -f LastFM-Api

run: clean test
