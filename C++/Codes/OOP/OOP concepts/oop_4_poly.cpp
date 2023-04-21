//Polymorphism :- Ablity of an object to have many forms
// Polymorphism and pointers :- https://youtu.be/anU8zQfBkP8
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

    //New method 
    // This same method is implemented in Developer and Mnager differently
    // Base class
    void  Work(){
        cout << Name << " is checking mails."<< endl;
    }

    // Here after putting "virtual", the its first go to the 
    // child class and check whether, there are this "work()" method.
    // If it has , then thr programme will run it.
    // If the child doent have the method, then the programme will run the method in the parent.
    void virtual Work_(){
        cout << Name << " is checking mails....."<< endl;
    }
};

// child class is Developer
class Developer : public Emp {
    public:
        string programming_lang;

    Developer(string name, string company, int age, string pl)
        :Emp(name, company, age){
            programming_lang = pl;
    }
    //Creating a function
    void pl_out(){
        cout << Name << " knows how to use " << programming_lang << "." << endl;
    }

    //Work method apply differently from the method in the base class
    void  Work(){
        cout << Name << " is debugging the "<< programming_lang<<" code." << endl;
    }
    void  Work_(){
        cout << Name << " is debugging the "<< programming_lang<<" code...." << endl;
    }

};

// child class is Manager
class Manager : public Emp{    // Since we havent put "public Emp" here, manager objects cannot access the methods in Emp class (ex:- AskForPromotion)
    public:
    string Field;

    Manager(string name, string company, int age, string field) : Emp(name , company, age){
        Field = field;
    }

    //Work method apply differently from the method in the base class
    void  Work(){
        cout << Name << "is managing the "<< Field<<" field." << endl;
    }
    void  Work_(){
        cout << Name << "is managing the "<< Field<<" field....." << endl;
    }

};

int main(){

    Emp  emp_1 = Emp("Lw","Amazon",45);
    emp_1.Work();
    cout<<endl;

    Developer d_1 = Developer("Khan", "Face_Book",30,"cpp");
    d_1.Work();

    Manager m_1 = Manager("Jhon", "Face_Book", 40, "R&D");
    m_1.Work();

    //The most common use of polymorphism is when a
    //parent class reference is used to refer to a child class object.
    Emp *e1 = &d_1; //pointers
    Emp *e2 = &m_1;

    e1->Work();
    e2->Work();

    cout<<endl;

    e1->Work_();
    e2->Work_();

};
