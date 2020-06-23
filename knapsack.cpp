#include <iostream>
#include <vector>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;


int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  vector<vector<int> > T(n+1,vector<int>(W+1,0));
    
  for(int i = 0 ; i <= n ; i++){
  	for(int j = 0; j<= W ; j++){
  		if(i == 0){
  			T[0][j] = j;
		  }
		  else if(j == 0){
		  	T[i][0] = 0;
		  }
  		/*if(j < w[i]){
  			T[i][j] = w.at(i-1);
		  }else{
		  	T[i][j] = max((w.at(i-1)+T[i-1][j-w.at(i-1)]),T[i-1][j]);
		  }*/
		  else if(i == 1){
		  	if(j < w.at(i-1)){
		  		T[i][j] = T[i][j-1];
			  }else{
			  	T[i][j] = w.at(i-1);
			  }
		  }
		  else if(j < w.at(i-1)){
		  	T[i][j] = T[i-1][j];
		  }
		  else{
		  	T[i][j] = max((w.at(i-1)+T[i-1][j-w.at(i-1)]),T[i-1][j]);
		  }
	  }
  }
  
  return T[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  cout <<optimal_weight(W, w);
}
