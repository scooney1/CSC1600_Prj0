/*
 * compares user-supplied name and password to entries in a master
 * file of names and passwords
 * returns TRUE if a match is found, FALSE otherwise
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FALSE, TRUE } boolean;

// receive a user response of name and password
boolean matchUserPassword(char* name, char* passwd)	{

	printf("into matchUserPassword\n");fflush(stdout);
	// declare variable for password file
	FILE *usePass;
	// open the master password file
	usePass = fopen("passwrd.txt","r");
	// declare variables for names and passwords in the file
	char possible[30];
	char response[256];

	// go through the whole password file looking for a match
	int loopCount = 0;
	while(TRUE)	{

		printf("loopCount=%d\n",loopCount);//fflush(stdout);
		if(loopCount++ > 5) return FALSE;

		// read an entry in from the password file
		fscanf(usePass, "%s" "%s", possible, response);
		//printf("Possible: %s\n",possible);//Prints out strings read into possible
		//printf("Response: %s\n",response);//Prints out strings read into response
		// if the end is reached, there is no match.  return FALSE
		if(feof(usePass)) {

			break;
		}
		// see if the name matches
		int different = strcmp(name,possible);  // returns 0 if name is in file
		if(different) continue;  // skip checking password if name not found
		// matches user name

		// see if the password matches
		different = strcmp(response,passwd);
		if(!different)	{

			// matches password, too.  return TRUE
			// but first, close the master password file
				fclose(usePass);
				return TRUE;
			}
	}
	// not found.  close the master password file
	fclose(usePass);
	return FALSE;
}
