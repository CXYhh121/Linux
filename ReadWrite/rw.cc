#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
int data = 0;
pthread_rwlock_t rw;

void* reader(void* arg)
{
    for(;;){
        pthread_rwlock_rdlock(&rw);
        cout << "reader read done: " << data << endl;
        pthread_rwlock_unlock(&rw);
        usleep(100);
    }
}

void* writer(void* arg)
{
    for(;;){
        pthread_rwlock_wrlock(&rw);
        cout << "writer write done : "<< ++data << endl;
        pthread_rwlock_unlock(&rw);
        usleep(90);
    }
}


int main()
{
    pthread_rwlock_init(&rw,NULL);
    pthread_t r[5],w;
    for(int i = 0;i < 5; ++i){
         pthread_create(&r[i],NULL,reader,NULL);
    }
    pthread_create(&w,NULL,writer,NULL);

    for(int i = 0;i < 5; ++i){
         pthread_join(r[i],NULL);
    }
    pthread_join(w,NULL);
    pthread_rwlock_destroy(&rw);
    return 0;
}
