class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
		queue<int> ls;
		queue<int> gt;
		int eq = 0;
		for (const auto&num: nums) {
			if (num<pivot)
				ls.push(num);
			else if (num > pivot)
				gt.push(num);
			else
				eq++;
		}
		
		vector<int> out;
		while (!ls.empty()) {
			out.push_back(ls.front());
			ls.pop();
		}

		while (eq--) out.push_back(pivot);

		while (!gt.empty()) {
			out.push_back(gt.front());
			gt.pop();
		}
		return out;

    }
};
