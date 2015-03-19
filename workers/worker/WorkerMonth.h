#pragma once
#include "Worker.h"

/*
 * Worker with monthly wage
 */
class WorkerMonth: public Worker {
    public:
        WorkerMonth ();
        WorkerMonth (int id, string name, const Decimal &salary,
                     bool typeIO = false, bool rawSalaryIO = true);

        virtual Decimal getMonthSalary  () const;
        virtual string  getWorkerType   () const;
};
