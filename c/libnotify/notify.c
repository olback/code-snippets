#include <stdio.h>
#include <stdlib.h>
#include <libnotify/notify.h>
#include <gtk/gtk.h>

void ncb(NotifyNotification* n, char* action, gpointer user_data) {
    printf("Callback: %s!\n%s\n", action, user_data);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    notify_init("Hello world!");
    NotifyNotification * n = notify_notification_new("Title", "Some body text", "gtk-missing-image");
    //notify_notification_set_category(n, "Development");
    notify_notification_add_action(n, "clicked", "Test", NOTIFY_ACTION_CALLBACK(ncb), NULL, NULL);
    notify_notification_show(n, NULL);
    
    gtk_main_iteration_do(FALSE);
    //gtk_main();
    g_object_unref(G_OBJECT(n));
    notify_uninit();
    return 0;
}
