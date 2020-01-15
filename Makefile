APP = play

CXX = g++-9

SDL_INCLUDES = ./include
SDL_LIBS = ./lib
SDL_VERSION = SDL2-2.0.0

CPPFLAGS += -I $(SDL_INCLUDES) -L $(SDL_LIBS) -l $(SDL_VERSION)

OBJECTS = main.o \
		  board.o \
		  piece.o

#-------------------------------------------------------------------------------
all: play

play: $(OBJECTS)
	$(CXX) $(CPPFLAGS) $^ -o $@

run: play
	./$(APP)

clean:
	rm $(APP) *.o

main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp

board.o: board.cpp
	$(CXX) $(CPPFLAGS) -c board.cpp

piece.o: piece.cpp
	$(CXX) $(CPPFLAGS) -c piece.cpp

view.o: view.cpp
	$(CXX) $(CPPFLAGS) -c view.cpp
