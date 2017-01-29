
#include "ThreadPool.h"
#include <unistd.h>
#include <iostream>

static void *startJobs(void *arg) {
	ThreadPool *pool = (ThreadPool *)arg;
	pool->doJobs();
	return NULL;
}

void ThreadPool::doJobs() {
	while (!stop) {
		pthread_mutex_lock(&lock);
		if (!jobs_queue.empty() ) {
			Job* job = jobs_queue.front();
			job->execute();
			jobs_queue.pop();
			pthread_mutex_unlock(&lock);
		}
		else {
			pthread_mutex_unlock(&lock);
			sleep(1);
		}
	}
	pthread_exit(NULL);
}

void ThreadPool::addJob(Job *job) {
	jobs_queue.push(job);
}

ThreadPool::ThreadPool(int threads_num) : threads_num(threads_num), stop(false), isDone(true) {
	threads = new pthread_t[threads_num];

	pthread_mutex_init(&lock, NULL);
	for (int i = 0; i < threads_num; i++) {
		pthread_create(threads + i, NULL, startJobs, this);
	}
}

void ThreadPool::terminate() {
	stop = true;
}

ThreadPool::~ThreadPool() {
	delete[] threads;
	pthread_mutex_destroy(&lock);
}

void ThreadPool::ThreadPoolJoin() {
    //waiting that the jobs will be done
	while (!jobs_queue.empty()) {}
}
