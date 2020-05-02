#include <semaphore.h>

class FizzBuzz
{
private:
    int n;
    sem_t fizz_sem;
    sem_t buzz_sem;
    sem_t fizz_buzz_sem;
    sem_t num_sem;
public:
    FizzBuzz(int n)
    {
        this->n = n;
        sem_init(&fizz_sem, 0, 0);
        sem_init(&buzz_sem, 0, 0);
        sem_init(&fizz_buzz_sem, 0, 0);
        sem_init(&num_sem, 0, 0);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        for (int i = 3; i <= n; i += 3) {
            if ((i % 5) != 0) {
                sem_wait(&fizz_sem);
                printFizz();
                sem_post(&num_sem);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        for (int i = 5; i <= n; i += 5) {
            if ((i % 3) != 0) {
                sem_wait(&buzz_sem);
                printBuzz();
                sem_post(&num_sem);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        for (int i = 15; i <= n; i += 15) {
            sem_wait(&fizz_buzz_sem);
            printFizzBuzz();
            sem_post(&num_sem);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; ++i) {
            if ((i % 15) == 0) {
                sem_post(&fizz_buzz_sem);
                sem_wait(&num_sem);
            } else if ((i % 3) == 0) {
                sem_post(&fizz_sem);
                sem_wait(&num_sem);
            } else if ((i % 5) == 0) {
                sem_post(&buzz_sem);
                sem_wait(&num_sem);
            } else {
                printNumber(i);
            }
        }
    }
};