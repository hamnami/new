#include<stdio.h>
void mergeArray(int arr1[],int size1,int arr2[],int size2,int result[])
{
 int i=0,j=0,k=0;
 while(i<size1&&j<size2)
{
 if(arr1[i]<arr2[j])
{
 result[k]=arr2[j];
 j++;
 }
 k++;
 }
 while(i<size1)
{
 result[k]=arr1[i];
 i++;
 k++;
}
 while(j<size2)
 {
  result[k]=arr2[j];
 j++;
 k++;
}
}
int main()
{
 int arr1[]={1,3,5,7};
 int size1=4;
 int arr2[]={2,4,6,8};
 int size2=4;
 int result[8];
 mergeArray(arr1,size1,arr2,size2,result);
 printf("Merged Array:");
 for(int i=0;i<size1+size2;i++)
{
printf("%d",result[i]);
}
return 0;
}
