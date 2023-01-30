#include <bits/stdc++.h>
#include <windows.h> 

using namespace std;

int i_Sleep=1000;

void v_start_cmd()
{
	system("start Why.exe");
	Sleep(i_Sleep);
	if(i_Sleep>=100)
		i_Sleep-=50;
	return;
}

int main()
{
	system("start cmd.exe");
	
	for(int i=1;i<=10000;i++)
	{
		srand((unsigned)rand());
		int i_code=rand();
		switch(i_code%8)
		{
			case 0:
				printf("$");
				break;
			case 1:
				printf("?");
				break;
			case 2:
				printf("/");
				break;
			case 3:
				printf("\\");
				break;
			case 4:
				printf("*");
				break;
			case 5:
				printf("#");
				break;
			case 6:
				printf("%");
				break;
			case 7:
				printf(".");
				break;
		}
	}
	
	getchar();
	
	printf("Please input:\n");
	char c_ctrl[20];
	scanf("%s",c_ctrl);
	
	if(strcmp(c_ctrl,"file_recreate")==0)
	{
		FILE *Fp_file=fopen("Readme.txt","wt");
		fprintf(Fp_file,"Thank you for using.\nIt's just joking.");
		return 0;
	}
	else if(strcmp(c_ctrl,"why")==0)
	{
		return 0;
	}
	else
	{
		for(int i=1;i<=1000;i++)
			v_start_cmd();
	}
}

/*






*/
