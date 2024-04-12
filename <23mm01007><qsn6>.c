#include<stdio.h>
#include<math.h>
struct sturec{
    char name[10];
    int rollno;
    float percentage;
};
void sortName(struct sturec* t,int e);
void findOne(struct sturec* u,int w);
void insert(struct sturec* a,int m);
void delete(struct sturec*a,int m);
void specs(struct sturec* a,int m);
void main(){
    int n;
    int choice;
    printf("\n Enter number of students:");
    scanf(" %d",&n);
    struct sturec s[n];//to store details of students
    struct sturec* p;
    p=s;
    //declares a pointer p of type sturec 
    // assigns it the address of the first element of the array s.
    
    int i,j;
    for(i=0;i<n;i++){
        printf("\n Details of %d student:",i+1);
        scanf(" %s %d %f",s[i].name,&s[i].rollno,&s[i].percentage);
    }
    printf("\n Enter the choice you want:");
    scanf(" %d",&choice);
    switch(choice){
    case 1:
    sortName(p,n);
    break;
    case 2:
    findOne(p,n);
    break;
    case 3:
    insert(p,n);
    break;
    case 4:
    delete(p,n);
    break;
    case 5:
    specs(p,n);
    break;
    default:
    printf("\n Wrong input:");
    break;
    }
}

void sortName(struct sturec *a,int m)//m-size of array
{
    int x,y;
    struct sturec temp[20];
    for(x=0;x<m;x++)
    {
    for(y=x;y<m;y++)
    {
        if((*(a+x)).name[0]>(*(a+y)).name[0])
        // checks if the first character of the name field of the current element
        // (a[x]) is greater than the first character of the name field of the next element (a[y]).
        {
            temp[x]=*(a+x);
            (*(a+x))=(*(a+y));
            (*(a+y))=temp[x];
        }
    }
    }
    for(x=0;x<m;x++)
    {
        printf("\n %s %d %f",(*(a+x)).name,(*(a+x)).rollno,(*(a+x)).percentage);
    }
}
void findOne(struct sturec *a,int m)
{
    int r;
    printf("\n Enter roll number to be found:");
    scanf(" %d",&r);
    int x,y;
    for(x=0;x<m;x++)
    {
        if((*(a+x)).rollno==r)
        {
            y=x;
            break;
        }
    }
    printf("\n Details are:");
    printf("\n %s   %d  %f",(*(a+y)).name,(*(a+y)).rollno,(*(a+y)).percentage);
}
void insert(struct sturec* a,int m){
    int x,y;
    struct sturec l[m+1],temp[20];
    printf("\n Enter Student details:");
    scanf(" %s %d %f",l[m].name,&l[m].rollno,&l[m].percentage);
    for(x=0;x<m;x++){
        l[x]=(*(a+x));
    }
        for(x=0;x<m+1;x++){
            for(y=x;y<m+1;y++){
                if(l[x].rollno>l[y].rollno){
                    temp[x]=l[x];
                    l[x]=l[y];
                    l[y]=temp[x];
                }
            }
        }
        for(x=0;x<m+1;x++){
            printf("\n %s   %d  %f",l[x].name,l[x].rollno,l[x].percentage);
        }
}
void delete(struct sturec*a,int m){
    int r;
    printf("\n Enter roll number to be deleted:");
    scanf(" %d",&r);
    int x,y;
    for(x=0;x<m;x++){
        if((*(a+x)).rollno==r){
            y=x;
            break;
        }
    }
    for(x=y;x<m-1;x++){
        (*(a+x))=(*(a+x+1));
    }
    for(x=0;x<m-1;x++){
        printf("\n %s   %d  %f",(*(a+x)).name,(*(a+x)).rollno,(*(a+x)).percentage);
    }
}
 void specs(struct sturec* a,int m){
    int x,sum=0;
    float sum1=0;
    float h[5];
    h[0]=m;
    h[1]=(*(a)).percentage;
    h[2]=(*(a)).percentage;
    for(x=0;x<m;x++){
        h[1]=(h[1]>(*(a+x)).percentage)?h[1]:(*(a+x)).percentage;
    }
      for(x=0;x<m;x++){
        h[2]=(h[2]<(*(a+x)).percentage)?h[2]:(*(a+x)).percentage;
    }
    for(x=0;x<m;x++){
        sum+=(*(a+x)).percentage;
    }
    h[3]=(sum/m);
    for(x=0;x<m;x++){
       
       sum1+=(*(a+x)).percentage * (*(a+x)).percentage;
    }
    h[4]=sqrt((sum1/m)-(h[3]*h[3]));
    for(x=0;x<5;x++){
        printf("\n %f",h[x]);
    }
}