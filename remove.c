#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffersize 1000


void erasetext();
void removetext(char *str, const char *word);      //declaring functions

int main()
{
   erasetext();
    return 0;
}


                                                   //defining function to delete specific text from file
void erasetext(){

char nam[30]; char word[100]; char buffer[1000];        //declaring variables and pointers
FILE * f1; FILE * f2;


printf("enter file name:");                          //file to edit
scanf("%s", nam);

printf("Enter word to remove:");                    // input of specific word to remove
scanf("%s", word);

f1 = fopen(nam,"r");                                  // opening existing file in read only mode
f2 = fopen("new.txt", "w");                           // opening temporary file in write only mode

if(f1 == NULL || f2 == NULL){                         // fopen returns null if unable to open file in specified mode

    printf("Unable to open files.\n");
    return;
}

while((fgets(buffer,buffersize,f1)!= NULL)){        //fgets reads string from file and stores in character array until file reaches null or maximum capacity specified by buffersize

    removetext(buffer,word);                    //remove occurrences of word for a line

    fputs(buffer,f2);                           //copy text to new file

}

fclose(f1);                                    //close files
fclose(f2);

remove(nam);                                  //remove previous file
rename("new.txt" ,nam);                       //rename new file

printf("The word %s has been removed.", word);

return;

}



                                                    //function definition to match each character of file with word
void removetext(char *str, const char *word){

int x,z,stringlen,trlen;                            // declaring local variables
int found;

stringlen = strlen(str);                            //strlen function to get length of string in file
trlen = strlen(word);                               //length of word

for(x=0; x<= (stringlen-trlen); x++){

    found = 1;

    for(z=0;z<trlen;z++){

       if(str[x+z] != word[z]){                        //matching character of string with character of word
        found = 0;
        break;
       }

    }
    if(str[x+z]!= ' ' && str[x+z] != '\t' && str[x+z] != '\n' && str[x+z] != '\0')     //check if element is not a character
    {
            found = 0;
        }


        /*
         * If word is found then shift all characters to left
         * and decrement the string length
          */

        if(found == 1)
        {
            for(z=x; z<= (stringlen - trlen); z++)
            {
                str[z] = str[z + trlen];
            }

            stringlen = stringlen - trlen;

                                                             //to match next occurrence of word from current index.
            x--;
        }

}


}