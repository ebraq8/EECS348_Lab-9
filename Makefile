CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = matrix
OBJS = main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET)
