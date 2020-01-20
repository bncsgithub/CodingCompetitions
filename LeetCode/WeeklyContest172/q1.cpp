// Easy problem
int maximum69Number (int num) {
	
	string str = to_string(num);
	cout << str << endl;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '6'){
		
			str[i] = '9';
			break;
		}
	}
	
	return stoi(str);
}
