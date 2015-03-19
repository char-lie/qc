#pragma once
#include <memory>
#include "../worker/Worker.h"

/*
 * Abstract builder for Builder pattern
 */
class WorkerBuilder {
    protected:
        shared_ptr<Worker> worker;
    public:
        WorkerBuilder                   ();
        ~WorkerBuilder                  ();
        shared_ptr<Worker> getWorker    ();
        void reset                      ();
        /*
         * Method for building new worker:
         * reads him from the input stream
         */
        virtual void buildNewWorker     (istream &in) = 0;
};
