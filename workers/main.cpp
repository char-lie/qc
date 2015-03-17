#include <iostream>
#include "Worker.h"
#include "WorkerHour.h"
#include "WorkerDirector.h"

using namespace std;

int main() {
    //WorkerHour w(1, "John", 1, true);
    Worker* w;
    WorkerDirector director;
    director.constructWorker(cin);
    w = director.getWorker();
    w->setRawSalaryIO(false);
    cout << (*w) << endl;
    delete w;
    return 0;
}
