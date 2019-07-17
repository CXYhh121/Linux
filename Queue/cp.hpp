#ifndef __CP__HPP__
#define __CP__HPP__

#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

class BlockQueue{
    private:
        queue<int> q;
        int cap;//队列的容量
        pthread_mutex_t lock;   //互斥锁
        pthread_cond_t full;  //条件变量，判断队列是否为满
        pthread_cond_t empty;

        void LockQueue()
        {
            pthread_mutex_lock(&lock);  //给队列加锁
        }

        void UnlockQueue()
        {
            pthread_mutex_unlock(&lock);//给队列解锁
        }

        bool QueueIsFull()
        {
            return q.size() == cap;
        }
        bool QueueIsEmpty()
        {
            return q.size() == 0;
        }
        void SignalConsumer()
        {
            pthread_cond_signal(&empty);//唤醒在empty的条件变量下等待的消费者
        }
        void ConsumerWait()
        {
            pthread_cond_wait(&empty,&lock);//队列为空，消费者开始等待并释放锁
        }
        void SignalProduct()
        {
            pthread_cond_signal(&full);//唤醒在full条件变量下等待的生产者
        }
        void ProductWait()
        {
            pthread_cond_wait(&full,&lock);//队列为full，生产者开始等待并释放锁
        }

    public:
        BlockQueue(int cap_ = 32):cap(cap_)//队列初始化
        {
            pthread_mutex_init(&lock,NULL);
            pthread_cond_init(&full,NULL);
            pthread_cond_init(&empty,NULL);
        }
        //生产者生产数据
        void PushData(const int& in)
        {
            LockQueue();
            while(QueueIsFull()){
                SignalConsumer();//若队列满了则通知消费者消费
                ProductWait();//生产者停止生产
            }
            //队列不为满则生产者可以生产product
            q.push(in);//将数据写进队列
            SignalConsumer();//一旦有数据就唤醒消费者消费
            UnlockQueue();
        }
        //消费者消费数据
        void PopData(int& out)
        {
            LockQueue();
            while(QueueIsEmpty()){
                SignalProduct();//通知生产者生产
                ConsumerWait();//消费者停止消费
            }
            //队列不为空，消费者可以消费
            //consumer
            out = q.front();//将队列头部数据保存下来
            q.pop();//删除该数据
            SignalProduct();//一旦有空间就通知生产者生产
            UnlockQueue();
        }
        //析构函数，清理资源
        ~BlockQueue()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&full);
            pthread_cond_destroy(&empty);
        }
};

#endif
