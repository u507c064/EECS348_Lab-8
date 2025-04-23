CPP = g++

CPPFLAGS = -std=c++11 -Wall -Wextra
SRC = main.cpp matrix.cpp
HPP = matrix.hpp
MATRIX = matrix_program

all: $(MATRIX)

$(MATRIX): $(SRC) $(HPP)
	$(CPP) $(CPPFLAGS) -o $(MATRIX) $(SRC)

clean:
	rm -f $(MATRIX)
