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
		int bestAns = INT_MAX;
		if(word1 == word2){
			if(myMap.find(word1) == myMap.end()) return -1;
			if(myMap[word1].size() == 1) return 0;
			for(int i = 0; i < myMap[word1].size() - 1; i ++){
				int tmp = abs(myMap[word1][i] - myMap[word1][i+1]);
				if(tmp < bestAns) bestAns = tmp;
			}
		}else{
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
			
			for(int i = 0; i < v1.size() ; i ++){
				for(int j = 0; j < v2.size() ; j ++){
					int tmp = abs(v1[i] - v2[j]);
					if(tmp < bestAns){
						bestAns = tmp;
					}
				}
			}
		}
		return bestAns;
	}
	
};
