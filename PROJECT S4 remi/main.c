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


//Mon builder
GtkBuilder *builder;


//-----Mes Widgets----//
//Containers
GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *fixedE;
GtkWidget *fixedstart;
GtkWidget *image1resizer;
GtkWidget *frame1;
GtkWidget *frame2;

//Boutons
GtkWidget *startbutton;
GtkWidget *backbutton;
GtkWidget *upbutton;
GtkWidget *forwardbutton;
GtkWidget *downbutton;
GtkWidget *prog1;
GtkWidget *spin1;
GtkWidget *timer;

GtkWidget *image1;
GtkWidget *imageE;

int countdownmax, countcurrent;
gboolean timer_handler(GtkWidget *);
void change();
SDL_Surface *imageES;
int *p;




int main()
{
    //Initialiser Gtk avec dimensions de la fenetre
    gtk_init(NULL,NULL); 
     init_sdl();

    //creation du builder
    builder = gtk_builder_new_from_file("main.glade");

    //Connexion des widgets
    window = GTK_WIDGET(gtk_builder_get_object(builder,"window"));
    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder,"fixed1"));
    fixedstart = GTK_WIDGET(gtk_builder_get_object(builder,"fixedstart"));
    fixedE = GTK_WIDGET(gtk_builder_get_object(builder,"fixedE"))
    ;
    startbutton = GTK_WIDGET(gtk_builder_get_object(builder,"startbutton"));
    backbutton = GTK_WIDGET(gtk_builder_get_object(builder,"backbutton"));
    upbutton = GTK_WIDGET(gtk_builder_get_object(builder,"upbutton"));
    forwardbutton = GTK_WIDGET(gtk_builder_get_object(builder,"forwardbutton"));
    downbutton = GTK_WIDGET(gtk_builder_get_object(builder,"downbutton"));
    prog1 = GTK_WIDGET(gtk_builder_get_object(builder,"prog1"));
    spin1 = GTK_WIDGET(gtk_builder_get_object(builder,"spin1"));
    timer = GTK_WIDGET(gtk_builder_get_object(builder,"timer"));
    
    frame1 = GTK_WIDGET(gtk_builder_get_object(builder,"frame1"));
    frame2 = GTK_WIDGET(gtk_builder_get_object(builder,"frame2"));
    image1 = GTK_WIDGET(gtk_builder_get_object(builder,"image1"));
    image1resizer = GTK_WIDGET(gtk_builder_get_object(builder,"image1resizer"));
    imageE= GTK_WIDGET(gtk_builder_get_object(builder,"imageE"));

    //Titre de la fenêtre
    gtk_window_set_title(GTK_WINDOW(window), "EyeContact Project");

    //------------------------Couleurs desfenêtres------------------------//
    GdkColor color;
    gdk_color_parse( "#F3A813", &color);
    gtk_widget_modify_bg(frame1,GTK_STATE_NORMAL,&color);
    gtk_widget_modify_bg(frame2,GTK_STATE_NORMAL,&color);
    gdk_color_parse( "#2CCDD8", &color);
    gtk_widget_modify_bg(GTK_WIDGET(window),GTK_STATE_NORMAL,&color);
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
    change("Assets/E.jpg",200,200);



    //---------------------Timer---------------------------------//
    guint ID = g_timeout_add_seconds(1,(GSourceFunc) timer_handler,timer);



    

    gtk_main();
    return EXIT_SUCCESS;




}
gboolean	timer_handler(GtkWidget *timer) 
{
		time_t t = time(0);
		gtk_label_set_text(GTK_LABEL(timer), ctime(&t));    // update time of day

		if (countcurrent) {
			countcurrent = countcurrent - 1;
			gtk_progress_bar_set_fraction 
				(GTK_PROGRESS_BAR(prog1), (gdouble) countcurrent/countdownmax );
			}
        

		return TRUE; // FALSE kills the timer
}






void on_startbutton_clicked()
{
    //----------affichage test de snellen-------------//

    
    gtk_widget_show(backbutton);
    gtk_widget_show(upbutton);
    gtk_widget_show(forwardbutton);
    gtk_widget_show(downbutton);
    gtk_widget_hide(imageE);
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
    leftrotation(imageES,p);
    
    SDL_SaveBMP(imageES, "Assets/E.bmp");
    change("Assets/E.bmp",200,200);

    



    




}
void change(char* filename,int w,int h)
{


    gtk_widget_hide(imageE);
    imageE = gtk_image_new_from_file(filename);
    GdkPixbuf *pixbuf3;
    pixbuf3  = gdk_pixbuf_new_from_file(filename,NULL);
    GdkPixbuf *pixbuf4 = NULL;
      
	
    pixbuf4 = gdk_pixbuf_scale_simple(pixbuf3,w,h,GDK_INTERP_NEAREST);
    gtk_image_set_from_pixbuf(GTK_IMAGE(imageE),pixbuf4);

	gtk_container_add (GTK_CONTAINER (fixedE), imageE);
    gtk_fixed_move(GTK_FIXED(fixedE),imageE,(205/2 - w/2),(205/2-h/2));
	gtk_widget_show(imageE);
}
void on_backbutton_clicked()
{
    
    

    srand(time(NULL));
  
    
    int r = rand() %4;
    int w = 15 + rand() % (201 - 15);
    printf("%d\n",w);

    printf("%d\n",r);
    if (r == 0)
    {
        leftrotation(imageES,p);
        SDL_SaveBMP(imageES, "Assets/E.bmp");
        change("Assets/E.bmp",w,w);
    }
    if (r == 1)
    {
        rightrotation(imageES,p);
        SDL_SaveBMP(imageES, "Assets/E.bmp");
        change("Assets/E.bmp",w,w);
    }
    if (r == 2)
    {
        leftrotation(imageES,p);
        SDL_SaveBMP(imageES, "Assets/E.bmp");
        change("Assets/E.bmp",w,w);

    }
    else
    {
        leftrotation(imageES,p);
        SDL_SaveBMP(imageES, "Assets/E.bmp");
        change("Assets/E.bmp",w,w);

    }
    

}
void on_upbutton_clicked()
{
    on_backbutton_clicked();
}
void on_forwardbutton_clicked()
{
    on_backbutton_clicked();
}
void on_downbutton_clicked()
{
    on_backbutton_clicked();
}


void on_cancelbutton_clicked()
{
    gtk_widget_destroy(window);
    main();
}