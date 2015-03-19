#include <iostream>
#include <vector>
#include "worker/Worker.h"
#include "builder/WorkerDirector.h"

using namespace std;
typedef shared_ptr<Worker> p_worker;

ostream& operator<<(ostream& out, const vector<p_worker>& workers) {
    for (auto w : workers) {
        out << (*w) << endl;
    }
    return out;
}

istream& operator>>(istream& in, vector<p_worker>& workers) {
    p_worker w;
    WorkerDirector director;
    while (!in.eof()) {
        director.constructWorker(in);
        w = director.getWorker();
        if (w == NULL && !in.eof()) {
            in.setstate(ios::failbit);
            break;
        }
        else if (in.eof()) {
            break;
        }
        w->setRawSalaryIO(false);
        workers.push_back(w);
    }
    return in;
}
