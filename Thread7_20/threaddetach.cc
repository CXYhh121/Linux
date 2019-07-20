#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
void* handler(void* arg)
{
    int i = 3;
    while(i--)
    {
        cout << "I am a new thread" <<endl;
    }
    pthread_detach(pthread_self());
    return NULL;
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,handler,(void*)"thread 1");

    int ret = 0;
    sleep(1);//很重要，让线程先分离再等待

    if(pthread_join(tid,NULL) == 0){
        cout << "thread wait success" <<endl;
        ret = 0;
    }else{
        cout << "thread wait failed" <<endl;
        ret = 1;
    }
    return ret;
}
