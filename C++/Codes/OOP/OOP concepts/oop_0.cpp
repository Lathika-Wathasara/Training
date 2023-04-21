//  https://www.youtube.com/watch?v=wN0x9eZLix4
//  OOP concepts :- Encapsulation, Abstraction, Inheritance, Polymorphism

# include<iostream>
using namespace std;

class Emp{
    public:
    string Name;
    string Company;
    int Age;

    //class method as a function
    void details_print(){               
        cout << "Name: - " << Name << endl;
        cout << "Company: -" << Company << endl;
        cout << "Age: - " << Age << endl;
    }
    
    //constructor :- no return type(ex:- void),  should have the same name as the class, normally public
    // Used to pass the values, as the class is defining (ex:- add Name, when we define emp_1)
    //When we are creating the constructor, we loos the default constructor (so we need to give values as we define emp_1)
    Emp(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

};

int main(){

    //Befor constructor
    // Emp emp_1;
    // emp_1.Name ="Lw";
    // emp_1.Company ="Sys";
    // emp_1.Age = 24;
    // emp_1.details_print();

    //After constructor
    Emp  emp_1 = Emp("Lw","Amazon",45);
    emp_1.details_print();


};