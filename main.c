#include <stdio.h>

// -lX11 -lXss
#include <X11/Xlib.h>
#include <X11/extensions/scrnsaver.h>
#include <stdbool.h>
#include <unistd.h>


#define DECREASE 0
#define INCREASE 1

#define TIME_RANGE 1.0/1000.0                      // oneMillisecond
#define USLEEP_TIME_RANGE 1000000 * TIME_RANGE     // oneMillisecond 

#define TIME_IDLE 1000 * 120


void ChangeBrightness(int oldBrightness,float timeRange, char* filename, int sleepTime, bool decreaseBrightness ){
            
            
            float offset;
            float range =(float)oldBrightness * timeRange;
            FILE * brightnessFile;

            if (decreaseBrightness == 0){
            
               offset = oldBrightness;
               while (offset >=0){
            
                  offset -= range;
            
                  if (oldBrightness - (int)offset >= 1){
                     oldBrightness = (int)offset;

                     brightnessFile = fopen(filename, "w");

                     if (brightnessFile == NULL) {
                        printf("Impossible open the file\n");
                        break;
                     }

                     fprintf(brightnessFile, "%d", (int)offset);
                     fclose(brightnessFile);
                     }
   
                  usleep(sleepTime) ;
               }
            }
            else{
               
               offset = 0;
               int difference = 0;
               while (offset <= oldBrightness){
                  
                  offset += range;
            
                  if (offset - difference > 1){
                     difference = (int)offset;

                     brightnessFile = fopen(filename, "w");

                     if (brightnessFile == NULL) {
                        printf("Impossible open the file\n");
                        break;
                     }

                     fprintf(brightnessFile, "%d", (int)offset);
                     fclose(brightnessFile);
                     }
   
                  usleep(sleepTime);
               }
            }
        
           
}

int main(int argc, char const *argv[])
{
    Display *display;
    XScreenSaverInfo info;
    bool interlock = 0;
    int oldBrightness;
    FILE *brightnessFile;
   
    

    
    display = XOpenDisplay(NULL);

    if (display == NULL) {
        fprintf(stderr, "Impossibile aprire il display.\n");
        return 1;
    }
    

    while (1){
   
    XScreenSaverQueryInfo(display, DefaultRootWindow(display), &info);

        if (!interlock){
            sleep(1);
        }

        if (!interlock && info.idle > TIME_IDLE){
            brightnessFile = fopen("/sys/class/backlight/intel_backlight/brightness", "r+");
            
            if (brightnessFile == NULL) {
               printf("Impossibile aprire il file\n");
               break;
            }
            
            fscanf(brightnessFile, "%d", &oldBrightness);
            fclose(brightnessFile);

            ChangeBrightness(oldBrightness,TIME_RANGE,"/sys/class/backlight/intel_backlight/brightness",USLEEP_TIME_RANGE,DECREASE);
            interlock=1;

        }
        
        if (interlock && info.idle < 1000 ){ 
       
          
            ChangeBrightness(oldBrightness,TIME_RANGE,"/sys/class/backlight/intel_backlight/brightness",USLEEP_TIME_RANGE,INCREASE);   
            interlock=0;

         } 
    
   } 
    
    XCloseDisplay(display);

    return 0;

  
}
