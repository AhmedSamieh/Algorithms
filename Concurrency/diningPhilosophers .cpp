#include <semaphore.h>

class DiningPhilosophers
{
    mutex fork[5];
public:
    DiningPhilosophers()
    {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {
        if ((philosopher & 1) == 1) {
            unique_lock<mutex> right_guard(fork[philosopher]);
            unique_lock<mutex> left_guard(fork[(philosopher + 1) % 5]);
            pickRightFork();
            pickLeftFork();
            eat();
            putRightFork();
            putLeftFork();
        } else {
            unique_lock<mutex> left_guard(fork[(philosopher + 1) % 5]);
            unique_lock<mutex> right_guard(fork[philosopher]);
            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
        }
    }
};