//Encapsulation
//OOP concepts :- Encapsulation, Abstraction, Inheritance, Polymorphism

# include<iostream>
using namespace std;

class Emp{
    //Now we cannot access these 3 properties outside our class
    private:
    string Name;
    string Company;
    int Age;

    //Accessing the private parts using functions
    public:
    void set_name(string name){
        Name = name; //setter
    }
    string get_name(){
        return Name; //getter
    }
    void set_company(string company){
        Company = company;
    }
    string get_company(){
        return Company;
    }
    void set_age(int age){
        Age = age;
    }
    int get_age(){
        return Age;
    }

    void details_print(){
        cout << "Name: - " << Name << endl;
        cout << "Company: -" << Company << endl;
        cout << "Age: - " << Age << endl;
    }
 
    //constructor
    Emp(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

};

int main(){

    Emp  emp_1 = Emp("Lw","Amazon",45);
    emp_1.details_print();

    //use set and get
    emp_1.set_age(23);
    cout<<"\n";
    cout<< emp_1.get_name() << " is " << emp_1.get_age() << " years old.";


};