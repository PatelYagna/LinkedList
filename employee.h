#include <string>
using namespace std;

// Define a base class Employee
class Employee {

protected:
    string name;
    int age, vacationDays;
    double weeklySalary, healthCareContributions;

public:
    // Constructor for the Employee class
    Employee(string name, int age) {
        this->name = name;
        this->age = age;
        weeklySalary = 0.0;
        vacationDays = 0;
        healthCareContributions = 0.0;
    }

    // Virtual function to calculate weekly salary (to be implemented by derived classes)
    virtual double calculateWeeklySalary() = 0;

    // Virtual function to calculate healthcare contributions (to be implemented by derived classes)
    virtual double calculateHealthCareContributions() = 0;

    // Virtual function to calculate vacation days (to be implemented by derived classes)
    virtual int calculateVacationDays() = 0;

    // Get the name of the employee
    virtual string getName() { return this->name; }

    // Get the age of the employee
    virtual int getAge() { return this->age; }
};

// Define a derived class Professional inheriting from Employee
class Professional : public Employee {

private:
    double monthlySalary;
    int daysVacation;

public:
    // Constructor for the Professional class
    Professional(string name, int age, double monthly) : Employee(name, age) {
        monthlySalary = monthly;
        daysVacation = 30;
    }

    // Implementation of calculating weekly salary for a Professional
    double calculateWeeklySalary() {
        return (monthlySalary / 4);
    }

    // Implementation of calculating healthcare contributions for a Professional
    double calculateHealthCareContributions() {
        return ((monthlySalary * 0.10) / 4);
    }

    // Implementation of calculating vacation days for a Professional
    int calculateVacationDays() {
        return daysVacation;
    }

    // Function to print Professional employee information
    void print() {
        cout << endl << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Weekly Salary: " << calculateWeeklySalary() << endl;
        cout << "Healthcare Contributions: " << calculateHealthCareContributions() << endl;
        cout << "Vacation Days: " << calculateVacationDays() << endl << endl;
    }
};

// Define a derived class Nonprofessional inheriting from Employee
class Nonprofessional : public Employee {

private:
    double hourlyRate;
    int hoursWorked;

public:
    // Constructor for the Nonprofessional class
    Nonprofessional(string name, int age, double rate, int hours) : Employee(name, age) {
        hourlyRate = rate;
        hoursWorked = hours;
    }

    // Implementation of calculating weekly salary for a Nonprofessional
    double calculateWeeklySalary() {
        return (hourlyRate * hoursWorked);
    }

    // Implementation of calculating healthcare contributions for a Nonprofessional
    double calculateHealthCareContributions() {
        return (hourlyRate * hoursWorked * 0.05);
    }

    // Implementation of calculating vacation days for a Nonprofessional
    int calculateVacationDays() {
        return (hoursWorked / 10);
    }

    // Function to print Nonprofessional employee information
    void print() {
        cout << endl << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Weekly Salary: " << calculateWeeklySalary() << endl;
        cout << "Healthcare Contributions: " << calculateHealthCareContributions() << endl;
        cout << "Vacation Days: " << calculateVacationDays() << endl << endl;
    }
};
