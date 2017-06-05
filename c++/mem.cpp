/* memmove example */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define LOCALDNLMEDIUM  6
#define DOWNLOADFOLDER "/mnt/sdcard_dnl/GEN3_DOWNLOAD"

int main ()
{
	int iRetVal = -1;
	string line, bid, mscript;
	size_t pos;
	unsigned int i;
	char boardidfile[255] = "board-id/0x0000.txt";
	unsigned char searchCharacter[2] = "/";
	bool bIsCharFound;

	ifstream cmdlinefp;
	cmdlinefp.open("/home/dus5cob/test/cmdline",ios::in);
	if(cmdlinefp.is_open())
	{
		getline (cmdlinefp,line);
		pos = line.find("dnlid=");
		if(pos != std::string::npos)
		{
			bid=line.substr(pos + strlen("dnlid="),4);
			cout << "\n=====================================================\n";
			cout << "\tInitiate Download based on dnlid 0x" << bid <<'\n';
			cout << "=====================================================\n";
			snprintf(boardidfile,255,"%s/board-id/0x%s.txt", DOWNLOADFOLDER,bid.c_str() );
			cout << "\t" << bid.c_str() <<'\n';
			cout << "\t" << boardidfile <<'\n';
		}
		else
		{
			printf("Couldn't get board id\n");
			return -1;
		}

		cmdlinefp.close();
	}
#if 0
char str[] = "memmove can be very useful......";
memmove (str+20,str+15,11);
puts (str);
#endif
	
	snprintf(boardidfile,255,"board-id/0x%s.txt",bid.c_str());
	cout << "\tboardidfile : " << boardidfile <<'\n';
	do
	{
		bIsCharFound = false;
		for( i = 0; i < strlen(boardidfile); i++)
		{
			if (boardidfile[i] == searchCharacter[0])
			{
				printf("\ti = %d : boradfile lengeth = %ld\n", i, strlen(boardidfile)-1);
				memmove (boardidfile,boardidfile+i+1,strlen(boardidfile)-1);
				bIsCharFound = true;
				break;
			}
		}
	}while( true == bIsCharFound);
	cout << "\t" << boardidfile <<'\n';

  return 0;
}
