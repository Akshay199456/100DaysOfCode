/*
Problem: Generate all substrings of a string

Got C++ compiler setup on VS Code. To run the file, need to first build the file to create the debugging
file. Need to follow the steps provided in https://code.visualstudio.com/docs/cpp/config-clang-mac
to set it up. Once we have the debuggin file, can run it in the terminal. All instructions have been 
provided in the link.

*/
/*
Time complexity: O(n^2)
Space complexity: O(1)
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


void displayVector(vector<string> result){
    for(int i = 0; i < result.size(); i ++)
        cout<<result[i]<<" ";
    cout<<endl;
}

int main(){
    string test = "abcd";
    vector<string> result;
    //result.push_back("");
    /*
    for(int i = 0 ; i < test.size(); i++){
        int endSize = result.size();
        for(int j = 0; j < endSize ; j++){
            if(result[j].compare("") == 0)
                result.push_back(string(1, test[i]));
            else{
                if(result[j][result[j].size() - 1] == test[i-1])
                    result.push_back(result[j] + string(1, test[i]));
            }
        }
    }
    */

   for(int i = 0; i < test.size(); i++){
       string substr = string(1,test[i]);
       result.push_back(substr);
       for(int j = i+1; j < test.size(); j++){
           substr += string(1,test[j]);
           result.push_back(substr);
       }
   }
    cout<<"Hello world\n";
    displayVector(result);
    return 0;
}