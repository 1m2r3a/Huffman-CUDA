#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

extern int startCPUCompression(const char* inputFileName, const char* outputFileName);
extern int startCPUDecompression(const char* inputFileName, const char* outputFileName);

extern int startGPUCompression(const char* filename,const int BLOCK_NUMBER, const int THREAD_NUMBER, const char* outputFilename);
extern int startGPUDecompression(const char* inputFileName, const char* outputFileName);

using namespace std;

int main(int argc,char* argv[])
{
	
	//Check for NULLS strcmp() returns undefined behavior against NULL
	if(argv[1] == NULL || argv[2] == NULL)
		printf("Arguments are NULL. Check -h for help.");
	else
		if(strcmp(argv[1],"-h")==0)
			printf("\n This is the help");
	else
		if(strcmp(argv[1],"-gpu")==0)
		{
		 if(strcmp(argv[2],"-c")==0)
		  {
			printf("GPU Compression: %s %s\n",argv[1],argv[2]);
			int NUMBER_OF_BLOCKS = 512;
			int NUMBER_OF_THREADS= 512;

			//Set the blocks and threads if the user inputs them
			if(argv[4]!=NULL && argv[5]!=NULL)
			{
			 NUMBER_OF_BLOCKS = atoi(argv[4]);
			 NUMBER_OF_THREADS = atoi(argv[5]);
			 printf("Number of blocks set to: %d\n Number of threads set to: %d\n",NUMBER_OF_BLOCKS,NUMBER_OF_THREADS);
			}
			else
				printf("Number of blocks and threads set to default: %d %d",NUMBER_OF_BLOCKS,NUMBER_OF_THREADS);
		
			char* outputCompressFileName = "data";
			if(argv[6] != NULL)
					outputCompressFileName=argv[6];

			startGPUCompression(argv[3],NUMBER_OF_BLOCKS,NUMBER_OF_THREADS,outputCompressFileName);
		   }
		 else
			if(strcmp(argv[2],"-d")==0)
			{	
				printf("%s %s\n",argv[1],argv[2]);

				char* inputDecompressFileName = "data";
				char* outputDecompressFileName = "out";
				if(argv[3] != NULL)
					inputDecompressFileName=argv[3];

				if(argv[4] != NULL && argc >= 4)
					outputDecompressFileName=argv[4];

				printf("Input file name set to: %s\nOutput file name set to: %s", inputDecompressFileName,outputDecompressFileName); 
			    startGPUDecompression(inputDecompressFileName,outputDecompressFileName);
		 }
		}
	else
		if(strcmp(argv[1],"-cpu")==0)
		{
		 if(strcmp(argv[2],"-c")==0)
		 {
			char* inputCompressFileName = NULL ;
		    char* outputCompressFileName = "dataCpu";
		 	if(argv[3] != NULL)
			{	
				inputCompressFileName = argv[3];
				printf("Input file specified to:%s\n",inputCompressFileName);
			}else
			{
				printf("Input file not specified. check -h");
				return 1;
			}

			if(argv[4] != NULL)
				outputCompressFileName =argv[4];

			printf("Input file name set to: %s\nOutput file name set to: %s", inputCompressFileName,outputCompressFileName); 

			startCPUCompression(argv[3],outputCompressFileName);	 
		 }
		 else
			if(strcmp(argv[2],"-d")==0)
			{	
				printf("\n %s %s %s",argv[1],argv[2],argv[3]);

				char* inputDecompressFileName = "dataCpu";
				char* outputDecompressFileName = "outCpu";

				if(argv[3] != NULL)
					inputDecompressFileName=argv[3];

				if(argv[4] != NULL && argc >= 4)
					outputDecompressFileName=argv[4];
					
				printf("Input file name set to: %s\nOutput file name set to: %s", inputDecompressFileName,outputDecompressFileName); 
			    startCPUDecompression(inputDecompressFileName,outputDecompressFileName);
		    }
		}
	else
		printf("Uncaught error");
	return 0;
}