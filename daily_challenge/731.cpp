class MyCalendarTwo {
	vector<pair<int, int>> booking, overlap;
public:
    MyCalendarTwo() { 
    }
    
    bool book(int start, int end) {
		for (const auto&op: overlap) {
			if (start < op.second && end > op.first) {
				return false;
			}
		}
		for (const auto&b: booking) {
			if (start < b.second && end > b.first) {
				overlap.push_back({max(start, b.first), min(end, b.second)});
			}
		}
		booking.push_back({start, end});
		return true;
    }
};
