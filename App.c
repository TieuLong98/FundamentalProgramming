#include <stdio.h>
#include <string.h>
//Store CSV in An Array of Structs
typedef struct
{
    char name[50];
    int born;
    char major[50];
    int numb;
}Character;
 
int main(void)
{
    int flag = 0;
    int check;
    char search[50];
    FILE  *file;
    file = fopen("C:/Users/admin/Desktop/FundamentalProgramming/Project.csv","r");

    if( file == NULL){
        printf("Error When Opening File!!\n");
        return 1;
    }

    Character nhanvat[100];
    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file,"%[^,],%d,%[^,],%d\n",
                        nhanvat[records].name,
                        &nhanvat[records].born,
                        nhanvat[records].major,
                        &nhanvat[records].numb);
        //if read == 4 that means it reachs all columns so row will increase continuously
        if(read == 4) records++;
        //Records is unlimited just satisfy the format of read is 4 variables above
        if(read != 4 && !feof(file))
        {
            printf("Format Is Incorrect!!\n");
            //Check fortmat
            printf("%d",read);
            return 1;
        }
        
        if(ferror(file))
        {
            printf("Error When Loading File!!\n");
            return 1;
        }

    }while(!feof(file));

    fclose(file);

    printf("Number of Characters is: %d\n",records);

    for(int i = 0; i < records; i++)
    {
        printf("%s %d %s %d\n",
                nhanvat[i].name,
                nhanvat[i].born,
                nhanvat[i].major,
                nhanvat[i].numb);
    }
    do
    {
        printf("\nPlease Input The Name to Search: ");
        scanf("%s",search);
        flag++;
        for(int i = 0; i < records; i++)
        {
            check = strcmp(search,nhanvat[i].name);
            if(check == 0 )
            {
                printf("Found!!!\n");
                printf("Name: %s \nBorn: %d \nMajor: %s \nNumb: %d\n",
                nhanvat[i].name,
                nhanvat[i].born,
                nhanvat[i].major,
                nhanvat[i].numb);
            }
  
        }
    }while(flag < 3);
    

    return 0;
}