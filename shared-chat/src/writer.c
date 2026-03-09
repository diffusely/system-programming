#include "../hdr/shared_chat.h"

int main(int argc, char **argv)
{
	if (argc < 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    char *username = argv[1];
    char buff[BUFFER_SIZE];

    int fd = shm_open("/my_chat", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(SharedChat));

    void *ptr = mmap(NULL, sizeof(SharedChat), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    SharedChat *chat = (SharedChat*) ptr;

    sem_init(&chat->s_write, 1, 1);
    sem_init(&chat->s_read, 1, 0);

    while(1) {
        sem_wait(&chat->s_write);
        printf("%s: ", username);
        scanf(" %[^\n]", buff);
        strncpy(chat->message, buff, BUFFER_SIZE);
        sem_post(&chat->s_read);
    }

    munmap(chat, sizeof(SharedChat));
    close(fd);
    shm_unlink("/my_chat");
    return 0;
}