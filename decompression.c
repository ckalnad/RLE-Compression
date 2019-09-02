#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) 

{

	FILE *fpt1,*fpt2;
	fpt1=fopen("final.txt","rb");
	fpt2=fopen(argv[1],"w");
	char cc,d,e;
	unsigned char c;
	
    
    int count=0,count1=0,ccc=0;
    int i=0,symcount=0;

	if (fpt1 == NULL)
    {
        printf("Cannot open file ");
        exit(0);
    }
 
    if (fpt2 == NULL)
    {
        printf("Cannot open file ");
        exit(0);
    }
 
 rewind(fpt1);

    while((ccc=fgetc(fpt1))!=EOF)
    {
	
	{
			//printf("Count=%d\n",count);
        	//printf("%c",(unsigned char)c);
			count++;

	}
    }

    printf("\nCount=%d\n",count);
    rewind(fpt1);

    unsigned char data[count-1];
	while(i<count)
	{
    	
    	{
		//if(cc!='\n')
			{
			cc=fgetc(fpt1);
			data[i]=(unsigned char)cc;
			//printf("\n");
			//printf("%c",data[i]);
			i++;

			}
	
    	}
    
	}


	int ii=0,jj=0,kk=0;
	int RLE=0;

	/*for(ii=0;ii<count;ii++)
	{
		printf("%c",data[ii]);
	}*/
	//printf("\n");

	if(data[0]==0)
	{
		RLE=0;
	}
	else
	{
		RLE=1;
	}


	for(jj=0;jj<count;jj++)
	{
		if(RLE==1)
		{
			//printf("insiderepif");
			//printf("data=%c",(unsigned char)data[jj]);
			for(kk=0;kk<data[jj];kk++)
			{
				//printf("insiderepfor");
				printf("%c",data[jj+1]);
				fwrite(&data[jj+1],1,1,fpt2);
				
			}
			jj=jj+1;
			
			if(data[jj+1]==0)
			{
				RLE=!RLE;
			}
			else
			{
				RLE=RLE;
			}

		}
	

		
		else if(RLE==0)
		{
			while(!RLE)
			{
				jj++;
				printf("%c",data[jj]);
				fwrite(&data[jj],1,1,fpt2);
				if(data[jj+1]==0)
				{
					RLE=!RLE;
				}
				else
				{
					RLE=RLE;
				}
			
			}
			jj++;
		}
	}
			
fclose(fpt1);
fclose(fpt2);
	

	return 0;
}
