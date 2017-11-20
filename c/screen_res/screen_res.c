// The C standart library
#include <stdlib.h>

// GTK+
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>

// X11
#include <X11/Xlib.h>


/*
    Printing a current screen resoltion by using the GTK+3
    https://en.wikipedia.org/wiki/GTK%2B
 */
int
print_screen_resolution_by_GTK(int argc, char *argv[])
{
    GdkScreen *screen;
    gint width, height;

    gtk_init(&argc, &argv);

    if ((screen = gdk_screen_get_default()) != NULL) {
        width = gdk_screen_get_width(screen);
        height = gdk_screen_get_height(screen);
        g_printf("Current screen resolution: %dx%d (by used GTK+)\n", width, height);
    }
    return 0;
}


/*
    Printing a current screen resoltion by using the libX11 (worked only for Unix-like OS)
    https://en.wikipedia.org/wiki/X_Window_System

    Based on:
        https://www.x.org/releases/X11R7.6/doc/libX11/specs/libX11/libX11.html
        http://surfingtroves.blogspot.com/2011/01/how-to-get-screen-resolution-in-linux-c.html
 */
int
print_display_resolution_by_X11()
{
    Display *display;
    Window window;
    XWindowAttributes xw_attrs;

    if ((display = XOpenDisplay(NULL)) == NULL) {
        fprintf(stderr, "Failed to open default display\n");
        return -1;
    }

    window = DefaultRootWindow(display);

    XGetWindowAttributes(display, window, &xw_attrs);

    printf("Current window resolution: %dx%d (by used X11)\n", xw_attrs.width, xw_attrs.height);

    XCloseDisplay(display);

    return 0;
}


int main(int argc, char *argv[])
{
    print_screen_resolution_by_GTK(argc, argv);
    print_display_resolution_by_X11();
    return EXIT_SUCCESS;
}