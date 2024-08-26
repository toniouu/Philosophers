#include "philo.h"

pthread_mutex_t mutex;

void    *test1(void *arg)
{
    int i = 0;
    char *ms;

    ms = (char *)arg;
    while (i < 100)
    {
        pthread_mutex_lock(&mutex);
        while (i < 20)
        {
            printf("Mutex verrouille par le thread 1 : %d\n\n", i);
            i++;
        }
        pthread_mutex_unlock(&mutex);
        printf("Mutex verrouille par le thread 1 : %d\n\n", i);
        pthread_mutex_lock(&mutex);
        while (i < 80)
        {
            printf("Mutex verrouille par le thread 1 : %d\n\n", i);
            i++;
        }
        pthread_mutex_unlock(&mutex);
        i++;
    }
    return (NULL);
}

void    *test2(void *arg)
{
    int i = 0;
    char *ms;

    ms = (char *)arg;
    pthread_mutex_lock(&mutex);
    while (i < 100)
    {
        printf("Mutex verrroulle par le thread 2 : %d\n\n", i);
        i++;
    }
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int main(void)
{
    pthread_t thread1;
    pthread_t thread2;
    void    *result;

    pthread_mutex_init(&mutex, NULL);
    char *ms1 = "Thread N---->1";
    char *ms2 = "Thread N---->2";
    pthread_create(&thread1, NULL, test1, NULL);
    pthread_create(&thread2, NULL, test2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return (0);
}
