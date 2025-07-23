 #include<iostream>
using namespace std;

class Person{
    string name;
    int *age;
    
    public:
        //Constructors
        Person() =default;
        Person(string name, int age);
        
        //Destructors
        ~Person();
        
        //Getters
        void getDetails(){
            cout<<"You are: "<<this ->name<<" and your age is: "<<*(this->age)<<endl;
        }
        int getAge(){
            return *age;
        }

        //Setters
        Person& setAge(int a){
            this->age=new int{a};
            return *this;
        }
        Person& setName(string name){
            this->name=name;
            return *this;
        }

};

Person::~Person(){
    delete age;
    cout<<"Object destroyed: "<<this->name<<endl;
}

Person::Person(string n, int a){
    this->name = n;
    this->age = new int {a};
    cout<<"Object created with name "<<this->name<<" and age: "<<*(this->age)<<endl;
}

int main(){
    Person p1("Pragyan",12);
    p1.setAge(13).setName("Advait");
    p1.getDetails();
    //delete p1;
}