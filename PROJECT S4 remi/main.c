#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "outilsdl.h"
#include "rotations.h"
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
GtkWidget *resultsfixed;
GtkWidget *resultsframe;
GtkWidget *fixedE;
GtkWidget *blackfixed;
GtkWidget *fixedstart;
GtkWidget *image1resizer;
GtkWidget *frame1;
GtkWidget *frame2;
GtkWidget *blackframe;
GtkWidget *results;
GtkWidget *instructions;

//Boutons
GtkWidget *startbutton;
GtkWidget *stackswitcher1;
GtkWidget *backbutton;
GtkWidget *upbutton;
GtkWidget *forwardbutton;
GtkWidget *downbutton;
GtkWidget *sitebutton;
GtkWidget *prog1;
GtkWidget *spin1;
GtkWidget *timer;

GtkWidget *score;

GtkWidget *image1;
GtkWidget *imageE;

int countdownmax, countcurrent;
gboolean timer_handler(GtkWidget *);
void change();
char* presult;
char* finalscore;
char* nbessays;
SDL_Surface *imageES;
static int w = 200;
static int r = 0;
int success = 0;
int test = 0;
int essays = 0;


int *p;
double *q;
GdkColor color;


static void load_css()
{
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    const gchar *css_style_file = "style.css";
    GFile *css_fp = g_file_new_for_path(css_style_file);
    GError *error = 0;
    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_file(provider,css_fp,&error);
    g_object_unref(provider);
}




int main()
{
    //Initialiser Gtk avec dimensions de la fenetre
    gtk_init(NULL,NULL); 
     init_sdl();
     load_css();

    //creation du builder
    builder = gtk_builder_new_from_file("main.glade");
    
    presult = malloc(sizeof(char));
    finalscore = malloc(sizeof(char));
    nbessays = malloc(sizeof(char));

    
    
    

    

    //Connexion des widgets
    window = GTK_WIDGET(gtk_builder_get_object(builder,"window"));
    instructions = GTK_WIDGET(gtk_builder_get_object(builder,"instructions"));
    score = GTK_WIDGET(gtk_builder_get_object(builder,"score"));
    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder,"fixed1"));
    fixedstart = GTK_WIDGET(gtk_builder_get_object(builder,"fixedstart"));
    fixedE = GTK_WIDGET(gtk_builder_get_object(builder,"fixedE"));
    blackfixed = GTK_WIDGET(gtk_builder_get_object(builder,"blackfixed"));
    resultsfixed = GTK_WIDGET(gtk_builder_get_object(builder,"resultsfixed"));
    resultsframe = GTK_WIDGET(gtk_builder_get_object(builder,"resultsframe"));
    
    startbutton = GTK_WIDGET(gtk_builder_get_object(builder,"startbutton"));
    stackswitcher1 = GTK_WIDGET(gtk_builder_get_object(builder,"stackswitcher1"));
    sitebutton = GTK_WIDGET(gtk_builder_get_object(builder,"sitebutton"));
    backbutton = GTK_WIDGET(gtk_builder_get_object(builder,"backbutton"));
    results = GTK_WIDGET(gtk_builder_get_object(builder,"results"));
    upbutton = GTK_WIDGET(gtk_builder_get_object(builder,"upbutton"));
    forwardbutton = GTK_WIDGET(gtk_builder_get_object(builder,"forwardbutton"));
    downbutton = GTK_WIDGET(gtk_builder_get_object(builder,"downbutton"));
    prog1 = GTK_WIDGET(gtk_builder_get_object(builder,"prog1"));
    spin1 = GTK_WIDGET(gtk_builder_get_object(builder,"spin1"));
    timer = GTK_WIDGET(gtk_builder_get_object(builder,"timer"));
    
    frame1 = GTK_WIDGET(gtk_builder_get_object(builder,"frame1"));
    frame2 = GTK_WIDGET(gtk_builder_get_object(builder,"frame2"));
    blackframe = GTK_WIDGET(gtk_builder_get_object(builder,"blackframe"));
    image1 = GTK_WIDGET(gtk_builder_get_object(builder,"image1"));
    image1resizer = GTK_WIDGET(gtk_builder_get_object(builder,"image1resizer"));
    imageE= GTK_WIDGET(gtk_builder_get_object(builder,"imageE"));

    //Titre de la fenêtre
    gtk_window_set_title(GTK_WINDOW(window), "EyeContact Project");

    //------------------------Couleurs desfenêtres------------------------//
    
    gdk_color_parse( "#FFA500", &color);
    gtk_widget_modify_bg(frame1,GTK_STATE_NORMAL,&color);
    gdk_color_parse( "#FFFFFF", &color);
    gtk_widget_modify_bg(frame2,GTK_STATE_NORMAL,&color);
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
    //--------------------------------------------------------------//

    //-------------------------Page 2 ------------------------------//
    //change("Assets/E.jpg",200,200);



    //---------------------Timer---------------------------------//
    guint ID = g_timeout_add_seconds(1,(GSourceFunc) timer_handler,timer);



    

    gtk_main();
    return EXIT_SUCCESS;




}

gboolean	timer_handler(GtkWidget *timer) 
{
		time_t t = time(0);
		gtk_label_set_text(GTK_LABEL(timer), ctime(&t));    // update time of day

		if (countcurrent) 
            {
                

                if (countcurrent == 1)
                {
                    
                    gtk_widget_show(startbutton);
                    gtk_widget_show(stackswitcher1);
                    gtk_widget_show(instructions);
                    gtk_widget_hide(imageE);
                    gtk_widget_hide(backbutton);
                    gtk_widget_hide(upbutton);
                    gtk_widget_hide(forwardbutton);
                    gtk_widget_hide(downbutton);
                    
                    
                    test +=1;
                    success++;
                   
                    
                    char* instructions2 = "                        And now, cover your right eye!    ";
                    if (test == 2)
                    { 
                        gdk_color_parse( "#ADFF2F", &color);
                        gtk_widget_modify_bg(frame2,GTK_STATE_NORMAL,&color);
                        gtk_widget_modify_bg(blackframe,GTK_STATE_NORMAL,&color);
                        gtk_widget_hide(startbutton);
                        gtk_widget_hide(prog1);
                        gtk_widget_hide(spin1);
                        instructions2 = "                           Finish!           ";
                        char yourscore[50] = "You got the following score : ";
                        
                        
                        sprintf(finalscore,"%d",success);
                        sprintf(nbessays,"%d",essays);
                        printf("%s\n",finalscore);
                        
                        strcat(yourscore,finalscore);
                        char inter[50] = " / ";
                       
                        strcat(yourscore,inter);
                        
                        strcat(yourscore,nbessays);
                        
                        gtk_widget_destroy(fixedE);
                        gtk_label_set_text(GTK_LABEL(score),yourscore);
                        gtk_widget_show(score);
                        


                        

                    }
                    
                    
                    gtk_label_set_text(GTK_LABEL(instructions),instructions2);
                    
                    
                }
                
			    countcurrent = countcurrent - 1;

			    gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR(prog1), (gdouble) countcurrent/countdownmax );

			}
        

		return TRUE; // FALSE kills the timer
}






void on_startbutton_clicked()
{
    //----------affichage test de snellen-------------//

    success = 0;
    gtk_widget_show(backbutton);
    gtk_widget_show(upbutton);
    gtk_widget_show(forwardbutton);
    gtk_widget_show(downbutton);
    gtk_widget_hide(imageE);
     gtk_widget_hide(spin1);
    gtk_widget_hide(startbutton);
    gtk_widget_hide(instructions);
    gtk_widget_hide(stackswitcher1);
    char filename[] = "Assets/E.jpg";
    change(filename);


    

    //---------Lancement de la progress bar----------//
    countdownmax = (int) gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin1));
    if(countdownmax <= 0)
    {
        countcurrent = countdownmax = 0;

    }
    else
    {
        countcurrent = countdownmax;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(prog1), (gdouble) 1.00);
    }
    //-------------------------------------------------//


    //--------Lancement de la premiere image du texte----------------//

   
    
    imageES = load_image(filename);
    
    p = (int *) malloc(458*458*sizeof(int));
    q = (double *) malloc(458*458*sizeof(double)); 
    //leftrotation(imageES,p);
    
    SDL_SaveBMP(imageES, "Assets/E.bmp");
    //change("Assets/E.bmp",200);
    

    

}
void change(char* filename,int w)
{


    gtk_widget_hide(imageE);
    imageE = gtk_image_new_from_file(filename);
    GdkPixbuf *pixbuf3;
    pixbuf3  = gdk_pixbuf_new_from_file(filename,NULL);
    GdkPixbuf *pixbuf4 = NULL;
      
	
    pixbuf4 = gdk_pixbuf_scale_simple(pixbuf3,w,w,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imageE),pixbuf4);

	gtk_container_add (GTK_CONTAINER (fixedE), imageE);
    gtk_fixed_move(GTK_FIXED(fixedE),imageE,(205/2 - w/2),(205/2-w/2));
	gtk_widget_show(imageE);
    /*gdk_color_parse( "#2CCDD8", &color);
    gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);*/
    
}

void randomrotation()
{
     essays++;
     r = rand() %4;
     if (success > 0 && success <= 3)
     {
        w = 125;
     }
      if (success > 3 && success <= 9)
     {
        w = 65;
     }
       if (success > 9  && success <= 12)
     {
        w = 25;
     }
      if (success > 12 && success <= 15)
     {
        w = 15;
     }

    
    if (r == 0)
    {
        leftrotation(imageES,p);
        SDL_SaveBMP(imageES, "Assets/E.bmp");
        change("Assets/E.bmp",w);
    }
    if (r == 1)
    {
        rightrotation(imageES,p);
        SDL_SaveBMP(imageES, "Assets/E.bmp");
        change("Assets/E.bmp",w);
    }
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
void on_backbutton_clicked()
{
    
    

    srand(time(NULL));
 

    if (verification(buildmatrix(imageES,q),imageES,q) == "Left")
    {
       
        //gtk_label_set_text(GTK_LABEL(results),presult);
        GdkColor color;
        gdk_color_parse( "#00FF00", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        success ++;

    }
    else
    {
       
        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
    }
    randomrotation();
    
  
    
   
    

}
void on_upbutton_clicked()
{
    srand(time(NULL));
    

    if (verification(buildmatrix(imageES,q),imageES,q) == "Up")
    {
        //sprintf(presult,"%d",success);
        //gtk_label_set_text(GTK_LABEL(results),presult);
        GdkColor color;
        gdk_color_parse( "#00FF00", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        success ++;

    }
    else
    {
        
        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
    }
    randomrotation();
    
}
void on_forwardbutton_clicked()
{
      srand(time(NULL));
    

    if (verification(buildmatrix(imageES,q),imageES,q) == "Right")
    {
       //sprintf(presult,"%d",success);
       
        //gtk_label_set_text(GTK_LABEL(results),presult);
  
        GdkColor color;
        gdk_color_parse( "#00FF00", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
        success ++;

    }
    else
    {
        //gtk_label_set_text(GTK_LABEL(results),"False");

        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
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

        success ++;

    }
    else
    {
       
        GdkColor color;
        gdk_color_parse( "#DC143C", &color);
        gtk_widget_modify_bg(resultsframe,GTK_STATE_NORMAL,&color);
        gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color);
    }
    randomrotation();
   
}





