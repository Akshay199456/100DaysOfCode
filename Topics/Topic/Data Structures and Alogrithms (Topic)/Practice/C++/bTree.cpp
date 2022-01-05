#include<vector>

struct Node{
    int element;
    Node * left;
    Node * right;
    
    Node(int element){
        this->element = element;
        this->left = NULL;
        this->right = NULL;
    }
};

class bTree{
    private:
        Node * root;
        void displaybTree(Node*, string);
    public:
        bTree();
        void addElement(vector<int>);
        Node* returnRootElement();
        void recursiveAddElement(Node*, Node*, Node*);
        void displayTree(string);
        void checkElement(Node*, int);
};

// Constructor 
bTree::bTree(){
    root = NULL;
}

// Adds element to the tree
void bTree::addElement(vector<int> list){
    for(int i=0 ; i<list.size(); i++){
        Node * newObject = new Node(list[i]);
        if(root == NULL)
            root = newObject;
        else{
            // Need to write the code here
            if(newObject->element <= root->element)
                recursiveAddElement(root->left, root, newObject);
            else
                recursiveAddElement(root->right, root, newObject);
        }
        cout<<"\n Element inserted: "<<newObject->element<<"\n";
    }
}

// Calls this helper function to continuosly add elements to the tree
void bTree::recursiveAddElement(Node* current, Node* parent, Node* newObject){
    // Need to write the code here
    if(current == NULL){
        if(newObject->element <= parent->element)
            parent->left = newObject;
        else
            parent->right = newObject;
    }
    
    else{
        if(newObject->element <= current->element)
            // Need to verify if this is right
            recursiveAddElement(current->left, current, newObject);
        else
            // Need to verify if this is right
            recursiveAddElement(current->right, current, newObject);
    }
}

// Returns the root element
Node* bTree::returnRootElement(){
    cout<<"\n Root: "<<root->element<<"\n";
    return root;
}

// Displays the tree in 3 ways: pre-order, post-order and in-order
void bTree::displaybTree(Node * root, string operation){
    if(root == NULL){
        
    }
    
    else{
        if(operation.compare("preOrder") == 0){
            // Displaying pre-order
            cout<<" "<<root->element;
            displaybTree(root->left, "preOrder");
            displaybTree(root->right, "preOrder");
        }
        
        else if(operation.compare("inOrder") == 0){
            // Displaying in-order
            displaybTree(root->left, "inOrder");
            cout<<" "<<root->element;
            displaybTree(root->right, "inOrder");
        }
        
        else if(operation.compare("postOrder") == 0){
            // Displaying post-order
            displaybTree(root->left, "postOrder");
            displaybTree(root->right, "postOrder");
            cout<<" "<<root->element;
        }
    }
}

// Sets up the display tree
void bTree::displayTree(string operation){
    cout<<"\n\n Displaying all the elements:";
    displaybTree(root, operation);
}

void bTree::checkElement(Node* current, int element){
    if(current == NULL)
        cout<<"\n Element "<<element<<" was not found in the tree\n";
    else{
        if(element == current->element)
            cout<<"\n Element "<<element<<" was found in the tree\n";
        else if(element <= current->element)
            checkElement(current->left, element);
        else if(element >= current->element)
            checkElement(current->right, element);
    }
}

int main(){
    bTree object = bTree();
    vector<int> list = {23,45,11,1,13,33,64};
    
    object.addElement(list);
    object.displayTree("inOrder");
    object.checkElement(object.returnRootElement(), 16);
    return 0;
}