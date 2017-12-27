GtkCssProvider *cssProvider = gtk_css_provider_new ();
gtk_css_provider_load_from_resource(cssProvider, "/net/olback/rdg/style.css");
gtk_style_context_add_provider(gtk_widget_get_style_context(window), cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);
