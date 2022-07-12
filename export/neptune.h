//List of functions provided by libneptune

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <pwd.h>
#include <appimage/appimage.h>

//Lists programs installed by Neptune using cat. Programs stored in /etc/neptune/list
int list(); 

//Searches through /etc/neptune/data/ database for program.
int find();  

/*  Trys to install AppImage provided. If it cannot find an AppImage, it will try to install from 
    AppImage repository. Can use direct path or file in current directory.  */
int install(char *file); 

//  Low level function that needs the exact filepath and integrates AppImage for all users
int integrate(char *file);

// Moves app to cache and deregisters it. Only provide the name, not the full path
int destroy(char *program);

// Reinstalls app. Only provide file name
int reinstall(char* program); 

/*  If argc = 2 aka they called nep update, then it will update the AppImage repository. 
    If argc > 2, then it will update argv[2]. Only provide AppImage name    */
int update(int argc, char *program);

/*  Runs a program inside of the aisap sandbox, using the profiled generated by install();
    Give it the name of the program, as well as your argc and argv. argv[0] will be ignored 
    because that is represented by file */
int run(char *file, int arg, char* argv[]);

// Uninstalls app, along with all data in the app
int uninstall(char* name);

// Refreshes your list of apps, if its screwed up for some reason
int refresh(); 