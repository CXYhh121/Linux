#include <unistd.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <pthread.h>
using namespace std;

void* route(void* arg)
{
    for(;;){
        cout << "I am a thread!" << endl;
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    int ret;
    ret = pthread_create(&tid,NULL,route,NULL);
    if(ret != 0){
        cout <<"pthread_create:" << strerror(ret) << endl;
        exit(EXIT_FAILURE);
    }
    for(;;)
    {
        cout << "I am a main thread,my threadtid is: " << tid << endl;
        sleep(1);
    }
    return 0;
}
