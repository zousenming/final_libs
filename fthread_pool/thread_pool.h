#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef	void* (*pfunc)(void* pri_arg, void* parg);

/* new version use the follow methods */
void	thpool_init(int num);
// the arg is the every task arg
int		thpool_post_task(pfunc, void* arg);
// the thread_data arg is this thread fixed arg every callback will push it
int 	thpool_add_thread(void* pri_arg);
int 	thpool_del_thread(int tid);

#ifdef __cplusplus
}
#endif

#endif
