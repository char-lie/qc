#pragma once
#include "../worker/WorkerHour.h"
#include "WorkerBuilder.h"

/*
 * Builder for worker with hour wage
 */
class WorkerHourBuilder : public WorkerBuilder {
    public:
        WorkerHourBuilder() : WorkerBuilder() { };
        ~WorkerHourBuilder() { };
        void buildNewWorker(istream &in) {
            this->worker.reset(new WorkerHour());
            in >> (*worker);
        }
};
