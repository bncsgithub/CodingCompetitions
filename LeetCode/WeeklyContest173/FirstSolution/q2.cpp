#include<vector>
#include<iostream>
using namespace std;
//2, 3, 4
vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
	
	vector<vector<int>> validRestaurants;
	for(auto &x: restaurants){
		if(veganFriendly == 0){
			if( ((x[2] == 1) || (x[2] == 0) ) && (x[3] <= maxPrice) && (x[4] <= maxDistance) ){
				//cout << "true" << endl;
				validRestaurants.push_back(x);
			}		
		}
		else if( (x[2] == veganFriendly) && (x[3] <= maxPrice) && (x[4] <= maxDistance) ){
			//cout << "true" << endl;
			validRestaurants.push_back(x);
		}
		else{}
	}
	//cout << "Here are the valid restaurants" << endl;
	sort(validRestaurants.begin(), validRestaurants.end(), [](const vector<int>& a, const vector<int>& b){
		if(a[1] > b[1]){
			return true;
		}
		else if(a[1] < b[1]){
			return false;
		}
		else{
			return a[0] > b[0];
		}
		//return a[1] > b[1];
	});
	vector<int> y;
	for(auto  &x : validRestaurants){
		y.push_back(x[0]);
		//cout << "Restaurant " << x[0] << " Rating " << x[1] << endl;
	}
	//vector<int> x;
	//x.push_back(1);
	//return x;
	return y;
}

void printVector(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
}
int main(){
	//vector<vector<int>> restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
	//vector<vector<int>> restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
	vector<vector<int>> restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
	int veganFriendly = 0, maxPrice = 30, maxDistance = 3;
	vector<int> answer = filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);
	printVector(answer);
	return 0;
}
