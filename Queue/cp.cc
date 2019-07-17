#include <time.h>
#include "cp.hpp"

void *consumer(void *arg)//arg中存放的是我们创建的阻塞队列的首地址
{
    int Data;
    BlockQueue* bq = (BlockQueue*)arg;
    for(;;){
        bq->PopData(Data);
        cout <<"Consumer Data: "<< Data << endl;
    }
}
void *product(void *arg)
{
    BlockQueue* bq = (BlockQueue*)arg;
    for(;;){
        int data = rand() % 100 + 1;
        bq->PushData(data);
        cout << "producter data: " << data << endl;
        sleep(1);
    }
}

int main()
{
    srand((unsigned long)time(NULL));//生成随机数
    BlockQueue bq(6);//阻塞队列

    pthread_t c,p;//创建两个线程c为消费者，p为生产者
    pthread_create(&c,NULL,consumer,(void*)&bq);//让生产者和消费者都看到该阻塞队列
    pthread_create(&p,NULL,product,(void*)&bq);
    

    pthread_join(c,NULL);
    pthread_join(p,NULL);

    return 0;
}
