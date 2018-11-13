# compiler options
CXXFLAGS += --std=c++11

# source files
SOURCES = $(wildcard *.cpp)

# object files
OBJECTS = $(SOURCES:.cpp=.o)

# main link objects
MOBJECTS = $(filter-out test%, $(OBJECTS))

# test link objects
TOBJECTS = $(filter-out main.o, $(OBJECTS))

# inlcuded libraries
INCLUDE = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

# executable filename
EXECUTABLE = mice

all: $(EXECUTABLE)
rebuild: clean $(EXECUTABLE)

# $^ - all dependencies
# $@ - result name
# $< - first dependency

$(EXECUTABLE): $(MOBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(INCLUDE)

test: CXXFLAGS += -g
test: $(TOBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(INCLUDE)

debug: CXXFLAGS += -g
debug: $(EXECUTABLE)

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	-rm -f $(EXECUTABLE) test $(OBJECTS)
