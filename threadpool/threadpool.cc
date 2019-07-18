#include "threadpool.hpp"


int cal(int x,int y,int op)
{
    int ret = -1;
    switch(op)
    {
        case 0:
            ret = x + y;
            break;
        case 1:
            ret = x - y;
            break;
        case 2:
            ret = x * y;
            break;
        case 3:
            ret = x / y;
            break;
        default:
            cout << "cal error!" << endl;
            break;
    }
}

int main()
{
    ThreadPool tp;
    tp.InitThreadPool();
    srand((unsigned long)time(NULL));
    for(;;){
        sleep(1);
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        int op = rand() % 4;
        Task t(x,y,op);
        t.Register(cal);

        tp.PushTask(t);
    }
    return 0;
}
