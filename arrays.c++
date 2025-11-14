#include <iostream> 

using namespace std;

//? === ARRAY CLASS DEFINITION === //
// Simple dynamic array wrapper with basic operations
class Array 
{
    private:
        int size ;
        int *arr;
        int length; 

    public:
        Array(int sz) {
            size = sz;
            arr = new int[size];
            length = 0;
        }
        
        //? === FILL === //
        // Read N values from stdin to populate the array (N <= size)
        void Fill(){
            int numberOfItems;
            cout<<"Enter number of Array content : \n";
            cin>>numberOfItems;
            if(numberOfItems>size){
                cout<<"You can't exceed the array size!\n";
                return;
            }
            for(int i = 0; i < numberOfItems ; i++){
                cout << "Enter value for element " << (i+1) << ": ";
                cin >> arr[i];
                length++;
            }
        }
        //? === // FILL // === //



        //? === DISPLAY === //
        // Print current contents in a compact, readable format
        void Display(){
            cout << "\n=== Array ===" << endl;
            if (length == 0){
                cout << "(empty)" << endl;
            } else {
                for(int i = 0; i < length; i++){
                    cout << arr[i] << (i+1 < length ? "\t" : "");
                }
                cout << endl;
            }
            cout << "===============" << endl;
        }
        //? === // DISPLAY // === //


        // Return capacity
        int gitSize(){
            return size;
        }


        // Return current number of elements
        int gitLength(){
            return length;
        }
        

        //? === APPEND === //
        // Add item at the end if there is capacity
        void Append(int newItem){
            if (length < size){
                arr[length] = newItem;
                length++;
            } else {
                cout << "Array is full — cannot append." << endl;
            }
        }
        //? === // APPEND // === //



        //? === SEARCH === //
        // Return index of key or -1 if not found
        int Search(int key ){
            int index = -1;
            for(int i = 0; i < length; i++){
                if (arr[i] == key){
                    index = i;
                    break;
                }
            }
            return index;
        }
        //? === // SEARCH // === //



        //? === INSERT === //
        // Insert newItem at `index` shifting following elements.
        // Valid when 0 <= index <= length and there is capacity.
        void Insert(int index , int newItem){
            if (index > 0 && index <size )
            {
                for(int i=length ; i>index ; i--){
                    arr[i]=arr[i-1];
                }
                arr[index] = newItem;
                length++;
            } else {
                cout << "ERROR - index out of range or array full." << endl;
            }
        }
        //? === // INSERT // === //


        //? === DELETE === //
        // Remove item at `index` and shift remaining elements
        void Delete(int index){
            if(index >= 0 && index < length){
                for (int i = index; i < length - 1; i++){
                    arr[i] = arr[i+1];
                }
                arr[length - 1] = 0;
                length--;
            } else {
                cout << "ERROR - invalid index; nothing deleted." << endl;
            }
        }
        //? === // DELETE // === //


};

int main() {

    //? === CREATE === //
    int arrSize;
    cout<<"Enter the array size: \n";
    cin>>arrSize;
    Array arr(arrSize);
    //? === // CREATE // === //


    //? === FILL === //
    arr.Fill();
    cout<<"Array size:  "<<arr.gitSize()<<"\t"<<"Array length:  "<<arr.gitLength()<<"\n";
    //? === // FILL // === //


    //? === DISPLAY === //
    arr.Display();
    //? === // DISPLAY // === //

 
    //? === APPEND === //
    cout<<"Enter new Item to append : \n";
    int newItem ;
    cin>>newItem;
    arr.Append(newItem);
    cout<<"The new ";
    arr.Display();
    cout<<"The new length : "<<arr.gitLength()<<"\n";
    //? === // APPEND // === //
    


    //? === SEARCH === //
    cout<<"Enter the value to search for:  \n";
    int key;
    cin>>key;
    int index = arr.Search(key); 
    if(index == -1 ){
        cout<<"Item not found! \n";
    }else {
        cout<<"Item found at : "<<index<<"\n";
    }
    //? === // SEARCH // === //

    //? === INSERT === //
    int indexOfNewItem;
    int newItemToInsert;

    cout<<"Enter Index and Item \n";
    cin>>indexOfNewItem;
    cin>>newItemToInsert;

    arr.Insert(indexOfNewItem,newItemToInsert);

    arr.Display();
    cout<<"Array size:  "<<arr.gitSize()<<"\t"<<"Array length:  "<<arr.gitLength()<<"\n";
    //? === // INSERT // === //

    
    //? === DELETE === //
    int indexToDelete ; 
    cout<<"Enter index to delete it's item : \n";
    cin>>indexToDelete;
    arr.Delete(indexToDelete);
    arr.Display();
    cout<<"Array size:  "<<arr.gitSize()<<"\t"<<"Array length:  "<<arr.gitLength()<<"\n";
    //? === // DELETE // === //

    return 0;   
} 
