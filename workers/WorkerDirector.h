#pragma once
#include "WorkerBuilder.h"
#include "Worker.h"
#include "WorkerHourBuilder.h"
#include "WorkerMonthBuilder.h"

class WorkerDirector {
    private:
        WorkerBuilder* workerBuilder;
    public:
        WorkerDirector() : workerBuilder(NULL) { }
        Worker* getWorker () { return this->workerBuilder->getWorker(); }
        void setWorkerBuilder(WorkerBuilder* wb) { this->workerBuilder = wb; }
        void constructWorker(istream &in) {
            string workerType;
            in >> workerType;
            if (workerType == "H") {
                this->setWorkerBuilder(new WorkerHourBuilder());
            }
            else if (workerType == "M") {
                this->setWorkerBuilder(new WorkerMonthBuilder());
            }
            this->workerBuilder->buildNewWorker(in);
        }
};
