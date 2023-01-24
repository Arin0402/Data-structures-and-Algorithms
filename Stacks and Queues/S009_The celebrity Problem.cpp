#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// https://www.youtube.com/watch?v=Z5AEc12ieOs

// 1.
// O(N^2)
// O(N)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // to store the number of persons that knows the ith person
        vector<int> in(n, 0);
        
        // to store the number of persons that the ith person knows
        vector<int> out(n, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                if(M[i][j] == 1){
                    
                    in[j]++; // j is known by i
                    out[i]++; // i knows j
                }
                
            }
        }
        
        for(int i = 0; i < n; i++){
            
            // for a person to be celebrity he sholud be known by everyone and should not know everyone.
            if(in[i] == n-1 && out[i] == 0) return i;
        }
        
        return -1;
    }
};

// 2
// O(N)
// O(N)

// Create a stack and push all the id's in the stack.
// Run a loop while there are more than 1 element in the stack.
// Pop top two element from the stack (represent them as A and B)
// If A knows B, then A can't be a celebrity and push B in stack. Else if A doesn't know B, then B can't be a celebrity push A in stack.
// Assign the remaining element in the stack as the celebrity.
// Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            
            int per1 = st.top();
            st.pop();
            
            int per2 = st.top();
            st.pop();
            
            if(M[per1][per2] == 1) st.push(per2);
            else if(M[per1][per2] == 0) st.push(per1);
            
        }
        
        // potential candidate for celebrity.
        int C = st.top();
        
        for(int i = 0; i < n; i++){
            
            // if i does not C or C knows i , return -1
            if(i != C && (M[i][C] == 0 || M[C][i] == 1)) return -1;
        }
        
        return C;
    }
};

// 3
// O(N)
// O(1)

// Yogesh's solution.
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        int C = 0;
        
        for(int i = 0; i < n; i++){
            if(M[C][i] == 1){
                C = i;
            }
        }
        
        
        for(int i = 0; i < n; i++){
            if(i != C && (M[i][C] == 0 || M[C][i] == 1)) return -1;
        }
        
        return C;
        
    }
};