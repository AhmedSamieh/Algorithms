#include <semaphore.h>

class BoundedBlockingQueue
{
    queue<int> q;
    mutex      q_mutex;
    sem_t      enqueue_sem;
    sem_t      dequeue_sem;
public:
    BoundedBlockingQueue(int capacity)
    {
        sem_init(&enqueue_sem, 0, capacity);
        sem_init(&dequeue_sem, 0, 0);
    }

    void enqueue(int element)
    {
        sem_wait(&enqueue_sem);
        q_mutex.lock();
        q.push(element);
        q_mutex.unlock();
        sem_post(&dequeue_sem);
    }

    int dequeue()
    {
        sem_wait(&dequeue_sem);
        q_mutex.lock();
        int element = q.front();
        q.pop();
        q_mutex.unlock();
        sem_post(&enqueue_sem);
        return element;
    }

    int size()
    {
        q_mutex.lock();
        int size = q.size();
        q_mutex.unlock();
        return size;
    }
};
