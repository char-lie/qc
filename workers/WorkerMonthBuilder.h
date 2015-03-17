#pragma once
#include "WorkerMonth.h"
#include "WorkerBuilder.h"

class WorkerMonthBuilder : public WorkerBuilder {
    public:
        WorkerMonthBuilder() : WorkerBuilder() { };
        ~WorkerMonthBuilder() { };
        void buildNewWorker(istream &in) {
            this->worker = new WorkerMonth();
            in >> (*worker);
        }
};
