const int LETTER_SIZE = 26;

struct TrieNode{
    TrieNode* pointers[LETTER_SIZE];
    bool isEndOfWord;
    
    TrieNode(){
        for(int i=0; i<LETTER_SIZE; i++)
            this->pointers[i] = NULL;
        this->isEndOfWord = false;
    }
};

class Trie{
    private:
        TrieNode* root;
        void createTrie(string);
        bool checkElementInTrie(string);
    public:
        Trie();
        void assignRootNode();
        void createTrieFromList(vector<string>);
        void checkElement(string);
};

Trie::Trie(){
    root = NULL;
}

void Trie::assignRootNode(){
    root = new TrieNode(); 
}

void Trie::createTrieFromList(vector<string> list){
    for(int i=0; i<list.size(); i++){
        string element = list[i];
        createTrie(list[i]);
    }
}

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
    current->isEndOfWord = true;
}

void Trie::checkElement(string element){
    cout<<"\n------------------------------------\n";
    bool status = checkElementInTrie(element);
    if(status)
        cout<<"\n Element "<<element<< " exists in the trie \n";
    else
        cout<<"\n Element "<<element<<" doesn't exist in the trie\n";
    cout<<"\n------------------------------------\n";
}

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

int main(){
    vector<string> list = {"Hello", "World", "this", "is", "it", "fellow", "humans"};
    Trie object = Trie();
    object.assignRootNode();
    object.createTrieFromList(list);
    object.checkElement("Hell");
    
    return 0;
}