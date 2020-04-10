class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        
        if(num1.size() == num2.size()) {
            for(int i = num1.size()-1; i >= 0; i--) {
                int sum = (num1[i]-'0') + (num2[i]-'0') + carry;
                if(sum > 9) {
                    carry = 1;
                    result = to_string(sum % 10) + result;
                }
                else {
                    carry = 0;
                    result = to_string(sum) + result;
                }
            }
            if(carry == 1) result = to_string(carry) + result;
        }
        else {
            string min_str;
            if(num1.size() < num2.size()) min_str = num1;
            else min_str = num2;
            string max_str;
            if(num1.size() > num2.size()) max_str = num1;
            else max_str = num2;
                        
            for(int i = 0; i < max_str.size(); i++) {
                if(i >= min_str.size()) {
                    int sum = (max_str[max_str.size()-i-1]-'0') + carry;
                    if(sum > 9) {
                        carry = 1;
                        result = to_string(sum % 10) + result;
                    }
                    else { 
                        carry = 0;
                        result = to_string(sum) + result;
                    }
                    continue;
                }
                int sum = (num1[num1.size()-i-1]-'0') + (num2[num2.size()-i-1]-'0') + carry;
                if(sum > 9) {
                    carry = 1;
                    result = to_string(sum % 10) + result;
                }
                else {
                    carry = 0;
                    result = to_string(sum) + result;
                }
            }
            if(carry == 1) result = to_string(carry) + result;
        }    
        return result;
    }
};
