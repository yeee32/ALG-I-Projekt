CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Werror
TARGET = merge
SRCS = main.cpp array.cpp filesManager.cpp minHeap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
