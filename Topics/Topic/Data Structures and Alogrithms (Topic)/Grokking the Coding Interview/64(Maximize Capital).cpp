/*
Problem statement:


*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1. 2 heaps

    i was on th eright rack to figuring this out. i had come up with the min heap for capital and 
    the max heap for profits. it took me a bit of time but iw as able to get there.
    in addition, i had figure out that for a certain initalcapital and a bunch of projects
    available to us, we want to select the project with the highest profits as the capital
    from the project has no influence than act as an inital barrier to entry.
    i shoulkd have pushed a bit harder and i would have got the answer i was looking for. always 
    focus on coming up with a brute foce approach., we can then use the patterns we have
    learnt to idenityf bottlenecks and imporve the efficiency of the solution.

    to be fair, i did tell that e can do this for the total no of projects we have 
    by getting all the projects with their profits for a speofic investment and then
    doing that for the toal number of projects. the only thing was that i didnt code it.

    also this pattern fo 2 heaps was different from the usual 2 heaps problems we have solved
    till now. in the 2 heaps problems we ahd solved till now, they were primarily median
    problems. in median problems, we want the middle of the numbers to be available to
    us which is why we use the 2 heap patterns in a way such that we kep the middle always at the top.

    However, this problem used the 2 heaps pattern in a different way and i would say this
    is the typical way for using it. we used the min heap to put in all our projects and
    organize them in terms of their capital. we then selected all the projects that we
    were able to select based on our capital and put them into a max heap based on their
    profits so that the project that is at the top fo the heap is the one with the max
    profit and is the first project we are going to select.


    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
while selecting projects have two constraints
    1. can select a project only when we have the required capital
    2. there is a maximum limit on how many projects we can select

since we dont have any constraint on time, should choose a project, among the projects for which
we have enough captial, which gives us a maximum profits. following this greedy appraoch
will give the ebst solution

while selecting project will do things:
    1. find all projects that we can choose with avialble capital
    2. from the list of projects in the first step, choose the project that gives us a
    maximum rpofit

can follow the two heaps approach similar to find the median of a number stream. here are the
steps:
1. add all project capitals to a min-heap so that we can select a project with the samllest
capital requireement
2. go through the top projects of the min-heap and filter the projects that can be 
completed iwht out  available capital. insert the profits of all thes eprojects into a 
max-heap so that we can choose a project with the maximum proofit.
3. finally select the top project of max heap for investment
4. repeat the 2nd and 3rd steps for required number of projects

Tiome complexity:
at most, all the projkects will be pusehde to both the heaps once, time complexity
of algorithm is O(nlogn + klogn) where n is the toal no of projects and k is the number of 
projects we are selecing

Space compelxity:
O(n)
*/




//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MaximizeCapital {
 public:
  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {
    // TODO: Write your code here
    priority_queue<pair<int,int>> maxProfitHeap;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minCapitalHeap;
    int totalCapital = initialCapital;

    // insert all projects into minCapitalHeap
    for(int i=0; i< capital.size(); i++)
      minCapitalHeap.push(make_pair(capital[i], profits[i]));

    // for each of the projects
    for(int i=0; i < numberOfProjects; i++){
      // get all the projects that are qualified
      while(!minCapitalHeap.empty() && minCapitalHeap.top().first <= totalCapital){
        pair<int,int> currentPair = minCapitalHeap.top();
        maxProfitHeap.push(make_pair(currentPair.second, currentPair.first));
        minCapitalHeap.pop();
      }

      // select the project with the highest profit which should be at the top of the max heap
      if(!maxProfitHeap.size())
        return totalCapital;
      
      totalCapital += maxProfitHeap.top().first;
      maxProfitHeap.pop();
    }
    return totalCapital;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximizeCapital::findMaximumCapital(vector<int>{1}, vector<int>{2}, 2, 1);
  cout << "Maximum capital: " << result << endl;
  result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2, 3}, vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: " << result << endl;
}


//Other Appraoches(2)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MaximizeCapital {
 public:
  struct capitalCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
  };

  struct profitCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return y.first > x.first; }
  };

  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {
    int n = profits.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> minCapitalHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, profitCompare> maxProfitHeap;

    // insert all project capitals to a min-heap
    for (int i = 0; i < n; i++) {
      minCapitalHeap.push(make_pair(capital[i], i));
    }

    // let's try to find a total of 'numberOfProjects' best projects
    int availableCapital = initialCapital;
    for (int i = 0; i < numberOfProjects; i++) {
      // find all projects that can be selected within the available capital and insert them in a
      // max-heap
      while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
        auto capitalIndex = minCapitalHeap.top().second;
        minCapitalHeap.pop();
        maxProfitHeap.push(make_pair(profits[capitalIndex], capitalIndex));
      }

      // terminate if we are not able to find any project that can be completed within the available
      // capital
      if (maxProfitHeap.empty()) {
        break;
      }

      // select the project with the maximum profit
      availableCapital += maxProfitHeap.top().first;
      maxProfitHeap.pop();
    }

    return availableCapital;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2}, vector<int>{1, 2, 3}, 2, 1);
  cout << "Maximum capital: " << result << endl;
  result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2, 3}, vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: " << result << endl;
}
