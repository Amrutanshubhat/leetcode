class NumberContainers {
	unordered_map<int, set<int>> num;
	unordered_map<int, int> idx;
public:
    NumberContainers() { }
    
    void change(int index, int number) {
		auto it = idx.find(index);
       	if (it != idx.end()) {
			auto temp_it = num.find(it->second);
			if (!temp_it->second.empty())
				temp_it->second.erase(index);
		}
		idx[index] = number;
		num[number].insert(index);
    }
    
    int find(int number) {
       	auto it = num.find(number);
		if (it == num.end() || it->second.empty()) return -1;
		return *it->second.begin();
    }
};
