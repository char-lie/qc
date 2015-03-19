#pragma once
#include "../worker/Worker.h"

class WorkerBuilder {
    protected:
        Worker* worker;
    public:
        WorkerBuilder() { this->worker = NULL; }
        virtual ~WorkerBuilder() { }
        Worker* getWorker() { return this->worker; }
        virtual void buildNewWorker(istream &in) = 0;
};
