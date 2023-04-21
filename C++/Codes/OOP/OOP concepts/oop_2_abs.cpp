//Abstraction :- Hide complex things behind a procedeur and make them see as simple
//OOP concepts :- Encapsulation, Abstraction, Inheritance, Polymorphism

# include<iostream>
using namespace std;

//Abstracton class
// Which ever class sign this contract should be able to provide implemantation for a method called 'ask for promotion'
class AbstractEmployee{
    virtual void AskForPromotion()=0; // pure virtual function 

};

class Emp:AbstractEmployee{
    private:
    string Name;
    string Company;
    int Age;

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

int main(){

    Emp  emp_1 = Emp("Lw","Amazon",45);
    emp_1.details_print();
    
    Emp emp_2 = Emp("Ka", "Amazon", 25);
    emp_2.details_print();

    emp_1.AskForPromotion();
    emp_2.AskForPromotion();

};