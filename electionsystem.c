#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int n,d,vd,i,z;
int vid[100];
struct voterin
{
    char name[30];
    char gender[10];
    int mobno;
    int age;
    char dob[10];
};
typedef struct voterin Voterin;
struct voter
{
    Voterin info;
    struct voter *next;
};
typedef struct voter *Voter;
struct candi
{
   char cname[20];
   int srno;
   char partyname[60];
   struct candi *next;
};
typedef struct candi *Candi;
void voterdb(Voter ward[],int i)
{
    printf("Enter the number of voters in WARD\n");
    scanf("%d",&z);
    while(z--)
   { 
        Voter temp,temp1;
        printf("Enter the voter details in the order NAME,DATE OF BIRTH,AGE,GENDER,MOBILE NUMBER,VOTER ID%d:\n",z+1);
        Voterin x;
        scanf("%s%s%d%s%d",x.name,x.dob,&x.age,x.gender,&x.mobno);
        printf("ENTER VOTER ID OF VOTERS");
   
       scanf("%d",&vid[z]);
   

        if(ward[i]==NULL)
        {
            temp=(Voter)malloc(sizeof(struct voter));
            temp->info=x;
            ward[i]=temp;
            ward[i]->next=NULL;
        }
        else
        {
            temp1=ward[i];
            while (temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            temp=(Voter)malloc(sizeof(struct voter));
            temp->info=x;
            temp1->next=temp;
            temp->next=NULL;
        }
   }
}  

void swap(struct candi *a,struct candi *b)
{
	int prt;
	prt=a->srno;
	a->srno=b->srno;
	b->srno=prt;
}
void bubblesort(Candi poli)
{
	int flg,i;
    Candi cur,cur1;
	if(poli==NULL)
	return;
	do
	{
		flg=0;
		cur=poli;
        cur1=cur->next;
		while(cur1->next!=NULL)
		{
			if(cur->srno>cur->next->srno)
			{
				swap(cur,cur->next);
				flg=1;
			}
			cur=cur->next;
		}
		cur1=cur;
	}
	while(flg);	
}
void Votecount(int count[],int voterch)
{
    int i;
    for ( i = 1; i <=d ; i++)
    {
        if(count[i]==voterch)
        {
            count[i]++;
        }
    } 
}
int winner(int count[])
{
    int fh,sh,tmp,i;
    fh=count[1];
    sh=count[2];
    if (fh<sh)
    {
        tmp=fh;
        fh=sh;
        sh=tmp;
    }
    for (i = 3; i < d; i++)
    {
        if (count[i]>fh)
        {
            fh=count[i];
        }
        
    }
    for ( i = 1; i < d; i++)
    {
        if (count[i]==fh)
        {
            return i;
        }
        
    }
    
}
int main(int argc, char const *argv[])
{
    int n,i,j,p,ru=0,nota=0,flag=0,voteid;
    printf("---------WELCOME TO THE ELECTION COMMISSION OF INDIA----------\n\n\n\n");
    printf("-----Welcome To the Voters Registration-----\n\n");
    printf("Enter the number of wards\n");
    scanf("%d",&n);
    p=n;
    Voter ward[n];
    for (j = 0; j < n; j++)
    {
        ward[j]=(Voter)malloc(sizeof(struct voter));
        ward[j]=NULL;
        printf("Enter Ward number %d Voter details\n",j+1);
        voterdb(ward,j);
    }
    printf("VOTER DATABASE\n\n\n");
    Voterin x;
    

    for ( i = 0; i < n; i++)
    {
        printf("WARD NUMBER %d\n",i+1);
        Voter temp;
        temp=ward[i];
        while (temp!=NULL)
        {
            x=temp->info;
            printf("%s\t%s\t%d\t%s\t%d\t\n",x.name,x.dob,x.age,x.gender,x.mobno);
            temp=temp->next;
            ru++;
        }
    }
   
    printf("Confirm end of voter's list\n");
    char cnf[5];
    scanf("%s",cnf);
    if(cnf=="Yes"||cnf=="yes"||cnf=="YES"||cnf=="s"||cnf=="S")
    {
        //system("cls");
    }
    printf("\n\n\n\t\t\t\t\t\t\t\tCANDIDATE DETAILS\n\n\n");
    int c,k;
    printf("Enter the number of candidates\n");
    scanf("%d",&c);
    d=c;
    int count[c];
    Candi poli[c],cur,cur2,cur1;
    printf("%d\n",c);
    for(i=1;i<=c;i++)
    {
        poli[i]=(Candi)malloc(sizeof(struct candi));
        //printf("HI\n");
        printf("ENTER THE CANDIDATE PARTY NAME,SERIAL NUMBER,CANDIDATE NAME\n\n");
        scanf("%s%d%s",poli[i]->partyname,&poli[i]->srno,poli[i]->cname);
    }
    for(k=1;k<=d;k++)
    {
        count[k]=0;
    }
    //bubblesort(poli);
    printf("\n\n\nTHE ELECTION CANDIDATES\n\n");
    for ( i = 1; i <= d; i++)
    {
        printf("%s\t%d\t%s\n",poli[i]->partyname,poli[i]->srno,poli[i]->cname);
    }
    
    
    while(ru--)
    {
        printf("\n\nWELCOME TO GENERAL ELECTIONS\n\n");
        printf("Enter your ward number\n");
        scanf("%d",&vd);
        printf("To Cast Your Vote Please Enter Your Voter Id\n\n");
       
        scanf("%d",&voteid);
        for ( i = 0; i < 100; i++)
        {
            if (voteid==vid[i])
            {
                printf("Your are eligible to vote\n");
                printf("Please proceed forward to cast your vote\n");
                flag=1;
            }
            
        }
        if (flag==0)
        {
            printf("NOT ELIGIBLE TO VOTE\n\n");
            break;
        }
        
        printf("\n\n\nTHE ELECTION CANDIDATES\n\n");
        for ( i = 1; i <= d; i++)
        {
            printf("%s\t%d\t%s\n",poli[i]->partyname,poli[i]->srno,poli[i]->cname);
        }
        
        printf("IMPORTANT  NOTE TO CAST YOUR VOTE TO NOTA(NONE OF THE ABOVE) PLEASE ENTER SERIAL NUMBER\nAS %d\n",d+1);
        int voterch;
        printf("\n\nEnter The Serial Number Of The Candidate You Like To Cast Your Vote To\n\n");
        scanf("%d",&voterch);
        if (voterch==d+1)
        {
            nota++;
        }
        else
        {
            Votecount(count,voterch);   
        }
    }
    printf("\n\nTHE MAXIMUM NUMBER OF VOTES TO BE CASTED HAVE BEEN CASTED\n\n");
    printf("THIS ENDS THE VOTING PROCESS\nPLEASE WAIT FOR THE RESULTS TO BE ANNOUNCED\n");
    int win;
    win=winner(count);
    
    for ( i = 1; i <= d; i++)
    {
        if (poli[i]->srno==win)
        {
            printf("The winner of the election is \n");
             printf("%s\t%d\t%s\n",poli[i]->partyname,poli[i]->srno,poli[i]->cname);
        
        }
        
    }
    return 0;
    
}
