#include <stdio.h>
int main(){
	char ch[100],len,i,j;
	printf ("please enter a sentence: ");
	gets(ch);
	len=strlen(ch);

	//printf("%d",len);
	//printf("s:%s\n",ch);
	for(i=len-1;i>=0;i--)
	{
        //printf("%d:%c\n",i,ch[i]);
	   if(ch[i]==' ')
	   {

	   	for(j=i+1;j<len;j++){
	   		printf("%c",ch[j]);
		   }
		   printf(" ");
		   i--;
		   len = i+1;

	   }
	   if(i==0){
	   	for(j=0;j<len;j++){
	   		printf("%c",ch[j]);
		   }
		   printf("\n");
	   }
	}

}
