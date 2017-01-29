/*
 * ThreadPool.h
 *
 *  Created on: Jan 20, 2017
 *      Author: viki
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include "Job.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
private:
	queue<Job *> jobs_queue;
	int threads_num;
	pthread_t* threads;
	bool stop;
	bool isDone;
	pthread_mutex_t lock;

public:
/**
 * ThreadPool constructor
 * @param threads_num
 */
	ThreadPool(int threads_num);

/**
 * making the threads doing their jobs
 */
	void doJobs();

/**
 * adding a job to the jobs' list
 * @param job
 */
	void addJob(Job *job);

/**
 * terminate the threads' jobs
 */
	void terminate();

/**
 * ThreadPool destructor
 */
	virtual ~ThreadPool();

/**
 * waiting that threads will finish their jobs
 */
    void ThreadPoolJoin() ;
};

#endif /* THREADPOOL_H_ */
