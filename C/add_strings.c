void reverse(char* str){
	int i = 0, j = 0;
    char* tmp = malloc(sizeof(char));
    
	while(str[i] != '\0'){
		i++;
	}

	for(j = 0; j < i/2; j++){
	    *tmp = *(str+j);
        *(str+j) = *(str+(i-j-1));
        *(str+(i-j-1)) = *tmp;
	}
}

char * addStrings(char * num1, char * num2){
    char* result = malloc(5100 * sizeof(char));
    int carry = 0;
    int index = 0;
        
    if(strlen(num1) == strlen(num2)){
        for(int i = strlen(num1)-1; i >= 0; i--){
            int sum = (num1[i]-'0') + (num2[i]-'0') + carry;
            carry = sum / 10;
            result[index++] = (sum % 10) + '0';
        }
        if(carry == 1) result[index++] = carry + '0';
        result[index] = '\0';
    }
    else{
        int i = strlen(num1)-1, j = strlen(num2)-1; 
                        
        while(carry || i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0){
                sum = sum + (num1[i] - '0');
                i --;
            }
            if(j >= 0){
                sum = sum + (num2[j] - '0');
                j --;
            }
            result[index++] = (sum % 10) + '0';
            carry = sum / 10;
        }
        result[index] = '\0';
    }    
    
    reverse(result);
    return result;
}
