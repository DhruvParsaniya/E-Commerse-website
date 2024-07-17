#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp = fopen("p9.txt", "r");
    if (fp == NULL)
    {
        printf("File not opened\n");
    }
    else
    {
        printf("File Opened Successfully\n");
    }
    int n;
    fscanf(fp, "%d", &n);
    int len;
    fscanf(fp, "%d", &len);
    int width;
    fscanf(fp,"%d",&width);
    int arr[len];
    for(int i=0;i<n;i++)
    {
        fscanf(fp," %d", &arr[i]);
    }
    int time=0;
    printf("---------------------------------------------\n");
    printf("\t\t1.FCFS\n\t\t2.SCAN\n\t\t3.C-SCAN\n");
    printf("---------------------------------------------");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
    printf("FCFS\n");
    int l=n-arr[0];
    time=abs(l);
    for(int i=0;i<len-1;i++)
    {
        time+=abs(arr[i]-arr[i+1]);
    }
    printf("Seek time  %d \n",time);
    }
    else if(choice==2)
    {
        printf("SCAN\n");
        int dir;
        printf("Please tell which direction to be followed 0 for left and 1 for right\n");
        scanf("%d",&dir);
        int min=10000;
        int max=0;
        for(int i=0;i<len;i++)
        {
            if(min>arr[i])min=arr[i];
            if(max<arr[i])max=arr[i];
        }
        if(dir==0)
        {
            time=n+max;
        }
        else
        {
            time=width-n+width-min;
        }
        printf("Seek time %d",time);
    }
    else
    {
        printf("C-SCAN\n");
        int dir;
        printf("Please tell which direction to be followed 0 for left and 1 for right\n");
        scanf("%d",&dir);
        for (int i=0; i<len-1; i++){
              for (int j=i+1; j<len; j++){
                 if (arr[i] > arr[j]){
                   int t=arr[i];
                   arr[i] = arr[j];
                   arr[j] = t;
                 }
            }
        }
        int min=0;
        int max=0;
        for(int i=0;i<len-1;i++)
        {
            if(arr[i]<n && arr[i+1]>n)
            {
                min=arr[i];
                max=arr[i+1];
                break;
            }
        }
        if(dir==0)
        {
            time+=(n+2*width-max);
        }
        else
        {
            time+=(2*width-n+min);
        }
        printf("Seek time %d",time);
    }
    return 0;
}
