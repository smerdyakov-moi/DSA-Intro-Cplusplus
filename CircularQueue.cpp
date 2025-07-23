#include<iostream>
using namespace std;

class CircQueue{
    private:
        int arr[5];
        int back{-1};
        int front{-1};
        int itemcount{};
    public:
        CircQueue(){  for(int i = 0 ; i < 5 ; i ++){arr[i] = 0;}  }
        bool isEmpty(){return (front==-1 && back==-1)? true:false;}
        bool isFull(){return ( (back+1)%5 == front )? true:false;}

       void enqueue(int x){
            if (isFull()){cout<<"Cam not add"<<endl; return;}
            else if(isEmpty()){front=0;back=0;}
            else{back=(back+1)%5;}
            arr[back]=x;
            itemcount++;
        }
       int dequeue(){
            if (isEmpty()){cout<<"Cannot not remove"<<endl; return -1;}
            int x{arr[front]};
            arr[front] = 0;
            if(front==back){front=-1;back=-1;}
            else{front =(front+1)%5;}
            itemcount--;
            return x;
       }
       int count(){
            return itemcount;
       }
       void display(){
            cout<<"Your elements in the queue are: "<<endl;
            for(int i{} ; i < 5 ; i ++ ){
                cout<<arr[i]<<" ";
            }
            cout<<""<<endl;
       }
};

int main() {
    CircQueue q1;
    int option{};
    int value{};

    cout<<boolalpha;
    cout << "Your options:" << endl;
    cout << "(1) Is the queue empty?\n(2) Is the queue full?\n(3) Enqueue\n(4) Dequeue\n(5) Count elements\n(6) Display queue\n(-1) Exit\n";
    while (option != -1) {
        cout << "Enter your option: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Queue is empty: " << q1.isEmpty() << endl;
                break;
            case 2:
                cout << "Queue is full: " << q1.isFull() << endl;
                break;
            case 3:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q1.enqueue(value);
                break;
            case 4:
                cout << "Dequeued value: " << q1.dequeue() << endl;
                break;
            case 5:
                cout << "Number of elements: " << q1.count() << endl;
                break;
            case 6:
                q1.display();
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
