#include <thread>
#include <iostream>
#include <atomic>
#include <unistd.h>

std::atomic<int>  xTotal;
std::atomic<int>  yTotal;

int x[100];

void thread1()
{
    for (int i=0;i<49;i++)
    {
       xTotal=xTotal + x[i];
       sleep(5);
    }
    return;
}

void thread2()
{
    for (int i=50;i<100;i++)
    {
       yTotal=yTotal + x[i];
       sleep(5);
    }
    return;
}

int main(int argc,char *argv[])
{
    x[0]=100;
    x[99]=-101;
    xTotal=0;
    yTotal=0;
    std::cout << "this is the main " << std::endl;
    std::thread T1(thread1);
    std::thread T2([] () -> void {
                       for (int i=50;i<100;i++)
                       {
                            yTotal=yTotal + x[i];
                       }
                      return;
                      });
    std::cout << T1.get_id() << "  " << T2.get_id() << std::endl;
    T1.join();
    T2.join();
    std::cout << "the answer is xTotal " << xTotal << std::endl;
    std::cout << "the answer is yTotal " << yTotal << std::endl;
    return 0;
}
