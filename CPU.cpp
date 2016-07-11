#include <string>
#include<time.h>
#include<fstream>
#include "CPU.h"



string decode(Nod* root, string encoded_str)
{
    string res = "";
    Nod* Nod = root;
    for (int i = 0; i != encoded_str.size(); ++i)
    {
        if (encoded_str[i] == '0') { 
            Nod = Nod->left;
        } else { 
            Nod = Nod->right;
        }
        if (itIsLeaf(Nod))
        {
            res += Nod->c;
            Nod = root;
        }
    }
	return res;
}


myStrs decom(myStrs encode, HuffmanTable* myStr,int myStrSize,myStrs binary, int fs)
{
	int o;
	
    myStrs out;
	out.ch=(char*)malloc(sizeof(char)*fs*2);
	binary.ch=(char*)malloc(sizeof(char)*fs*8*2);
		
	for(int i=0;i<=encode.length ;i++)
		{

			if(i==encode.length){
			switch(encode.position)
			{
				case 1:
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
					binary.length++;
				break;

				case 2:
					binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
					binary.length++;
				break;

				case 3:
					binary.ch[binary.length] = (encode.ch[i] & 0x04) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
					binary.length++;
					break;

				case 4:
					binary.ch[binary.length] = (encode.ch[i] & 0x08) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x04) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
					binary.length++;
					break;

				case 5:
					binary.ch[binary.length] = (encode.ch[i] & 0x10) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x08) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x04) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
					binary.length++;
					break;

				case 6:
					binary.ch[binary.length] = (encode.ch[i] & 0x20) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x10) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x08) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x04) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
					binary.length++;
					break;

				case 7:
					binary.ch[binary.length] = (encode.ch[i] & 0x40) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x20) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x10) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x08) ? 1:0; 
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x04) ? 1:0; 
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0; 
					binary.length++;
					break;

				case 8:
					binary.ch[binary.length] = (encode.ch[i] & 0x80) ? 1:0; 
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x40) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x20) ? 1:0; 
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x10) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x08) ? 1:0; 
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x04) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
					binary.length++;
					binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
					binary.length++;
					break;

				default: break;
			  }
			break;
		}

			binary.ch[binary.length] = (encode.ch[i] & 0x80) ? 1:0;
			binary.length++;
			binary.ch[binary.length] = (encode.ch[i] & 0x40) ? 1:0;
			binary.length++;
			binary.ch[binary.length] = (encode.ch[i] & 0x20) ? 1:0;
			binary.length++;
			binary.ch[binary.length] = (encode.ch[i] & 0x10) ? 1:0;
			binary.length++;
			binary.ch[binary.length] = (encode.ch[i] & 0x08) ? 1:0;
			binary.length++;
			binary.ch[binary.length] = (encode.ch[i] & 0x04) ? 1:0;
			binary.length++;
			binary.ch[binary.length] = (encode.ch[i] & 0x02) ? 1:0;
			binary.length++;
			binary.ch[binary.length] = (encode.ch[i] & 0x01) ? 1:0;
			binary.length++;
				
	}
		  
	int k,j,e=0;
	for (int i=0; i<binary.length; i++)
	{
		for(k=0;k<myStrSize;k++)
			for( j=0;j<myStr[k].len;j++)
			{
				if (myStr[k].code[j] == binary.ch[i+j])
				{
					e++;
				}
	
				if(e == myStr[k].len)
				{
					out.ch[out.length]=myStr[k].c;
					out.length++;  
					i+=j;
					goto jump;
				}
				
				if(j == myStr[k].len-1) 
					e=0;
			}
			jump: e=0;
		}
	return out;
}


int startCPUCompression(const char* inputFileName, const char* outputFileName)
{
  int filesize =0;
  FILE *f = fopen(inputFileName, "rb");
  if(f == NULL) printf("Failed");
  string input;
  clock_t st = clock();

   if(f)
   {	  
	  fseek(f, 0, SEEK_END);
	  filesize = ftell(f);
	  printf("-----------------------------------------------------------------------------------------\nfile size is: %d \n\n", filesize);
	  input.resize(ftell(f));
	  rewind(f);
	  fread(&input[0],1,input.size(),f);
	  fclose(f); 
   }

	std::map<char, int> mymap;
	std::map<char,int>::iterator it;
	
	for (std::string::const_iterator i=input.cbegin(); i!=input.cend(); ++i)
	{
		it = mymap.find(*i);
		if(it != mymap.end())
		{
			it->second++;
		}else 
			mymap.insert(std::pair<char,int>(*i,1));
	}

	clock_t end_histogram = clock();

	char cha[256]; int cha_fq[256];

	int itdx = 0;

	for (std::map<char,int>::const_iterator ip=mymap.cbegin(); ip!=mymap.cend(); ++ip)
	{
		cha[itdx] =  ip->first;
		cha_fq[itdx] =ip->second;
		itdx++;
	}

	buildTable(cha,cha_fq,itdx);
    Nod * root = myPQueue.top();
    myPQueue.pop();
	int arrs[256], top = 0;
	Codes(root, arrs, top);

	clock_t end_build = clock();

	myStrs strs;
	int o=0;

	strs.ch=(char*) malloc(input.size());

	for (std::string::const_iterator i=input.cbegin(); i!=input.cend(); ++i)
	{
		for(int j = 0; j< myIndx; j++)
		{
			if(*i == huffmanTable[j].c)
				{
					
					for(int k=0;k< huffmanTable[j].len;k++)
					{
	
						if(strs.position ==8)
						{
							o++;
							strs.position =0;
							strs.length++;
							strs.ch[o]  = (strs.ch[o]  << 1) | huffmanTable[j].code[k];
							strs.position++;
						}else{
							strs.ch[o]  = (strs.ch[o]  << 1) | huffmanTable[j].code[k];
							strs.position++;
						}
					}
					break;
			}
		}
	}

	clock_t end_encode = clock();
	FILE *outputencode = fopen(outputFileName,"wb");

	fprintf(outputencode,"%d\n%d\n",filesize,myIndx);

	for(int i=0;i<myIndx;i++)
		fprintf(outputencode,"%d %d\n",cha[i],cha_fq[i]);

	fprintf(outputencode,"%d %d\n",strs.length,strs.position);
	if(strs.ch!=NULL)			
			fwrite(strs.ch, strs.length+1, 1, outputencode);

	fclose(outputencode);
	clock_t end_compression = clock();


	cout<<"Finish reading and bulding : " << double(end_build-st)/ CLOCKS_PER_SEC<<endl;
	cout<<"End compression IS : " << double(end_encode-st)/ CLOCKS_PER_SEC<<endl;
	cout<<"All encoding IS : " << double(end_compression-st)/ CLOCKS_PER_SEC<<endl;

	return 0;
}

extern int startCPUDecompression(const char* inputFileName, const char* outputFileName)
{
	clock_t start_dec = clock();
	myStrs s;
	FILE *inEncode;

	int ssizeOfTable =0;char chs[256]; int chs_fq[256];

	inEncode = fopen(inputFileName,"rb");

	int flSize = 0;

	if(inEncode == NULL)
		printf("FAIK");

	fscanf(inEncode,"%d\n",&flSize);
	printf("flSize: %d\n",flSize);

	fscanf(inEncode,"%d\n",&ssizeOfTable);
	printf("ssizeOfTable: %d\n",ssizeOfTable);

	printf("TABLE:\n");
	
	for(int i = 0 ; i< ssizeOfTable;i++)
	{
		fscanf(inEncode,"%d %d\n",&chs[i],&chs_fq[i]);
		printf("%c %d\n",chs[i],chs_fq[i]);
	}
	
	buildTable(chs,chs_fq,ssizeOfTable);
    Nod * roos = myPQueue.top();
    myPQueue.pop();
	int art[256], htop = 0;
	Codes(roos, art, htop);
	
	fscanf(inEncode,"%d %d\n",&s.length,&s.position);	
	printf("POS AND LENT : %d %d\n",s.length,s.position);
	
	s.ch = (char*) malloc(sizeof(char)*s.length+1);
	fread(s.ch, s.length+1, 1,inEncode );
	
	clock_t middle = clock();
	myStrs out,binary;
	out = decom(s,huffmanTable,myIndx,binary,flSize);
	
	ofstream m(outputFileName, ios::binary);
	
	for(int p = 0; p<out.length;p++)
		m<<out.ch[p];
	clock_t en = clock();

	cout<<"Middle : " << double(middle-start_dec)/ CLOCKS_PER_SEC<<endl;
	cout<<endl<<"Decompress: " << double(en-start_dec)/ CLOCKS_PER_SEC<<endl;
	
	return 0;

}