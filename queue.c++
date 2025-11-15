#include <iostream>
using namespace std;

//? === NODE CLASS DEFINITION === //
class Node {
    public:
        int data;
        Node * next;
        Node(){
            data = 0;
            next = NULL;
        }
};
//? === // NODE CLASS DEFINITION // === //


//? === QUEUE CLASS DEFINITION  === //
class Queue{
    public:
        Node * front;
        Node * rear ;

        //? === QUEUE CLASS OPERATIONS === //

        // Constructor
        Queue(){
            front = rear = NULL;
        }

        // Check whether the queue is empty
        bool isEmpty(){
            return (front == NULL);
        }   
        
        // Enqueue `item` to the rear of the queue
        void enqueue(int item){
            Node * newNode = new Node;
            newNode->data = item;

            if (isEmpty())
            {
                front = rear = newNode;
            }else{
                rear->next = newNode;
                rear = newNode;
            }
            
        }

        // Dequeue an item from the front of the queue and return its value
        int dequeue(){
            int delValue=-999;
            if (isEmpty())
            {
                return delValue;
            }else if (front == rear){
                delValue = front->data;
                delete front;
                front = rear = NULL;
                return delValue;
            }else{
                Node * delPtr = front;
                delValue = front->data;
                front = front->next;
                delete delPtr;
                return delValue;
            }
            

        }

        // Display the contents of the queue
        void display(){
            Node * temp = front;
            cout<<"\n====DISPLAY====\n";
            if(isEmpty()){
                cout<<"Nothing to display! \n\n";
            }else{
                while (temp != NULL)
                {
                    cout<<temp->data<<"   ";
                    temp= temp->next;
                }
                cout<<endl<<endl;

            }        
        }

        // Peek at the front item without removing it
        int peek(){
            if(!isEmpty())
                return front->data;
            else
                return -999;
        }

        // Count the number of items in the queue
        int count(){
            int counter = 0;
            Node * temp = front ;
            while (temp!= NULL)
            {
                counter++;
                temp = temp->next;
            }
            return counter;
        }

        // Get the front and rear item values
        int getFront(){
            return front->data;
        }

        // Get the rear item value
        int getRear(){
            return rear->data;
        }

        // Clear the queue
        void clear(){
            while (!isEmpty())
            {
                dequeue();
            }
            
        }
        //? === QUEUE CLASS OPERATIONS === //
};
//? === // QUEUE CLASS DEFINITION  // === //

int main(){
    Queue q ;
    
    // Check if the queue is empty , if yes , enqueue items .
    if(q.isEmpty())
        cout<<"\nQueue is empty!\n\n";
    
    int size;
    cout<<"Eneter how many items to enqueue : ";
    cin>>size;
    for(int i=0 ; i<size ; i++){
        int item;
        cout<<"Item ("<<(i+1)<<") : ";
        cin>>item;
        q.enqueue(item);
    }

    // Display queue contents 
    q.display();

    // Dequeue items
    cout<<"1st dequeue :\n";
    q.dequeue();
    q.display();

    cout<<"2nd dequeue :\n";
    q.dequeue();
    q.display();

    // Peek
    if (q.peek() == -999)
    {
        cout<<"Queue is empty, nothing to peek!\n";
    }else{
        cout<<"Peek item : "<<q.peek()<<endl<<endl;
    }

    // Count
    if (q.count() == 0)
    {
        cout<<"Queue is empty, nothing to count!\n";
    }else{
        cout<<"Items in queue : "<<q.count()<<endl<<endl;
    }

    // Get Front and Rear
    if(q.isEmpty()){
        cout<<"Queue is empty, no front or rear item!\n\n";
    }else{
        cout<<"Front item : "<<q.getFront()<<endl;
        cout<<"Rear item : "<<q.getRear()<<endl<<endl;
    }
    
    // Clear Queue
    cout<<"Clearing Queue...\n";
    q.clear();
    q.display();

    return 0;

}


