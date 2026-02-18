#include <iostream>
using namespace std;

class Person
{
private:
    int number;
    string name;
    string address;

public:
    Person();
    Person(int num, string n, string addr);

    int getNumber();
    string getName();
    string getAddress();

    void setNumber(int num);
    void setName(string n);
    void setAddress(string addr);

    void display();
     ~Person();
};

Person::Person()
{
    number = 0;
    name = "";
    address = "";
}

Person::Person(int num, string n, string addr)
{
    number = num;
    name = n;
    address = addr;
}

Person::~Person()
{
    cout<<"Destroying Person: "<< name <<endl;
}

int Person::getNumber()
{
    return number;
}

string Person::getName()
{
    return name;
}

string Person::getAddress()
{
    return address;
}

void Person::setNumber(int num)
{
    number = num;
}

void Person::setName(string n)
{
    name = n;
}

void Person::setAddress(string addr)
{
    address = addr;
}

void Person::display()
{
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
}

class HourlyEmployee : public Person
{
private:
    double hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee();

    HourlyEmployee(int num, string n, string addr, double hours, double rate);

    double getHoursWorked();
    double getHourlyRate();

    void setHoursWorked(double hours);
    void setHourlyRate(double rate);

    friend double monthPayment(HourlyEmployee e);

    void display();
};

HourlyEmployee::HourlyEmployee() : Person()
{
    hoursWorked = 0.0;
    hourlyRate = 0.0;
}

HourlyEmployee::HourlyEmployee(int num, string n, string addr, double hours, double rate) : Person(num, n, addr)
{
    hoursWorked = hours;
    hourlyRate = rate;
}

double HourlyEmployee::getHoursWorked()
{
    return hoursWorked;
}

double HourlyEmployee::getHourlyRate()
{
    return hourlyRate;
}

void HourlyEmployee::setHoursWorked(double hours)
{
    hoursWorked = hours;
}

void HourlyEmployee::setHourlyRate(double rate)
{
    hourlyRate = rate;
}

void HourlyEmployee::display()
{
    Person::display();
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Hourly Rate: " << hourlyRate << endl;
    cout << "Monthly Payment: " << monthPayment(*this) << endl;
}

double monthPayment(HourlyEmployee e)
{
    return e.getHoursWorked() * e.getHourlyRate();
}

int main() {
    int n;
    do {
        cout << "Enter number of employees: ";
        cin >> n;

        if(n <= 0 || n > 50){
            cout<<"Invalid number of employees. Please enter a number between 1 and 50."<<endl;
        }
        
    } while (n <= 0 || n > 50);
    
    HourlyEmployee *pArr = new HourlyEmployee[n];

    for (int i = 0; i < n; i++){
        cout <<"Enter details for employee"<<endl;
        int num;
        string name;    
        string address;
        double hours;
        double rate;

        cout << "Number: ";
        cin >> num;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Address: ";
        getline(cin, address);
        cout << "Hours Worked: ";
        cin >> hours;   
        cout << "Hourly Rate: ";
        cin >> rate;

        pArr[i] = HourlyEmployee(num, name, address, hours, rate);
    }

    cout << "Employee details:" << endl;
    for (int i = 0; i < n; i++){
        pArr[i].display();
        cout << "-------------------" << endl;
    }

    cout<<"Employee numbers and monthly payments:"<<endl;
    for (int i = 0; i < n; i++){
        cout<<"Employee Numbers:" <<pArr[i].getNumber()<<endl;
        cout<<"Monthly Payment:"<<monthPayment(pArr[i])<<endl;
        cout << "-------------------" << endl;
    }

    double sumOfMonthlyPayments = 0.0;
    double averageMonthlyPayment = 0.0;
    for (int i = 0; i < n; i++){
        sumOfMonthlyPayments += monthPayment(pArr[i]);
    }

    averageMonthlyPayment = sumOfMonthlyPayments / n;
    cout<<"Average Monthly Payment: "<< averageMonthlyPayment <<endl;

    delete[] pArr;
    return 0;
}