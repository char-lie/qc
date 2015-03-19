#pragma once
#include "../worker/WorkerHour.h"
#include "WorkerBuilder.h"

class WorkerHourBuilder : public WorkerBuilder {
    public:
        WorkerHourBuilder() : WorkerBuilder() { };
        ~WorkerHourBuilder() { };
        void buildNewWorker(istream &in) {
            this->worker = new WorkerHour();
            in >> (*worker);
        }
};
