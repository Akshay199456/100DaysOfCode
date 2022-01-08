/*

/*
-------------------------    My Approaches:
1. Iterating through array

We use a ,map to store the teams and their scores. in addition, we keep track of the scores as we are going along. that allows us to select the winner as we are going along instead of having to
go through the map a second time to find the max

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other Approaches 
1.

/*
-------------------------    Video Explanation 

*/


// My approaches(1)
#include <vector>
using namespace std;

string getWinner(vector<vector<string>> competitions,
                        vector<int> results){
	string winnerName = "";
	int winnerScore = -1;
	unordered_map<string, int> scores;
	
	for(int i=0; i < competitions.size(); i++){
		/*
		1. go through the competion vector
		2. check if each teams score is stored in map
			1. if not, add it to map with value decided based on win or loss
			2. if it is, updated its score with the result of the competition
		3. if either of the teams score is greater than the winner score, update winner score and name with the team that has current max total
		4. return winner name
		*/
		for(int j=0; j<competitions[i].size(); j++){
			if (scores.find(competitions[i][j]) == scores.end())
				scores[competitions[i][j]] = 0;
		}
		
		if(results[i])
			scores[competitions[i][0]] += 3;
		else
			scores[competitions[i][1]] += 3;
		
		int pairMax = -1;
		string pairWinner = "";
		
		for(int j=0; j < competitions[i].size(); j++){
			if(pairMax < scores[competitions[i][j]]){
				pairMax = scores[competitions[i][j]];
				pairWinner = competitions[i][j];
			}
		}
		
		if(pairMax > winnerScore){
			winnerScore = pairMax;
			winnerName = pairWinner; 
		}
	}
	return winnerName;
}

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  // Write your code here.
  return getWinner(competitions, results);
}


// Other Approaches(1)