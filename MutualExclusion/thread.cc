#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int total = 0;
pthread_mutex_t mutx;

void* handler(void* arg)
{
    int count = 100000000;
    pthread_mutex_lock(&mutx);
    while(count--)
        total++;
    pthread_mutex_unlock(&mutx);
    return (void*)1;
}
int main()
{
    pthread_t t1,t2;
    pthread_mutex_init(&mutx,NULL);
    pthread_create(&t1,NULL,handler,NULL);
    pthread_create(&t2,NULL,handler,NULL);

    sleep(1);
    cout <<"total value: "<< total << endl;
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&mutx);
    return 0;
}
