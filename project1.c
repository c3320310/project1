#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int option;
    printf("please select an option:\n");
    printf("rotation encryption = 1 \nrotation decryption = 2 \nsubstitution encryptiopn = 3 \nsubstitution decryption= 4\n");
    scanf("%d",&option );
    
        switch(option){
            
            case 1:
/* input text from scanf to plainText string and print to screen, scanf the key shift, integer between -25 to +25
* if lower case eg 'a' add key shift: eg 'a' +(1) = 98, + 26 (allows for negative key shift) - 97 this will
* give integer between 26 - 52. mod 26 to give integer between 0-26. then add 65 to give uppercase. 
* output printf cipher string. 
*/
            
                printf("selected option %d rotation encryption\n", option);

	char plainText[1024]={"123!@# ABC this can be what ever message you like xyz 789&*("};
	char cipher[1024];
	char letter;
	int i, key;
	
	printf("text for encryption:");          //can not get scanf to work??
	//scanf("%[^\n]%*c", plainText);          //scanf not working on codeboard??     //use this for input from keyboard
	printf("%s\n", plainText);
	printf("key shift (-25 to 25): ");             // key shift -25 to +25
	scanf("%d", &key);
	printf("%d\n",key);                            //print key shift to screen
	
	  
	  if(key<-25 || key >25){            //ends if not valid key shift
	        printf("invalid keyshift");
	        return 0;
	  }
	
	for(i = 0; i<strlen(plainText); ++i){
		letter = plainText[i];                            //each letter to be tested from plainText string
		
		if(letter >= 97 && letter <= 'z'){                  //if single character literal 'a' and 'z' could have said 97 and 123
			letter = (letter + key + 26 - 97)% 26 + 65;     //this will convert lower case to integer between 0-26 including key shift then add 65 to give upper case
			                                                //(+ 26) allows for negative shift
			cipher[i] = letter;                              // assigns new letter to cipher string index i 
		}
		else if(letter >= 'A' && letter <= 'Z'){
			letter = (letter + key +26 -65)% 26 + 65;       //this converts ascii to integer between 26-52 then does mod 26 
			                                                //to integer between 0-26 including key shift then add 65 to give upper case
			cipher[i] = letter;                             // assigns new letter to cipher string index i
		}
		else if(i<1024){                                  // if not upper or lower 
		    cipher[i]= letter;                             // do nothing assign straight to cipher string index i
		}
	}
	
	printf("Encrypted message: %s", cipher);           //print encrypted message

            break;
            
            case 2:
/* input hard code, bellow is string that has key shift of 4. user needs to scanf key shift of 4 to get correct text abck 
 * if lower case eg 'a' minus key shift: eg 'a' - (1) = 96, + 26 (allows for negative key shift) - 97 
 * to give integer between 26 - 52. mod 26 to give integer between 0-26. then add 65 to give uppercase 
 * output printf plainText string. 
 */
                printf("selected option %d rotation decryption.\n", option);
                
    char decipher[1024] = "123!@# EFG XLMW GER FI ALEX IZIV QIWWEKI CSY PMOI BCD 789&*(";     //this is key shift 4
	char normalText[1024];
	char letter2;
	int count2, key2;
	
	printf("cipher text: %s\n",decipher);
	//scanf("%s",decipher);                   //can take scanf if you know how to write in roation code on a keyboard??
	printf("key shift{-25 to 25): ");      // note 0 will be no rotation
	scanf("%d", &key2);
	
	    if(key2<-25 || key2 >25){         //ends if not valid key shift
	        printf("invalid keyshift");
	        return 0;
	    }
	    
	for(count2 = 0; count2<strlen(decipher); ++count2){
		letter2 = decipher[count2];                   //tests each letter of cipher string
		
		if(letter2 >= 'a' && letter2 <= 'z'){                // string single 'a' could have said 97 to 123
			letter2 = (letter2 + 26 - key2 - 97)% 26 + 65;      //this converts lower case ascii to integer between 26-52 then does mod 26
			                                                 //to integer between 0-26 including key shift then add 65 to give upper case 
			                                                //(+26) allows for negative key shift
			 normalText[count2]= letter2;                          // assigns letter to plaintText string 
		}
		else if(letter2 >= 'A' && letter2 <= 'Z'){
			letter2 = (letter2 + 26 - key2 - 65)% 26 + 65;       //this converts upper case ascii to integer between 26-52 then does mod 26
			                                                 //to integer between 0-26 including key shift then add 65 to give upper case 
			                                                //(+26) allows for negative key shift
			 normalText[count2]= letter2;                          // assigns letter to plaintText string
		}
		else if(count2<1024){
		    normalText[count2] = letter2;                       //if not upper or lower case do nothing assign to plainText no change 
		}
	}
	
	printf("decripded message: %s", normalText);
       
            break;
            
            case 3:
/* input from scanf to plainText string. test each letter one at a time,
 * either - 97 if lower case, or - 65 if uppercase to find the substitution index
 * then assign to cipher string for printf output*/             
                printf("selected option %d substitution encryption:\n", option);
                
    char code[1024]; 
	char sub[1024]="QWERTYUIOPASDFGHJKLZXCVBNM";
	char Text[1024]={"123!@# ABC this can be what ever message you like xyz 789&*("}; 
	char letter3;
	int count3, subindex;
	
	printf("input text for encription: %s\n", Text);
	//scanf("%[^\n]%*c",Text);                  //scanf not working??   //use if want to input from keyboard

	for(count3 = 0; count3<strlen(Text); ++count3){
		letter3 = Text[count3];                         //this assigns index of text to letetr for substitution
		
		if(letter3 >= 'a' && letter3 <= 'z'){            // single character literal 'a' and 'z' could have said 97 and 123
			subindex = letter3 - 97;                   //sub index = lower case - 97 to give integer between 0 - 26
			code[count3]=sub[subindex]; 	
		}
		else if(letter3 >= 'A' && letter3 <= 'Z'){        //if upper case
			subindex = letter3 - 65;                   //sub index = upper case - 65 to give integer between 0 - 26
			code[count3]=sub[subindex];
		}
		else if(count3<1024){
		    code[count3]=Text[count3];     //if not upper or lower do nothing assign else to code unchanged.
		}
	}
	printf("%s", code);       //print the cipher string
	
            break;
            
            case 4:
            
                printf("selected option %d substitution decryption:\n", option);
                
    char cipher4[1024]="123!@# QWE ZIOL EQF WT VIQZ TCTK DTLLQUT NGX SOAT BNM 789&*(";            //input text already in qwerty  
	char alphabet[1024]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";               //standard alphabet   
	char substitute[1024]="QWERTYUIOPASDFGHJKLZXCVBNM";             //standard qwerty
	char regText[1024];                                     //output text 
	char uppercase[1024];                                   //after converting letter to upper case
	char letter4;
	int index4, n;
	
	printf("%s\n",cipher4);
	//printf("input text for encription: %s\n", plainText);    // promp user if using scanf
	//scanf("%[^\n]%*c", cipher);                           //use if want to input from keyboard

	for(index4 = 0; index4 <strlen(cipher4); ++index4){
		letter4 = cipher4[index4];                         //this assigns index i of encripted text to a letetr for substitution
		
		if(letter4 >= 'a' && letter4 <= 'z'){                  // single character literal 'a' and 'z' could have said 97 and 123
			uppercase[index4] = letter4 - 32;                      //this will convert to upper case
		}
		else if(letter4 >= 'A' && letter4 <= 'Z'){            //if upper case do nothing and assign to uppercase string
		    uppercase[index4] = cipher4[index4];	                     
		}
		else if(index4<1024){
		    regText[index4] = cipher4[index4];                   //if  not  upper or lower do nothing and assign straight to regText string
		}
// once input text has been converted to upper case then need to test against known substitution text.//			
		for(n=0 ; n<strlen(alphabet) ; n++){        //tests each letter against the sub string, 
		    if(uppercase[index4]==substitute[n]){           // when uppercase input matches upper case qwerty index
		        regText[index4]= alphabet[n];       // the matched substitue index is used in the corresponding alphabet index and assigned to reg text string
		    }
		}
	}
	printf("%s", regText);       //print the decryptded string
            break;
            
            default:
            printf("you did not select an option from 1-4 please try again");
        }
    return 0;
}
