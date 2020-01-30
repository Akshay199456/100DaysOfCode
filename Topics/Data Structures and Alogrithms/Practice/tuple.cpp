/*
    Tuples are objects that pack elements of different types together into
    a single object just like pair<string, int> but generalized for any number of
    elements

    Other methods are:
        1. tie -> can be used to abstract values based on positional arguments
            eg:
                mytuple = make_tuple(10,2.6,'a')
                tie(myint, ignore, mychar) = mytuple
                // myint = 10; mychar ='a'  
*/
#include<tuple>
#include<iostream>
#include<string>
using namespace std;

// Creates a tuple given a list of element properties
tuple<string, string, int> createTuple(string name, string city, int id){
    tuple<string, string, int> tuple_elements = make_tuple(name, city, id);
    return tuple_elements;
}

// Displays the tuple elements
void displayTuple(tuple<string, string, int> tuple_elements){
    /*
        Tried using for loops but it didn't seem to work.
    */
        cout<< get<0> (tuple_elements) <<" "<< \
                get<1> (tuple_elements) <<" "<< \
                get<2> (tuple_elements) <<" size =" \
                <<tuple_size<decltype(tuple_elements)>::value<<"|\n";
}

int main(){
    tuple<string, string, int> tuple_elements = createTuple("Akshay", "Houston", 123);
    displayTuple(tuple_elements);
    return 0;
}
