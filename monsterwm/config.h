/* see LICENSE for copyright and license */

#ifndef CONFIG_H
#define CONFIG_H

/** modifiers **/
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */

/** generic settings **/
#define MASTER_SIZE     0.52
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False means panel is on bottom */
#define PANEL_HEIGHT    20        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    TILE      /* initial layout/mode: TILE MONOCLE BSTACK GRID FLOAT */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_WINDOW   False     /* follow the window when moved to a different desktop */
#define FOLLOW_MOUSE    True      /* focus the window the mouse just entered */
#define CLICK_TO_FOCUS  True      /* focus an unfocused window when clicked  */
#define FOCUS_BUTTON    Button3   /* mouse button to be used along with CLICK_TO_FOCUS */
#define BORDER_WIDTH    2         /* window border width */
#define FOCUS           "#DE935F" /* focused window border color    */
#define UNFOCUS         "#131517" /* unfocused window border color  */
#define MINWSZ          50        /* minimum window size in pixels  */
#define DEFAULT_DESKTOP 0         /* the desktop to focus initially */
#define DESKTOPS        7         /* number of desktops - edit DESKTOPCHANGE keys to suit */

/**
 * open applications to specified desktop with specified mode.
 * if desktop is negative, then current is assumed
 */
static const AppRule rules[] = { \
    /*  class     desktop  follow  float */
    /* { "MPlayer",     -1,    True,   True }, */
    { "feh",         -1,    True,   True },
};

/* helper for spawning shell commands */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/**
 * custom commands
 * must always end with ', NULL };'
 */
static const char *termcmd[] = { "urxvt",     NULL };
static const char *menucmd[] = { "dmenu_run_aliases", "-fn", "Lemon-9", "-nb", "#131517", "-nf", "#aaa", "-sb", "#49545E", "-sf", "#111", "-i", "-h", "20", NULL };
static const char *volupcmd[] = { "pamixer", "--increase", "5", NULL };
static const char *voldowncmd[] = { "pamixer", "--decrease", "5", NULL };
static const char *volmutecmd[] = { "pamixer", "--toggle-mute", NULL };
static const char *xcompcmd[] = { "/home/william/bin/togglecomp", NULL };

#define DESKTOPCHANGE(K,N) \
    {  MOD1,             K,              change_desktop, {.i = N}}, \
    {  MOD1|ShiftMask,   K,              client_to_desktop, {.i = N}},

/**
 * keyboard shortcuts
 */
static Key keys[] = {
    /* modifier          key            function           argument */
    {  MOD1,             XK_b,          togglepanel,       {NULL}},
    {  MOD1,             XK_BackSpace,  focusurgent,       {NULL}},
    {  MOD4,             XK_q,          killclient,        {NULL}},
    {  MOD1,             XK_Right,      next_win,          {NULL}},
    {  MOD1,             XK_Left,       prev_win,          {NULL}},
    {  MOD4,             XK_t,          resize_master,     {.i = -15}}, /* decrease size in px */
    {  MOD4,             XK_r,          resize_master,     {.i = +15}}, /* increase size in px */
    {  MOD4,             XK_d,          resize_stack,      {.i = -15}}, /* shrink   size in px */
    {  MOD4,             XK_s,          resize_stack,      {.i = +15}}, /* grow     size in px */
    {  MOD1|CONTROL,     XK_Left,       rotate,            {.i = -1}},
    {  MOD1|CONTROL,     XK_Right,      rotate,            {.i = +1}},
    {  MOD1|SHIFT,       XK_h,          rotate_filled,     {.i = -1}},
    {  MOD1|SHIFT,       XK_l,          rotate_filled,     {.i = +1}},
    {  MOD1,             XK_Tab,        last_desktop,      {NULL}},
    {  MOD1,             XK_Return,     swap_master,       {NULL}},
    {  MOD1|SHIFT,       XK_l,          move_down,         {NULL}},
    {  MOD1|SHIFT,       XK_g,          move_up,           {NULL}},
    {  MOD1|SHIFT,       XK_t,          switch_mode,       {.i = TILE}},
    {  MOD1|SHIFT,       XK_m,          switch_mode,       {.i = MONOCLE}},
    {  MOD1|SHIFT,       XK_b,          switch_mode,       {.i = BSTACK}},
    {  MOD1|SHIFT,       XK_g,          switch_mode,       {.i = GRID}},
    {  MOD1|SHIFT,       XK_f,          switch_mode,       {.i = FLOAT}},
    {  MOD1|CONTROL,     XK_r,          quit,              {.i = 0}}, /* quit with exit value 0 */
    {  MOD1|CONTROL,     XK_q,          quit,              {.i = 1}}, /* quit with exit value 1 */
    {  MOD4,             XK_Return,     spawn,             {.com = termcmd}},
    {  MOD4,             XK_v,          spawn,             {.com = menucmd}},
    {  MOD1,             0xffab,        spawn,             {.com = volupcmd}}, /* Augmenter le volume  touche multimédia */
    {  MOD1,             0xffad,        spawn,             {.com = voldowncmd}}, /* réduire le volume */
    {  MOD1,             0xffb0,        spawn,             {.com = volmutecmd}}, /* muet */
    {  MOD1,             XK_x,          spawn,             {.com = xcompcmd}}, /* xcompmgr */
    {  MOD1,             XK_j,          moveresize,        {.v = (int []){   0,  25,   0,   0 }}}, /* move down  */
    {  MOD1,             XK_k,          moveresize,        {.v = (int []){   0, -25,   0,   0 }}}, /* move up    */
    {  MOD1,             XK_l,          moveresize,        {.v = (int []){  25,   0,   0,   0 }}}, /* move right */
    {  MOD1,             XK_h,          moveresize,        {.v = (int []){ -25,   0,   0,   0 }}}, /* move left  */
    {  MOD4|SHIFT,       XK_j,          moveresize,        {.v = (int []){   0,   0,   0,  25 }}}, /* height grow   */
    {  MOD4|SHIFT,       XK_k,          moveresize,        {.v = (int []){   0,   0,   0, -25 }}}, /* height shrink */
    {  MOD4|SHIFT,       XK_l,          moveresize,        {.v = (int []){   0,   0,  25,   0 }}}, /* width grow    */
    {  MOD4|SHIFT,       XK_h,          moveresize,        {.v = (int []){   0,   0, -25,   0 }}}, /* width shrink  */
       DESKTOPCHANGE(    XK_F1,                             0)
       DESKTOPCHANGE(    XK_F2,                             1)
       DESKTOPCHANGE(    XK_F3,                             2)
       DESKTOPCHANGE(    XK_F4,                             3)
       DESKTOPCHANGE(    XK_F5,                             4)
       DESKTOPCHANGE(    XK_F6,                             5)
       DESKTOPCHANGE(    XK_F7,                             6)
};

/**
 * mouse shortcuts
 */
static Button buttons[] = {
    {  MOD4,    Button1,     mousemotion,   {.i = MOVE}},
    {  MOD4,    Button3,     mousemotion,   {.i = RESIZE}},
};
#endif

/* vim: set expandtab ts=4 sts=4 sw=4 : */
