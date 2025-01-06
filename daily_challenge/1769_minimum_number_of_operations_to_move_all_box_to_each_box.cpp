class Solution {
public:
    vector<int> minOperations(string boxes) {
    	vector<int> ones;
		for (size_t i=0; i<boxes.size(); i++) {
			if (boxes[i] == '1') 
				ones.emplace_back(i);
		}
		vector<int> out;
		for (int i=0; i<boxes.size(); i++) {
			int cnt=0;
			for (const auto&x: ones) {
				cnt += abs(i-x);
			}
			out.push_back(cnt);
		}
		return out;
    }
};
