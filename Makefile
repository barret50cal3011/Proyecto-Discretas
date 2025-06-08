CXX = g++
CXXFLAGS = -Wall -std=c++17 -Isrc/headers

FILES = interpreter main util
SRC = $(addsuffix .cpp, $(FILES))
SRC_Path = $(addprefix src/, $(SRC))

OBJ = $(addprefix build/, $(SRC:.cpp=.o))

EXE = boolean.exe

.PHONY: all clean clean-all

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q build\*.o build\classes\*.o 2> NUL || exit 0

clean-all:
	del /Q build\*.o build\classes\*.o boolean.exe 2> NUL || exit 0
