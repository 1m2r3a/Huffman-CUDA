#include <ctime>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/copy.h>
#include <thrust/sort.h>
#include <thrust/reduce.h>
#include <thrust/iterator/constant_iterator.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "HuffmanTreeBuilder.cpp"

using namespace std;
using namespace thrust;

__constant__ HuffmanTable  deviceHuffmanTable[256];

__global__ void mykerneldecompres(myStringer* encode, int encodeSize,HuffmanTable* myStructure,int* myStrSize,myStringer* out,decompresserBinary* binary, int fs){
	int UID= threadIdx.x + blockIdx.x * blockDim.x;

	if(UID < encodeSize  )
	{
		for(int i=0;i<=encode[UID].length ;i++)
		{
			if(i==encode[UID].length){
			switch(encode[UID].position)
			{
			
				case 1:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
					binary[UID].length++;
					break;

				case 2:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
					binary[UID].length++;
					break;

				case 3:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x04) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
					binary[UID].length++;
					break;

				case 4:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x08) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x04) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
					binary[UID].length++;
					break;

				case 5:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x10) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x08) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x04) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
					binary[UID].length++;
					break;

				case 6:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x20) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x10) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x08) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x04) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
					binary[UID].length++;
					break;

				case 7:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x40) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x20) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x10) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x08) ? 1:0; 
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x04) ? 1:0; 
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0; 
					binary[UID].length++;
					break;

				case 8:
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x80) ? 1:0; 
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x40) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x20) ? 1:0; 
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x10) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x08) ? 1:0; 
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x04) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
					binary[UID].length++;
					binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
					binary[UID].length++;
					break;

				default:
					printf("Fail",UID,encode[UID].position,encode[UID].length);
					break;
				}
			break;
			}
		
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x80) ? 1:0;
			binary[UID].length++;
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x40) ? 1:0;
			binary[UID].length++;
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x20) ? 1:0;
			binary[UID].length++;
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x10) ? 1:0;
			binary[UID].length++;
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x08) ? 1:0;
			binary[UID].length++;
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x04) ? 1:0;
			binary[UID].length++;
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x02) ? 1:0;
			binary[UID].length++;
			binary[UID].ch[binary[UID].length] = (encode[UID].ch[i] & 0x01) ? 1:0;
			binary[UID].length++;
				
			}

			long p=0, k=0 ,j=0 ,e=0;
			
			for ( p=0; p<binary[UID].length; p++)
			{
				for(k=0;k<myStrSize[0];k++)
				{
					
					for( j=0;j<myStructure[k].len;j++)
					{ 
						if (myStructure[k].code[j] == binary[UID].ch[p+j])
						{
							e++;
						}

						if(e == myStructure[k].len)
						{
							out[UID].ch[out[UID].length]=myStructure[k].c;
							out[UID].length++;  
							p+=j;
							if(p >= binary[UID].length)
								goto jump;
							goto jump;
						}
						if(j == myStructure[k].len-1) 
							e=0;
					}
				}
				jump: e=0;
					

		}
	}
}

__global__ void kernelCompression(char* rawData,int size,int* myStrSize,myStringer* myString, int chunkSize)
{
	
	int tableSize = myStrSize[0];
	int UID= threadIdx.x + blockIdx.x * blockDim.x;

	if(UID < size)
	{
		int o=0;

		for(int j = UID * chunkSize; j<(chunkSize*UID)+chunkSize;j++)
		{
			if(j < size)
				for(int i =0;i<tableSize;i++)
			   {
				if(rawData[j] == deviceHuffmanTable[i].c)
				{
					
					for(int k=0;k< deviceHuffmanTable[i].len;k++)
					{
	
						if(myString[UID].position ==8)
						{
							o++;
							myString[UID].position =0;
							myString[UID].length++;
							myString[UID].ch[o]  = (myString[UID].ch[o]  << 1) | deviceHuffmanTable[i].code[k];
							myString[UID].position++;
						}else{
							myString[UID].ch[o]  = (myString[UID].ch[o]  << 1) | deviceHuffmanTable[i].code[k];
							myString[UID].position++;
						}
					}
					break;			
				}
			 }
		}
	}	
}



int startGPUCompression(const char* inputFilename,const int BLOCK_NUMBER, const int THREAD_NUMBER,const char* outputFilename)
{
	
  clock_t begin = clock();
  int fileSize =0;
  cudaError_t cudaReturnValue;
  
  char* device_rawData; //device input containing the raw data

  FILE *f = fopen(inputFilename, "rb");
  if(f == NULL) printf("FILE NOT FOUND");
  string host_rawData;
  
  if(f)
  {
	  
	  fseek(f, 0, SEEK_END);
	  fileSize = ftell(f);
	  printf("-----------------------------------------------------------------------------------------\nfile size is: %d %f\n\n", fileSize,ceil(fileSize/(float)(BLOCK_NUMBER*THREAD_NUMBER)));
	  host_rawData.resize(ftell(f));
	  rewind(f);
	  fread(&host_rawData[0],1,host_rawData.size(),f);
	  fclose(f); 
  }
  
    cudaMalloc(&device_rawData, host_rawData.size());
    cudaMemcpy(device_rawData, host_rawData.c_str(), host_rawData.size(), cudaMemcpyHostToDevice);

    device_vector<char> device_vectorIn(host_rawData.begin(), host_rawData.end());

    thrust::sort(device_vectorIn.begin(), device_vectorIn.end());

    device_vector<char> device_symbol(device_vectorIn.size());
    device_vector<int>  device_symbolFrequency(device_vectorIn.size());

    thrust::pair<device_vector<char>::iterator, device_vector<int>::iterator> temporaryPair = reduce_by_key(device_vectorIn.begin(), device_vectorIn.end(),
	   make_constant_iterator(1), device_symbol.begin(),   device_symbolFrequency.begin());
  
    device_symbol.erase(temporaryPair.first, device_symbol.end());
    device_symbolFrequency.erase(temporaryPair.second, device_symbolFrequency.end());
    cudaDeviceSynchronize();
  
	clock_t end_thrust = clock();

	int character_frequency[256];
	char character[256];


	thrust::copy(device_symbolFrequency.begin(),device_symbolFrequency.end(),character_frequency);
	thrust::copy(device_symbol.begin(), device_symbol.end(), character);
    
		
	//Build the tree and the table
	buildHuffmanTree(character,character_frequency,device_symbol.size());
    Node * root = myQueue.top();
    myQueue.pop();

	int binaryCode[256], top = 0;
	buildHuffmanTable(root, binaryCode, top);
	
	cudaReturnValue = cudaMalloc((void**) &deviceHuffmanTable, sizeof(HuffmanTable)*myIdx);
	if (cudaReturnValue != cudaSuccess)  printf("cudaMemcpy failed!");

	cudaReturnValue = cudaMemcpyToSymbol (deviceHuffmanTable, hostHuffmanTable, sizeof(HuffmanTable)*myIdx );
	if (cudaReturnValue != cudaSuccess)  printf("cudaMemcpy failed!");
 
	int* d_myStrSize;
	cudaMalloc((void**) &d_myStrSize, sizeof(int));
	cudaMemcpy(d_myStrSize, &myIdx, sizeof(int),cudaMemcpyHostToDevice);

	myStringer* myString;
	cudaMalloc((void**)&myString, sizeof(myStringer)*THREAD_NUMBER*BLOCK_NUMBER);
	cudaMemset(myString,0,sizeof(myStringer)*THREAD_NUMBER*BLOCK_NUMBER);
	
	cout<<"SIZE: : "<<host_rawData.size()<<" "<<myIdx<<endl;

	int chunkSize=ceil(fileSize/(float)(BLOCK_NUMBER*THREAD_NUMBER));
	
	kernelCompression<<<BLOCK_NUMBER,THREAD_NUMBER>>>(device_rawData,host_rawData.size(),d_myStrSize,myString,chunkSize);

	ofstream myFile (outputFilename, ios::out | ios::binary);

    myFile<<BLOCK_NUMBER<<" "<<THREAD_NUMBER<<endl;

	myFile<<fileSize<<endl<<myIdx<<endl;

	for(int i=0;i<myIdx;i++)
		myFile<<(int)character[i]<<" "<<character_frequency[i]<<" ";

	cudaDeviceSynchronize();

	cout<<"End compression\n";
	clock_t end_encode = clock();

	myStringer *host=(myStringer*)malloc(sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER);
	cudaMemcpy(host, myString, sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER,cudaMemcpyDeviceToHost);
	
	for( int i=0;i<BLOCK_NUMBER*THREAD_NUMBER & i< fileSize ;i++)
		if(host[i].ch!=NULL)
		{
			myFile<<host[i].length<<" "<<host[i].position<<" ";
			 myFile.write (host[i].ch, host[i].length+1);
		}
			
	cudaFree(device_rawData);
	cudaFree(myString);
	cudaFree(d_myStrSize);
	cudaFree(device_rawData);
	free(host);

	clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"ALL: " <<elapsed_secs<<endl;
    cout<<"Thrust: "<< double(end_thrust - begin) / CLOCKS_PER_SEC<<endl;
    cout<<"Encode: "<< double(end_encode - begin) / CLOCKS_PER_SEC<<endl;
    cout<<"Chunk size" << chunkSize;
	
	return 0;
}

int startGPUDecompression(const char* inputFileName, const char* outputFileName)
{
	
	clock_t start = clock();
  
	int sizeOfTable =0;
	int fileSize = 0;
	char ch[256];
	int character_frequency[256];
	int BLOCK_NUMBER = 256,THREAD_NUMBER = 32;

	ifstream inputEncode(inputFileName,ios::in | ios::binary);

	if(inputEncode == NULL)
		printf("File not found or in use\n");

	inputEncode>>BLOCK_NUMBER;
	inputEncode>>THREAD_NUMBER;
	inputEncode>>fileSize;
	inputEncode>>sizeOfTable;

	printf("\n------------------------------------\n%d\n",fileSize);

	myStringer *host=(myStringer*)malloc(sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER);

	int temp;
	for(int i = 0 ; i< sizeOfTable;i++)
	{
		inputEncode>>temp;
		inputEncode>>character_frequency[i];
		ch[i]=(char)temp;
	}

	buildHuffmanTree(ch,character_frequency,sizeOfTable);
    Node * root = myQueue.top();
    myQueue.pop();
	int binaryCode[256], top = 0;
	buildHuffmanTable(root, binaryCode, top);
 
	char x[10];

	for(int i = 0 ; i< BLOCK_NUMBER*THREAD_NUMBER && i<fileSize;i++)
	{
		inputEncode>>host[i].length;
		inputEncode>>host[i].position;
		inputEncode.read(x,1);
		inputEncode.read(host[i].ch,host[i].length+1);
	}
	cout<<"Stuff has been read\n";
	clock_t middle = clock();

	
    HuffmanTable *d_Str;
	cudaMalloc((void**) &d_Str, sizeof(HuffmanTable)*myIdx);
	cudaMemcpy(d_Str, hostHuffmanTable,  sizeof(HuffmanTable)*myIdx,cudaMemcpyHostToDevice);

	int* d_myStrSize;
	cudaMalloc((void**) &d_myStrSize, sizeof(int));
	cudaMemcpy(d_myStrSize, &myIdx, sizeof(int),cudaMemcpyHostToDevice);

	myStringer* d_encoded;
	cudaMalloc((void**) &d_encoded,sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER);
	cudaMemcpy(d_encoded,host,sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER, cudaMemcpyHostToDevice);

	myStringer* d_output;
	cudaMalloc((void**) &d_output,sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER);
	cudaMemset(d_output,0,sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER);

	decompresserBinary* d_bin;
	cudaMalloc((void**) &d_bin,sizeof(decompresserBinary)*BLOCK_NUMBER*THREAD_NUMBER);
	cudaMemset(d_bin,0,sizeof(decompresserBinary)*BLOCK_NUMBER*THREAD_NUMBER);
	
	mykerneldecompres<<<BLOCK_NUMBER,THREAD_NUMBER>>>(d_encoded,BLOCK_NUMBER*THREAD_NUMBER,d_Str,d_myStrSize,d_output,d_bin,fileSize);

	cudaDeviceSynchronize();

	myStringer *host_output=(myStringer*)malloc(sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER);
	memset(host_output,0,(sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER));
	cudaMemcpy(host_output, d_output, sizeof(myStringer)*BLOCK_NUMBER*THREAD_NUMBER,cudaMemcpyDeviceToHost);
	
	ofstream out(outputFileName,ios::binary);

	for( int i=0;i<BLOCK_NUMBER*THREAD_NUMBER ;i++)
	{
		if(host_output[i].ch!=NULL)
			out<<host_output[i].ch;
	}
	clock_t end = clock();
    
	

	cout<<"Middle : " << double(middle-start)/ CLOCKS_PER_SEC<<endl;
	cout<<"Decompress time: "<<double(end - start) / CLOCKS_PER_SEC;
	
	return 0;
}
