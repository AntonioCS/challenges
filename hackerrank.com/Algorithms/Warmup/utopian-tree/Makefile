CFLAGS=-Wall -g -std=c99 -o
CC=gcc
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))

main: main.c
	$(CC) $(CFLAGS) utopian-tree $^
	