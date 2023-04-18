CXX=g++
CXXFLAGS=-std=c++11
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)
TARGET=Main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJS) $(TARGET)