#include <iostream> 

using namespace std;
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
        
        void Fill(){
            int numberOfItems;
            cout<<"Enter number of Array content : \n";
            cin>>numberOfItems;
            if(numberOfItems>size){
                cout<<"You can't exceed the array size!\n";
                return;
            }else{
                for(int i=0; i<numberOfItems ; i++){
                    cout<<"Enter Item no."<<i+1<<" : \n";
                    cin>>arr[i];
                    length++;
                }
            }
            
        }

        void Display(){
            cout<<"Array content : \n";
            for(int i=0 ; i<length ; i++){
                cout<<arr[i]<<"\t";
            }
            cout<<"\n";
        }

        int gitSize(){
            return size;
        }

        int gitLength(){
            return length;
        }

        void Append(int newItem){
            if (length < size){
                arr[length]=newItem;
                length++;
            }else{
                cout<<"You can't Append an item! \n";
            }
                

        }

        int Search(int key ){
            int index = -1;
            for(int i=0 ; i<length; i++){
                if(arr[i]==key){
                    index = i;
                    break;
                }
            }
            return index;
        }

        void Insert(int index , int newItem){
            if (index > 0 && index <size )
            {
                for(int i=length ; i>index ; i--){
                    arr[i]=arr[i-1];
                }
                arr[index]=newItem;
                length++;
            }else{
                cout<<"ERROR!- index out of range . \n";
            }
            
        }

        void Delete(int index){
            if(index < length && index >= 0){
                for (int i=index ; i<length-1 ; i++){
                    arr[i]=arr[i+1];
                }
                arr[length-1]=0;
                length--;

            }else{
                cout<<"ERROR - You can't delete a null item ! \n";
            }
            
        }


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
