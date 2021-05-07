/*
-------------------------Question:
A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: False

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: True

Note:

sx, sy, tx, ty will all be integers in the range [1, 10^9].
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Recursive approach

At each stage, we only have 2 steps that we can take that will allow us to go from the start to the destination. We can follow this as long as sx<=tx && sy<=ty.

Time complexity: O(2^(tx+ty))
Space complexity: O(tx*ty)

2. Top-down approach

We can use top-down approach to store any repeated calls athat are being made in Other Approaches(1)

Time complexity: O(tx*ty)
Space complexity: O(tx*ty)

3. Bottom-up approach

We can improve upon Other Approaches(2) by using the bottom-up approach. Using this approach, at any stage we only choose one of the oparents as either of the two elements can't be less than 0. As a result, this narrows down our results
a bit

Time complexity: O(max(tx,ty));
Space complexity: O(1)

4. Using modulus operator

We can use the modulus operator to improve upon Other Approaches(3) by getting rid of calculations as long as tx > ty or vice versa and other certain conditions.

Time Complexity: O(log(max(m,n)))
Space complexity: O(1)
*/

// Other Approaches(1)
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx == tx && sy == ty)
            return true;
        else if(sx > tx || sy > ty)
            return false;
        else
            return reachingPoints(sx+sy, sy, tx, ty) || reachingPoints(sx, sx+sy, tx, ty);
    }
};

// Other Approaches(2)
struct pair_hash{
    template<class T1, class T2> size_t operator () (pair<T1, T2> const & pair) const
    {
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        
        return h1 ^ h2;
    }
};

class Solution {
public:
    bool checkMoveExists(int sx, int sy, int tx, int ty, unordered_set<pair<int,int>, pair_hash> & pairSet){
        if(sx == tx && sy == ty)
            return true;
        else if(sx > tx || sy > ty)
            return false;
        else{
            pair<int,int> elementPair = make_pair(sx, sy);
            if(pairSet.find(elementPair) == pairSet.end()){
                pairSet.emplace(elementPair);
                return checkMoveExists(sx+sy, sy, tx, ty, pairSet) || checkMoveExists(sx, sx+sy, tx, ty, pairSet);
            }
            return false;
        }      
    }
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        unordered_set<pair<int,int>, pair_hash> pairSet;
        return checkMoveExists(sx, sy, tx, ty, pairSet);
    }
};

// Other Approaches(3)
class Solution {
public:
    bool checkMoveExists(int sx, int sy, int tx, int ty){
        while(tx >= sx && ty >= sy){
            if(sx == tx && sy == ty)
                return true;
            else{
                if(tx > ty)
                    tx -= ty;
                else
                    ty -= tx;
            }
        }
        return false;
    }
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        return checkMoveExists(sx, sy, tx, ty);
    }
};

// Other Approaches(4)
class Solution {
public:
    bool checkMoveExists(int sx, int sy, int tx, int ty){
        bool isEnd = false;
        while(tx >= sx && ty >= sy && !isEnd){
            if(tx == ty)
                isEnd = true;
            else{
                if(tx > ty){
                    if(ty > sy)
                        tx %= ty;
                    else
                        return (tx - sx) % ty == 0; 
                }
                else{
                    if(tx > sx)
                        ty %= tx;
                    else
                        return (ty-sy) % tx == 0;
                }
            }
        }
        return tx == sx && ty == sy;
    }
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        return checkMoveExists(sx, sy, tx, ty);
    }
};