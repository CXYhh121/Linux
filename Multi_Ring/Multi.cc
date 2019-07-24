#include "ring.hpp"
#include <time.h>

void* consumer(void* arg)
{
    Ring* r = (Ring*)arg;
    int data;
    for(;;){
        r->GetData(data);
        cout << "consumer data:"<< data <<endl;
    }
}

void* producter(void* arg)
{
    Ring* r = (Ring*)arg;
    for(;;){
        int data = rand() % 100 + 1;
        r->PutData(data);
        cout << "product data:"<< data <<endl;
        sleep(1);
    }
}

int main()
{
    srand((unsigned long)time(NULL));//生成随机数
    Ring r;//定义一个环形队列，基于信号量
    pthread_t c,p;//创建两个线程c为消费者，p为生产者
    pthread_create(&c,NULL,consumer,(void*)&r);//让生产者和消费者都看到该环形队列
    pthread_create(&p,NULL,producter,(void*)&r);
    

    pthread_join(c,NULL);
    pthread_join(p,NULL);

    return 0;
}
