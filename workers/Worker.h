#pragma once

#include "Decimal.h"
#include <string>

class Worker {
    protected:
        int     id;
        string  name;
        Decimal salary;
        bool    typeIO;
        bool    rawSalaryIO;
    public:
        Worker ();
        Worker (int id, string name, const Decimal &salary,
                bool displayingType = false, bool rawSalaryIO = true);

        int     getId                   () const;
        string  getName                 () const;
        Decimal getSalary               () const;
        bool    isTypeIO                () const;
        bool    isRawSalaryIO           () const;

        void    setId                   (int id);
        void    setName                 (string name);
        void    setSalary               (const Decimal &salary);
        void    setTypeIO               (bool typeIO);
        void    setRawSalaryIO          (bool rawSalaryIO);

        virtual Decimal getMonthSalary  () const  = 0;
        virtual string  getWorkerType   () const  = 0;
};

ostream& operator<<(ostream &out, const Worker &worker);
istream& operator>>(istream &in,  Worker &worker);
