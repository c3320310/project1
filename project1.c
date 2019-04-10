#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char plainText[1024] = "abcdABCDwxyzWZYZ";       // need to find way to get input
	char letter;
	int i, key;
	
	printf("original text: %s\n",plainText);
	//	scanf("%[^\n]%*c",plainText);  use this for input from keyboard
	printf("key shift {-25 to 25}: ");
	scanf("%d", &key);
	
	  
	  if(key<-25 || key >25){           //ends if not valid key shift
	        printf("invalid keyshift");
	        return 0;
	  }
	
	for(i = 0; i<strlen(plainText); ++i){
		letter = plainText[i];
		
		if(letter >= 97 && letter <= 'z'){                  // single character literal 'a' and 'z' could have said 97 and 123
			letter = (letter + key + 26 - 97)% 26 + 65;     //this will convert lower case to upper
			                                                //(+ 26) allows for negative shift
			plainText[i] = letter;
		}
		else if(letter >= 'A' && letter <= 'Z'){
			letter = (letter + key +26 -65)% 26 + 65;       //this converts ascii to numbers 0-26 then does mod 
			                                            // then adds 65 to get 26upper case
			plainText[i] = letter;
			
		}
	}
	
	printf("Encrypted message: %s", plainText);
	
	return 0;
}
/*
need to work on input method. and menu set up, and set up functions for above
meun
1 encript with rotation with text and key shift
2 decript rotation "   "
3 encript with substitution text and sub
4 decript substitution      "    "
5 decript rotation text only
6 decript substitution text only
*/
