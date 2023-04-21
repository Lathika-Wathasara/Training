//Inheritance :- Has base class (parent class), and derived class (chld class) 
//OOP concepts :- Encapsulation, Abstraction, Inheritance, Polymorphism

# include<iostream>
using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;

};

class Emp:AbstractEmployee{
    // 3 types of access modifiers :- private, public, protected
    private:
    string Company;
    int Age;

    protected: // public for certain special cases, otherwise private.
    string Name;

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
 
    Emp(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion(){
        if (Age <40){
            cout<< Name << ", sorry! No promotion for you." << endl;
        }
        else{
            cout<< Name << ", you are promotted." << endl;
        }
    
    }

};

// child class - Developer, PArent class :- Emp
// Here the child class inherits all the features of the parent class.
// we put 'public' in front of Emp, so that Developer objects can access the methods in Emp.
class Developer : public Emp {
    public:
        string programming_lang;

    //needs to creat a constructor for Developer class
    //When we hav ne default constructor, there might be errors. Here we have inheritted from Emp class, which is we made for Emp class.
    //So we need to creat a constructor for the Developer class
    Developer(string name, string company, int age, string pl)
        :Emp(name, company, age){
            programming_lang = pl;
    }
    //Creating a function
    void pl_out(){
        // Here to make "Name" accessable in this child class, we need to make the Access Modifier as "protected"
        cout << Name << " kows how to use " << programming_lang << "." << endl;
    }
};

// child class is Manager
class Manager : Emp{    // Since we havent put "public Emp" here, manager objects cannot access the methods in Emp class (ex:- AskForPromotion)
    public:
    string Field;

    // constructor
    Manager(string name, string company, int age, string field) : Emp(name , company, age){
        Field = field;
    }

};

int main(){

    Emp  emp_1 = Emp("Lw","Amazon",45);
    emp_1.details_print();
    
    Emp emp_2 = Emp("Ka", "Amazon", 25);
    emp_2.details_print();

    Developer d_1 = Developer("Khan", "Face_Book",30,"cpp");
    d_1.pl_out();
    // d_1 can access the method "AskForPromition" after we made the methods of Emp accessible to Developer. 
    d_1.AskForPromotion();

    Manager m_1 = Manager("Jhon", "Face_Book", 40, "R&D");
   // m_1.AskForPromotion();   // (This gives an error, because Emp's methods are private to the child classes )
};