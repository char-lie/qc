#pragma once
#include <vector>
#include "WorkerBuilder.h"
#include "../worker/Worker.h"
#include "WorkerHourBuilder.h"
#include "WorkerMonthBuilder.h"

using namespace std;

typedef shared_ptr<WorkerBuilder> p_WorkerBuilder;

/*
 * Director for Builder pattern.
 * Creates new worker depending on type
 */
class WorkerDirector {
    private:
        vector<p_WorkerBuilder> builders;
        p_WorkerBuilder workerBuilder;
    public:
        WorkerDirector                  ();
        ~WorkerDirector                 ();
        shared_ptr<Worker> getWorker    ();
        void setWorkerBuilder           (p_WorkerBuilder workerBuilder);
        /*
         * Reads new worker from input stream
         */
        void constructWorker            (istream &in);
};
