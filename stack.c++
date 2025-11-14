#include <iostream>
using namespace std;

//? === NODE CLASS DEFINITION === //
// Represents a single node in the stack
class Node{
    public:
        int data;
        Node * next;
        Node(){
            data = 0;
            next = NULL;
        }
};
//? === // NODE CLASS DEFINITION // === //


//? === STACK CLASS DEFINITION === //
// Implements a stack using a linked list
class Stack{

    //? === CONSTRUCTOR === //
    public:
        Node * top;
        Stack(){
            top = NULL;
        }

    //? === // CONSTRUCTOR // === //


    //? === STACK OPERATIONS === //

        // Check whether the stack is empty
        bool isEmpty(){
            return (top == NULL);
        }

        // Push `item` onto the stack
        void push(int item){
            if (isEmpty())
            {
                Node * newNode = new Node;
                newNode->data = item;
                top = newNode;
                newNode->next = NULL;
            }else{
                Node * newNode = new Node;
                newNode->data = item;
                newNode->next = top ;
                top = newNode ; 
            }
            
        }

        // Pop the top item from the stack and return its value
        int pop(){
            int value = top->data;
            Node * delPtr = top;
            top = top->next;
            delete delPtr;
            return value;
        }

        // Peek at the top item without removing it
        int peek(){
            return top->data;
        }

        // Display all items in the stack (top -> bottom)
        void display(){
            Node * temp = top;
            cout << "\n=== Stack (top -> bottom) ===" << endl;
            if (temp == NULL){
                 cout << "(empty)" << endl << endl; 
                 return;
                }
            while (temp != NULL){
                cout << temp->data;
                if (temp->next != NULL)
                    cout << " -> ";
                temp = temp->next;
            }
            cout << endl << endl;
        }

        // Count the number of items in the stack
        int count(){
            int counter = 0;
            
            Node * temp = top ;
            while (temp != NULL){
                counter++;
                temp= temp->next;
            }
            return counter;
        }

        // Check whether `item` is present in the stack
        bool isFound(int item){
            bool found = false;
            Node * temp = top ;
            while(temp != NULL){
                if(temp->data == item){
                    found = true;
                }
                temp = temp->next;
            }
            return found;
        }

        // Check whether the stack is full (i.e., memory allocation fails)
        void isFull(){
            Node * ptr = new Node;
            if (ptr == NULL)
                cout<<"The stack is Full";  
        }

    //? === // STACK OPERATIONS // === //

};

int main() {

    // Create a stack instance
    Stack s;

    // Check if the stack is empty
    if (s.isEmpty())
    {
        cout<<"Stack is empty! \n\n";
    }

    // Push items onto the stack
    int size , item;
    cout<<"Enter number of items: ";
    cin>>size;
    
    for(int i=0 ; i<size ; i++){
        cout<<"Enter item ("<<(i+1)<<"): ";
        cin>>item;
        s.push(item);
    }

    // Display stack contents
    s.display();


    // Pop an item from the stack
    cout<<"The item ("<<s.pop()<<") got popped .\n\n";
    s.display();
    

    // Peek at the top item
    cout<<"The top item is: "<<s.peek()<<"\n\n";


    // Count total items in the stack
    cout<<"Total items in stack: "<<s.count()<<"\n\n";


    // Search for an item in the stack
    int searchItem;
    cout<<"Enter item to search: ";
    cin>>searchItem;
    if (s.isFound(searchItem))
        cout<<"Item found in stack .\n\n";
    else
        cout<<"Item not found in stack .\n\n";


    // Check if the stack is full
    s.isFull();
    

    // End of program
    return 0 ;
}