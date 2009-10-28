#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "semaphore_book.h"

void *check_malloc (int size)
{
      void *p = malloc (size);
      if (p == NULL) {
	    perror("malloc failed");
	    exit(-1);
      }
      return p;
 }


Shared *make_shared ()
{
      int i;
      Shared *shared  = check_malloc(sizeof(Shared));
      shared->counter = 0;
      return shared;
}

void *entry(void *arg)
{
      Shared *shared = (Shared *) arg;
      //      child_code (shared);
      pthread_exit(NULL);
}

/*pthread_t make_thread((void *entry)(void , Shared *shared))
{
      int n;
      pthread_t thread;

      n = pthread_create (&thread, NULL, entry, (void *)shared);
      if (n != 0) {
	    perror("pthread_create failed");
	    exit(-1);
      }
}
*/

void join_thread (pthread_t thread){
      int ret = pthread_join(thread, NULL);
      if ( ret == -1 ) {
	    perror("pthread_join failed");
	    exit(-1);
      }
}

Semaphore *make_semaphore(int n)
{
      Semaphore *sem = check_malloc (sizeof(Semaphore));
      int ret = sem_init(sem, 0, n);
      if (ret == -1) {
	    perror("sem_init failed");
	    exit(-1);
      }
      return sem;
}

int sem_signal(Semaphore *sem)
{
      return sem_post(sem);
}
