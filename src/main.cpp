#include <Arduino.h>

/* This is a small demo of the high-performance ThreadX kernel.  It includes examples of eight
   threads of different priorities, using a message queue, semaphore, mutex, event flags group, 
   byte pool, and block pool.  */

#include <tx_api.h>
#include <gx_api.h>
#include <gx_display.h>

#include <wio_terminal_demo_gui_resources.h>
#include <wio_terminal_demo_gui_specifications.h>

/* GUIX stuff */

#define GUIX_THREAD_STACK_SIZE  4096
#define GUIX_THREAD_PRIORITY    4 
#define CLOCK_TIMER         20

TX_THREAD                       guix_thread;
UCHAR                           guix_thread_stack[GUIX_THREAD_STACK_SIZE];


/* Define thread prototypes.  */

void    thread_guix_entry(ULONG thread_input);



/* Define what the initial system looks like.  */

void    tx_application_define(void *first_unused_memory)
{

(VOID)first_unused_memory;
CHAR    *pointer;

    /* Create the GUI thread. */
    UINT status = tx_thread_create(&guix_thread, 
            "GUIX Thread", 
            thread_guix_entry, 
            0, 
            guix_thread_stack,
            GUIX_THREAD_STACK_SIZE,
            GUIX_THREAD_PRIORITY,
            GUIX_THREAD_PRIORITY, 
            TX_NO_TIME_SLICE,
            TX_AUTO_START);
}


#include <TFT_eSPI.h>
TFT_eSPI tft;
// TFT_eSprite spr = TFT_eSprite(&tft); // main sprite


static void wioterminal_lcd_buffer_toggle(GX_CANVAS *canvas, GX_RECTANGLE *dirty) {
    for(int i = 0; i < 320*240; i++) {
        uint16_t pix = ((uint16_t*)canvas->gx_canvas_memory) [i];
        pix = pix << 8 | pix >> 8;
        ((uint16_t*)canvas->gx_canvas_memory) [i] = pix;
    }

    Serial.printf("%04x\n", ((uint16_t*)canvas->gx_canvas_memory) [0]);
    Serial.printf("%04x\n\n", ((uint16_t*)canvas->gx_canvas_memory) [1]);

    tft.pushImage(0, 0, 320, 240, (uint16_t*)canvas->gx_canvas_memory);

    for(int i = 0; i < 320*240; i++) {
        uint16_t pix = ((uint16_t*)canvas->gx_canvas_memory) [i];
        pix = pix << 8 | pix >> 8;
        ((uint16_t*)canvas->gx_canvas_memory) [i] = pix;
    }

}


UINT wioterminal_graphics_driver_setup(GX_DISPLAY *display) {
    _gx_display_driver_565rgb_setup(display, NULL, wioterminal_lcd_buffer_toggle);
    
    return GX_SUCCESS;
}

int progress_bar_val = 0; 

UINT main_window_event_process(GX_WINDOW *window, GX_EVENT *event_ptr) {
    switch (event_ptr->gx_event_type)
    {
        case GX_EVENT_SHOW:
            /* Start a timer to update the progress bar at regular intervals. */
            gx_system_timer_start((GX_WIDGET *)window, CLOCK_TIMER, 50, 2);

            /* Call default event process. */
            gx_window_event_process(window, event_ptr);

            break;
        case GX_EVENT_TIMER:
            Serial.printf("timer!");
            if (event_ptr->gx_event_payload.gx_event_timer_id == CLOCK_TIMER)
            {
                GX_PROGRESS_BAR *progress_bar = &MAIN_WINDOW.MAIN_WINDOW_progress_bar;
                gx_progress_bar_value_set(progress_bar, progress_bar_val);
                progress_bar_val++; 
                if(progress_bar_val > 100) {
                    progress_bar_val = 0;

                    GX_EVENT my_event;
                    memset(&my_event, 0, sizeof(GX_EVENT));
                    my_event.gx_event_type = LOADING_COMPLETE;
                    my_event.gx_event_target = (GX_WIDGET *) window;
                    gx_system_event_send(&my_event);
                    gx_system_timer_stop((GX_WIDGET *)window, CLOCK_TIMER);
                }

                GX_PROMPT *prompt = &MAIN_WINDOW.MAIN_WINDOW_prompt;
                GX_CONST GX_CHAR *text[] = { "This", "is", "taking", "a", "while..."};
                gx_prompt_text_set(prompt, text[(progress_bar_val / 20) % 5]);
            }
            // else if (event_ptr->gx_event_payload.gx_event_timer_id == 333) {
            // }
            break;
        default:
            return gx_window_event_process(window, event_ptr);
    }
}



VOID thread_guix_entry(ULONG thread_input)
{
    GX_WINDOW_ROOT *root;

    /* Initialize GUIX.  */
    gx_system_initialize();
    
    /* Setup graphics-related hardware and create the display. */
    gx_studio_display_configure(DISPLAY_1, wioterminal_graphics_driver_setup, LANGUAGE_ENGLISH, DISPLAY_1_THEME_1, &root);

    //gx_canvas_memory_define(root->gx_window_root_canvas, (GX_COLOR*)spr.frameBuffer(1), 320*240);

    /* create the main screen */
    gx_studio_named_widget_create("MAIN_WINDOW", (GX_WIDGET *) root, GX_NULL);

    /* create other screens */
    gx_studio_named_widget_create("SECOND_WINDOW", GX_NULL, GX_NULL);


    /* Show the root window to make it visible.  */
    gx_widget_show(root);

    /* start GUIX thread */
    gx_system_start();
} 

void setup()
{
    Serial.begin(115200);

    Serial.print("\r\nArduino Environment is Up\r\n");

    // init Wio Terminal display
    tft.begin();
    tft.setRotation(3); 
    //tft.fillScreen(TFT_BLACK);
    // spr.createSprite(
    //     30,
    //     30);
    // spr.setColorDepth(8);
    // spr.createSprite(tft.width(), tft.height());
    // spr.setSwapBytes(true);

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();
}

void loop()
{
    /* Should never be here */
    while(1);
}