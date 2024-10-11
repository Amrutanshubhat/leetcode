class Solution {
public:
    int minLength(string s) {
		stack<char> st;
		size_t match = 0;
		for (const auto&c: s) {
			switch(c) {
				case 'B':
					{
						if (!st.empty() && st.top() == 'A') {
							match++;
							st.pop();
						} else {
							st.push(c);
						}
					}
					break;
				case 'D':
					{
						if (!st.empty() && st.top() == 'C') {
							match++;
							st.pop();
						} else {
							st.push(c);
						}
					}
					break;
				default:
					st.push(c);
					break;
			}
		}
		return s.size()-(2*match);
    }
};
