#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <getopt.h>
#include <string.h>

#include "fsLow.h"
#include "mfs.h"

int main (int argc, char * argv[])
	{
	char * cmdin;
	char * cmd;
	char * filename;
	uint64_t volumeSize;
	uint64_t blockSize;
    int retVal;
    
	if (argc > 3)
		{
		filename = argv[1];
		volumeSize = atoll (argv[2]);
		blockSize = atoll (argv[3]);
		}
	else
		{
		printf ("Usage: fsLowDriver volumeFileName volumeSize blockSize\n");
		return -1;
		}
		
	retVal = startPartitionSystem (filename, &volumeSize, &blockSize);	
	printf("Opened %s, Volume Size: %llu;  BlockSize: %llu; Return %d\n", filename, (ull_t)volumeSize, (ull_t)blockSize, retVal);

	if (retVal != PART_NOERROR)
		{
		printf ("Start Partition Failed:  %d\n", retVal);
		return (retVal);
		}
		
	retVal = initFileSystem (volumeSize / blockSize, blockSize);
	
	if (retVal != 0)
		{
		printf ("Initialize File System Failed:  %d\n", retVal);
		closePartitionSystem();
		return (retVal);
		}
		

	using_history();
	stifle_history(200);	//max history entries
	
	while (1)
		{
		cmdin = readline("Prompt > ");
#ifdef COMMAND_DEBUG
		printf ("%s\n", cmdin);
#endif
		
		cmd = malloc (strlen(cmdin) + 30);
		strcpy (cmd, cmdin);
		free (cmdin);
		cmdin = NULL;
		
		if (strcmp (cmd, "exit") == 0)
			{
			free (cmd);
			cmd = NULL;
			exitFileSystem();
			closePartitionSystem();
			// exit while loop and terminate shell
			break;
			}
			
		if ((cmd != NULL) && (strlen(cmd) > 0))
			{
			he = history_get(history_length);
			if (!((he != NULL) && (strcmp(he->line, cmd)==0)))
				{
				add_history(cmd);
				}
			processcommand (cmd);
			}
				
		free (cmd);
		cmd = NULL;		
		} // end while
	}