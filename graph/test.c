#include <gtk/gtk.h>  
int main(int argc,char *argv[])  
{  
    GtkWidget *window;  
    GtkWidget *label;  
    char title[]="test";  
    char text[]="This is the test.";  
    gtk_init(&argc, &argv);  
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_title(GTK_WINDOW(window), title);  
    gtk_widget_set_usize(GTK_WINDOW (window),300,150);  
  
    label=gtk_label_new(text);  
    gtk_container_add(GTK_CONTAINER(window), label);  
    gtk_widget_show(window);  
    gtk_widget_show(label);  
    gtk_main();  
    return 0;  
}  
