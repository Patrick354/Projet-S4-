#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"
#include "calcul.h"
#include "split.h"
#include "build_tree.h" 

int main()
{
    char* mat[12][3] = {
        {"Not Guessed","Missed","Correct"},
        {"Guessed","Not Missed","Correct"},
        {"Not Guessed", "Not Missed", "Correct"},
        {"Not Guessed","Missed","Correct"},
        {"Not Guessed","Not Missed","Correct"},
        {"Guessed","Not Missed","Correct"},
        {"Not Guessed","Not Missed","Not Correct"},
        {"Not Guessed","Not Missed","Not Correct"},
        {"Guessed","Not Missed","Correct"},
        {"Not Guessed","Not Missed","Correct"},
        {"Not Guessed","Not Missed","Correct"},
        {"Not Guessed","Not Missed","Correct"},
    };


    char* values[2][2] = {
        {"Not Guessed", "Guessed"},
        {"Not Missed","Missed"}
    };

    char* label[2] = {"Correct","Not Correct"};

    int True[50];
    int False[50];

    partition(mat,"Not Guessed",0,True,False);

    printf("-------------------------------------------------------------------------------------------------\n");


    int col = 0;
    char question[50];
    float gain = find_best_split(mat,label,values,col,question);

    printf("The most relevant question is : Is Guessed == %s \n", question);
    printf("The information gain is : %f\n",gain);

    printf("-------------------------------------------------------------------------------------------------\n");


    char* true_mat[12][3];
    char* false_mat[12][3];

    initialize_mat(true_mat);
    initialize_mat(false_mat);

    printf("Is Guessed == Not Guessed ?\n");

    send_array_from_number(mat,True,true_mat);
    send_array_from_number(mat,False,false_mat);


    int count_true = line_count(true_mat);
    int count_false = line_count(false_mat);

    printf("\nMatrice True : \n");

    for(int i = 0;i<count_true;i++)
    {
        printf("\n");
        for(int j = 0;j<3;j++)
        {
            printf("%s ",true_mat[i][j]);
        }
    }
    
    printf("\n");
    printf("\n");

    printf("Matrice False : \n");
    for(int i = 0;i<count_false;i++)
    {
        printf("\n");
        for(int j = 0;j<3;j++)
        {
            printf("%s ",false_mat[i][j]);
        }
    }

    printf("\n \n");    

    


printf("-------------------------------------------------------------------------------------------------\n");

    printf("Tree with Strings\n");

    char* test[2] = {"Not Guessed","Missed"};
    printf("Guessed is %s and Missed is %s\n\n",test[0],test[1]);
    build_tree(test);
    printf("\n");
    
printf("-------------------------------------------------------------------------------------------------\n\n");

    printf("Tree with probabilities\n") ;   

    float test1[2] = {0.74, 0.38};
    build_tree_num(test1);


    return 0;
}




