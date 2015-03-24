#include "list.h"
int main()
{	
	int num, num_input;
	char c;
	char user_input[20];	//array used to check if user entered yes
	char source_file[60];	//array used to scan file/path name (must be under 60 char)
	FILE *fp;		//create file pointer
	fp = NULL;		
	user_input[0] = 'y';
		
	while(fp == NULL)	//coninually loop until user entered valid file or path
	{
		printf("please enter the name or path of a text file \n");
		gets(source_file);
		fp = fopen(source_file, "r");
		if (fp == NULL) printf("invalid file or path.... try again \n");
	}
	 
        int number;
        
	while (!feof(fp))		//this loop scans through the file and copies the numbers into the linked list (it copies the last number twice for some reason
	{
	        fscanf(fp, "%d", &number);
       		add(number);
	}	
	delete(number);		//it kept adding the last number twice so i just deleted it once. 
	fclose (fp);		//close file
	prettyPrint();		
	
	while ( (!strcmp(user_input,"Y")) ||(!strcmp(user_input,"y")) || (!strcmp(user_input,"YES")) || (!strcmp(user_input,"yes")) || (!strcmp(user_input,"Yes")) ) 
	{
		printf ("please enter a number to search for and delete \n");
		scanf ("%d",&num_input);
		int x =  delete(num_input);
		if (x == EXIT_SUCCESS) printf("NUMBER WAS DELETED\n");
		else printf("NUMBER WAS NOT FOUND\n");
		prettyPrint();
		
		printf("Would you like to delete another number?\n");
		scanf("%s",&user_input);
	}
}


		 	
	
	
