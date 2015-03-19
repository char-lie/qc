#include "WorkerDirector.h"

WorkerDirector::WorkerDirector() {
    builders.push_back(p_WorkerBuilder(new WorkerHourBuilder));
    builders.push_back(p_WorkerBuilder(new WorkerMonthBuilder));
}

WorkerDirector::~WorkerDirector() {
    for (auto builder : this->builders) {
        builder.reset();
    }
}
shared_ptr<Worker> WorkerDirector::getWorker () {
    return this->workerBuilder->getWorker();
}
void WorkerDirector::setWorkerBuilder(p_WorkerBuilder workerBuilder) {
    this->workerBuilder = workerBuilder;
}

void WorkerDirector::constructWorker(istream &in) {
    string workerType;
    in >> workerType;
    if (workerType == "H") {
        this->setWorkerBuilder(this->builders[0]);
    }
    else if (workerType == "M") {
        this->setWorkerBuilder(this->builders[1]);
    }
    else {
        this->workerBuilder->reset();
        return;
    }
    this->workerBuilder->buildNewWorker(in);
}
