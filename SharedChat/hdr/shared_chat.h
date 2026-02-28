#pragma once

#include <semaphore.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 256

typedef struct SharedChat {
	char message[BUFFER_SIZE];
	sem_t s_write;
	sem_t s_read;
} SharedChat;