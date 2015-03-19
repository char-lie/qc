#pragma once
#include "Worker.h"

/*
 * Worker with hourly wage
 */
class WorkerHour: public Worker {
    public:
        WorkerHour ();
        WorkerHour (int id, string name, const Decimal &salary,
                    bool typeIO = false, bool rawSalaryIO = true);

        static Decimal  getSalaryK      ();

        virtual Decimal getMonthSalary  () const;
        virtual string  getWorkerType   () const;
};
