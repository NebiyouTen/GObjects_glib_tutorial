#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iterator>
#include "cli_args.h"
#include <glib.h>
#include <gst/gst.h>

using namespace std;

int parse_line(string line, map<string,string> &configs);

int main(int argc, char **argv){

    int i, opt, parsed_configs;
    bool parsing_done;
    gchar *config_file_name = NULL, *start_time= NULL, *end_time= NULL, *speed;
    string  temp, line, str_config_file_name, str_start_time, str_end_time,str_speed;
    map<string,string> configs;
    map<string,string>::iterator configs_iter;
    ifstream config_file;
    GOptionContext *ctx;
    GError *err = NULL;
    guint major, minor, micro, nano;

    speed = g_strdup("Normal");
    static GOptionEntry entries[] =
    {
      { "config_file", 'f', 0, G_OPTION_ARG_STRING, &config_file_name, "Config file to read", NULL },
      { "start_time", 's', 0, G_OPTION_ARG_STRING, &start_time, "Start time", NULL },
      { "end_time", 'e', 0, G_OPTION_ARG_STRING, &end_time, "End time", NULL },
      { "speed", 'v', 0, G_OPTION_ARG_STRING, &speed, "Playback speed", "Normal" },
      { NULL }
    };



    ctx = g_option_context_new ("- UChannel Scaffold");
    g_option_context_add_main_entries (ctx, entries, NULL);
    g_option_context_add_group (ctx, gst_init_get_option_group ());
    if (!g_option_context_parse (ctx, &argc, &argv, &err)) {
       g_print ("Failed to initialize: %s\n", err->message);
       g_clear_error (&err);
       g_option_context_free (ctx);
       return 1;
    }

     g_option_context_free (ctx);



     if ( (config_file_name == NULL) || (start_time == NULL)
                  || (end_time == NULL) ){
       cout << "Invalid Arguments. see --help for more information.  \n";
       exit(1);
     }

     str_config_file_name = config_file_name;
     str_start_time = start_time;
     str_end_time = end_time;
     str_speed = speed;
     cout <<"Arguments: \n \t Confing file: "<< str_config_file_name;
     //cout.flush();
     cout << "\n \t Start time: " << str_start_time ;
     cout << "\n \t End time: " << str_end_time ;
     cout << "\n \t Speed:  " << str_speed;
     cout << "\n\n" ;
     //cout.flush();

     gst_version (&major, &minor, &micro, &nano);

     cout << "GStreamer Version "<< major<<"."<< minor<<"."<<micro<< "\n";

     /*
      * Read the config file
      */
     config_file.open(config_file_name);
     if (!config_file){
       cout<<"Unable to open file: " << config_file_name << "\n";
       exit(1);
     }

     while ( (config_file >> line) && (parsed_configs < CONFIGSTOPARSE) ){
        parsed_configs += parse_line(line, configs);
     }

     for (configs_iter = configs.begin(); configs_iter != configs.end() ; ++configs_iter){

          cout <<'\t' << configs_iter->first<<'\t'<< configs_iter->second;
          cout << endl;

     }

     config_file.close();
     return 0;
}


int parse_line(string line, map<string,string> &configs){

    string key,value;
    int parsing_char_index;

    parsing_char_index = line.find("=");
    key=line.substr(0,parsing_char_index);
    value = line.substr(parsing_char_index+1);

    #if 0
    if ( valid_key(key) ){
      configs.insert(pair<string,string>(line, line));
      return 1;
    }
    #endif
    configs.insert(pair<string,string>(line, line));
    return 0;

}
