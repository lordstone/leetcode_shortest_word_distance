class shortestDistance{
public:

	unordered_map<string, vector<int>> myMap;
	
	shortestDistance(vector<string> wordList){
		for(int i = 0; i < wordList.size() ; i ++){
			if(myMap.find(wordList[i]) == myMap.end()){
				myMap[wordList[i]] = vector<int> (1, i);
			}else{
				myMap[wordList[i]].push_back(i);
			}
		}
	}
	
	int getDistance(string word1, string word2){
		vector<int> v1, v2;
		if(myMap.find(word1) == myMap.end()){
			return -1;
		}else{
			v1 = myMap[word1];
		}
		if(myMap.find(word2) == myMap.end()){
			return -1;
		}else{
			v2 = myMap[word2];
		}
		int bestAns = INT_MAX;
		for(int i = 0; i < v1.size() ; i ++){
			for(int j = 0; j < v2.size() ; j ++){
				int tmp = abs(v1[i] - v2[j]);
				if(tmp < bestAns){
					bestAns = tmp;
				}
			}
		}
		return bestAns;
	}
	
};
