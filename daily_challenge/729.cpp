class MyCalendar {
	vector<pair<int, int>> bookings;
public:
    MyCalendar() {
		        
    }
    
    bool book(int start, int end) {
    	for (const auto&b: bookings) {
			if ((start >= b.first && start < b.second) ||
					(start < b.first && end >= b.second) ||
					(end > b.first && end < b.second)) {
				return false;
			}
		}
		bookings.push_back({start, end});
		return true;
    }
};
