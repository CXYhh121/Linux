#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PATH "/tmp"
#define PRJ_ID 0x6666
#define SIZE 4026
int main()
{
    key_t k = ftok(PATH,PRJ_ID);
    if(k < 0)
    {
        printf("ftok error!\n");
        return 1;
    }

    int shm_id = shmget(k,SIZE,IPC_CREAT | IPC_EXCL | 0644);
    if(shm_id < 0)
    {
        printf("shmget error!\n");
        return 2;
    }
    return 0;
}
