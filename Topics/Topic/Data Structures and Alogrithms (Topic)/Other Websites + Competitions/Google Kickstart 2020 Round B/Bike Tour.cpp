/*
-------------------------Question:

Problem
Li has planned a bike tour through the mountains of Switzerland. His tour consists of N checkpoints, numbered from 1 to N in the order he will visit them. The i-th checkpoint has a height of Hi.

A checkpoint is a peak if:
It is not the 1st checkpoint or the N-th checkpoint, and
The height of the checkpoint is strictly greater than the checkpoint immediately before it and the checkpoint immediately after it.

Please help Li find out the number of peaks.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Hi.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of peaks in Li's bike tour.

Limits
Time limit: 10 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Hi ≤ 100.

Test set 1
3 ≤ N ≤ 5.

Test set 2
3 ≤ N ≤ 100.

Sample

Input
 	
Output
 
4
3
10 20 14
4
7 7 7 7
5
10 90 20 90 10
3
10 3 10

  
Case #1: 1
Case #2: 0
Case #3: 2
Case #4: 0

  
In sample case #1, the 2nd checkpoint is a peak.
In sample case #2, there are no peaks.
In sample case #3, the 2nd and 4th checkpoint are peaks.
In sample case #4, there are no peaks.
*/

/*
-------------------------My Approaches:

*/


// My Approaches(1)
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

int main()
{
    std::string variableString, line;
    int testCases;
    
    std::getline(cin, variableString);
    testCases = stoi(variableString);
    //std::cout<<"No of testCases: "<<testCases<<"\n";
    
    for(int i = 0; i < testCases; i++){
        std::getline(cin, variableString);
        std::vector<int> elements;
        int inputNumber = stoi(variableString), count = 0;
        // std::cout<<"Input Number: "<<inputNumber<<"\n";
        std::getline(cin, variableString);
        auto iss = istringstream{variableString};
        while(iss >> line){
            elements.push_back(stoi(line));
            // std::cout<<"Line: "<<line<<"\n";
        }
        
        for(int i = 1; i < elements.size() - 1; i++){
            if((elements[i] > elements[i-1]) && (elements[i] > elements[i+1]))
                ++count;
        }
        
        std::cout<<"Case #"<<i+1<<": "<<count<<"\n";
    }

    return 0;
}

