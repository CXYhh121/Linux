#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;

//定义条件变量和互斥量
pthread_cond_t cond;
pthread_mutex_t mutex;
void *r1(void *arg)
{
    while(1){
        pthread_cond_wait(&cond, &mutex);
        cout << "i am a thread..." << endl;
    }
} 
void *r2(void *arg)
{
    while(1){
        pthread_cond_signal(&cond);
        sleep(1);
    }
}
int main()
{
    pthread_t t1, t2;
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, r1, NULL);
    pthread_create(&t2, NULL, r2, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
} 
