#include "../hdr/shared_chat.h"

int main()
{
    int fd = shm_open("/my_chat", O_RDWR, 0666);
    void *ptr = mmap(NULL, sizeof(SharedChat), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    SharedChat *chat = (SharedChat*) ptr;

    while(1) {
        sem_wait(&chat->s_read);
        printf("Message: %s\n", chat->message);
        sem_post(&chat->s_write);
    }

    munmap(chat, sizeof(SharedChat));
    close(fd);
    return 0;
}