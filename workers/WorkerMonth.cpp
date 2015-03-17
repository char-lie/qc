#include "WorkerMonth.h"

WorkerMonth::WorkerMonth() : Worker() {
}

WorkerMonth::WorkerMonth (int id, string name, const Decimal &salary,
                          bool typeIO, bool rawSalaryIO) :
                Worker(id, name, salary, typeIO, rawSalaryIO) {
}

Decimal WorkerMonth::getMonthSalary() const {
    return this->getSalary();
}

string WorkerMonth::getWorkerType() const {
    return "H";
}
