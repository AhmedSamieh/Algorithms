#include <semaphore.h>

class H2O {
    sem_t h_sem;
    sem_t o_sem;
    mutex o_sem_mutex;
public:
    H2O() {
        sem_init(&h_sem, 0, 2);
        sem_init(&o_sem, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        sem_wait(&h_sem);
        releaseHydrogen();
        sem_post(&o_sem);
    }

    void oxygen(function<void()> releaseOxygen) {
        o_sem_mutex.lock();
        sem_wait(&o_sem);
        sem_wait(&o_sem);
        o_sem_mutex.unlock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&h_sem);
        sem_post(&h_sem);
    }
};