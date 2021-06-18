#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_image.h"
#include "outilsdl.h"
#include "rotations.h"
#include "buildtest.h"
#include <math.h>
#include <ctype.h>
#include <time.h>
#include "verify.h"







//Mon builder
GtkBuilder *builder;


//-----Mes Widgets----//
//Containers
GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *computerfixed;
GtkWidget *arrowfixed;
GtkWidget *eyefixed;
GtkWidget *resultsfixed;
GtkWidget *dalfixed;
GtkWidget *resultsframe;
GtkWidget *fixedE;
GtkWidget *blackfixed;
GtkWidget *rfixed;
GtkWidget *fixedstart;
GtkWidget *image1resizer;
GtkWidget *frame1;
GtkWidget *frame2;
GtkWidget *blackframe;
GtkWidget *frameb;
GtkWidget *framesep;
GtkWidget *results;
GtkWidget *instructions;
GtkWidget *distance;
GtkWidget *lacuity;
GtkWidget *validtext;
GtkWidget *validanswer;
GtkWidget *entry1;
GtkWidget *entry2;

//Boutons
GtkWidget *startbutton;
GtkWidget *stackswitcher1;
GtkWidget *backbutton;
GtkWidget *upbutton;
GtkWidget *forwardbutton;
GtkWidget *downbutton;
GtkWidget *randbutton;



GtkWidget *score;

GtkWidget *image1;
GtkWidget *imageE;
GtkWidget *imagec;
GtkWidget *imagea;
GtkWidget *imagee;
Mix_Music *tmusique;
Mix_Music *fmusique; 
Mix_Music *gomusique;  



void change();
char* presult;
char* finalscore;
char* nbessays;
char tmp[128];

int iessays = 36;
int racuity = 0;
int finalacuity = 0;
int tacuity = 0;
SDL_Surface *imageES;
static int w = 200;
static int r = 0;
int success = 0;
int test = 0;
int essays = 0;
char tmp[128];
char answ[128];


int *p;
double *q;
GdkColor color;







int main()
{
    //Initialiser Gtk avec dimensions de la fenetre
    gtk_init(NULL,NULL); 
     init_sdl();
     if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
     

    //creation du builder
    builder = gtk_builder_new_from_file("main.glade");
    
    presult = malloc(sizeof(char));
    finalscore = malloc(sizeof(char));
    nbessays = malloc(sizeof(char));
    tmusique = Mix_LoadMUS("Assets/t.mp3");
    fmusique = Mix_LoadMUS("Assets/f.mp3");
    gomusique = Mix_LoadMUS("Assets/go.mp3");

    
    
    

    

    //Connexion des widgets
    window = GTK_WIDGET(gtk_builder_get_object(builder,"window"));
    instructions = GTK_WIDGET(gtk_builder_get_object(builder,"instructions"));
    lacuity= GTK_WIDGET(gtk_builder_get_object(builder,"lacuity"));
    score = GTK_WIDGET(gtk_builder_get_object(builder,"score"));
    distance = GTK_WIDGET(gtk_builder_get_object(builder,"distance"));
    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder,"fixed1"));
    fixedstart = GTK_WIDGET(gtk_builder_get_object(builder,"fixedstart"));
    computerfixed = GTK_WIDGET(gtk_builder_get_object(builder,"computerfixed"));
    arrowfixed = GTK_WIDGET(gtk_builder_get_object(builder,"arrowfixed"));
    eyefixed = GTK_WIDGET(gtk_builder_get_object(builder,"eyefixed"));
    fixedE = GTK_WIDGET(gtk_builder_get_object(builder,"fixedE"));
    blackfixed = GTK_WIDGET(gtk_builder_get_object(builder,"rfixed"));
    dalfixed = GTK_WIDGET(gtk_builder_get_object(builder,"dalfixed"));
    rfixed = GTK_WIDGET(gtk_builder_get_object(builder,"rfixed"));
    resultsfixed = GTK_WIDGET(gtk_builder_get_object(builder,"resultsfixed"));
    resultsframe = GTK_WIDGET(gtk_builder_get_object(builder,"resultsframe"));
    frameb = GTK_WIDGET(gtk_builder_get_object(builder,"frameb"));
    framesep = GTK_WIDGET(gtk_builder_get_object(builder,"framesep"));
    
    startbutton = GTK_WIDGET(gtk_builder_get_object(builder,"startbutton"));
    stackswitcher1 = GTK_WIDGET(gtk_builder_get_object(builder,"stackswitcher1"));
    validanswer = GTK_WIDGET(gtk_builder_get_object(builder,"validanswer"));
    randbutton = GTK_WIDGET(gtk_builder_get_object(builder,"randbutton"));
    backbutton = GTK_WIDGET(gtk_builder_get_object(builder,"backbutton"));
    results = GTK_WIDGET(gtk_builder_get_object(builder,"results"));
    upbutton = GTK_WIDGET(gtk_builder_get_object(builder,"upbutton"));
    forwardbutton = GTK_WIDGET(gtk_builder_get_object(builder,"forwardbutton"));
    downbutton = GTK_WIDGET(gtk_builder_get_object(builder,"downbutton"));
    entry1 = GTK_WIDGET(gtk_builder_get_object(builder,"entry1"));
    entry2 = GTK_WIDGET(gtk_builder_get_object(builder,"entry2"));
    validtext = GTK_WIDGET(gtk_builder_get_object(builder,"validtext"));
 
    
    frame1 = GTK_WIDGET(gtk_builder_get_object(builder,"frame1"));
    frame2 = GTK_WIDGET(gtk_builder_get_object(builder,"frame2"));
    blackframe = GTK_WIDGET(gtk_builder_get_object(builder,"blackframe"));
    image1 = GTK_WIDGET(gtk_builder_get_object(builder,"image1"));
    image1resizer = GTK_WIDGET(gtk_builder_get_object(builder,"image1resizer"));
    imageE= GTK_WIDGET(gtk_builder_get_object(builder,"imageE"));

    //Titre de la fenêtre
    gtk_window_set_title(GTK_WINDOW(window), "EyeContact Project");

    //------------------------Couleurs desfenêtres------------------------//
    
    gdk_color_parse( "#4682b4", &color);
    gtk_widget_modify_bg(frame1,GTK_STATE_NORMAL,&color);
    gtk_widget_modify_bg(frameb,GTK_STATE_NORMAL,&color);
    
    gdk_color_parse( "#FFFFFF", &color);
    gtk_widget_modify_bg(frame2,GTK_STATE_NORMAL,&color);
    gtk_widget_modify_bg(framesep,GTK_STATE_NORMAL,&color);
    gdk_color_parse( "#2CCDD8", &color);
    gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);
    gdk_color_parse( "#FFFFFF", &color);
    gtk_widget_modify_bg(blackframe,GTK_STATE_NORMAL,&color);

    


    //-------------------------------------------------------------------//

   g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

    gtk_builder_connect_signals(builder,NULL);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_widget_show(window);

    gtk_widget_hide(backbutton);
    gtk_widget_hide(upbutton);
    gtk_widget_hide(forwardbutton);
    gtk_widget_hide(downbutton);
    gtk_widget_hide(validanswer);
    gtk_widget_hide(validtext);


    //---------------------Page1-----------------------------------//
     
    char filename[] = "Assets/logo.png";
    image1 = gtk_image_new_from_file(filename);

      
    GdkPixbuf *pixbuf1;
    pixbuf1  = gdk_pixbuf_new_from_file(filename,NULL);
    GdkPixbuf *pixbuf2 = NULL;
      
	
    pixbuf2 = gdk_pixbuf_scale_simple(pixbuf1,280,230,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(image1),pixbuf2);

	gtk_container_add (GTK_CONTAINER (image1resizer), image1);
    gtk_container_add(GTK_CONTAINER(fixedE),image1);
	gtk_widget_show(image1);

    imagec = gtk_image_new_from_file("Assets/computer.jpg");

      
    GdkPixbuf *pixbuf3;
    pixbuf3  = gdk_pixbuf_new_from_file("Assets/computer.jpg",NULL);
    GdkPixbuf *pixbuf4 = NULL;
      
	
    pixbuf4 = gdk_pixbuf_scale_simple(pixbuf3,173,176,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imagec),pixbuf4);

	
    gtk_container_add(GTK_CONTAINER(computerfixed),imagec);
	gtk_widget_show(imagec);

    imagea = gtk_image_new_from_file("Assets/arrow.png");

      
    GdkPixbuf *pixbuf5;
    pixbuf5  = gdk_pixbuf_new_from_file("Assets/arrow.png",NULL);
    GdkPixbuf *pixbuf6 = NULL;
      
	
    pixbuf6 = gdk_pixbuf_scale_simple(pixbuf5,100,80,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imagea),pixbuf6);

	
    gtk_container_add(GTK_CONTAINER(arrowfixed),imagea);
	gtk_widget_show(imagea);

    imagee = gtk_image_new_from_file("Assets/eye.jpg");

      
    GdkPixbuf *pixbuf7;
    pixbuf7  = gdk_pixbuf_new_from_file("Assets/eye.jpg",NULL);
    GdkPixbuf *pixbuf8 = NULL;
      
	
    pixbuf8 = gdk_pixbuf_scale_simple(pixbuf7,100,80,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imagee),pixbuf8);

    gtk_container_add(GTK_CONTAINER(eyefixed),imagee);
	gtk_widget_show(imagee);

    



    

    gtk_main();
    return EXIT_SUCCESS;




}

void testchange() 
{
		

                    
    gtk_widget_show(startbutton);
    gtk_widget_show(stackswitcher1);
    gtk_widget_show(instructions);
    gtk_widget_show(lacuity);
    gtk_widget_hide(imageE);
    
    gtk_widget_hide(backbutton);
    gtk_widget_hide(upbutton);
    gtk_widget_hide(forwardbutton);
    gtk_widget_hide(downbutton);

    gdk_color_parse( "#2CCDD8", &color);
    gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);
                    
                    
    test +=1;
    char* instructions2;
    if (test == 1)
    {
       instructions2 = "                    And now, cover your right eye!    ";
        gtk_widget_show(startbutton);
        gtk_widget_hide(stackswitcher1);

    }
    else
    {
       instructions2 = "                                         Finish";
        gtk_widget_hide(startbutton);
        gtk_widget_show(stackswitcher1);

    }
                    
                   
                    
                   
    gdk_color_parse( "#ADFF2F", &color);
    gtk_widget_modify_bg(frame2,GTK_STATE_NORMAL,&color);
    gtk_widget_modify_bg(blackframe,GTK_STATE_NORMAL,&color);
   
   
   
    char yourscore[50] = "You got the following score : ";
     char youracuity[50] = "Your acuity for this eye : ";
                        
     char sacuity[50];
     sprintf(sacuity,"%d",finalacuity);
     strcat(youracuity,sacuity);
     strcat(youracuity,"/20");                   
    sprintf(finalscore,"%d",success);
    sprintf(nbessays,"%d",essays);
    printf("%s\n",finalscore);
                        
    strcat(yourscore,finalscore);
    char inter[50] = " / ";
                       
    strcat(yourscore,inter);
                        
    strcat(yourscore,nbessays);
                        
    
    gtk_label_set_text(GTK_LABEL(score),yourscore);
    gtk_label_set_text(GTK_LABEL(lacuity),youracuity);
    gtk_widget_show(score);
    gtk_label_set_text(GTK_LABEL(instructions),instructions2);
}
                    
                    
    
                
			    

			
        

	






void on_startbutton_clicked()
{
    
    
    gdk_color_parse( "#FFFFFF", &color);
    gtk_widget_modify_bg(frame2,GTK_STATE_NORMAL,&color);
     gtk_widget_modify_bg(blackframe,GTK_STATE_NORMAL,&color);
    
    success = 0;
    essays = 0;
    finalacuity = 0;
    racuity = 0;
    tacuity = 0;
    Mix_PlayMusic(gomusique, 1);
    gtk_widget_show(backbutton);
    gtk_widget_show(upbutton);
    
    gtk_widget_show(forwardbutton);
    gtk_widget_show(downbutton);
;
    
    gtk_widget_hide(imagee);
    gtk_widget_hide(imagea);
    gtk_widget_hide(imagec);
    gtk_widget_hide(score);
    gtk_widget_hide(lacuity);
    gtk_widget_hide(instructions);
    gtk_widget_hide(distance);
    gtk_widget_hide(startbutton);
    gtk_widget_hide(instructions);
    gtk_widget_hide(stackswitcher1);
    char filename[] = "Assets/E.jpg";
    imageES = load_image(filename);
    

    p = (int *) malloc(458*458*sizeof(int));
    q = (double *) malloc(458*458*sizeof(double)); 
   
   
    
    SDL_SaveBMP(imageES, "Assets/E.bmp");
    change("Assets/E.bmp",325);
    

    

}
void change(char* filename,int w)
{


    //gtk_widget_hide(imageE);
    imageE = gtk_image_new_from_file(filename);
    GdkPixbuf *pixbuf3;
    pixbuf3  = gdk_pixbuf_new_from_file(filename,NULL);
    GdkPixbuf *pixbuf4 = NULL;
      
	
    pixbuf4 = gdk_pixbuf_scale_simple(pixbuf3,w,w,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imageE),pixbuf4);

	gtk_container_add (GTK_CONTAINER (fixedE), imageE);
    gtk_fixed_move(GTK_FIXED(fixedE),imageE,(325/2 - w/2),(325/2-w/2));
	gtk_widget_show(imageE);
 
    
}

void randomrotation()
{
     essays++;
    if (essays < 36)
    {
            r = rand() %4;
            
            if (essays == 1)
            {
                w = (325);
                racuity = 200;
            }
            if (essays > 1 && essays <= 3)
            {
                w = (325/2);
                racuity = 100;
                 
            }
            if (success > 3  && success <= 6)
            {
                w = (int)(162.5/1.42);
                racuity = 70;
                 
            }
            if (success > 6 && success <= 10)
            {
                w = (int)(117.0/1.4);
                racuity = 50;
            }
            if (success > 10 && success <= 15)
            {
                w = (int)(84.0/1.25);
                racuity = 40;
            }
             if (success > 15 && success <= 21)
            {
                w = (int)(67.0/1.34);
                 racuity = 30;
            }
            if (success > 21 && success <= 28)
            {
                w = (int)(50.0/1.2);
                racuity = 25;
            }
            if (success > 28 && success <= 36)
            {
               w = (int)(42.0/1.25);
               racuity = 20;
            }



    
            if (r == 0)
            {
                leftrotation(imageES,p);
                SDL_SaveBMP(imageES, "Assets/E.bmp");
                change("Assets/E.bmp",w);
            }
            else
            {       
                if (r == 1)
                {
                rightrotation(imageES,p);
                SDL_SaveBMP(imageES, "Assets/E.bmp");
                change("Assets/E.bmp",w);
                }
                else
                {
                    if (r == 2)
                    {
                        leftrotation(imageES,p);
                        SDL_SaveBMP(imageES, "Assets/E.bmp");
                        change("Assets/E.bmp",w);

                    }
                    else
                    {
                        leftrotation(imageES,p);
                        SDL_SaveBMP(imageES, "Assets/E.bmp");
                        change("Assets/E.bmp",w);

                    }

                }
        

            }
    
   
        
    
    }
    else
    {
         testchange();

    }
   
     
    
   
 

}
void on_backbutton_clicked()
{
    
    

    
 

    if (verification(buildmatrix(imageES,q),imageES,q) == "Left")
    {
       
        //gtk_label_set_text(GTK_LABEL(results),presult);
        GdkColor color;
        gdk_color_parse( "#00FF00", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(tmusique, 1);
        success ++;

    }
    else
    {
       
        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(fmusique, 1);
        if (!tacuity)
        {
            tacuity = 1;
            finalacuity = racuity;

        }
    }
    randomrotation();
    
  
    
   
    

}
void on_upbutton_clicked()
{
 
    

    if (verification(buildmatrix(imageES,q),imageES,q) == "Up")
    {
        //sprintf(presult,"%d",success);
        //gtk_label_set_text(GTK_LABEL(results),presult);
        GdkColor color;
        gdk_color_parse( "#00FF00", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(tmusique, 1);
        success ++;

    }
    else
    {
        
        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(fmusique, 1);

        if (!tacuity)
        {
            tacuity = 1;
            finalacuity = racuity;

        }
    }
    randomrotation();
    
}
void on_forwardbutton_clicked()
{
      
    

    if (verification(buildmatrix(imageES,q),imageES,q) == "Right")
    {
       //sprintf(presult,"%d",success);
       
        //gtk_label_set_text(GTK_LABEL(results),presult);
  
        GdkColor color;
        gdk_color_parse( "#00FF00", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(tmusique, 1);
        success ++;
        

    }
    else
    {
        //gtk_label_set_text(GTK_LABEL(results),"False");

        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(fmusique, 1);
        if (!tacuity)
        {
            tacuity = 1;
            finalacuity = racuity;

        }
    }
    
    randomrotation();
    
    
}
void on_downbutton_clicked()
{
     srand(time(NULL));
    

    if (verification(buildmatrix(imageES,q),imageES,q) == "down")
    {

        //sprintf(presult,"%d",success);
       
        //gtk_label_set_text(GTK_LABEL(results),presult);
        GdkColor color;
        gdk_color_parse( "#00FF00", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(tmusique, 1);

        success ++;

    }
    else
    {
       
        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        Mix_PlayMusic(fmusique, 1);
        if (!tacuity)
        {
            tacuity = 1;
            finalacuity = racuity;

        }
    }
    randomrotation();
   
}
void	on_validtext_clicked(GtkEntry *e)
{
    buildtest(tmp,150);
    imagec = gtk_image_new_from_file("test.ppm");
         
    GdkPixbuf *pixbuf3;
    pixbuf3  = gdk_pixbuf_new_from_file("test.ppm",NULL);
    GdkPixbuf *pixbuf4 = NULL;
      
	
    pixbuf4 = gdk_pixbuf_scale_simple(pixbuf3,375,230,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imagec),pixbuf4);

	
    gtk_container_add(GTK_CONTAINER(dalfixed),imagec);
	gtk_widget_show(imagec);

    

}
void on_validanswer_clicked()
{
    if (answ[0] == tmp[0])
    {
        Mix_PlayMusic(tmusique,1);
    }
    else
    {
        Mix_PlayMusic(fmusique,1);
    }
    
}
void on_randbutton_clicked()
{
    memset(tmp, '\0', sizeof(tmp));
    r = rand() %26;
    r += 65;
    char inter = (char) r;
    strncat(tmp,&inter,1);
    buildtest(tmp,150);
    imagec = gtk_image_new_from_file("Assets/test.ppm");
    GdkPixbuf *pixbuf3;
    pixbuf3  = gdk_pixbuf_new_from_file("Assets/test.ppm",NULL);
    GdkPixbuf *pixbuf4 = NULL;
      
	
    pixbuf4 = gdk_pixbuf_scale_simple(pixbuf3,375,230,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imagec),pixbuf4);

	
    gtk_container_add(GTK_CONTAINER(rfixed),imagec);
	gtk_widget_show(imagec);

    

} 
void	on_entry1_changed(GtkEntry *e) 
{
    gtk_widget_show(validtext);
    
    
	
	sprintf(tmp, "%s", gtk_entry_get_text(e));
	
}

void	on_entry2_changed(GtkEntry *e)
 {
     gtk_widget_show(validanswer);
	
	sprintf(answ, "%s", gtk_entry_get_text(e));
	
}





