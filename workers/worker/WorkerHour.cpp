#include "WorkerHour.h"

WorkerHour::WorkerHour() : Worker() {
}

WorkerHour::WorkerHour (int id, string name, const Decimal &salary,
                        bool typeIO, bool rawSalaryIO) :
                Worker(id, name, salary, typeIO, rawSalaryIO) {
}

Decimal WorkerHour::getSalaryK() {
    return Decimal(208*8, 1);
}

Decimal WorkerHour::getMonthSalary() const {
    return this->getSalary() * WorkerHour::getSalaryK();
}

string WorkerHour::getWorkerType() const {
    return "H";
}
