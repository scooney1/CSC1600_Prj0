/*
============================================================================
 Name        : Login.c
 Author      : S. Cooney
 Copyright   : 2017
 Description : Project 0 -- Read user ID and password
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FALSE, TRUE } boolean;
boolean matchUserPassword(char* name, char* passwd);

int main(void) {

	char name[20];
	char word[200];
	setbuf(stdout,NULL);

	boolean permitted = FALSE;
	while(TRUE)	{

		printf("Enter User Name:");
		scanf("%s",name);
		printf("Enter Password:");
		scanf("%s",word);
		permitted = matchUserPassword(name,word);
		if(permitted) break;
		printf("%s and %s are not a valid name/password pair here.\n",name,word);
	}

	printf("\nWelcome aboard, %s!\n",name);
	return EXIT_SUCCESS;
}
