#pragma once
#include "../worker/WorkerMonth.h"
#include "WorkerBuilder.h"

/*
 * Builder for worker with monthly wage
 */
class WorkerMonthBuilder : public WorkerBuilder {
    public:
        WorkerMonthBuilder() : WorkerBuilder() { };
        ~WorkerMonthBuilder() { };
        void buildNewWorker(istream &in) {
            this->worker.reset(new WorkerMonth());
            in >> (*worker);
        }
};
