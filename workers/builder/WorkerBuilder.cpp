#include "WorkerBuilder.h"

WorkerBuilder::WorkerBuilder() {
    this->worker.reset();
}
WorkerBuilder::~WorkerBuilder() {
    this->worker.reset();
}
shared_ptr<Worker> WorkerBuilder::getWorker() {
    return this->worker;
}
void WorkerBuilder::reset() {
    this->worker.reset();
}
