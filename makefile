CC = gcc
CFLAGS = -Wall -std=c99 -I./include
LDFLAGS = -L./lib -lraylib -lm -lopengl32 -lgdi32 -lwinmm

game.exe: main.c map.c player.c raycaster.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)