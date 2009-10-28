typedef sem_t Semaphore;
typedef struct {
      int counter;
} Shared;

void *check_malloc (int size);
Shared *make_shared ();
void *entry(void *arg);
void join_thread (pthread_t thread);
Semaphore *make_semaphore(int n);
int sem_signal(Semaphore *sem);
