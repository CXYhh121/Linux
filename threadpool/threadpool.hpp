#ifndef __THREADPOOL_HPP__
#define __THREADPOOL_HPP__

#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <unistd.h>
using namespace std;



typedef int (*HandlerTask_t)(int x,int y,int op);
class Task{
    private:
        int x;
        int y;
        char op; //0+,1-,2*,3/
        HandlerTask_t handler;
    public:
        Task(int x_ = -1,int y_ = -1,int op_ = -1)
            :x(x_),y(y_),op(op_)
        {

        }
        void Register(HandlerTask_t handler_)
        {
            handler = handler_;
        }

        void Run()
        {
            int res = handler(x,y,op);
            const char* op_ = "+-*/";
            cout << "thread:[ "<<pthread_self() << " ]"<< " handler reslut:";
            cout << x << op_[op] << y << " = " << res << endl;
        }

        ~Task()
        {

        }
};

class ThreadPool{
    private:
        int thread_nums;
        int idle_nums;
        queue<Task> task_queue;
        pthread_mutex_t lock;
        pthread_cond_t cond;
    public:
        void LockQueue()
        {
            pthread_mutex_lock(&lock);
        }
        void UnlockQueue()
        {
            pthread_mutex_unlock(&lock);
        }
        bool QueueIsEmpty()
        {
            return task_queue.size() == 0;
        }
        void ThreadIdle()
        {
            idle_nums++;
            pthread_cond_wait(&cond,&lock);
            idle_nums--;
        }
        void WakeupThread()
        {
            idle_nums--;
            pthread_cond_signal(&cond);
            idle_nums++;
        }
        void PopTask(Task& t)
        {
            t = task_queue.front();
            task_queue.pop();
        }
    public:
        ThreadPool(int num_ = 5):thread_nums(num_),idle_nums(0)
        {
            pthread_mutex_init(&lock,NULL);
            pthread_cond_init(&cond,NULL);
        }

        static void* ThreadRotinue(void* arg)
        {
            pthread_detach(pthread_self());
            ThreadPool *tp = (ThreadPool*)arg;
            for(;;){
                tp->LockQueue();
                while(tp->QueueIsEmpty()){
                   tp->ThreadIdle();
                }
                Task t;
                tp->PopTask(t);
                //Task t = task_queue.front();
                //task_queue.pop();
                tp->UnlockQueue();
                t.Run();
            }
        }

        void InitThreadPool()
        {
            pthread_t t;
            for(auto i = 0; i < thread_nums;i++){
                pthread_create(&t,NULL,ThreadRotinue,this);
            }

        }



        void PushTask(const Task &t)
        {
            LockQueue();
            task_queue.push(t);
            WakeupThread();
            UnlockQueue();
        }
        ~ThreadPool()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }

};


#endif
