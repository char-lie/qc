#include "Worker.h"

Worker::Worker() : id(-1), name(""), salary(0), typeIO(false) {
}

Worker::Worker (int id, string name, const Decimal &salary,
                bool typeIO, bool rawSalaryIO) :
                id(id), name(name), salary(salary), typeIO(typeIO),
                rawSalaryIO(rawSalaryIO) {
}

bool Worker::isTypeIO () const {
    return this->typeIO;
}

bool Worker::isRawSalaryIO () const {
    return this->rawSalaryIO;
}

int Worker::getId () const {
    return this->id;
}

string Worker::getName () const {
    return this->name;
}

Decimal Worker::getSalary () const {
    return this->salary;
}

void Worker::setTypeIO (bool typeIO) {
    this->typeIO = typeIO;
}

void Worker::setRawSalaryIO (bool rawSalaryIO) {
    this->rawSalaryIO = rawSalaryIO;
}

void Worker::setId (int id) {
    this->id = id;
}
void Worker::setName (string name) {
    this->name = name;
}
void Worker::setSalary (const Decimal &salary) {
    this->salary = salary;
}

ostream& operator<<(ostream &out, const Worker &worker) {
    if (worker.isTypeIO()) {
        out << worker.getWorkerType() << ' ';
    }
    out << worker.getId() << ' ' << worker.getName() << ' '
        << (worker.isRawSalaryIO()? worker.getSalary():worker.getMonthSalary());
    return out;
}

istream& operator>>(istream &in,  Worker &worker) {
    string workerType;
    int id;
    string name;
    Decimal salary;

    in.clear();

    if (worker.isTypeIO()) {
        in >> workerType;
    }
    else {
        workerType = worker.getWorkerType();
    }

    if (workerType == worker.getWorkerType()) {
        in >> id >> name >> salary;
    }
    else {
        in.setstate(ios::failbit);
    }

    if (!(in.rdstate() & ios::failbit)) {
        worker.setId(id);
        worker.setName(name);
        worker.setSalary(salary);
    }
    return in;
}
