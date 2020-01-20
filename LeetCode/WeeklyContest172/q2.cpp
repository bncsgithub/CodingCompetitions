// Medium Problem
vector<string> printVertically(string s) {
	//vector<string> ans;
	stringstream ss(s);
	stringstream ss2(s);
	string word;
	//int numWord = 0;
	int lengthLongestWord = 0;
	while(ss >> word){
		//numWord++;
		if(word.length() > lengthLongestWord){
			lengthLongestWord = word.length();
		}
	}
	
	//cout << numWord << endl;
	//cout << lengthLongestWord << endl;
	vector<string> ans (lengthLongestWord, "");
	//vector<string> ans;
	//for(int i = 0; i < lengthLongestWord; i++){
		//ans.push_back("null");
	//}
	while(ss2 >> word){
		for(int i = 0; i < word.length(); i++){
			
			ans[i] += word[i];
		}
		
		for(int i = word.length(); i < lengthLongestWord; i++){
			//cout << ans[i].length() << endl;
			//cout << ans[
			string aWord = ans[i];
			int lengthOfWord = ans[i].length();
			int size = lengthOfWord - 1;
			//cout << aWord[size] << endl;
			if(aWord == ""){
				ans[i] += " ";
			}
			// else if( aWord[size] != ' '){
				// continue;
			// }
			//if(ans[ans[i].length() - 1] != ' '){
				//continue;
			//}
			else{
				ans[i] += " ";
			}
		}
	}
	// for(auto x : ans){
	// 	cout << x << endl;
	// }
  int count = 0;
  for(auto x : ans){
    while( x[x.length() - 1] == ' '){
      int wordLength = x.length();
      int index = wordLength - 1;
      if(x[index] == ' '){
        x.pop_back();
        ans[count] = x;
                    
      }
      //else{
      //  break;
      //}
    }
    count++;
  }
        return ans;
}
