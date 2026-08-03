class Solution {
public:
    // Check if a string is made entirely of digits
    bool isNum(const string& s) {
        for(char ch : s) {
            if (!isdigit(ch))
                return false;
        }
        return true;
    }

    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                // Pop characters to form the substring
                string temp = "";
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }

                // Pop the opening bracket "["
                if (!st.empty()) st.pop();

                // Get the number
                string k = "";
                while (!st.empty() && isNum(st.top())) {
                    k = st.top() + k;
                    st.pop();
                }

                int count = stoi(k);  // convert string to int

                // Repeat the substring
                string repeated = "";
                for (int j = 0; j < count; j++) {
                    repeated += temp;
                }

                // Push the repeated string back
                st.push(repeated);
            } else {
                // Correct way to push a char as string
                st.push(string(1, s[i]));
            }
        }

        // Build the result from the stack
        string result = "";
        stack<string> reversed;
        while (!st.empty()) {
            reversed.push(st.top());
            st.pop();
        }
        while (!reversed.empty()) {
            result += reversed.top();
            reversed.pop();
        }

        return result;
    }
};
