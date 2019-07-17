#ifndef __RING_HPP__
#define __RING_HPP__

#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM 32

using namespace std;

class Ring{
    private:
        int circle[NUM];//环形队列
        int cap;//信号量的容量
        int c_step;//消费者下标
        int p_step;//生产者下标
        sem_t sem_data;//消费者可以消费的数据
        sem_t sem_blank;//生产者可以生产的位置

        void P(sem_t &s)
        {
            sem_wait(&s);
        }
        void V(sem_t &s)
        {
            sem_post(&s);
        }
    public:
        Ring():cap(NUM)
        {
            c_step = p_step = 0;
            sem_init(&sem_data,0,0);
            sem_init(&sem_blank,0,NUM);
        }
        
        //消费者调用该接口进行消费
        void GetData(int& out)
        {
            P(sem_data);//消费者申请数据资源消费
            out = circle[c_step];//消费者从环形队列中取数据
            c_step++;
            V(sem_blank);//消费者增加空间
            c_step %= cap;//当走到最后时重新置为0
        }
        //生产者调用该接口进行生产
        void PutData(const int& in)
        {
            P(sem_blank);//生产者申请空间生产
            circle[p_step] = in;//往环形队列中插入数据
            p_step++;//下标++
            V(sem_data);//生产者增加数据
            p_step %= cap;//因为是环形队列，当走到下标最后时将它重置为0
        }

        ~Ring()
        {
            sem_destroy(&sem_data);
            sem_destroy(&sem_blank);
        }
};

#endif
