// Names: , Objective
//Jon Marc Jackson (2106386), 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define MAXSIZE 70 
struct FLname // structure to store participant's name
{
	char F_name[MAX]; //First Name
	char L_name[MAX]; // Last Name
};
struct Date //structure to store Date of Birth for participant
{
	int day; // Day 
	int month; // month 
	int year; // year
};
struct P_scores //structure to store scores and times for each competition
{  
    int T1score;
    int T2score;
    int Swimscore;
    int Cyclescore;
    int Runscore; 
    int Overallscore; 
    int Triathletetime; 
    int T1; 
    int T2; 
    int Swimtime; 
    int Cycletime; 
    int Runtime;
};
typedef struct PData // data for participant
{
	struct FLname Name;
	int age;
	struct Date DOB;
	int Id_num;
	char school[MAXSIZE];
	char gender[8];// Gender eg. Male
    char Event_type[MAXSIZE];
    struct P_scores Scores;
}participant;

//functions
void create();
void search();
void report();
void update();
void display_besttimes_s();
void display_besttimes_r();
void display_besttimes_t1();
void display_besttimes_c();
void display_besttimes_t2();

void display_besttimes_s_2();
void display_besttimes_r_2();
void display_besttimes_t1_2();
void display_besttimes_c_1();
void display_besttimes_t2_2();

void display_besttimes_s_3();
void display_besttimes_r_3();
void display_besttimes_t1_3();
void display_besttimes_c_3();
void display_besttimes_t2_3();
int size; //global variable

int main(){
    int choice;
    do{
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("                                        | Welcome to the JaTSo Login Station |\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n1.REGISTER PARTICIPANT");
        printf("\n2.DISPLAY PARTICIPANTS INFORMATION");
        printf("\n3.ENTER TIMES");
        printf("\n4.VIEW BEST TIMES");
        printf("\n5.OVERALL REPORT");
        printf("\n0.EXIT");
        printf("\nPLEASE ENTER CHOICE:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                create(); //registering participants
                break;            
            case 2:
                search(); //searching for a participant
                break;
            case 3:
                update(); //to add times for each participant
                break;
            case 4:
             //printing besttimes for each event in each competition
                display_besttimes_s();
                printf("\n");
                display_besttimes_r();
                printf("\n");
                display_besttimes_t1();
                printf("\n");
                display_besttimes_c();
                printf("\n");
                display_besttimes_t2();
                printf("\n");
                display_besttimes_s_2();
                printf("\n");
                display_besttimes_r_2();
                printf("\n");
                display_besttimes_t1_2();
                printf("\n");
                display_besttimes_c_1();
                printf("\n");
                display_besttimes_t2_2();
                printf("\n");
                display_besttimes_s_3();
                printf("\n");
                display_besttimes_r_3();
                printf("\n");
                display_besttimes_t1_3();
                printf("\n");
                display_besttimes_c_3();
                printf("\n");
                display_besttimes_t2_3();
                printf("\n");
                
                break;
            case 5:
                report();
                break;
        }
    }while(choice!=0);
    return 0;

}
void create(){//registering participant
    participant *participants;//pointer
    int i;
    FILE *fp;
    printf("\nPlease enter number of participants: ");
    scanf("%d", &size); 
    participants = (participant*)calloc(size, sizeof(participant)); //allocating memory to pointer
    
    fp=fopen("Participants.txt", "w"); //creating file
    
    for (i = 0; i < size; ++i){        
        printf("\n\nEnter the name of the participant:\t\t\t|\t");
        scanf("%15s %15s",participants[i].Name.F_name, participants[i].Name.L_name);
                
        do{// loop to determine if the participant is eligible
            printf("Enter the age of the participant:\t\t\t|\t");
            scanf("%d", &participants[i].age);
            if (participants[i].age<6)
                printf("You are too young. You must be 6-15\n");
            
            if (participants[i].age>15){
                printf("You are too old. You must be 6-15\n");
            }            
        }while(participants[i].age<6 || participants[i].age>15);

		printf("Enter the Gender of the participant:\t\t\t|\t");
		scanf("%s", participants[i].gender);		
		printf("Enter the date of birth of the participant(dd mm yyyy):\t|\t");
		scanf("%d %d %d", &participants[i].DOB.day, &participants[i].DOB.month, &participants[i].DOB.year);
		printf("Enter the school of the participant:\t\t\t|\t");
		scanf("%s", participants[i].school);
		printf("Enter the participant's ID:\t\t\t\t|\t");
		scanf("%d", &participants[i].Id_num);
                
        // determining what competetion the participant will be invloved in
        if(participants[i].age>=6 && participants[i].age<=8){
            char temp[] = "Kids of Steel";
	        strcpy(participants[i].Event_type, temp);
            printf("The Event type the participant will be entering is:\t|\tKids of Steel");
        }
        if(participants[i].age>=9 && participants[i].age<=11){
            char temp[] = "Iron Kids";
            strcpy(participants[i].Event_type, temp);
            printf("The Event type the participant will be entering is:\t|\tIron Kids");
        }
        if(participants[i].age>=12 && participants[i].age<=15){
            char temp[] = "Cast Iron Kids"; 
            strcpy(participants[i].Event_type, temp);
            printf("The Event type the participant will be entering is:\t|\tCast Iron Kids");
        }
        fwrite(&participants[i], sizeof(participant),1,fp); //writing information to the file
    } 
    fclose(fp); 
}
void search(){ //searching for particpant to see their information
    participant p2;
    FILE *fp;
    int n, found=0;
    fp=fopen("Participants.txt", "r");
    printf("\nEnter id number to search:");
    scanf("%d",&n);
    while(fread(&p2,sizeof(participant),1,fp)){
        if(p2.Id_num == n){
            found=1;
            printf("\n------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n-------------------------------------------------------| Participants information |-------------------------------------------------------------\n");
            printf("The participant's name is:\t\t|\t %s %s\n",p2.Name.F_name, p2.Name.L_name);
            printf("The participant's age is:\t\t|\t %d\n",p2.age);
            printf("The participant's birthday is:\t\t|\t %d/%d/%d\n",p2.DOB.day,p2.DOB.month,p2.DOB.year);
            printf("The participant's gender is:\t\t|\t %s\n",p2.gender);
            printf("The participant's school is:\t\t|\t %s\n",p2.school);
            printf("The participant's ID is:\t\t|\t %d\n",p2.Id_num);
            printf("The participant's event type is:\t|\t %s\n",p2.Event_type);                       
        }
        if(!found)
            printf("\nParticipant not found");
    }
    fclose(fp);        
}

void display_besttimes_s(){ //displaying best times for swimming in Kids of Steel
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Swimscore < p[a].Scores.Swimscore && p[i].Event_type==*temp1){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for swimmming is %s %s with a score of %d points",*temp1,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Swimscore);
    } 
    fclose(fp);
}
void display_besttimes_r(){ //displaying best times for running in Kids of Steel
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Runscore < p[a].Scores.Runscore && p[i].Event_type==*temp1){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for running is %s %s with a score of %d points",*temp1,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Runscore);
    } 
    fclose(fp);
}
void display_besttimes_t1(){ //displaying best times for Transition 1 in Kids of Steel
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.T1 < p[a].Scores.T1 && p[i].Event_type==*temp1){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for T1 is %s %s with a score of %d points",*temp1,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.T1score);    
    } 
    fclose(fp);
} 
void display_besttimes_t2(){
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.T2score < p[a].Scores.T2score && p[i].Event_type==*temp1){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for T2 is %s %s with a score of %d points",*temp1,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.T2score);
        
    }
    fclose(fp);
}
void display_besttimes_c(){ //displaying best times for cycling in Kids of Steel
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Cyclescore < p[a].Scores.Cyclescore && p[i].Event_type==*temp1){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for cycling is %s %s with a score of %d points",*temp1,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Cyclescore);
        
    }
    fclose(fp);
}

void display_besttimes_s_2(){ //displaying best times in swimming for iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Swimscore < p[a].Scores.Swimscore && p[i].Event_type==*temp2){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for swimmming is %s %s with a score of %d points",*temp2,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Swimscore);
    } 
    fclose(fp);
}
void display_besttimes_r_2(){ // displaying best times in running for iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Runscore < p[a].Scores.Runscore && p[i].Event_type==*temp2){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for running is %s %s with a score of %d points",*temp2,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Runscore);
    } 
    fclose(fp);
}
void display_besttimes_t1_2(){ // displaying best times in Transition 1 for iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.T1 < p[a].Scores.T1 && p[i].Event_type==*temp2){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for T1 is %s %s with a score of %d points",*temp2,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.T1score);    
    } 
    fclose(fp);
} 
void display_besttimes_t2_2(){ // displaying best times in transition 2 for iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.T2score < p[a].Scores.T2score && p[i].Event_type==*temp2){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for T2 is %s %s with a score of %d points",*temp2,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.T2score);
        
    }
    fclose(fp);
}
void display_besttimes_c_1(){ // displaying best times in cycling for iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Cyclescore < p[a].Scores.Cyclescore && p[i].Event_type==*temp2){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for cycling is %s %s with a score of %d points",*temp2,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Cyclescore);
        
    }
    fclose(fp);
}
void display_besttimes_s_3(){ // displaying best times in swimming for cast iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Swimscore < p[a].Scores.Swimscore && p[i].Event_type==*temp3){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for swimmming is %s %s with a score of %d points",*temp3,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Swimscore);
    } 
    fclose(fp);
}
void display_besttimes_r_3(){ // // displaying best times in running for cast iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Runscore < p[a].Scores.Runscore && p[i].Event_type==*temp2){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for running is %s %s with a score of %d points",*temp3,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Runscore);
    } 
    fclose(fp);
}
void display_besttimes_t1_3(){ // displaying best times in transition 1 for cast iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.T1 < p[a].Scores.T1 && p[i].Event_type==*temp3){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for T1 is %s %s with a score of %d points",*temp3,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.T1score);    
    } 
    fclose(fp);
} 
void display_besttimes_t2_3(){ // displaying best times in transition 2 for cast iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.T2score < p[a].Scores.T2score && p[i].Event_type==*temp3){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for T2 is %s %s with a score of %d points",*temp3,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.T2score);
        
    }
    fclose(fp);
}
void display_besttimes_c_3(){ // displaying best times in cycling for cast iron Kids
    int choice1, found=0;
    char *temp1[]={"Kids of Steel"};
    char *temp2[]={"Iron Kids"};
    char *temp3[]={"Cast Iron Kids"};
    participant *p, p1;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(participant);
    p = (participant*)calloc(n,sizeof(participant));
    rewind(fp);
    for (int i = 0; i < n; i++){
        fread(&p[i],sizeof(participant),1,fp);
    }
    for (int i = 0; i < n; i++){
        for (int a = 0; a < n; a++){
            if(p[i].Scores.Cyclescore < p[a].Scores.Cyclescore && p[i].Event_type==*temp2){
                p1=p[i];
                p[i]=p[a];
                p[a]=p1;
            }                      
        }
    }
    for (int i = 0; i < n; i++){
        printf("\nIn %s the participant with the best times for cycling is %s %s with a score of %d points",*temp3,p[i].Name.F_name, p[i].Name.L_name,p[i].Scores.Cyclescore);
        
    }
    fclose(fp);
}
void report(){ //overall report
    participant p4;
    FILE *fp;
    fp=fopen("Participants.txt", "r");
    while(fread(&p4,sizeof(participant),1,fp)){
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n-------------------------------------------------------| Overall Information |-------------------------------------------------------------\n");
        printf("The participant's id is:\t\t\t\t|\t %d\n",p4.Id_num);
        printf("The participant's school is:\t\t\t\t|\t %s\n",p4.school);
        printf("The participant's name is:\t\t\t\t|\t %s %s\n",p4.Name.F_name, p4.Name.L_name);
        printf("The participant's swim time is:\t\t\t\t|\t %d with a score of %d\n",p4.Scores.Swimtime, p4.Scores.Swimscore);
        printf("The participant's first transition time is :\t\t|\t %d with a score of %d\n",p4.Scores.T1, p4.Scores.T1score);
        printf("The participant's cycling time is:\t\t\t|\t %d with a score of %d\n",p4.Scores.Cycletime, p4.Scores.Cyclescore);
        printf("The participant's second transition time is:\t\t|\t %d with a score of %d\n",p4.Scores.T2, p4.Scores.T2score);
        printf("The participant's running time is:\t\t\t|\t %d with a score of %d\n",p4.Scores.Runtime, p4.Scores.Runscore);
        printf("The participant's overall time is:\t\t\t|\t %d with a score of %d\n",p4.Scores.Triathletetime,p4.Scores.Overallscore);
    } 
    fclose(fp);        
}
void update(){//adding participants time to existing information
    participant p1;
    FILE *fp, *fp1;
    int n, found=0;
    p1.Scores.Swimscore=0;
    p1.Scores.Cyclescore=0;
    p1.Scores.Runscore=0;
    p1.Scores.T1score=0;
    p1.Scores.T2score=0;
    p1.Scores.Triathletetime=0;
    p1.Scores.Overallscore=0;
    fp=fopen("Participants.txt", "r");
    fp1=fopen("Temp.txt", "w");
    printf("\nEnter id number to add participants times:");
    scanf("%d",&n);
    while(fread(&p1,sizeof(participant),1,fp)){
        if(p1.Id_num == n){
            found=1;
            //asking for information if participant is found
            printf("\nPlease enter in seconds for the times!");
            printf("\nEnter the swimming time: ");
            scanf("%d", &p1.Scores.Swimtime);
            printf("Enter the first transition time: ");
            scanf("%d", &p1.Scores.T1);
            printf("Enter the cycling time: ");
            scanf("%d", &p1.Scores.Cycletime);
            printf("Enter the second transition time: ");
            scanf("%d", &p1.Scores.T2);
            printf("Enter the running time: ");
            scanf("%d", &p1.Scores.Runtime);     

            //calculating scores
            p1.Scores.Swimscore = (p1.Scores.Swimtime * 2);
            p1.Scores.Cyclescore = (p1.Scores.Cycletime * 2);
            p1.Scores.Runscore = (p1.Scores.Runtime * 2);
            p1.Scores.T1score = (p1.Scores.T1 * 2);
            p1.Scores.T2score = (p1.Scores.T2 * 2);        
 		    p1.Scores.Overallscore = (p1.Scores.Swimscore + p1.Scores.Cyclescore + p1.Scores.Runscore + p1.Scores.T1score + p1.Scores.T2score); 	    
            p1.Scores.Triathletetime =(p1.Scores.Swimtime+ p1.Scores.Runtime+ p1.Scores.Cycletime+ p1.Scores.T1+ p1.Scores.T2);
            fwrite(&p1, sizeof(participant),1,fp1);
        }
        fclose(fp);
        fclose(fp1); 
        if(found){
            // if found file is updated
            fp1=fopen("Temp.txt", "r");
            fp=fopen("Participants.txt", "w");
                while(fread(&p1, sizeof(participant),1,fp1)){
                    fwrite(&p1,sizeof(participant),1,fp);
                }
            fclose(fp);
            fclose(fp1);
        }
        if(!found)
            printf("\nParticipant not found");
    }
    fclose(fp);
}
