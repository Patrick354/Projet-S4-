#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX 12
#define FALSE 1
#define TRUE 0
#define NEW_QUESTION { "" , FALSE }



//P
struct Question
{
    char question[50];
    int match;
};


static const struct Question empty = NEW_QUESTION;


//P
int size(int* row, int size)
{
	int i = 1;
	while(i < size+1 && (row[i] != 0) && row[i] <= 12 && row[i]>0)  // || row[i] == 1))
	{
		i += 1; 
	}
	return i;
}



int nb_line(int pos)
{
    int res;
    res = pos/3;
    if(pos%3 != 0)
    {
        res++;
    }
    return res;
}





//J'ai crée une structure spliting car on ne peut pas retourner deux valeurs en C
//La structure contient un array true et un array false qui vont chacun contenir le numéro de la ligne ( comme ça on n'a pas à copier chaque élement )
//P

struct Partition
{
	int row_true[50];
	int row_false[50] ;
};


//P
void array_copy(char *original, char *copy, int w)
{
	for(int i = 0; i < w; i++)
	{
		copy[i] = original[i];
	}
}


/*
L
        Verison 1 de la fonction class_counts

struct table *class_counts(char** m)
{

    struct table *counts;
    counts = malloc(sizeof(struct table));
    
    (*counts).string = "Missed";
    (*(counts+1)).string = "Guessed";
    (*(counts+2)).string = "Correct";
    (*(counts+3)).string = "Not Missed";
    (*(counts+4)).string = "Not Guessed";
    (*(counts+5)).string = "Not Correct";
    
    (*counts).numbers = 0;
    (*(counts+1)).numbers = 0;
    (*(counts+2)).numbers = 0;
    (*(counts+3)).numbers = 0;
    (*(counts+4)).numbers = 0;
    (*(counts+5)).numbers = 0;

    
    for(size_t i = 0;i < 36;i++)
    {
        for(size_t j = 0; j < 6;j++)
        {
            if((*(m+i)) == (*(counts+j)).string)
            {
                (*(counts+j)).numbers++;
                break;
            }
        }
    }
    return counts;
    
}



*/


//L
int* class_count(char** h, char* mat[12][3], int len)
{
    static int count_tab[6]; 
    int index = 0;
    int count = 0;
    for(int i = 0; i<len ;i++ )
    {
        for(int x =0;x<12;x++)
        {
            for(int y = 0;y < 3 ;y++)
            {
                if(mat[x][y] == h[i])
                {
                    count++;
                }
            }
        }
        count_tab[index] = count;
        index++;
        count = 0;
    }
    return count_tab;
}


//L
float calc_impur(char* mat[12][3],char** h) 
{
    int* counts = class_count(h,mat,6);
    float lbl;
    float impurty = 1;
    for(int i = 0; i < 6; i++)
    {
        lbl = (float)counts[i]/36; 
        impurty -= lbl*lbl;
    }
    return impurty;

}


//L&P
void send_array_from_number_true(char* mat[12][3], int* r_true,char* res[12][3])
{
    int index = 0;
    int size1 = size(r_true,50);
    for(int i = 0; i < size1; i++)
    {
        for(int y = 0; y<3;y++)
        {
            res[index][y] = mat[i][y];
        }
        index++;
    }
}


//L&P
void send_array_from_number_false(char* mat[12][3], int* r_false,char* res[12][3])
{
    int index = 0;
    int size1 = size(r_false,50);
    for(int i = 0; i < size1; i++)
    {
        for(int y = 0; y<3;y++)
        {
            res[index][y] = mat[i][y];
        }
        index++;
    }

}



//L&P
//#TODO : mettre info_gain en dessous de partition
float info_gain(float cu,char** h,struct Partition p, char* mat[12][3])
{
    char* r_true[12][3];
    send_array_from_number_true(mat,p.row_true,r_true);
    char* r_false[12][3];
    send_array_from_number_false(mat,p.row_false,r_false);
    
    int size_true = size(p.row_true,50);
    int size_false = size(p.row_false,50);

    printf("%d\n",size_true);
    printf("%d\n",size_false);

    float div = (float)size_true/(size_true+size_false);



    return (float) cu-(div*(calc_impur(r_true,h)))-((1-div)*(calc_impur(r_false,h)));

}


//P
//Permets de poser une question
struct Question questions(char* str,char* str2)
{

    char res[50];
    char* is = "Is ";
    char* equal = " == ";
    char* ponct = " ?";

    struct Question question1; 

    strcat(res,is);
    strcat(res,str);
    strcat(res,equal);
    strcat(res,str2);
    strcat(res,ponct);

    strcpy(question1.question,res);

    if(str == str2)
    {
	    question1.match = TRUE;
    }
    else
    {
	    question1.match = FALSE;
    }
    
    return question1;
    
}

struct Partition partition(char* mat[12][3],char* str2)
{
	struct Partition partition1;
	struct Question res = NEW_QUESTION;
	int start_true = 0;
	int start_false = 0;
	int stock = 0;

	for(int i = 0; i < 12; i ++)
	{
		for(int y = 0; y < 3; y ++)
		{
			res = questions(mat[i][y],str2);
			printf(" ");
			if(res.match == TRUE)
			{
				partition1.row_true[start_true] = i;
				start_true +=1;
			}
			res = empty;

		}
		if(stock == start_true)
		{
			partition1.row_false[start_false] = i;
			start_false += 1;
		}
		stock = start_true;

	}
	printf("\n");

	return partition1;
	

}




struct best_split
{
    float best_gain;
    char question[50];
};


/*
char* col0[2][1] = {
    {"Not Guessed"},
    {"Guessed"},
    };


char* col1[2][1] = {{"Not Missed"},
                    {"Missed"},};

char* col2[2][1] = {{"Not Correct"},
                    {"Correct"},};


char* h2[3] = {"Guessed","Missed","Correct"};  

*/

//L
struct best_split find_best_split(char* mat[12][3], char** h1,char** h2 )
{

    struct best_split bs;
    float cu = calc_impur(mat,h1);
    int n_features = 2;
    struct Question question = empty;
    int x;
    struct Partition partition1;
    float gain;
    


    for(int col = 0;col <= n_features ;col++ )
    {
        if(col == 0)
        {
            char* res[2][1] = { {"Not Guessed"},
                                {"Guessed"},
                                };
            for(int i =0; i < 2;i++)
            {
                question = questions(res[0][i],h2[x]);
                partition1 = partition(mat,question.question);
            
            
                gain = info_gain(cu,h1,partition1,mat);
                if(gain >= bs.best_gain)
                {
                    bs.best_gain = gain;
                    array_copy(question.question,bs.question,50);
                }
                question = empty;
            }
        }

        x++;

        if(col == 1)
        {
            char* res[2][1] = { {"Not Missed"},
                                {"Missed"},
                                };
            for(int i =0; i < 2;i++)
            {
                question = questions(res[0][i],h2[x]);
                partition1 = partition(mat,question.question);
            
            
                gain = info_gain(cu,h1,partition1,mat);
                if(gain >= bs.best_gain)
                {
                    bs.best_gain = gain;
                    array_copy(question.question,bs.question,50);
                }
                question = empty;
            }
        }
        
        x++; 
        
        if(col == 2)
        {
            char* res[2][1] = { {"Not Correct"},
                                {"Correct"},
                                };

            for(int i =0; i < 2;i++)
            {
                question = questions(res[0][i],h2[x]);
                partition1 = partition(mat,question.question);
            
            
                gain = info_gain(cu,h1,partition1,mat);
                if(gain >= bs.best_gain)
                {
                    bs.best_gain = gain;
                    array_copy(question.question,bs.question,50);
                }
                question = empty;
            }
        
    
        }
    }
    return bs;

}







//je parcours ma matrice et si je tombe sur un truc qui correspond à mon str2 je mets le numéro de la ligne dans la liste true. Si aucun élément ne correspond à str2 je 
//mets le numéro de la ligne dans la liste false
//
//deux c'est le numéro de ligne et trois le numéro de colonne
//
//problème à résoudre : stack smashing, je suis trop fatigué pour le réparer mais je pense que l'algo est pas mal, j'espère tu pourras le décoder. 

/*


*/

int main()
{
    /*
    char mat[12][3];
    mat[0][0] = "Not Guessed";
    mat[0][1] = "Missed";
    mat[0][2] = "Not Correct";   
    mat[1][0] = "Not Guessed";
    mat[1][1] = "Missed";
    mat[1][2] = "Not Correct";  
    mat[2][0] = "Not Guessed";
    mat[2][1] = "Missed";
    mat[2][2] = "Not Correct";  
    mat[3][0] = "Not Guessed";
    mat[3][1] = "Missed";
    mat[3][2] = "Not Correct";  
    mat[4][0] = "Not Guessed";
    mat[4][1] = "Missed";
    mat[4][2] = "Not Correct";  
    mat[5][0] = "Not Guessed";
    mat[5][1] = "Missed";
    mat[5][2] = "Not Correct";  
    mat[6][0] = "Not Guessed";
    mat[6][1] = "Missed";
    mat[6][2] = "Not Correct";  
    mat[7][0] = "Not Guessed";
    mat[7][1] = "Missed";
    mat[7][2] = "Not Correct";  
    mat[8][0] = "Not Guessed";
    mat[8][1] = "Missed";
    mat[8][2] = "Not Correct";  
    mat[9][0] = "Not Guessed";
    mat[9][1] = "Missed";
    mat[9][2] = "Not Correct";  
    mat[10][0] = "Not Guessed";
    mat[10][1] = "Missed";
    mat[10][2] = "Not Correct";  
    mat[11][0] = "Not Guessed";
    mat[11][1] = "Missed";
    mat[11][2] = "Not Correct";  
    */

    /*
    char** mat;
    mat = malloc(36*sizeof(char**));
    *(mat+1) = "Not Guessed";
    *(mat+2) = "Missed";
    *(mat+3) = "Missed";
    *(mat+4) = "Not correct";
    *(mat+5) = "Missed";
    *(mat+6) = "Missed";
    *(mat+7) = "Missed";
    *(mat+8) = "Not correc";
    *(mat+9) = "Missed";
    *(mat+10) = "Not Guessed";
    *(mat+11) = "Missed";
    *(mat+12) = "Missed";
    *(mat+13) = "Missed";
    *(mat+14) = "Missed";
    *(mat+15) = "Missed";
    *(mat+16) = "Missed";
    *(mat+17) = "Missed";
    *(mat+18) = "Missed";
    *(mat+19) = "Missed";
    *(mat+20) = "Missed";
    *(mat+21) = "Missed";
    *(mat+22) = "Missed";
    *(mat+23) = "Missed";
    *(mat+24) = "Missed";
    *(mat+25) = "Missed";
    *(mat+26) = "Missed";
    *(mat+27) = "Missed";
    *(mat+29) = "Missed";
    *(mat+30) = "Missed";
    *(mat+31) = "Missed";
    *(mat+32) = "Missed";
    *(mat+33) = "Missed";
    *(mat+34) = "Missed";
    *(mat+35) = "Missed";
    *(mat+36) = "Missed";
    */


  char* mat[12][3] = {
        {"Not Guessed","Missed","Not Correct"},
        {"Guessed","Not Missed","Not Correct"},
        {"Not Guessed","Not Missed","Correct"},
        {"Not Guessed","Missed","Not Correct"},
        {"Not Guessed","Not Missed","Correct"},
        {"Guessed","Not Missed","Not Correct"},
        {"Not Guessed","Not Missed","Not Correct"},
        {"Not Guessed","Not Missed","Not Correct"},
        {"Guessed","Not Missed","Not Correct"},
        {"Not Guessed","Not Missed","Correct"},
        {"Not Guessed","Not Missed","Correct"},
        {"Not Guessed","Not Missed","Correct"},

    };
    


  

    char* h[6] = {"Not Guessed","Not Missed","Not Correct","Guessed","Missed","Correct"};

    float imp = calc_impur(mat,h);
    printf(" imp == %f\n", imp);

    struct Partition partition1;
    partition1 = partition(mat,"Not Guessed");


    int size1 = size(partition1.row_false,50);
    for(int i = 0 ; i< size1;i++)
    {
        printf("%d\n",partition1.row_false[i]);
    }

    /*    
    float gain = info_gain(imp,h,partition1,mat);
    printf("gain == %f\n",gain);
    */
/*
    char* res[12][3];
    send_array_from_number_true(mat,partition1.row_true,res); 
    float impure = calc_impur(res,h);
    printf("%f\n",impure);
    */

/*    
    int* mat = {2 , 2};
    
    float res = calc_impur(mat);
    printf("Le résultat = %f",res);
  */  

    //free(mat);
    return 0;
}

