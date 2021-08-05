/*******************************************************************************/
/*  This file is auto-generated by Azure RTOS GUIX Studio. Do not edit this    */
/*  file by hand. Modifications to this file should only be made by running    */
/*  the Azure RTOS GUIX Studio application and re-generating the application   */
/*  specification file(s). For more information please refer to the Azure RTOS */
/*  GUIX Studio User Guide, or visit our web site at azure.com/rtos            */
/*                                                                             */
/*  GUIX Studio Revision 6.1.8.0                                               */
/*  Date (dd.mm.yyyy):  5. 8.2021   Time (hh:mm): 18:33                        */
/*******************************************************************************/


#define GUIX_STUDIO_GENERATED_FILE
#include <stddef.h>
#include "wio_terminal_demo_gui_resources.h"
#include "wio_terminal_demo_gui_specifications.h"

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent);
SECOND_WINDOW_CONTROL_BLOCK SECOND_WINDOW;
MAIN_WINDOW_CONTROL_BLOCK MAIN_WINDOW;
GX_DISPLAY display_1_control_block;
GX_WINDOW_ROOT display_1_root_window;
GX_CANVAS  display_1_canvas_control_block;
ULONG      display_1_canvas_memory[38400];

extern GX_CONST GX_THEME *display_1_theme_table[];
extern GX_CONST GX_STRING *display_1_language_table[];

GX_STUDIO_DISPLAY_INFO wio_terminal_demo_gui_display_table[1] =
{
    {
    "display_1",
    "display_1_canvas",
    display_1_theme_table,
    display_1_language_table,
    DISPLAY_1_THEME_TABLE_SIZE,
    DISPLAY_1_LANGUAGE_TABLE_SIZE,
    DISPLAY_1_STRING_TABLE_SIZE,
    320,                                     /* x resolution                   */
    240,                                     /* y resolution                   */
    &display_1_control_block,
    &display_1_canvas_control_block,
    &display_1_root_window,
    display_1_canvas_memory,                 /* canvas memory area             */
    153600,                                  /* canvas memory size in bytes    */
    GX_SCREEN_ROTATION_NONE                  /* rotation angle                 */
    }
};

static VOID gx_studio_screen_toggle(GX_WIDGET *target1, GX_WIDGET *target2)
{
    GX_WIDGET *parent = target1->gx_widget_parent;
    if (parent)
    {
        gx_widget_detach(target1);
        gx_widget_attach(parent, target2);
        if (target1->gx_widget_status & GX_STATUS_STUDIO_CREATED)
        {
            gx_widget_delete(target1);
        }
    }
}

static GX_WIDGET *gx_studio_action_target_get(GX_WIDGET *current, GX_CONST GX_STUDIO_ACTION *action)
{
    GX_WIDGET *parent = GX_NULL;
    GX_WIDGET *target = GX_NULL;
    INT        search_depth;
    GX_STUDIO_WIDGET *widget_define;

    if (action->flags & GX_ACTION_FLAG_DYNAMIC_TARGET)
    {
                                             /* dynamically create the target widget */
        widget_define = (GX_STUDIO_WIDGET *) action->target;
        if(action->flags & GX_ACTION_FLAG_DYNAMIC_PARENT)
        {
            gx_window_root_find(current, (GX_WINDOW_ROOT **)&parent);
            search_depth = GX_SEARCH_DEPTH_INFINITE;
        }
        else
        {
            parent = (GX_WIDGET *)action->parent;
            search_depth = 1;
        }
        gx_widget_find(parent, widget_define->widget_id, search_depth, &target);
        if (target == GX_NULL)
        {
            target = gx_studio_widget_create(GX_NULL, widget_define, GX_NULL);
        }
        if (target)
        {
            target->gx_widget_status |= GX_STATUS_STUDIO_CREATED;
        }
    }
    else
    {
        target = (GX_WIDGET *) action->target;
    }
    return target;
}

static GX_WIDGET *gx_studio_action_target_find(GX_WIDGET *current, GX_CONST GX_STUDIO_ACTION *action)
{
    GX_WIDGET *parent = GX_NULL;
    GX_WIDGET *target = GX_NULL;
    GX_STUDIO_WIDGET *widget_define;

    if (action->flags & GX_ACTION_FLAG_DYNAMIC_TARGET)
    {
                                             /* Find the dynamically created target */
        widget_define = (GX_STUDIO_WIDGET *) action->target;
        if(action->flags & GX_ACTION_FLAG_DYNAMIC_PARENT)
        {
            gx_window_root_find(current, (GX_WINDOW_ROOT **)&parent);
        }
        else
        {
            parent = (GX_WIDGET *)action->parent;
        }
        gx_widget_find(parent, widget_define->widget_id, GX_SEARCH_DEPTH_INFINITE, &target);
    }
    else
    {
        target = (GX_WIDGET *) action->target;
    }
    return target;
}

static GX_WIDGET *gx_studio_action_parent_find(GX_WIDGET *current, GX_CONST GX_STUDIO_ACTION *action)
{
GX_WIDGET *parent = GX_NULL;
GX_STUDIO_WIDGET *widget_define;

    if (action->flags & GX_ACTION_FLAG_DYNAMIC_PARENT)
    {
                                             /* Find the dynamically created target */
        widget_define = (GX_STUDIO_WIDGET *)action->parent; 
        gx_window_root_find(current, (GX_WINDOW_ROOT **)&parent); 
        gx_widget_find(parent, widget_define->widget_id, GX_SEARCH_DEPTH_INFINITE, &parent); 
    }
    else
    {
        parent = (GX_WIDGET *)action->parent; 
    }
    return parent; 
}

static VOID gx_studio_animation_execute(GX_WIDGET *current, GX_CONST GX_STUDIO_ACTION *action)
{
    GX_ANIMATION *animation;
    GX_ANIMATION_INFO animation_info;
    GX_WIDGET *parent = GX_NULL;
    GX_WIDGET *target = GX_NULL;
    gx_system_animation_get(&animation);
    if (animation)
    {
        animation_info = *action->animation;

        if((action->flags & GX_ACTION_FLAG_POP_TARGET) ||
           (action->flags & GX_ACTION_FLAG_POP_PARENT))
        {
            gx_system_screen_stack_get((GX_WIDGET **)&parent, &target);
        }

        if(action->flags & GX_ACTION_FLAG_POP_TARGET)
        {
            animation_info.gx_animation_target = target;
        }

        if(action->flags & GX_ACTION_FLAG_POP_PARENT)
        {
            animation_info.gx_animation_parent = (GX_WIDGET *)parent;
        }

        if ((!animation_info.gx_animation_target) &&
            (action->flags & GX_ACTION_FLAG_DYNAMIC_TARGET))
        {
            target = gx_studio_action_target_get(current, action);
            animation_info.gx_animation_target = target;
        }

        if (!animation_info.gx_animation_parent)
        {
            animation_info.gx_animation_parent = gx_studio_action_parent_find(current, action);
        }

        if (animation_info.gx_animation_target &&
            animation_info.gx_animation_parent)
        {
            gx_animation_start(animation, &animation_info);
        }
    }
}

UINT gx_studio_auto_event_handler(GX_WIDGET *widget, GX_EVENT *event_ptr, GX_CONST GX_STUDIO_EVENT_PROCESS *record)
{
    UINT status = GX_SUCCESS;
    GX_CONST GX_STUDIO_ACTION *action;
    GX_CONST GX_WIDGET *parent = GX_NULL;
    GX_WIDGET *target = GX_NULL;
    GX_CONST GX_STUDIO_EVENT_ENTRY *entry = record->event_table;

    while(entry->event_type)
    {
        if (entry->event_type == event_ptr->gx_event_type)
        {
            if((entry->event_type == GX_EVENT_ANIMATION_COMPLETE) &&
               (entry->event_sender != event_ptr->gx_event_sender))
            {
                entry++;
                continue;
            }
            action = entry->action_list;

            while(action->opcode)
            {
                switch(action->opcode)
                {
                case GX_ACTION_TYPE_ATTACH:
                    if((action->flags & GX_ACTION_FLAG_POP_TARGET) ||
                       (action->flags & GX_ACTION_FLAG_POP_PARENT))
                    {
                        gx_system_screen_stack_get((GX_WIDGET **)&parent, &target);
                    }

                    if(!(action->flags & GX_ACTION_FLAG_POP_PARENT))
                    {
                        parent = action->parent;
                    }
                    if(!(action->flags & GX_ACTION_FLAG_POP_TARGET))
                    {
                        target = gx_studio_action_target_get(widget, action);
                    }
                    if (parent && target)
                    {
                        gx_widget_attach(parent, target);
                    }
                    break;

                case GX_ACTION_TYPE_DETACH:
                    target = gx_studio_action_target_find(widget, action);
                    if (target)
                    {
                        gx_widget_detach(target);
                        if (target->gx_widget_status & GX_STATUS_STUDIO_CREATED)
                        {
                            gx_widget_delete(target);
                        }
                    }
                    break;

                case GX_ACTION_TYPE_TOGGLE:
                    if(action->flags & GX_ACTION_FLAG_POP_TARGET)
                    {
                       gx_system_screen_stack_get(GX_NULL, &target);
                    }
                    else
                    {
                        target = gx_studio_action_target_get(widget, action);
                    }
                    gx_studio_screen_toggle(widget, target);
                    break;

                case GX_ACTION_TYPE_SHOW:
                    target = gx_studio_action_target_get(widget, action);
                    if(target)
                    {
                        gx_widget_show(target);
                    }
                    break;

                case GX_ACTION_TYPE_HIDE:
                    target = gx_studio_action_target_find(widget, action);
                    if(target)
                    {
                        gx_widget_hide(target);
                    }
                    break;

                case GX_ACTION_TYPE_ANIMATION:
                    gx_studio_animation_execute(widget, action);
                    break;

                case GX_ACTION_TYPE_WINDOW_EXECUTE:
                    if((action->flags & GX_ACTION_FLAG_POP_TARGET) ||
                       (action->flags & GX_ACTION_FLAG_POP_PARENT))
                    {
                        gx_system_screen_stack_get((GX_WIDGET **)&parent, &target);
                    }

                    if(!(action->flags & GX_ACTION_FLAG_POP_PARENT))
                    {
                        parent = widget->gx_widget_parent;
                    }
                    if(!(action->flags & GX_ACTION_FLAG_POP_TARGET))
                    {
                        target = gx_studio_action_target_get(widget, action);
                    }
                    if (parent && target)
                    {
                        gx_widget_attach(parent, target);
                        gx_window_execute((GX_WINDOW *) target, GX_NULL);
                    }
                    break;

                case GX_ACTION_TYPE_WINDOW_EXECUTE_STOP:
                    return event_ptr->gx_event_sender;

                case GX_ACTION_TYPE_SCREEN_STACK_PUSH:
                    target = gx_studio_action_target_get(widget, action);
                    if(target)
                    {
                        gx_system_screen_stack_push(target);
                    }
                    break;

                case GX_ACTION_TYPE_SCREEN_STACK_POP:
                    gx_system_screen_stack_pop();
                    break;

                case GX_ACTION_TYPE_SCREEN_STACK_RESET:
                    gx_system_screen_stack_reset();
                    break;

                default:
                    break;
                }
                action++;
            }
        }
        entry++;
    }

    if (record->chain_event_handler)
    {
        status = record->chain_event_handler(widget, event_ptr);
    }
    return status;
}


UINT gx_studio_icon_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_ICON *icon = (GX_ICON *) control_block;
    GX_ICON_PROPERTIES *props = (GX_ICON_PROPERTIES *) info->properties;
    status = gx_icon_create(icon, info->widget_name, parent, props->normal_pixelmap_id, info->style, info->widget_id, info->size.gx_rectangle_left, info->size.gx_rectangle_top);
    if (props->selected_pixelmap_id)
    {
        gx_icon_pixelmap_set(icon, props->normal_pixelmap_id, props->selected_pixelmap_id);
    }
    return status;
}

UINT gx_studio_progress_bar_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_PROGRESS_BAR *bar = (GX_PROGRESS_BAR *) control_block;
    GX_PROGRESS_BAR_INFO *bar_info = (GX_PROGRESS_BAR_INFO *) info->properties;
    status = gx_progress_bar_create(bar,
                    info->widget_name,
                    parent,
                    bar_info,
                    info->style,
                    info->widget_id,
                    &info->size);
    return status;
}

UINT gx_studio_prompt_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_PROMPT *prompt = (GX_PROMPT *) control_block;
    GX_PROMPT_PROPERTIES *props = (GX_PROMPT_PROPERTIES *) info->properties;
    status = gx_prompt_create(prompt, info->widget_name, parent, props->string_id, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        gx_prompt_font_set(prompt, props->font_id);
#if defined(GUIX_5_4_0_COMPATIBILITY)
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id);
#else
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id, props->disabled_text_color_id);
#endif
    }
    return status;
}

UINT gx_studio_window_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_WINDOW *window = (GX_WINDOW *) control_block;
    GX_WINDOW_PROPERTIES *props = (GX_WINDOW_PROPERTIES *) info->properties;
    status = gx_window_create(window, info->widget_name, parent, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        if (props->wallpaper_id)
        {
            gx_window_wallpaper_set(window, props->wallpaper_id, info->style & GX_STYLE_TILE_WALLPAPER);
        }
    }
    return status;
}
GX_WINDOW_PROPERTIES SECOND_WINDOW_properties =
{
    0                                        /* wallpaper pixelmap id          */
};
GX_ICON_PROPERTIES SECOND_WINDOW_icon_properties =
{
    GX_PIXELMAP_ID_WHISKEY_IMG,              /* normal pixelmap id             */
    0                                        /* selected pixelmap id           */
};

GX_CONST GX_STUDIO_WIDGET SECOND_WINDOW_icon_define =
{
    "icon",
    GX_TYPE_ICON,                            /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED|GX_STYLE_HALIGN_CENTER|GX_STYLE_VALIGN_CENTER,   /* style flags */
    0,                                       /* status flags                   */
    sizeof(GX_ICON),                         /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_create,                   /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {0, 0, 319, 239},                        /* widget size                    */
    GX_NULL,                                 /* no next widget                 */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(SECOND_WINDOW_CONTROL_BLOCK, SECOND_WINDOW_icon), /* control block */
    (void *) &SECOND_WINDOW_icon_properties  /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET SECOND_WINDOW_define =
{
    "SECOND_WINDOW",
    GX_TYPE_WINDOW,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED,   /* style flags                    */
    0,                                       /* status flags                   */
    sizeof(SECOND_WINDOW_CONTROL_BLOCK),     /* control block size             */
    GX_COLOR_ID_SELECTED_TEXT,               /* normal color id                */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_window_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {0, 0, 319, 239},                        /* widget size                    */
    GX_NULL,                                 /* next widget                    */
    &SECOND_WINDOW_icon_define,              /* child widget                   */
    0,                                       /* control block                  */
    (void *) &SECOND_WINDOW_properties       /* extended properties            */
};
GX_WINDOW_PROPERTIES MAIN_WINDOW_properties =
{
    0                                        /* wallpaper pixelmap id          */
};
GX_PROMPT_PROPERTIES MAIN_WINDOW_prompt_properties =
{
    GX_STRING_ID_STRING_5,                   /* string id                      */
    GX_FONT_ID_SANDYKIDS,                    /* font id                        */
    GX_COLOR_ID_SELECTED_TEXT,               /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_DISABLED_TEXT                /* disabled text color            */
};
GX_PROGRESS_BAR_INFO MAIN_WINDOW_progress_bar_properties =
{
    0,                                       /* mimimun value                  */
    100,                                     /* maximum value                  */
    0,                                       /* current value                  */
    GX_FONT_ID_SYSTEM,                       /* font_id                        */
    GX_COLOR_ID_SELECTED_TEXT,               /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_DISABLED_TEXT,               /* disabled text color            */
    0                                        /* fill pixelmap                  */
};

GX_CONST GX_STUDIO_WIDGET MAIN_WINDOW_progress_bar_define =
{
    "progress_bar",
    GX_TYPE_PROGRESS_BAR,                    /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_RAISED|GX_STYLE_ENABLED|GX_STYLE_PROGRESS_PERCENT|GX_STYLE_PROGRESS_TEXT_DRAW,   /* style flags */
    0,                                       /* status flags                   */
    sizeof(GX_PROGRESS_BAR),                 /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_progress_bar_create,           /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {14, 170, 313, 217},                     /* widget size                    */
    GX_NULL,                                 /* no next widget                 */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(MAIN_WINDOW_CONTROL_BLOCK, MAIN_WINDOW_progress_bar), /* control block */
    (void *) &MAIN_WINDOW_progress_bar_properties /* extended properties       */
};

GX_CONST GX_STUDIO_WIDGET MAIN_WINDOW_prompt_define =
{
    "prompt",
    GX_TYPE_PROMPT,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    0,                                       /* status flags                   */
    sizeof(GX_PROMPT),                       /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_prompt_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {2, 80, 321, 121},                       /* widget size                    */
    &MAIN_WINDOW_progress_bar_define,        /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(MAIN_WINDOW_CONTROL_BLOCK, MAIN_WINDOW_prompt), /* control block  */
    (void *) &MAIN_WINDOW_prompt_properties  /* extended properties            */
};

GX_ANIMATION_INFO MAIN_WINDOW_animation_1 = {
    (GX_WIDGET *) &SECOND_WINDOW,
    (GX_WIDGET *) &display_1_root_window,
    GX_NULL,
    GX_ANIMATION_TRANSLATE|GX_ANIMATION_EXPO_EASE_OUT, 0, 0, 1,
    {0, 0}, {0, 0}, 0, 255, 50
};


GX_STUDIO_ACTION MAIN_WINDOW_on_loading_completeactions[3] = {
    {GX_ACTION_TYPE_ATTACH, 0, &display_1_root_window, &SECOND_WINDOW, GX_NULL},
    {GX_ACTION_TYPE_ANIMATION, 0, &display_1_root_window, &SECOND_WINDOW, &MAIN_WINDOW_animation_1},
    {0, 0, GX_NULL, GX_NULL, GX_NULL}
};

static GX_STUDIO_EVENT_ENTRY gx_studio_MAIN_WINDOW_event_table[] = {
    { LOADING_COMPLETE, 0, MAIN_WINDOW_on_loading_completeactions},
    {0, 0, GX_NULL}
};

GX_STUDIO_EVENT_PROCESS MAIN_WINDOW_event_chain = {gx_studio_MAIN_WINDOW_event_table, (UINT (*)(GX_WIDGET *, GX_EVENT *))main_window_event_process};
static UINT gx_studio_MAIN_WINDOW_event_process(GX_WIDGET *target, GX_EVENT *event_ptr)
{
    return (gx_studio_auto_event_handler(target, event_ptr, &MAIN_WINDOW_event_chain));
}


GX_CONST GX_STUDIO_WIDGET MAIN_WINDOW_define =
{
    "MAIN_WINDOW",
    GX_TYPE_WINDOW,                          /* widget type                    */
    GX_ID_NONE,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED,   /* style flags */
    0,                                       /* status flags                   */
    sizeof(MAIN_WINDOW_CONTROL_BLOCK),       /* control block size             */
    GX_COLOR_ID_MAGENTA,                     /* normal color id                */
    GX_COLOR_ID_WINDOW_FILL,                 /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_window_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    (UINT (*)(GX_WIDGET *, GX_EVENT *)) gx_studio_MAIN_WINDOW_event_process, /* event function override */
    {0, 0, 319, 239},                        /* widget size                    */
    GX_NULL,                                 /* next widget                    */
    &MAIN_WINDOW_prompt_define,              /* child widget                   */
    0,                                       /* control block                  */
    (void *) &MAIN_WINDOW_properties         /* extended properties            */
};
GX_CONST GX_STUDIO_WIDGET_ENTRY wio_terminal_demo_gui_widget_table[] =
{
    { &SECOND_WINDOW_define, (GX_WIDGET *) &SECOND_WINDOW },
    { &MAIN_WINDOW_define, (GX_WIDGET *) &MAIN_WINDOW },
    {GX_NULL, GX_NULL}
};

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    UINT status = GX_SUCCESS;
    GX_WIDGET *widget = GX_NULL;
    GX_VALUE   list_count = 0;
    GX_VALUE   list_total_count = 0;

    if(parent && (parent->gx_widget_type == GX_TYPE_MENU))
    {
        list_total_count = ((GX_MENU *)parent)->gx_menu_list_total_count;
    }

    while(definition && status == GX_SUCCESS)
    {
        if (definition->create_function)
        {
            if (definition->style & GX_STYLE_DYNAMICALLY_ALLOCATED)
            {
                status = gx_widget_allocate(&widget, definition->control_block_size);
                if (status != GX_SUCCESS)
                {
                    return GX_NULL;
                }
            }
            else
            {
                if (control == GX_NULL)
                {
                    return GX_NULL;
                }
                widget = (GX_WIDGET *) (control + definition->control_block_offset);
            }

            status = definition->create_function(definition, widget, parent);

            if(list_count < list_total_count)
            {
                gx_menu_insert((GX_MENU *)parent, widget);
                ((GX_MENU *)parent)->gx_menu_list_total_count--;
                list_count++;
            }

            if (status == GX_SUCCESS)
            {
                if (definition->widget_type != GX_TYPE_TEMPLATE)
                {
#if defined(GUIX_5_4_0_COMPATIBILITY)
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id);
#else
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id, definition->disabled_fill_color_id);
#endif
                }

                if (!(definition->status & GX_STATUS_ACCEPTS_FOCUS))
                {
                    gx_widget_status_remove(widget, GX_STATUS_ACCEPTS_FOCUS);
                }

                if (definition->draw_function)
                {
                    gx_widget_draw_set(widget, definition->draw_function);
                }
                if (definition->event_function)
                {
                    gx_widget_event_process_set(widget, definition->event_function);
                }

                #if defined(GX_WIDGET_USER_DATA)
                widget->gx_widget_user_data = definition->user_data;
                #endif

                if (definition->child_widget)
                {
                    gx_studio_nested_widget_create(control, definition->child_widget, widget);
                }
            }
            definition = definition->next_widget;
        }
    }
    return widget;
}

GX_WIDGET *gx_studio_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    GX_WIDGET *widget;
    widget = gx_studio_nested_widget_create(control, definition, GX_NULL);

    if (parent && widget)
    {
        gx_widget_attach(parent, widget);
    }
    return widget;
}

UINT gx_studio_named_widget_create(char *name, GX_WIDGET *parent, GX_WIDGET **new_widget)
{
    UINT status = GX_FAILURE;
    GX_CONST GX_STUDIO_WIDGET_ENTRY *entry = wio_terminal_demo_gui_widget_table;
    GX_WIDGET *widget = GX_NULL;

    while(entry->widget_information)
    {
        if (!strcmp(name, entry->widget_information->widget_name))
        {
            widget = gx_studio_widget_create((GX_BYTE *) entry->widget, entry->widget_information, parent);
            if (widget)
            {
                status = GX_SUCCESS;
            }
            break;
        }
        entry++;
    }

    if (new_widget)
    {
        *new_widget = widget;
    }
    return status;
}


UINT gx_studio_display_configure(USHORT display, UINT (*driver)(GX_DISPLAY *),
    GX_UBYTE language, USHORT theme, GX_WINDOW_ROOT **return_root)
{
    GX_CONST GX_THEME *theme_ptr;
    GX_RECTANGLE size;

    GX_STUDIO_DISPLAY_INFO *display_info = &wio_terminal_demo_gui_display_table[display];


/* create the requested display                                                */

    gx_display_create(display_info->display,
                      display_info->name,
                      driver,
                      (GX_VALUE) display_info->x_resolution,
                      (GX_VALUE) display_info->y_resolution);


/* install the request theme                                                   */

    if(display_info->theme_table)
    {
        theme_ptr = display_info->theme_table[theme];
        if(theme_ptr)
        {
            gx_display_color_table_set(display_info->display, theme_ptr->theme_color_table, theme_ptr->theme_color_table_size);
            
/* install the color palette if required                                       */
            if (display_info->display->gx_display_driver_palette_set &&
                theme_ptr->theme_palette != NULL)
            {
                display_info->display->gx_display_driver_palette_set(display_info->display, theme_ptr->theme_palette, theme_ptr->theme_palette_size);
            }

            gx_display_font_table_set(display_info->display, theme_ptr->theme_font_table, theme_ptr->theme_font_table_size);
            gx_display_pixelmap_table_set(display_info->display, theme_ptr->theme_pixelmap_table, theme_ptr->theme_pixelmap_table_size);
            gx_system_scroll_appearance_set(theme_ptr->theme_vertical_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_vertical_scrollbar_appearance);
            gx_system_scroll_appearance_set(theme_ptr->theme_horizontal_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_horizontal_scrollbar_appearance);
            gx_display_language_table_set_ext(display_info->display, display_info->language_table, (GX_UBYTE) display_info->language_table_size, display_info->string_table_size);
            gx_display_active_language_set(display_info->display, language);
        }
    }

/* Set screen rotation angle.                                                  */

    display_info->display->gx_display_rotation_angle = display_info->rotation_angle;

/* create the canvas for this display                                          */

    gx_canvas_create(display_info->canvas,
                     display_info->canvas_name,
                     display_info->display,
                     GX_CANVAS_MANAGED | GX_CANVAS_VISIBLE,
                     display_info->x_resolution,
                     display_info->y_resolution,
                     display_info->canvas_memory,
                     display_info->canvas_memory_size);

/* Create the root window for this canvas                                      */

    gx_utility_rectangle_define(&size,
                                0, 0,
                                (GX_VALUE) (display_info->x_resolution - 1),
                                (GX_VALUE) (display_info->y_resolution - 1));

    gx_window_root_create(display_info->root_window,
                          display_info->name,
                          display_info->canvas, GX_STYLE_NONE, 0, &size);
    if (return_root)
    {
        *return_root = display_info->root_window;
    }
    return GX_SUCCESS;
}
#undef GUIX_STUDIO_GENERATED_FILE
