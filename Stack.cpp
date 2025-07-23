#include<iostream>
#include<string>

using namespace std;

class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack(){
            top = -1;
            for(int i = 0 ; i < 5 ; i++ ){
                arr[i] = 0;
            }
        }
        bool isEmpty(){
            return (top == -1)? true:false;
        }
        bool isFull(){
            return (top==4)? true:false;
        }
        void push(int x){
            if(isFull()){cout<<"Stack Overflow"<<endl;}else{ top++; arr[top]=x;}
        }

        int value(){
            return arr[top];
        }

        int pop(){
            if(isEmpty()){cout<<"Stack Underflow"<<endl; return 0;} else{int temp{arr[top]} ; arr[top] =0; top-- ; return temp;}
        }
        int count(){ return top+1; }
        int peek(int pos){
            if(isEmpty()){
                cout<<"Stack underflow"<<endl;
                return 0;
            }else{
                return arr[pos];
            }
        }
        void change(int pos, int value){
            arr[pos]=value;
        }
        void display(){
            cout<<"All values in the stack are: "<<endl;
            for(int i{4} ; i>=0 ; i--){
                cout<<arr[i]<<endl;
            }
        }
};

int main() {
    cout << boolalpha;
    int option{};
    cout << "Your options:" << endl;
    cout << "(1)Is your Stack empty? \n(2) Is your Stack full? \n(3) Push to the stack \n(4) Get the top value \n(5) Remove the top value \n(6) Get the no. of data \n(7) Change the value at a position \n(9) Peek \n(10) Display the whole stack \n(-1) Exit the program" << endl;

    Stack s1;

    while(option != -1) {
        cout << "Enter your option: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << s1.isEmpty() << endl;
                break;
            case 2:
                cout << s1.isFull() << endl;
                break;
            case 3: {
                int n{};
                cout << "Enter the number: ";
                cin >> n;
                s1.push(n);
                cout << n << " successfully pushed to the stack." << endl;
                break;
            }
            case 4:
                cout << "Top value: " << s1.value() << endl;
                break;
            case 5:
                cout << "Removed: " << s1.pop() << endl;
                break;
            case 6:
                cout << "Total data in stack: " << s1.count() << endl;
                break;
            case 7: {
                int pos{}, val{};
                cout << "Enter position (0-4): ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> val;
                s1.change(pos, val);
                cout << "Value changed at position " << pos << "." << endl;
                break;
            }
            case 9: {
                int pos{};
                cout << "Enter position (0-4): ";
                cin >> pos;
                cout << "Value at position " << pos << ": " << s1.peek(pos) << endl;
                break;
            }
            case 10:
                s1.display();
                break;
            case -1:
                cout << "Program exited." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
    return 0;
}