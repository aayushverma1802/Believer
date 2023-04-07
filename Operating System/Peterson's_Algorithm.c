#include <stdio.h>
#include <pthread.h>
void *work(void *s);
int flag[2];
int turn, val = 0;
void main()
{
    pthread_t t1, t2;
    val = 0;

    lock_init();

    pthread_create(&t1, NULL, work, (void *)0);
    pthread_create(&t2, NULL, work, (void *)1);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Value: %d\n", val);
}

void lock_init()
{

    flag[0] = flag[1] = 0;
    turn = 0;
}

void lock(int other)
{
    flag[other] = 1;
    turn = 1 - other;
    while (flag[1 - other] == 1 && turn == 1 - other)
        ;
}

void unlock(int other)
{
    flag[other] = 0;
}

void *work(void *s)
{
    int i = 0;
    int other = (int *)s;

    printf("Thread : %d\n", other);
    lock(other);

    for (i = 0; i < 100000000; i++)
        val++;

    unlock(other);
}