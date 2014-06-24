#include <gtk/gtk.h>
#include <gtk/gtkhbox.h>
#include <gtk/gtkvbox.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include "Sword.h"
#include "Spear.h"
#include "Weapon.h"
#include "Crush.h"
using namespace std;

GtkWidget *window, *button_menu_add, *button_menu_delete, *button_menu_show, *button_menu_save_load, *vbox_menu, *hbox_menu, *fild1, *fild2;
GtkWidget *entri_name, *entri_kind, *entri_weight, *entri_overall_length, *entri_length_of_the_blade, *entri_length_of_the_handle, *entri_form_blade;
GtkWidget *entri_serch, *label,  *table_all;
string name = "";
vector<Weapon*> collection;
string signal_add_type = "SWORD";

static void button_sword_clicked(GtkWidget* widget, gpointer data);
static void button_spear_clicked(GtkWidget* widget, gpointer data);
static void button_crush_clicked(GtkWidget* widget, gpointer data);
static void button_menu_add_clicked(GtkWidget* widget, gpointer data);
static void button_menu_delete_clicked(GtkWidget* widget, gpointer data);
static void button_menu_show_clicked(GtkWidget* widget, gpointer data);
static void button_menu_save_load_clicked(GtkWidget* widget, gpointer data);
static void button_add_clicked(GtkWidget* widget, gpointer data);
int main(int argc, char ** argv)
{
	gtk_init(&argc, &argv);
	
	window  = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button_menu_add = gtk_button_new_with_label("Add");
	button_menu_delete = gtk_button_new_with_label("Delete");
	button_menu_show = gtk_button_new_with_label("Show");
	button_menu_save_load = gtk_button_new_with_label("Save/Load");
	vbox_menu    = gtk_vbox_new(FALSE, 10);
	hbox_menu    = gtk_hbox_new(FALSE, 10);
	fild1        = gtk_vbox_new(FALSE, 10);
	
	gtk_window_set_title(GTK_WINDOW(window), "Home collection");
	gtk_container_set_border_width(GTK_CONTAINER(window), 50);

	gtk_container_add(GTK_CONTAINER(window), vbox_menu);
	gtk_box_pack_start(GTK_BOX(vbox_menu), hbox_menu, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_menu), fild1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(fild1), fild2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_menu), button_menu_add, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_menu), button_menu_delete, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_menu), button_menu_show, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_menu), button_menu_save_load, TRUE, TRUE,0);

	g_signal_connect(G_OBJECT(button_menu_add), "clicked", G_CALLBACK(button_menu_add_clicked), NULL);
	g_signal_connect(G_OBJECT(button_menu_delete), "clicked", G_CALLBACK(button_menu_delete_clicked), NULL);
	g_signal_connect(G_OBJECT(button_menu_show), "clicked", G_CALLBACK(button_menu_show_clicked), NULL);
	g_signal_connect(G_OBJECT(button_menu_save_load), "clicked", G_CALLBACK(button_menu_save_load_clicked), NULL);

	button_menu_add_clicked(button_menu_add,"clicked");
	
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped(G_OBJECT (window), "delete_event", G_CALLBACK (gtk_widget_destroy), G_OBJECT (window));

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}
static void button_add_clicked(GtkWidget* widget, gpointer data)
{
	string name, kind, type, weight, overall_length, length_of_the_blade, length_of_the_handle;

	name = gtk_entry_get_text(GTK_ENTRY(entri_name));
	kind = gtk_entry_get_text(GTK_ENTRY(entri_kind));
	type = gtk_entry_get_text(GTK_ENTRY(entri_form_blade));
	weight = gtk_entry_get_text(GTK_ENTRY(entri_weight));
	overall_length = gtk_entry_get_text(GTK_ENTRY(entri_overall_length));
	length_of_the_blade  = gtk_entry_get_text(GTK_ENTRY(entri_length_of_the_blade));
	length_of_the_handle = gtk_entry_get_text(GTK_ENTRY(entri_length_of_the_handle));
	if(signal_add_type == "SWORD")
	{
		collection.push_back(new Sword(name,kind,weight,overall_length,length_of_the_blade,length_of_the_handle,type));
	}
	if(signal_add_type == "SPEAR")
	{
		collection.push_back(new Spear(name,kind,weight,overall_length,length_of_the_blade,length_of_the_handle,type));
	}
	if(signal_add_type == "CRUSH")
	{
		collection.push_back(new Crush(name,kind,weight,overall_length,length_of_the_blade,length_of_the_handle,type));
	}
	gtk_entry_set_text(GTK_ENTRY(entri_name), "");
	gtk_entry_set_text(GTK_ENTRY(entri_kind), "");
	gtk_entry_set_text(GTK_ENTRY(entri_form_blade), "");
	gtk_entry_set_text(GTK_ENTRY(entri_weight), "");
	gtk_entry_set_text(GTK_ENTRY(entri_overall_length), "");
	gtk_entry_set_text(GTK_ENTRY(entri_length_of_the_blade), "");
	gtk_entry_set_text(GTK_ENTRY(entri_length_of_the_handle), "");

}
static void button_sword_clicked(GtkWidget* widget, gpointer data)
{
	signal_add_type = "SWORD";
	button_menu_add_clicked(widget,"clicked");
}
static void button_spear_clicked(GtkWidget* widget, gpointer data)
{
	signal_add_type = "SPEAR";
	button_menu_add_clicked(widget,"clicked");
}
static void button_crush_clicked(GtkWidget* widget, gpointer data)
{
	signal_add_type = "CRUSH";
	button_menu_add_clicked(widget,"clicked");
}
static void button_menu_add_clicked(GtkWidget* widget, gpointer data)
{
	gtk_widget_destroy(fild2);
	fild2 = gtk_vbox_new(FALSE, 10);
	gtk_box_pack_start(GTK_BOX(fild1), fild2, TRUE, TRUE, 0);
	GtkWidget *vbox_add, *hbox_add_botton, *hbox_button_kind, *hbox_add_name, *hbox_add_kind, *hbox_add_weight, *hbox_add_overall_length, *hbox_add_length_of_the_blade, *hbox_add_length_of_the_handle, *hbox_add_fild;
	GtkWidget *button_add, *button_sword, *button_spear, *button_crush;
	GtkWidget *label_name, *label_kind, *label_weight, *label_overall_length, *label_length_of_the_blade, *label_length_of_the_handle, *label_form_blade, *label_type;
	
	button_add   = gtk_button_new_with_label("Add");
	button_sword = gtk_button_new_with_label("Sword");
	button_spear = gtk_button_new_with_label("Spear");
	button_crush = gtk_button_new_with_label("Crush");
	//hbox,vbox
	vbox_add                      = gtk_vbox_new(FALSE, 10);
	hbox_add_name                 = gtk_hbox_new(FALSE, 10);
	hbox_button_kind              = gtk_hbox_new(FALSE, 10);
	hbox_add_name                 = gtk_hbox_new(FALSE, 10);
	hbox_add_kind                 = gtk_hbox_new(FALSE, 10);
	hbox_add_weight               = gtk_hbox_new(FALSE, 10);
	hbox_add_overall_length       = gtk_hbox_new(FALSE, 10);
	hbox_add_length_of_the_blade  = gtk_hbox_new(FALSE, 10);
	hbox_add_length_of_the_handle = gtk_hbox_new(FALSE, 10);
	hbox_add_fild                 = gtk_hbox_new(FALSE, 10);
	hbox_add_botton               = gtk_hbox_new(FALSE, 10);
	//entri
	entri_name                 = gtk_entry_new();
	entri_kind                 = gtk_entry_new();
	entri_weight               = gtk_entry_new();
	entri_overall_length       = gtk_entry_new();
	entri_length_of_the_blade  = gtk_entry_new();
	entri_length_of_the_handle = gtk_entry_new();
	entri_form_blade           = gtk_entry_new();
	//label
	label_name                 = gtk_label_new("Name");
	label_kind                 = gtk_label_new("Kind");
	label_weight               = gtk_label_new("Weight");
	label_overall_length       = gtk_label_new("Length");
	label_length_of_the_blade  = gtk_label_new("Length of the blade");
	label_length_of_the_handle = gtk_label_new("Length of the handle");
	label_form_blade           = gtk_label_new("Form");
	label_type                 = gtk_label_new(signal_add_type.c_str());

	gtk_box_pack_start(GTK_BOX(fild2), vbox_add, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_button_kind, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_name, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_kind, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_weight, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_overall_length, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_length_of_the_blade, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_length_of_the_handle, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_fild, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_add), hbox_add_botton, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(hbox_button_kind), button_sword, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_button_kind), button_spear, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_button_kind), button_crush, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_name), label_name, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_name), entri_name, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_kind), label_kind, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_kind), entri_kind, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_weight), label_weight, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_weight), entri_weight, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_overall_length), label_overall_length, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_overall_length), entri_overall_length, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_length_of_the_blade), label_length_of_the_blade, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_length_of_the_blade), entri_length_of_the_blade, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_length_of_the_handle), label_length_of_the_handle, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_length_of_the_handle), entri_length_of_the_handle, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_add_fild), label_form_blade, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_fild), entri_form_blade, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_botton), label_type, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_add_botton), button_add, TRUE, TRUE, 0);
	
	g_signal_connect(G_OBJECT(button_sword), "clicked", G_CALLBACK(button_sword_clicked), NULL);
	g_signal_connect(G_OBJECT(button_spear), "clicked", G_CALLBACK(button_spear_clicked), NULL);
	g_signal_connect(G_OBJECT(button_crush), "clicked", G_CALLBACK(button_crush_clicked), NULL);
	g_signal_connect(G_OBJECT(button_add), "clicked", G_CALLBACK(button_add_clicked), NULL);
	
	gtk_widget_show_all(fild2);
}
static void button_delete_clicked(GtkWidget* widget, gpointer data)
{
	name = gtk_entry_get_text(GTK_ENTRY(entri_serch));
	for(int i=0; i < collection.size(); i++)
		if(collection[i]->GetName() == name)
			collection.erase(collection.begin()+i);
	gtk_entry_set_text(GTK_ENTRY(entri_serch), "");

}
static void button_serch_clicked(GtkWidget* widget, gpointer data)
{
	name = gtk_entry_get_text(GTK_ENTRY(entri_serch));
	for(int i=0; i < collection.size(); i++)
		if(collection[i]->GetName() == name)
		{
			label = gtk_label_new (collection[i]->Print().c_str());
			gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
			gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(table_all), label);
			gtk_widget_show(label);
		}
}
static void button_menu_delete_clicked(GtkWidget* widget, gpointer data)
{
	gtk_widget_destroy(fild2);
	fild2 = gtk_vbox_new(FALSE, 10);
	gtk_box_pack_start(GTK_BOX(fild1), fild2, TRUE, TRUE, 0);
	GtkWidget *serch, *delete_b, *vbox_delete, *hbox_serch;

	serch       = gtk_button_new_with_label("Serch");
	delete_b    = gtk_button_new_with_label("Delete");
	entri_serch = gtk_entry_new();
	vbox_delete = gtk_vbox_new(FALSE, 10);
	hbox_serch  = gtk_hbox_new(FALSE, 10);
	table_all   = gtk_scrolled_window_new (NULL, NULL);

	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (table_all), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request (table_all, 100, 250);

	gtk_box_pack_start(GTK_BOX(fild2), vbox_delete, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_delete), hbox_serch, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_delete), table_all, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_delete), delete_b, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_serch), entri_serch, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox_serch), serch, TRUE, TRUE, 0);


	g_signal_connect(G_OBJECT(serch), "clicked", G_CALLBACK(button_serch_clicked), NULL);
	g_signal_connect(G_OBJECT(delete_b), "clicked", G_CALLBACK(button_delete_clicked), NULL);

	
	gtk_widget_show_all(fild2);
}
static void button_menu_show_clicked(GtkWidget* widget, gpointer data)
{
	gtk_widget_destroy(fild2);
	fild2 = gtk_vbox_new(FALSE, 10);
	gtk_box_pack_start(GTK_BOX(fild1), fild2, TRUE, TRUE, 0);

	GtkWidget *table_all, *label, *table;

    
	table     = gtk_table_new (1, collection.size(), FALSE);
	table_all = gtk_scrolled_window_new (NULL, NULL);

	gtk_table_set_row_spacings (GTK_TABLE (table), 10);
    gtk_table_set_col_spacings (GTK_TABLE (table), 10);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (table_all), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request (table_all, 100, 300);
	gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(table_all), table);
	gtk_widget_show (table);

	for(int i=0; i < collection.size(); i++)
	{
		label = gtk_label_new (collection[i]->Print().c_str());
		gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
		gtk_table_attach_defaults (GTK_TABLE (table), label, 0, 1, i, i+1);
		gtk_widget_show(label);
	}

	gtk_box_pack_start(GTK_BOX(fild2), table_all, TRUE, TRUE, 0);	
	gtk_widget_show_all(fild2);
}
static void button_save_clicked(GtkWidget* widget, gpointer data)
{
	// копируем содержимое вектора в файл
    ofstream fout("collection.txt");
	for (int i = 0; i < collection.size(); i++) 
	{
		fout << endl << collection[i]->In_file();
    }
	fout.close();

}
static void button_loade_clicked(GtkWidget* widget, gpointer data)
{
	ifstream fin("collection.txt");
	string line;
	string infa[7];
	while (getline(fin, line)) 
	{
		if(line == "Sword")
		{
			for (int i=0; i<7 ;i++)
			{
				getline(fin, line);
				infa[i]=line;
			}
			collection.push_back(new Sword(infa[0],infa[1],infa[2],infa[3],infa[4],infa[5],infa[6]));
		}
		else
		{
			if(line == "Spear")
			{
				for (int i=0; i<7 ;i++)
				{
					getline(fin, line);
					infa[i]=line;
				}
				collection.push_back(new Spear(infa[0],infa[1],infa[2],infa[3],infa[4],infa[5],infa[6]));
			}
			else
				if(line == "Crush")
				{
					for (int i=0; i<7 ;i++)
					{
						getline(fin, line);
						infa[i]=line;
					}
					collection.push_back(new Crush(infa[0],infa[1],infa[2],infa[3],infa[4],infa[5],infa[6]));
				}
		}
	}
	fin.close();
}

static void button_menu_save_load_clicked(GtkWidget* widget, gpointer data)
{
	gtk_widget_destroy(fild2);
	fild2 = gtk_vbox_new(FALSE, 10);
	gtk_box_pack_start(GTK_BOX(fild1), fild2, TRUE, TRUE, 0);

	GtkWidget *save, *loade, *vbox_save;
	GtkWidget *label_null1, *label_null2, *label_null4, *label_null5, *label_null6, *label_null8, *label_null9, *label_null10, *label_null11;//знаю, что бред, но красиво

	save = gtk_button_new_with_label("Save");
	loade = gtk_button_new_with_label("Loade");

	label_null1 = gtk_label_new("");
	label_null2 = gtk_label_new("");
	label_null4 = gtk_label_new("");
	label_null5 = gtk_label_new("");
	label_null6 = gtk_label_new("");
	label_null8 = gtk_label_new("");
	label_null9 = gtk_label_new("");
	label_null10 = gtk_label_new("");
	label_null11 = gtk_label_new("");
	
	vbox_save = gtk_vbox_new(FALSE, 10);

	gtk_box_pack_start(GTK_BOX(fild2), vbox_save, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), save, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null4, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null5, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null6, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), loade, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null8, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null9, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null10, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_save), label_null11, TRUE, TRUE, 0);

	g_signal_connect(G_OBJECT(save), "clicked", G_CALLBACK(button_save_clicked), NULL);
	g_signal_connect(G_OBJECT(loade), "clicked", G_CALLBACK(button_loade_clicked), NULL);

	gtk_widget_show_all(fild2);
}