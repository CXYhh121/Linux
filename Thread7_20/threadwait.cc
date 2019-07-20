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
    return (void*)1;
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,handler,(void*)"thread 1");

    void* status;
    pthread_join(tid,&status);
    cout << (int*)status << endl;
    return 0;
}
