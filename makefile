CC = gcc
CFLAGS = -Wall -std=c99 -I./src/include
LDFLAGS = -L./src/lib -lraylib -lm -lopengl32 -lgdi32 -lwinmm

game.exe: src/main.c src/map.c src/player.c src/raycaster.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)