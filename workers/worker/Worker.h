#pragma once

#include "../utils/Decimal.h"
#include <string>

/*
 * Abstract Worker class
 */
class Worker {
    protected:
        int     id;
        string  name;
        Decimal salary;
        /*
         * Should we read and write worker type?
         */
        bool    typeIO;
        /*
         * Should we write raw salary (getSalary) or month salary?
         */
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

        /*
         * Calculate salary for month
         */
        virtual Decimal getMonthSalary  () const  = 0;
        /*
         * Get worker type to differ each worker when writing/reading them
         */
        virtual string  getWorkerType   () const  = 0;
};

ostream& operator<<(ostream &out, const Worker &worker);
istream& operator>>(istream &in,  Worker &worker);
