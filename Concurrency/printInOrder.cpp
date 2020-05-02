#include <semaphore.h>

class Foo
{
    sem_t sem_first_done;
    sem_t sem_second_done;
public:
    Foo()
    {
        sem_init(&sem_first_done, 0, 0);
        sem_init(&sem_second_done, 0, 0);
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&sem_first_done);
    }

    void second(function<void()> printSecond)
    {
        sem_wait(&sem_first_done);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&sem_second_done);
    }

    void third(function<void()> printThird)
    {
        sem_wait(&sem_second_done);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
