class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = []
        carry = 0
        
        if len(num1) == len(num2):
            for i in range(len(num1)):
                sum = int(num1[-(i+1)]) + int(num2[-(i+1)]) + carry
                if sum > 9:
                    carry = 1
                    result.append(sum % 10)
                else: 
                    carry = 0
                    result.append(sum)
            if carry == 1:
                result.append(carry)
        else:
            min_str = num1 if len(num1) < len(num2) else num2
            max_str = num1 if len(num1) > len(num2) else num2
                        
            for i in range(max(len(num1), len(num2))):
                if i >= len(min_str):
                    sum = int(max_str[-(i+1)]) + carry
                    if sum > 9:
                        carry = 1
                        result.append(sum % 10)
                    else: 
                        carry = 0
                        result.append(sum)
                    continue
                sum = int(num1[-(i+1)]) + int(num2[-(i+1)]) + carry
                if sum > 9:
                    carry = 1
                    result.append(sum % 10)
                else: 
                    carry = 0
                    result.append(sum)
            if carry == 1:
                result.append(carry)
            
        return "".join([str(n) for n in result[::-1]])
