#include <iostream>
using namespace std;
//? === NODE CLASS DEFINITION === //
class Node {
    public:
        int data;
        Node * left;
        Node * right;
        Node(int value){
            data = value;
            left = NULL;
            right = NULL;
        }
};
//? === // NODE CLASS DEFINITION // === //

//? === BST CLASS DEFINITION  === //
class BST{
    public:
        Node * root;

        //? === BST CLASS OPERATIONS === //

        // Constructor
        BST(){
            root = NULL;
        }

        // Check whether the BST is empty
        bool isEmpty(){
            return (root == NULL);
        } 
        
        // Insert function // Recursive, returns the root node
        Node * insert(Node * r , int item){
            if(r == NULL){
                Node * newNode = new Node(item);
                r = newNode;
            }else if (item < r->data){
                r->left = insert(r->left , item);
            }else{
                r->right= insert(r->right , item);
            }
            return r;
        }

        // Insert function // Overload, calls the recursive insert function
        void insert(int item){
            root = insert(root , item);
        }

        // Traversal functions, to print the tree nodes in different orders (Root, Left, Right)
        void preorder(Node * r){
            if(r == NULL)
                return;
            cout<<r->data<<"\t";
            preorder(r->left);
            preorder(r->right);
        }

        // (Left, Root, Right)
        void inorder(Node * r){
            if(r == NULL){
                return;
            }
            inorder(r->left);
            cout<<r->data<<"\t";
            inorder(r->right);
        }


        // (Left, Right, Root)
        void postorder(Node * r){
            if(r==NULL){
                return;
            }
            postorder(r->left);
            postorder(r->right);
            cout<<r->data<<"\t";
        }


        // Search function // Recursive, returns the node if found, else NULL
        Node * search(Node * r , int key){
            if(r==NULL){
                return NULL;
            }
            else if(r->data == key){
                return r;
            }else if (r->data < key ){
                return search(r->left , key);
            }else{
                return search(r->right, key);
            }
            
        }

        // Search function // Overload, calls the recursive search function
        bool search(int key){
            Node * result = search(root , key);
            return (result == NULL);
        }

        // Find Minimum function
        Node * findMin(Node * r){
            if(r == NULL){
                return NULL;
            }
            else if(r->left == NULL) {
                return r;
            }else {
                return findMin(r->left);
            }
        }

        // Find Maximum function
        Node * findMax( Node * r){
            if(r==NULL){
                return NULL;
            }else if (r->right == NULL){
                return r;
            }else{
                return findMax(r->right);
            }
        }

        // Delete Node function
        Node * deleteNode(Node * r , int key){
            if (r == NULL){
                return NULL;
            }
            else if (key < r->data){
                r->left = deleteNode(r->left , key);
            }else if(key > r->data){
                r->right = deleteNode(r->right , key);
            }else{
                if(r->left == NULL && r->right == NULL){
                    r=NULL;
                }else if (r->left != NULL && r->right ==NULL){
                    r->data = r->left->data;
                    delete r->left ;
                    r->left = NULL;
                }else if (r->left == NULL && r->right != NULL){
                    r->data = r->right->data;
                    delete r->right;
                    r->right = NULL;
                }else{
                    Node * max = findMax(r->left);
                    r->data = max->data;
                    r->left = deleteNode(r->left,max->data);
                }
            }
            return r;
        }

        //? === BST CLASS OPERATIONS === //

};
//? === // BST CLASS DEFINITION // === //

int main(){

    // Create BST object
    BST bst;


    // Insert items into the BST
    int size;
    cout<<"Enter size of to insert\n";
    cin>>size;
    for(int i=0 ; i<size ; i++){
        int item;
        cout<<"item ("<<i+1<<") : ";
        cin>>item;
        bst.insert(item);
    }

    // Print the BST in different orders
    bst.preorder(bst.root);
    cout<<"\n_____________________________________________________________________________\n\n";

    bst.inorder(bst.root);
    cout<<"\n_____________________________________________________________________________\n\n";

    bst.postorder(bst.root);
    cout<<"\n_____________________________________________________________________________\n\n";


    // Search for an item
    int key;
    cout<<"Enter item to search for :  ";
    cin>>key;

    if(bst.search(key)){
        cout<<"\nItem is found\n\n";
    }
    else{
        cout<<"\nItem not found !\n\n";
    }

    // Find Minimum and Maximum
    cout<<"Find Mininmum \n";
    Node *min = bst.findMin(bst.root);
    if(min == 0){
        cout<<"No items Exists\n\n";
    }else{
        cout<<"Minimum is : "<<min->data<<endl<<endl;
    }

    cout<<"Find Maximum \n";
    Node * max = bst.findMax(bst.root);
    if(max ==0 ){
        cout<<"No items Exist! \n\n";
    }else {
        cout<<"Maximum is : "<<max->data<<"\n\n";
    }


    // Delete a node
    cout<<"Enter item to delete : ";
    cin>>key;
    bst.deleteNode(bst.root , key);
    bst.preorder(bst.root);
    cout<<"\n_____________________________________________________________________________\n\n";
    
    
    
    
    return 0;

}