
#include "Job.h"

Job::Job(void *(*func)(void *arg), void *arg): func(func), arg(arg) {}

void Job::execute() {
	func(arg);
}

Job::~Job() {
}

