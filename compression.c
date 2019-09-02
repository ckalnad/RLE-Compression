#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) 
    {

    FILE *fpt1,*fpt2;
    char c,d,e,cc;
    fpt1=fopen(argv[1],"rb");
    int count=0,count1=0;
    int i=0,symcount=0;
    char *ch;
    int RLE;
	
    if (fpt1 == NULL)
    {
        printf("Cannot open file ");
        exit(0);
    }
 
    while((c=fgetc(fpt1))!=EOF)
    {
	//if(c!='\n')
	{
        	printf("%c",c);
		  count++;
	}
    }

    printf("\nCount=%d\n",count);
    rewind(fpt1);

//Compression code




unsigned char data[count-1];
while(i<count)
{
     while((cc=(unsigned char)fgetc(fpt1))!=EOF)
    {
	   //if(cc!='\n')
	   {
		data[i]=(unsigned char)cc;
		i++;
        count1++;
	   }
	
    }
    
}

//printf("Countif=%d\n",i);
printf("%s\n",data);

printf("Count=%d\n",count1);



rewind(fpt1);
    
    fpt2 = fopen("final.txt", "w");
    
    if (fpt2 == NULL)
    {
        printf("Cannot open file ");
        exit(0);
    }


    //int *text=(unsigned char *)calloc(fpt1,sizeof(unsigned char));

    int ii=0;
    unsigned char aa,bb;
    aa=data[ii];
    unsigned char countdata=1;
    unsigned char zero=0x00;
    unsigned char one=1;

    for(ii=0;ii<count;ii++)
    {
        bb=data[ii+1];
        cc=data[ii+2];
        /*if(aa==0)
        {   
            printf("%c",aa);
            //printf("0");
            fwrite(&aa,1,1,fpt2);
            fwrite(&zero,1,1,fpt2);
            aa=bb;
        }*/

        if(aa==bb)
        {

            if(countdata<255)
            {
                countdata++;
            }
            else
            {
                printf("%d%c",countdata,aa);
                fwrite(&countdata,1,1,fpt2);
                if(aa==0)
                {
                    fwrite(&zero,1,1,fpt2);        
                }
                else
                {
                    fwrite(&aa,1,1,fpt2);
                }
                countdata=1;
                aa=bb;
            }
        }


        else if(aa!=bb && bb!=cc)
        {
            //printf("insidediff");
            //printf("\t%c%c%c\t",aa,bb,cc);
            
            RLE=1;
            //printf("\t%c%c%c\t",aa,bb,cc);
            printf("%d%c",countdata,aa);
            printf("0");
            
            fwrite(&countdata,1,1,fpt2);
            if(aa==0)
                {
                    fwrite(&zero,1,1,fpt2);        
                }
                else
                {
                    fwrite(&aa,1,1,fpt2);
                }
            fwrite(&zero,1,1,fpt2);
            countdata=1;

            
            aa=bb;
            int differ = 1;
                    

            //printf("\t%c\t",aa);
            //printf("\t%c\t",bb);

            

            while(differ)
            {
                if((int)bb==0)
            {
                printf("010");
                fwrite(&zero,1,1,fpt2);
                fwrite(&one,1,1,fpt2);
                fwrite(&zero,1,1,fpt2);

            }

                //printf("inwhile");
                ii++;
                bb=data[ii+1];
                
                if(aa!=bb)
                {

                    printf("%c",aa);
                    if(aa==0)
                {
                    fwrite(&zero,1,1,fpt2);        
                }
                else
                {
                    fwrite(&aa,1,1,fpt2);
                }
                
                    aa=bb;

                    
                }
                else if(aa==bb)
                {
                    aa=bb;
                    differ=0;
                    printf("0");
                    
                    fwrite(&zero,1,1,fpt2);
                    
                    countdata=2;
                    RLE=0;
                }
            }

        }
       

        else
        {
        
            printf("%d%c",countdata,aa);

            fwrite(&countdata,1,1,fpt2);
            if(aa==0)
                {
                    fwrite(&zero,1,1,fpt2);        
                }
                else
                {
                    fwrite(&aa,1,1,fpt2);
                }
                aa = bb;
            countdata=1;    
        }


    }   
    
    printf("\n");

    printf("Contents copied to file\n ");
    fclose(fpt1);
    fclose(fpt2);

    return 0;

}

















