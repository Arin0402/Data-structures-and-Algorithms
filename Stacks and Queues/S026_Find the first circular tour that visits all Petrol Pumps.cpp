#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
// https://www.youtube.com/watch?v=7WYwqvOSaa8

// 1
// O(N^2)
// try from every petrol pump

// 2
// o(N)
struct petrolPump
{
    int petrol;
    int distance;
};

/*You are required to complete this method*/
class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
       
       // index from which we start tour.
       int start = 0;
       
       // extra fuel at any point we have.
       int extraFuel = 0;
       
       //extra fuel required to reach from starting point till the station before start.
       int requiredFuel = 0;
       
       for(int i = 0; i < n; i++){
           
           extraFuel += p[i].petrol - p[i].distance;
           
           // restart from the next point.
           if(extraFuel < 0){
               requiredFuel += extraFuel;
               extraFuel = 0;
               start = i+1;
           }
       }
       
       // after reaching the end if we have enough fuel left then we can complete the loop.
       if(extraFuel + requiredFuel >= 0) return start;
       return -1;
       
    }
};


