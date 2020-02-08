#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
	
	multimap<int, int> mmap;
	for(int i=0; i < arr.size(); i++){
		int key = arr[i];
		int index = i;
		//omap[key] = index;
		mmap.insert(pair<int, int>(key, index));
	}
	
	//for(auto x : omap){
		//cout << x.first << " " << x.second << endl;
	//}
	
	int rank = 1;
	for(auto it = mmap.begin(); it != mmap.end(); ++it){
		auto temp = it;
		++temp;
		if( (temp == mmap.end()) ||(it->first == (temp->first))){
			it->second = rank;
		}
		else{
			it->second = rank;
			rank++;
		}
		//cout << it->first << " " << it->second << endl;
		
	}
	
	//for(auto it = omap.begin(); it != omap.end(); ++it){
		////cout << it->first << " " << it->second << endl;
	//}
	
	for(int i = 0; i < arr.size(); i++){
		int rank = mmap.find(arr[i])->second;
		arr[i] = rank;
	}
	
	for(auto x : arr){
		cout << x << endl;
	}
	
	return arr;
	

	
	
	
	//map<int, int> omap2;
	//for(auto x : omap){
		//omap2[x.second] = x.first;
	//}
	
	//for(auto x : omap2){
		//cout << x.first << " " << x.second << endl;
	//}
}

int main(){
	vector<int> arr = {37,12,28,9,100,56,80,5,12};
	arrayRankTransform(arr);
	return 0;
}
