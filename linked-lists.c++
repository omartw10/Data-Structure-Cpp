 #include <iostream>
 using namespace std;

 //? === NODE CLASS DEFINITION === //
 // Represents a single node in the linked list
 class Node {
    public:
        int data;
        Node * next ;
 };
//? === // NODE CLASS DEFINITION // === //


 class linkedList{
    public : 
        Node * head ; 
        //? === CONSTRUCTOR === //
        // Initialize an empty linked list
        linkedList(){
            head = NULL;
        }
        //? === // CONSTRUCTOR // === //


        //? === UTILITIES === //
        // Check whether the list is empty
        bool isEmpty(){
            return (head == NULL);
        }

        void insertFirst(int newItem){
            Node * newNode = new Node ;
            newNode->data = newItem;

            if(isEmpty()){
                newNode->next = NULL;
                head = newNode ;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }
        //? === // UTILITIES // === //
        

        //? === DISPLAY === //
        // Print the list contents to the console in a readable format
        void display (){
            Node * temp = head;
            if(isEmpty()){
                cout << "\n=== List ===" << endl;
                cout << "The list is empty." << endl << endl;
                cout << "===============" << endl;
            }else{
                cout << "\n=== List ===\n\n";
                // Print elements with arrows for readability
                while (temp != NULL)
                {
                    cout << temp->data;
                    if (temp->next != NULL) cout << " -> ";
                    temp = temp->next;
                }
                cout << endl << endl;
                cout << "===============" << endl;
            }
              
        }
        //? === // DISPLAY // === //
        

        //? ===  COUNT  === //
        // Return the number of items in the list
        int count(){
            Node * temp = head;
            int counter=0;
            while (temp != NULL){
                counter++;
                temp = temp->next;
            } 
            return counter;    
        }
        //? === // COUNT // === //


        //? === SEARCH === //
        // Return true if `key` exists in the list
        bool isFound(int key){
            Node * temp = head;
            bool found = false ;
            while ( temp != NULL)
            {
                if (temp->data==key)
                {
                    found = true;
                }
                temp = temp->next;
            }
            return found;
            
        }
        //? === // SEARCH // === //


        //? === INSERT BEFORE === //
        // Insert `newItem` before the first occurrence of `before`.
        // If the list is empty, insert as the first element.
        void insertBefore(int before , int newItem){

            if (isEmpty())
            {
                cout << "List is empty. Inserting the new item as the first element." << endl;
                insertFirst(newItem);
                return;
            }

            if (head->data == before)
            {
                cout << "Target is the first element. Inserting new item at the front." << endl;
                insertFirst(newItem);
                return;
            }
            
            if(isFound(before)){
                Node * newNode = new Node;
                newNode->data = newItem;
                Node * temp = head;
                while (temp->next != NULL && temp->next->data != before)
                {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }else{
                cout << "Item not found; nothing inserted." << endl;
                return;
            }
            
        }
        //? === // INSERT BEFORE // === //


        //? === APPEND === //
        // Append a new item at the end of the list
        void append(int newItem){

            if(isEmpty()){
                insertFirst(newItem);
                return;
            }

            Node * temp = head ;
            Node * newNode = new Node;
            newNode->data = newItem;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL; 
            
        }

        //? === // APPEND // === //



        //? === DELETE === //
        // Delete the first occurrence of `item` from the list
        void deleteItem(int item){
            if (isEmpty()){
                cout << "List is empty — nothing to delete." << endl << endl;
                return;
            }
            if(head->data == item){
                Node * delPtr = head;
                head = head->next;
                delete delPtr;
                return;
            }else{
                Node * delPtr = head;
                Node * prev = NULL;
                while (delPtr != NULL && delPtr->data != item){
                    prev = delPtr;
                    delPtr = delPtr->next;
                }
                if (delPtr == NULL){
                    cout << "Item not found. Nothing deleted." << endl;
                    return;
                }
                prev->next = delPtr->next;
                delete delPtr;
                return;
            }
        }
        //? === // DELETE // === //
 };



 
int main() {

    // Create a linked list instance
    linkedList lst ;
    
    // Check if the list is empty and display the count
    if(lst.isEmpty()){
        cout << "The list is currently empty." << endl;
    }else{
        cout << "Number of items: " << lst.count() << endl;
    }

    // Insert elements into the list
    int item , size , i; 
    cout << "Enter number of elements to insert: ";
    cin >> size;
    if (size < 0){
        cout << "Negative number entered — no elements will be added." << endl;
        size = 0;
    }
    for(i = 0; i < size; i++){
        cout << "Enter value for element (" << i+1 << "): ";
        cin >> item;
        lst.insertFirst(item);
    }
    lst.display();
    cout << "Current number of items: " << lst.count() << endl;


    // Search for an element in the list
    cout << "Enter a value to search for: ";
    cin >> item;
    if(lst.isFound(item)){
        cout << "Item found in the list." << endl;
    }else{
        cout << "Sorry - item not found." << endl;
    }


    // Insert before a target value
    int newItem;
    cout << "Enter target value and new value to insert before it (e.g. 5 10): ";
    cin >> item >> newItem;
    lst.insertBefore(item , newItem );
    lst.display();


    // Append an element to the end of the list
    cout << "Enter a value to append to the end of the list: ";
    cin >> newItem;
    lst.append(newItem);
    lst.display();


    // Delete an element from the list
    int itemToDelete;
    cout << "Enter a value to delete from the list: ";
    cin >> itemToDelete;
    lst.deleteItem(itemToDelete);
    lst.display();

    
 }