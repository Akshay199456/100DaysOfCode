const int LETTER_SIZE = 26;
const int MAX_WORD_SIZE = 100;


// Creates a node from the constructor call
struct TrieNode{
    TrieNode* pointers[LETTER_SIZE];
    bool isEndOfWord;
    
    TrieNode(){
        for(int i=0; i<LETTER_SIZE; i++)
            this->pointers[i] = NULL;
        this->isEndOfWord = false;
    }
};

// public interace
class Trie{
    private:
        TrieNode* root;
        void createTrie(string);
        bool checkElementInTrie(string);
        void displayTrieStructure(TrieNode*, char[], int);
    public:
        Trie();
        void assignRootNode();
        void createTrieFromList(vector<string>);
        void checkElement(string);
        void displayTrie();
};

// assign root to null
Trie::Trie(){
    root = NULL;
}

// creates new node and assigns it to root
void Trie::assignRootNode(){
    root = new TrieNode(); 
}

// helper function for creating the trie for each string in the list
void Trie::createTrieFromList(vector<string> list){
    for(int i=0; i<list.size(); i++){
        string element = list[i];
        createTrie(list[i]);
    }
}

// inserts strings into the trie
void Trie::createTrie(string element){
    transform(element.begin(), element.end(), element.begin(), ::tolower);
    cout<<"\n Element is: "<<element;
    TrieNode* current = root;
    
    for(int i=0; i<element.size(); i++){
        int index = element[i] - 'a';
        if(!current->pointers[index])
            current->pointers[index] = new TrieNode();
        current = current->pointers[index];
    }
    // indicates that node means the end of the word
    current->isEndOfWord = true;
}

// helper function for checking if element exists in the trie
void Trie::checkElement(string element){
    cout<<"\n-------------------------------------------------------------\n";
    bool status = checkElementInTrie(element);
    if(status)
        cout<<"\n Element * "<<element<< " * exists in the trie \n";
    else
        cout<<"\n Element * "<<element<<" * doesn't exist in the trie\n";
    cout<<"\n-------------------------------------------------------------\n";
}

// Keeps navigating the current word level to check if node exists in the trie
bool Trie::checkElementInTrie(string element){
    TrieNode* current = root;
    transform(element.begin(), element.end(), element.begin(), ::tolower);
    for(int i=0; i<element.size(); i++){
        int index = element[i] - 'a';
        if(!current->pointers[index])
            return false;
        else
            current = current->pointers[index];
    }
    
    if(current->isEndOfWord)
        return true;
    else
        return false;
}

// helper function for displaying the trie
void Trie::displayTrie(){
    TrieNode* current = root;
    char letter_array[MAX_WORD_SIZE];
    displayTrieStructure(current, letter_array,0);
}

// Displays the trie structure
void Trie::displayTrieStructure(TrieNode* current, char letter_array[], int level){
    // Using char array to store the characters as each new addition would only modify the current
    // level and not impact the end result.
    for(int i=0; i<LETTER_SIZE; i++){
        if(current->pointers[i]){
            char ch = i + 'a';
            cout<<"\n Letter: "<<ch<<"\n";
            letter_array[level] = ch;
            displayTrieStructure(current->pointers[i], letter_array, level+1);
        }
    }
    
    // Need to indicate the end of the char array with '\0'
    // Even if 100 memory locations are allocated, '\0' indicates the end of the string and rest of the 
    // memory locations are not used.


    if(current->isEndOfWord){
        letter_array[level] = '\0';
        // Can display the char array as it is. It's automaically converted to string while displaying it
        cout<<"\n String found in Trie: "<<letter_array<<"\n";
        cout<<"\n Length of string: "<<strlen(letter_array)<<"\n";
    }
}

int main(){
    vector<string> list = {"Hello", "World", "this", "is", "it", "fellow", "humans"};
    Trie object = Trie();
    object.assignRootNode();
    object.createTrieFromList(list);
    object.checkElement("fhello");
    object.displayTrie();
    
    return 0;
}