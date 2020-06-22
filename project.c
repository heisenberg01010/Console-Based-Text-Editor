#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int ch;
char fn[20],e,c,name[20];

fpos_t position;

FILE *fp1,*fp2,*fp;

void Modify();
void NewFile();
void SaveAs();
void Copy();
void Delete();
void View();
void comparison();
void Edit();
void Find();
void erasetext();
void removetext(char *str, const char *word); 

#define esc 27
#define buffersize 1000

int main()
{
	while(1)
	{
		ch = 0;
		printf("\n-----------------------------------------TEXT EDITOR--------------------------------------------------");
		printf("\n\n\tMENU:\n\t\n");
		printf("\n\t1.NEWFILE\n\t2.VIEW\n\t3.COPY\n\t4.DELETE\n\t5.COMPARISON\n\t6.EDIT\n\t7.SAVEAS\n\t8.FIND\n\t9.EXIT\n");
		printf("\n\tEnter your choice: ");

		scanf("%d",&ch);

		if(ch < 1 || ch > 9)
		{
			printf("\tInvalid Input\n");
			exit(0);
		}
		

		switch(ch)
		{
			case 1:
			{
				NewFile();
				break;
			}
			case 2:
			{
				View();
				break;
			}
			case 3:
			{
				Copy();
				break;
			}	
			case 4:
			{
				Delete();
				break;
			}	
			case 5:
			{
				comparison();
				break;
			}	
			case 6:
			{
				Edit();
				break;
			}
			case 7:
			{
				SaveAs();
				break;
			}
			case 8:
			{
				Find();
				break;	
			}
			case 9:
			exit(0);
			
			default:
			{
				printf("Incorrect Input\n");
				break;
			}
		}
	}
return 0;
}

void NewFile()
{
	printf("\n\tEnter the name of the file to be created: ");
	scanf("%s", name);
	fp1=fopen(name,"w");
	printf("\n\tPress Esc and then Enter to save.\n\t");
	printf("Press Tab key and then Enter to quit without saving.\n\n\t");

	char temp;
	scanf("%c", &temp);


	while(1)
	{
		c=getchar();

		if(c == esc )
		{
			fclose(fp1);
			break;
		}

		else if(c == '\t')
		{
			remove(name);
			break;
		}

		fputc(c,fp1);

	}
}

void comparison()
{
	int line = 1, col = 0;
	  

	printf("\n\tEnter the first file: ");
		scanf("%s", name);
		fp1 = fopen(name,"r");
	printf("\n\tEnter the second file: ");
		scanf("%s", fn);
		fp2 = fopen(fn,"r");

	

    if (fp1 == NULL || fp2 == NULL) 
    { 
       printf("\tError : Files not open\n"); 
       return; 
    } 
	char ch1 = getc(fp1); 
    char ch2 = getc(fp2);

	while (ch1 != EOF && ch2 != EOF) 
    { 
        col++; 
  
        if (ch1 == '\n' && ch2 == '\n') 
        { 
            line++; 
            col = 0; 
        } 
  

        if (ch1 != ch2) 
        { 
            printf("\tFiles not identical\n"); 
            printf("\tLine Number : %d \t""Position : %d \n", line, col); 
            return;
        } 
  
        ch1 = getc(fp1); 
        ch2 = getc(fp2); 
    } 

    if(ch1 == EOF && ch2 == EOF)
    {	
    	printf("\n\tFiles are identical\n");
	}
	else
	{
        printf("\tFiles not identical\n"); 
	}
	
	fclose(fp1); 
    fclose(fp2); 
}

void View()
{
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");

	if(fp1==NULL)                                 
	{
		printf("\n\tFile not found!");
		return;
	}

	printf("\t");

	c=fgetc(fp1);
	while( c != EOF )                           
	{
		printf("%c",c);
		c=getc(fp1);
	}

	fclose(fp1);
	return;
}

void Copy()
{
	printf("\n\tEnter the filename from which to copy: ");
	scanf("%s", name);
	printf("\n\tEnter the new filename:  ");
	scanf("%s",fn);
	
	fp1=fopen(name,"r");

	if(fp1 == NULL)
	{
		printf("\n\tFile not found!");
		return;
	}
	
	fp2=fopen(fn,"w");

	while(!feof(fp1))
	{
		c=getc(fp1);
		putc(c,fp2);
	}

	printf("\n\tFile has been copied successfully");
	fclose(fp1);
	fclose(fp2);
}

void Delete()
{
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");

	if(fp1==NULL)
	{
		printf("\n\tFile not found!");
		return;
	}
	fclose(fp1);

	if(remove(fn)==0)
	{
		printf("\n\n\tFile has been deleted successfully!");
	}
	else
	{
		printf("\n\tError!\n"); 
	}
}

void Edit()
{
	printf("\n\tEdit options available:\n");
	printf("\t1. Append to file\n");
	printf("\t2. Delete all instances of a word in the file\n");
	printf("\n\tEnter you choice: ");

	int option;
	scanf("%d", &option);
	getchar();
	
	if(option < 1 || option > 2)
	{
		printf("\tInvalid Input\n");
		return;	
	}

	switch(option)
	{
		case 1:
		{
			printf("\n\tEnter the file name: ");
			scanf("%s",fn);
			fp1=fopen(fn,"r+");

			if(fp1==NULL)
			{
				printf("\n\tFile not found!");
				return;
			}
			while(!feof(fp1))
			{
				c=getc(fp1);
				printf("%c",c);

			}
			printf("\n\tPress Esc and then enter key to save.\n\n\t");

			while(1)
			{
				c=getchar();
				fputc(c,fp1);

				if(c == esc )
				{
					fclose(fp1);
					break;
				}
			}
			return;
		}
		
		case 2:
		{
			erasetext();
    		return;
		}	
	}
}

void SaveAs()
{
	printf("\n\tEnter the name of the file to be changed: ");
	scanf("%s", name);
	printf("\n\tEnter the new file name: ");
	scanf("%s", fn);

	fp1 = fopen(name, "r");
	
	if(fp1==NULL)
	{
		printf("\n\tFile not found!");
		return;
	}
	
	ch = rename(name, fn);	

	printf("\n\tpress '.' to save\n\n\t");

	while(1)
	{
		c=getchar();
		if(c == '.')
		{
			fclose(fp1);
			break;
		}
	}
}

/* function defintion to find all occurences of a word/pattern. */
void Find()
{
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");


	if(fp1==NULL)
	{
		printf("\n\tFile not found!");
		return;
	}


	char temp[100000];
	int line = 1;
	int match_no = 0;
	char str[100], *ptr[100], string[100];
	long int pos;
	/* taking input of the desired word/pattern. */
	printf("\tEnter the phrase to search: ");
	scanf("%s", str);
	/* storing our file characters in the temp variable.*/
	while(fgets(temp, 100000, fp1) != NULL) 
	{
		/* finding our word in the file and storing it in a pointer variable. */
		*ptr = strstr(temp, str);
		if((strstr(temp, str)) != NULL) 
		{	
			/* subtracting the location of the sentence pointer(temp) from our word pointer(ptr)
			   to get the location of our word.*/
			pos = *ptr - temp;
			/* using fseek function to place the pointer at the start of our word/pattern. */
			fseek(fp1, pos, SEEK_CUR);
			/* highlighting our word with red colour */
			*string = printf("\033[1;31m"); printf("\t%s", str); printf("\033[0m");
			/* printing it in a formatted way */
			printf("%s found on line %d at position %ld in line : %s\n", string, line, pos, temp);
			match_no++;
		}
		line++;	
	}
	/* condition of no match found */
	if(match_no == 0)
	{
		printf("\tNo match found");
	}

}

void erasetext()
{
    char nam[30]; char word[100]; char buffer[1000];        
    FILE * f1; FILE * f2;
    int line = 0,plus = 0;


    printf("\tEnter file name: ");                          
    scanf("%s", nam);

    printf("\tEnter word to remove: ");                    
    scanf("%s", word);

    printf("\tEnter line number to edit: ");
    scanf("%d", &line);

    if(line < 1)
    {
        printf("\tInvalid line number\n");
        return;
    }

    f1 = fopen(nam,"r");                                  
    f2 = fopen("new.txt", "w");                             

    if(f1 == NULL || f2 == NULL){                         

        printf("\tUnable to open files.\n");
        return;
    }


    plus = 0;

    while((fgets(buffer,buffersize,f1)!= NULL))
    {            
        plus++;

        if(plus == line)
        {
            removetext(buffer,word);                    
            fputs(buffer,f2);
        }

        else
        {
            fputs(buffer,f2);                           
        }

    }

    fclose(f1);                                    
    fclose(f2);

    remove(nam);                                  
    rename("new.txt" ,nam);                       

    printf("\tThe word \033[1;33m%s\033[0m has been removed form line %d.\n", word, line);

    return;

}

void removetext(char *str, const char *word)
{
    int x,z,stringlen,trlen;                            
    int found;

    stringlen = strlen(str);                            
    trlen = strlen(word);                               

    for(x=0; x<= (stringlen-trlen); x++)
    {

        found = 1;

        for(z=0;z<trlen;z++)
        {
            if(str[x+z] != word[z])
            {                        
                found = 0;
                break;
            }
        }
        
        if(str[x+z]!= ' ' && str[x+z] != '\t' && str[x+z] != '\n' && str[x+z] != '\0')     
        {
            found = 0;
        }

        if(found == 1)
        {
            for(z=x; z<= (stringlen - trlen); z++)
            {
                str[z] = str[z + trlen];
            }

            stringlen = stringlen - trlen;
            x--;
        }
    }
}
