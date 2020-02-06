APP = play

CXX = g++-9

SDL_INCLUDES = ./include
SDL_LIBS = ./lib
SDL_VERSION = SDL2-2.0.0

CXXFLAGS += -Wall
CPPFLAGS += -I $(SDL_INCLUDES) -L $(SDL_LIBS) -l $(SDL_VERSION)

OBJECTS = main.o \
		  board.o \
		  piece.o

#-------------------------------------------------------------------------------
all: play

play: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

run: play
	./$(APP)

clean:
	rm $(APP) *.o

main.o: main.cpp ./*.cpp ./*.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c main.cpp

board.o: board.cpp board.h colors.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c board.cpp

piece.o: piece.cpp piece.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c piece.cpp

view.o: view.cpp view.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c view.cpp
