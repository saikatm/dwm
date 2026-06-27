/* See LICENSE file for copyright and license details. */

/*
 * appearance
 *
 * font: see http://freedesktop.org/software/fontconfig/fontconfig-user.html
 */
static char *font = "JetBrainsMono Nerd Font:pixelsize=14:antialias=true:autohint=false";
#if FONT2_PATCH
/* Spare fonts */
static char *font2[] = {
/*	"Inconsolata for Powerline:pixelsize=12:antialias=true:autohint=true", */
/*	"Hack Nerd Font Mono:pixelsize=11:antialias=true:autohint=true", */
};
#endif // FONT2_PATCH

#if BACKGROUND_IMAGE_PATCH
static const char *bgfile = "/path/to/image.ff";
static const int pseudotransparency = 0;
#endif // BACKGROUND_IMAGE_PATCH

#if RELATIVEBORDER_PATCH
int borderperc = 20;
#else
static int borderpx = 8;
#endif // RELATIVEBORDER_PATCH

#if OPENURLONCLICK_PATCH
static uint url_opener_modkey = XK_ANY_MOD;
static char *url_opener = "xdg-open";
#endif // OPENURLONCLICK_PATCH

static char *shell = "/bin/sh";
char *utmp = NULL;
char *scroll = NULL;
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";

/* identification sequence returned in DA and DECID */
#if SIXEL_PATCH
char *vtiden = "\033[?62;4c";
int const sixelbyteorder = LSBFirst;
#else
char *vtiden = "\033[?6c";
#endif

/* Kerning / character bounding-box multipliers */
static float cwscale = 1.0;
static float chscale = 1.0;

wchar_t *worddelimiters = L" `'\"()[]{}";

#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
wchar_t *kbds_sdelim = L"!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ ";
wchar_t *kbds_ldelim = L" ";
#endif // KEYBOARDSELECT_PATCH

/* selection timeouts (in milliseconds) */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

/* alt screens */
int allowaltscreen = 1;

int allowwindowops = 0;

static double minlatency = 2;
static double maxlatency = 33;

#if SYNC_PATCH
static uint su_timeout = 200;
#endif // SYNC_PATCH

static unsigned int blinktimeout = 800;

/*
 * thickness of underline and bar cursors
 */
static unsigned int cursorthickness = 2;

#if HIDECURSOR_PATCH
int hidecursor = 1;
#endif // HIDECURSOR_PATCH

#if BOXDRAW_PATCH
/*
 * 1: render most of the lines/blocks characters without using the font for
 *    perfect alignment between cells (U2500 - U259F except dashes/diagonals).
 *    Bold affects lines thickness if boxdraw_bold is not 0. Italic is ignored.
 * 0: disable (render all U25XX glyphs normally from the font).
 */
const int boxdraw = 1;
const int boxdraw_bold = 1;
const int boxdraw_braille = 0;
#endif // BOXDRAW_PATCH

static int bellvolume = 0;

char *termname = "st-256color";

unsigned int tabspaces = 4;

#if ALPHA_PATCH
float alpha = 0.8;
#if ALPHA_GRADIENT_PATCH
float grad_alpha = 0.54;
float stat_alpha = 0.46;
#endif // ALPHA_GRADIENT_PATCH
#if ALPHA_FOCUS_HIGHLIGHT_PATCH
float alphaUnfocused = 0.6;
#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
#endif // ALPHA_PATCH

#if DRAG_AND_DROP_PATCH
char *xdndescchar = " !\"#$&'()*;<>?[\\]^`{|}~";
#endif // DRAG_AND_DROP_PATCH

/* Terminal colors (16 first used in escape sequence) */
/* Catppuccin Mocha */
static const char *colorname[] = {
	/* 8 normal colors */
	[0]  = "#45475a",  /* black   — Surface1    */
	[1]  = "#f38ba8",  /* red     — Red         */
	[2]  = "#a6e3a1",  /* green   — Green       */
	[3]  = "#f9e2af",  /* yellow  — Yellow      */
	[4]  = "#89b4fa",  /* blue    — Blue        */
	[5]  = "#cba6f7",  /* magenta — Mauve       */
	[6]  = "#94e2d5",  /* cyan    — Teal        */
	[7]  = "#bac2de",  /* white   — Subtext1    */

	/* 8 bright colors */
	[8]  = "#585b70",  /* bright black   — Surface2  */
	[9]  = "#f38ba8",  /* bright red     — Red       */
	[10] = "#a6e3a1",  /* bright green   — Green     */
	[11] = "#f9e2af",  /* bright yellow  — Yellow    */
	[12] = "#89b4fa",  /* bright blue    — Blue      */
	[13] = "#cba6f7",  /* bright magenta — Mauve     */
	[14] = "#94e2d5",  /* bright cyan    — Teal      */
	[15] = "#a6adc8",  /* bright white   — Subtext0  */

	[255] = 0,

	/* special colors */
	[256] = "#cba6f7",  /* cursor     — Mauve  */
	[257] = "#313244",  /* rev cursor — Surface0 */
	[258] = "#1e1e2e",  /* background — Base   */
	[259] = "#cdd6f4",  /* foreground — Text   */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
#if ALPHA_PATCH && ALPHA_FOCUS_HIGHLIGHT_PATCH
unsigned int defaultbg = 0;
unsigned int bg = 17, bgUnfocused = 16;
#else
unsigned int defaultbg = 258;
#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
unsigned int defaultfg = 259;
unsigned int defaultcs = 256;
unsigned int defaultrcs = 257;
#if SELECTION_COLORS_PATCH
unsigned int selectionfg = 258;
unsigned int selectionbg = 259;
static int ignoreselfg = 1;
#endif // SELECTION_COLORS_PATCH
#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
unsigned int highlightfg = 15;
unsigned int highlightbg = 160;
#endif // KEYBOARDSELECT_PATCH

#if BLINKING_CURSOR_PATCH
/*
 * https://invisible-island.net/xterm/ctlseqs/ctlseqs.html#h4-Functions-using-CSI-_-ordered-by-the-final-character-lparen-s-rparen:CSI-Ps-SP-q.1D81
 * Default style of cursor
 * 0: Blinking block
 * 1: Blinking block (default)
 * 2: Steady block ("█")
 * 3: Blinking underline
 * 4: Steady underline ("_")
 * 5: Blinking bar
 * 6: Steady bar ("|")
 * 7: Blinking st cursor
 * 8: Steady st cursor
 */
static unsigned int cursorstyle = 5; /* blinking bar — kitty style */
static Rune stcursor = 0x2603;
#else
/*
 * Default shape of cursor
 * 2: Block ("█")
 * 4: Underline ("_")
 * 6: Bar ("|")
 */
static unsigned int cursorshape = 6; /* bar — kitty style */
#endif // BLINKING_CURSOR_PATCH

static unsigned int cols = 80;
static unsigned int rows = 24;

#if ANYGEOMETRY_PATCH
static Geometry geometry = CellGeometry;
static unsigned int width = 564;
static unsigned int height = 364;
#endif // ANYGEOMETRY_PATCH

#if THEMED_CURSOR_PATCH
static char* mouseshape = "xterm";
#else
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;
#endif // THEMED_CURSOR_PATCH

static unsigned int defaultattr = 11;

#if XRESOURCES_PATCH
/*
 * Xresources preferences to load at startup
 * Live reload: kill -USR1 $(pidof st)
 */
ResourcePref resources[] = {
		{ "font",         STRING,  &font },
		{ "color0",       STRING,  &colorname[0] },
		{ "color1",       STRING,  &colorname[1] },
		{ "color2",       STRING,  &colorname[2] },
		{ "color3",       STRING,  &colorname[3] },
		{ "color4",       STRING,  &colorname[4] },
		{ "color5",       STRING,  &colorname[5] },
		{ "color6",       STRING,  &colorname[6] },
		{ "color7",       STRING,  &colorname[7] },
		{ "color8",       STRING,  &colorname[8] },
		{ "color9",       STRING,  &colorname[9] },
		{ "color10",      STRING,  &colorname[10] },
		{ "color11",      STRING,  &colorname[11] },
		{ "color12",      STRING,  &colorname[12] },
		{ "color13",      STRING,  &colorname[13] },
		{ "color14",      STRING,  &colorname[14] },
		{ "color15",      STRING,  &colorname[15] },
		{ "background",   STRING,  &colorname[258] },
		{ "foreground",   STRING,  &colorname[259] },
		{ "cursorColor",  STRING,  &colorname[256] },
		{ "termname",     STRING,  &termname },
		{ "shell",        STRING,  &shell },
		{ "minlatency",   INTEGER, &minlatency },
		{ "maxlatency",   INTEGER, &maxlatency },
		{ "blinktimeout", INTEGER, &blinktimeout },
		{ "bellvolume",   INTEGER, &bellvolume },
		{ "tabspaces",    INTEGER, &tabspaces },
		#if RELATIVEBORDER_PATCH
		{ "borderperc",   INTEGER, &borderperc },
		#else
		{ "borderpx",     INTEGER, &borderpx },
		#endif // RELATIVEBORDER_PATCH
		{ "cwscale",      FLOAT,   &cwscale },
		{ "chscale",      FLOAT,   &chscale },
		#if ALPHA_PATCH
		{ "alpha",        FLOAT,   &alpha },
		#endif // ALPHA_PATCH
		#if ALPHA_FOCUS_HIGHLIGHT_PATCH
		{ "alphaUnfocused",FLOAT,  &alphaUnfocused },
		#endif // ALPHA_FOCUS_HIGHLIGHT_PATCH
		#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
		{ "highlightfg",  INTEGER, &highlightfg },
		{ "highlightbg",  INTEGER, &highlightbg },
		#endif // KEYBOARDSELECT_PATCH
};
#endif // XRESOURCES_PATCH

static uint forcemousemod = ShiftMask;

/*
 * Internal mouse shortcuts.
 * Beware that overloading Button1 will disable the selection.
 */
static MouseShortcut mshortcuts[] = {
	/* mask                 button   function        argument       release  screen */
	#if OPEN_SELECTED_TEXT_PATCH
	{ ControlMask,          Button2, selopen,        {.i = 0},      1 },
	#endif // OPEN_SELECTED_TEXT_PATCH
	#if CLIPBOARD_PATCH
	{ XK_ANY_MOD,           Button2, clippaste,      {.i = 0},      1 },
	#else
	{ XK_ANY_MOD,           Button2, selpaste,       {.i = 0},      1 },
	#endif // CLIPBOARD_PATCH
	#if SCROLLBACK_MOUSE_PATCH
	{ ShiftMask,            Button4, kscrollup,      {.i = 1},      0, S_PRI},
	{ ShiftMask,            Button5, kscrolldown,    {.i = 1},      0, S_PRI},
	#elif UNIVERSCROLL_PATCH
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\033[5;2~"}, 0, S_PRI },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\033[6;2~"}, 0, S_PRI },
	#else
	{ ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
	{ ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
	#endif // SCROLLBACK_MOUSE_PATCH
	#if SCROLLBACK_MOUSE_ALTSCREEN_PATCH || REFLOW_PATCH
	{ XK_ANY_MOD,           Button4, kscrollup,      {.i = 1},      0, S_PRI },
	{ XK_ANY_MOD,           Button5, kscrolldown,    {.i = 1},      0, S_PRI },
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"}, 0, S_ALT },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"}, 0, S_ALT },
	#else
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
	#endif // SCROLLBACK_MOUSE_ALTSCREEN_PATCH
};

/*
 * Internal keyboard shortcuts.
 *
 * Kitty-style keybinds:
 *   Ctrl+Shift+C     copy
 *   Ctrl+Shift+V     paste
 *   Ctrl+Shift+Up    scroll up
 *   Ctrl+Shift+Down  scroll down
 *   Ctrl+Shift+Home  scroll to top
 *   Ctrl+Shift+End   scroll to bottom
 *   Ctrl+Equal       zoom in
 *   Ctrl+Minus       zoom out
 *   Ctrl+0           zoom reset
 */
#define MODKEY Mod1Mask
#define TERMMOD (ControlMask|ShiftMask)

#if EXTERNALPIPE_PATCH
static char *openurlcmd[] = { "/bin/sh", "-c",
	"xurls | dmenu -l 10 -w $WINDOWID | xargs -r open",
	"externalpipe", NULL };
#if EXTERNALPIPEIN_PATCH
static char *setbgcolorcmd[] = { "/bin/sh", "-c",
	"printf '\033]11;#008000\007'",
	"externalpipein", NULL };
#endif // EXTERNALPIPEIN_PATCH
#endif // EXTERNALPIPE_PATCH

static Shortcut shortcuts[] = {
	/* mask                 keysym           function         argument   screen */
	{ XK_ANY_MOD,           XK_Break,        sendbreak,       {.i =  0} },
	{ ControlMask,          XK_Print,        toggleprinter,   {.i =  0} },
	{ ShiftMask,            XK_Print,        printscreen,     {.i =  0} },
	{ XK_ANY_MOD,           XK_Print,        printsel,        {.i =  0} },

	/* zoom — kitty style: Ctrl+= / Ctrl+- / Ctrl+0 */
	{ ControlMask,          XK_equal,        zoom,            {.f = +1} },
	{ ControlMask,          XK_minus,        zoom,            {.f = -1} },
	{ ControlMask,          XK_0,            zoomreset,       {.f =  0} },
	/* zoom — also keep Ctrl+Shift+PgUp/Dn for compatibility */
	{ TERMMOD,              XK_Prior,        zoom,            {.f = +1} },
	{ TERMMOD,              XK_Next,         zoom,            {.f = -1} },
	{ TERMMOD,              XK_Home,         zoomreset,       {.f =  0} },

	/* copy/paste — kitty style: Ctrl+Shift+C / Ctrl+Shift+V */
	{ TERMMOD,              XK_C,            clipcopy,        {.i =  0} },
	{ TERMMOD,              XK_V,            clippaste,       {.i =  0} },
	{ TERMMOD,              XK_Y,            clippaste,       {.i =  0} },
	{ ShiftMask,            XK_Insert,       clippaste,       {.i =  0} },

	#if ALPHA_PATCH
	{ TERMMOD,              XK_O,            changealpha,     {.f = +0.05} },
	{ TERMMOD,              XK_P,            changealpha,     {.f = -0.05} },
	#endif // ALPHA_PATCH

	#if FULLSCREEN_PATCH
	{ XK_NO_MOD,            XK_F11,          fullscreen,      {.i =  0} },
	{ MODKEY,               XK_Return,       fullscreen,      {.i =  0} },
	#endif // FULLSCREEN_PATCH

	/* scrollback — kitty style: Ctrl+Shift+Up/Down/Home/End */
	#if SCROLLBACK_PATCH || REFLOW_PATCH
	{ TERMMOD,              XK_Up,           kscrollup,       {.i =  1}, S_PRI },
	{ TERMMOD,              XK_Down,         kscrolldown,     {.i =  1}, S_PRI },
	{ TERMMOD,              XK_Home,         kscrollup,       {.i = -1}, S_PRI },
	{ TERMMOD,              XK_End,          kscrolldown,     {.i = -1}, S_PRI },
	{ ShiftMask,            XK_Page_Up,      kscrollup,       {.i = -1}, S_PRI },
	{ ShiftMask,            XK_Page_Down,    kscrolldown,     {.i = -1}, S_PRI },
	#endif // SCROLLBACK_PATCH || REFLOW_PATCH

	{ TERMMOD,              XK_Num_Lock,     numlock,         {.i =  0} },

	#if COPYURL_PATCH || COPYURL_HIGHLIGHT_SELECTED_URLS_PATCH
	{ MODKEY,               XK_l,            copyurl,         {.i =  0} },
	#endif // COPYURL_PATCH
	#if OPENCOPIED_PATCH
	{ MODKEY,               XK_o,            opencopied,      {.v = "xdg-open"} },
	#endif // OPENCOPIED_PATCH
	#if NEWTERM_PATCH
	{ TERMMOD,              XK_Return,       newterm,         {.i =  0} },
	#endif // NEWTERM_PATCH
	#if EXTERNALPIPE_PATCH
	{ TERMMOD,              XK_U,            externalpipe,    { .v = openurlcmd } },
	#if EXTERNALPIPEIN_PATCH
	{ TERMMOD,              XK_M,            externalpipein,  { .v = setbgcolorcmd } },
	#endif // EXTERNALPIPEIN_PATCH
	#endif // EXTERNALPIPE_PATCH
	#if KEYBOARDSELECT_PATCH
	{ TERMMOD,              XK_Escape,       keyboard_select, { 0 } },
	#endif // KEYBOARDSELECT_PATCH
	#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
	{ TERMMOD,              XK_F,            searchforward,   { 0 } },
	{ TERMMOD,              XK_B,            searchbackward,  { 0 } },
	#endif // KEYBOARDSELECT_PATCH
	#if ISO14755_PATCH
	{ TERMMOD,              XK_I,            iso14755,        {.i =  0} },
	#endif // ISO14755_PATCH
	#if INVERT_PATCH
	{ TERMMOD,              XK_X,            invert,          { 0 } },
	#endif // INVERT_PATCH
	#if OSC133_PATCH
	{ ControlMask,          XK_Page_Up,      scrolltoprompt,  {.i = -1}, S_PRI },
	{ ControlMask,          XK_Page_Down,    scrolltoprompt,  {.i =  1}, S_PRI },
	#endif // OSC133_PATCH
};

/*
 * Special keys (change & recompile st.info accordingly)
 *
 * Mask value:
 * * Use XK_ANY_MOD to match the key no matter modifiers state
 * * Use XK_NO_MOD to match the key alone (no modifiers)
 * appkey value:
 * * 0: no value
 * * > 0: keypad application mode enabled
 * *   = 2: term.numlock = 1
 * * < 0: keypad application mode disabled
 * appcursor value:
 * * 0: no value
 * * > 0: cursor application mode enabled
 * * < 0: cursor application mode disabled
 */

#if !FIXKEYBOARDINPUT_PATCH
static KeySym mappedkeys[] = { -1 };
#endif // FIXKEYBOARDINPUT_PATCH

static uint ignoremod = Mod2Mask|XK_SWITCH_MOD;

#if !FIXKEYBOARDINPUT_PATCH
static Key key[] = {
	/* keysym           mask            string      appkey appcursor */
	{ XK_KP_Home,       ShiftMask,      "\033[2J",       0,   -1},
	{ XK_KP_Home,       ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_KP_Home,       XK_ANY_MOD,     "\033[H",        0,   -1},
	{ XK_KP_Home,       XK_ANY_MOD,     "\033[1~",       0,   +1},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033Ox",       +1,    0},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033[A",        0,   -1},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033OA",        0,   +1},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033Or",       +1,    0},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033[B",        0,   -1},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033OB",        0,   +1},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033Ot",       +1,    0},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033[D",        0,   -1},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033OD",        0,   +1},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033Ov",       +1,    0},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033[C",        0,   -1},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033OC",        0,   +1},
	{ XK_KP_Prior,      ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_KP_Prior,      XK_ANY_MOD,     "\033[5~",       0,    0},
	{ XK_KP_Begin,      XK_ANY_MOD,     "\033[E",        0,    0},
	{ XK_KP_End,        ControlMask,    "\033[J",       -1,    0},
	{ XK_KP_End,        ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[K",       -1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_KP_End,        XK_ANY_MOD,     "\033[4~",       0,    0},
	{ XK_KP_Next,       ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_KP_Next,       XK_ANY_MOD,     "\033[6~",       0,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[4l",      -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[L",       -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_KP_Insert,     XK_ANY_MOD,     "\033[4h",      -1,    0},
	{ XK_KP_Insert,     XK_ANY_MOD,     "\033[2~",      +1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[M",       -1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[2K",      -1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[3;2~",    +1,    0},
	#if DELKEY_PATCH
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      -1,    0},
	#else
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[P",       -1,    0},
	#endif // DELKEY_PATCH
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      +1,    0},
	{ XK_KP_Multiply,   XK_ANY_MOD,     "\033Oj",       +2,    0},
	{ XK_KP_Add,        XK_ANY_MOD,     "\033Ok",       +2,    0},
	{ XK_KP_Enter,      XK_ANY_MOD,     "\033OM",       +2,    0},
	{ XK_KP_Enter,      XK_ANY_MOD,     "\r",           -1,    0},
	{ XK_KP_Subtract,   XK_ANY_MOD,     "\033Om",       +2,    0},
	{ XK_KP_Decimal,    XK_ANY_MOD,     "\033On",       +2,    0},
	{ XK_KP_Divide,     XK_ANY_MOD,     "\033Oo",       +2,    0},
	{ XK_KP_0,          XK_ANY_MOD,     "\033Op",       +2,    0},
	{ XK_KP_1,          XK_ANY_MOD,     "\033Oq",       +2,    0},
	{ XK_KP_2,          XK_ANY_MOD,     "\033Or",       +2,    0},
	{ XK_KP_3,          XK_ANY_MOD,     "\033Os",       +2,    0},
	{ XK_KP_4,          XK_ANY_MOD,     "\033Ot",       +2,    0},
	{ XK_KP_5,          XK_ANY_MOD,     "\033Ou",       +2,    0},
	{ XK_KP_6,          XK_ANY_MOD,     "\033Ov",       +2,    0},
	{ XK_KP_7,          XK_ANY_MOD,     "\033Ow",       +2,    0},
	{ XK_KP_8,          XK_ANY_MOD,     "\033Ox",       +2,    0},
	{ XK_KP_9,          XK_ANY_MOD,     "\033Oy",       +2,    0},
	{ XK_Up,            ShiftMask,      "\033[1;2A",     0,    0},
	{ XK_Up,            Mod1Mask,       "\033[1;3A",     0,    0},
	{ XK_Up,         ShiftMask|Mod1Mask,"\033[1;4A",     0,    0},
	{ XK_Up,            ControlMask,    "\033[1;5A",     0,    0},
	{ XK_Up,      ShiftMask|ControlMask,"\033[1;6A",     0,    0},
	{ XK_Up,       ControlMask|Mod1Mask,"\033[1;7A",     0,    0},
	{ XK_Up,ShiftMask|ControlMask|Mod1Mask,"\033[1;8A",  0,    0},
	{ XK_Up,            XK_ANY_MOD,     "\033[A",        0,   -1},
	{ XK_Up,            XK_ANY_MOD,     "\033OA",        0,   +1},
	{ XK_Down,          ShiftMask,      "\033[1;2B",     0,    0},
	{ XK_Down,          Mod1Mask,       "\033[1;3B",     0,    0},
	{ XK_Down,       ShiftMask|Mod1Mask,"\033[1;4B",     0,    0},
	{ XK_Down,          ControlMask,    "\033[1;5B",     0,    0},
	{ XK_Down,    ShiftMask|ControlMask,"\033[1;6B",     0,    0},
	{ XK_Down,     ControlMask|Mod1Mask,"\033[1;7B",     0,    0},
	{ XK_Down,ShiftMask|ControlMask|Mod1Mask,"\033[1;8B",0,    0},
	{ XK_Down,          XK_ANY_MOD,     "\033[B",        0,   -1},
	{ XK_Down,          XK_ANY_MOD,     "\033OB",        0,   +1},
	{ XK_Left,          ShiftMask,      "\033[1;2D",     0,    0},
	{ XK_Left,          Mod1Mask,       "\033[1;3D",     0,    0},
	{ XK_Left,       ShiftMask|Mod1Mask,"\033[1;4D",     0,    0},
	{ XK_Left,          ControlMask,    "\033[1;5D",     0,    0},
	{ XK_Left,    ShiftMask|ControlMask,"\033[1;6D",     0,    0},
	{ XK_Left,     ControlMask|Mod1Mask,"\033[1;7D",     0,    0},
	{ XK_Left,ShiftMask|ControlMask|Mod1Mask,"\033[1;8D",0,    0},
	{ XK_Left,          XK_ANY_MOD,     "\033[D",        0,   -1},
	{ XK_Left,          XK_ANY_MOD,     "\033OD",        0,   +1},
	{ XK_Right,         ShiftMask,      "\033[1;2C",     0,    0},
	{ XK_Right,         Mod1Mask,       "\033[1;3C",     0,    0},
	{ XK_Right,      ShiftMask|Mod1Mask,"\033[1;4C",     0,    0},
	{ XK_Right,         ControlMask,    "\033[1;5C",     0,    0},
	{ XK_Right,   ShiftMask|ControlMask,"\033[1;6C",     0,    0},
	{ XK_Right,    ControlMask|Mod1Mask,"\033[1;7C",     0,    0},
	{ XK_Right,ShiftMask|ControlMask|Mod1Mask,"\033[1;8C",0,   0},
	{ XK_Right,         XK_ANY_MOD,     "\033[C",        0,   -1},
	{ XK_Right,         XK_ANY_MOD,     "\033OC",        0,   +1},
	{ XK_ISO_Left_Tab,  ShiftMask,      "\033[Z",        0,    0},
	{ XK_Return,        Mod1Mask,       "\033\r",        0,    0},
	{ XK_Return,        XK_ANY_MOD,     "\r",            0,    0},
	{ XK_Insert,        ShiftMask,      "\033[4l",      -1,    0},
	{ XK_Insert,        ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_Insert,        ControlMask,    "\033[L",       -1,    0},
	{ XK_Insert,        ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_Insert,        XK_ANY_MOD,     "\033[4h",      -1,    0},
	{ XK_Insert,        XK_ANY_MOD,     "\033[2~",      +1,    0},
	{ XK_Delete,        ControlMask,    "\033[M",       -1,    0},
	{ XK_Delete,        ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_Delete,        ShiftMask,      "\033[2K",      -1,    0},
	{ XK_Delete,        ShiftMask,      "\033[3;2~",    +1,    0},
	#if DELKEY_PATCH
	{ XK_Delete,        XK_ANY_MOD,     "\033[3~",      -1,    0},
	#else
	{ XK_Delete,        XK_ANY_MOD,     "\033[P",       -1,    0},
	#endif // DELKEY_PATCH
	{ XK_Delete,        XK_ANY_MOD,     "\033[3~",      +1,    0},
	{ XK_BackSpace,     XK_NO_MOD,      "\177",          0,    0},
	{ XK_BackSpace,     Mod1Mask,       "\033\177",      0,    0},
	{ XK_Home,          ShiftMask,      "\033[2J",       0,   -1},
	{ XK_Home,          ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_Home,          XK_ANY_MOD,     "\033[H",        0,   -1},
	{ XK_Home,          XK_ANY_MOD,     "\033[1~",       0,   +1},
	{ XK_End,           ControlMask,    "\033[J",       -1,    0},
	{ XK_End,           ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_End,           ShiftMask,      "\033[K",       -1,    0},
	{ XK_End,           ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_End,           XK_ANY_MOD,     "\033[4~",       0,    0},
	{ XK_Prior,         ControlMask,    "\033[5;5~",     0,    0},
	{ XK_Prior,         ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_Prior,         XK_ANY_MOD,     "\033[5~",       0,    0},
	{ XK_Next,          ControlMask,    "\033[6;5~",     0,    0},
	{ XK_Next,          ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_Next,          XK_ANY_MOD,     "\033[6~",       0,    0},
	{ XK_F1,            XK_NO_MOD,      "\033OP" ,       0,    0},
	{ XK_F1, /* F13 */  ShiftMask,      "\033[1;2P",     0,    0},
	{ XK_F1, /* F25 */  ControlMask,    "\033[1;5P",     0,    0},
	{ XK_F1, /* F37 */  Mod4Mask,       "\033[1;6P",     0,    0},
	{ XK_F1, /* F49 */  Mod1Mask,       "\033[1;3P",     0,    0},
	{ XK_F1, /* F61 */  Mod3Mask,       "\033[1;4P",     0,    0},
	{ XK_F2,            XK_NO_MOD,      "\033OQ" ,       0,    0},
	{ XK_F2, /* F14 */  ShiftMask,      "\033[1;2Q",     0,    0},
	{ XK_F2, /* F26 */  ControlMask,    "\033[1;5Q",     0,    0},
	{ XK_F2, /* F38 */  Mod4Mask,       "\033[1;6Q",     0,    0},
	{ XK_F2, /* F50 */  Mod1Mask,       "\033[1;3Q",     0,    0},
	{ XK_F2, /* F62 */  Mod3Mask,       "\033[1;4Q",     0,    0},
	{ XK_F3,            XK_NO_MOD,      "\033OR" ,       0,    0},
	{ XK_F3, /* F15 */  ShiftMask,      "\033[1;2R",     0,    0},
	{ XK_F3, /* F27 */  ControlMask,    "\033[1;5R",     0,    0},
	{ XK_F3, /* F39 */  Mod4Mask,       "\033[1;6R",     0,    0},
	{ XK_F3, /* F51 */  Mod1Mask,       "\033[1;3R",     0,    0},
	{ XK_F3, /* F63 */  Mod3Mask,       "\033[1;4R",     0,    0},
	{ XK_F4,            XK_NO_MOD,      "\033OS" ,       0,    0},
	{ XK_F4, /* F16 */  ShiftMask,      "\033[1;2S",     0,    0},
	{ XK_F4, /* F28 */  ControlMask,    "\033[1;5S",     0,    0},
	{ XK_F4, /* F40 */  Mod4Mask,       "\033[1;6S",     0,    0},
	{ XK_F4, /* F52 */  Mod1Mask,       "\033[1;3S",     0,    0},
	{ XK_F5,            XK_NO_MOD,      "\033[15~",      0,    0},
	{ XK_F5, /* F17 */  ShiftMask,      "\033[15;2~",    0,    0},
	{ XK_F5, /* F29 */  ControlMask,    "\033[15;5~",    0,    0},
	{ XK_F5, /* F41 */  Mod4Mask,       "\033[15;6~",    0,    0},
	{ XK_F5, /* F53 */  Mod1Mask,       "\033[15;3~",    0,    0},
	{ XK_F6,            XK_NO_MOD,      "\033[17~",      0,    0},
	{ XK_F6, /* F18 */  ShiftMask,      "\033[17;2~",    0,    0},
	{ XK_F6, /* F30 */  ControlMask,    "\033[17;5~",    0,    0},
	{ XK_F6, /* F42 */  Mod4Mask,       "\033[17;6~",    0,    0},
	{ XK_F6, /* F54 */  Mod1Mask,       "\033[17;3~",    0,    0},
	{ XK_F7,            XK_NO_MOD,      "\033[18~",      0,    0},
	{ XK_F7, /* F19 */  ShiftMask,      "\033[18;2~",    0,    0},
	{ XK_F7, /* F31 */  ControlMask,    "\033[18;5~",    0,    0},
	{ XK_F7, /* F43 */  Mod4Mask,       "\033[18;6~",    0,    0},
	{ XK_F7, /* F55 */  Mod1Mask,       "\033[18;3~",    0,    0},
	{ XK_F8,            XK_NO_MOD,      "\033[19~",      0,    0},
	{ XK_F8, /* F20 */  ShiftMask,      "\033[19;2~",    0,    0},
	{ XK_F8, /* F32 */  ControlMask,    "\033[19;5~",    0,    0},
	{ XK_F8, /* F44 */  Mod4Mask,       "\033[19;6~",    0,    0},
	{ XK_F8, /* F56 */  Mod1Mask,       "\033[19;3~",    0,    0},
	{ XK_F9,            XK_NO_MOD,      "\033[20~",      0,    0},
	{ XK_F9, /* F21 */  ShiftMask,      "\033[20;2~",    0,    0},
	{ XK_F9, /* F33 */  ControlMask,    "\033[20;5~",    0,    0},
	{ XK_F9, /* F45 */  Mod4Mask,       "\033[20;6~",    0,    0},
	{ XK_F9, /* F57 */  Mod1Mask,       "\033[20;3~",    0,    0},
	{ XK_F10,           XK_NO_MOD,      "\033[21~",      0,    0},
	{ XK_F10, /* F22 */ ShiftMask,      "\033[21;2~",    0,    0},
	{ XK_F10, /* F34 */ ControlMask,    "\033[21;5~",    0,    0},
	{ XK_F10, /* F46 */ Mod4Mask,       "\033[21;6~",    0,    0},
	{ XK_F10, /* F58 */ Mod1Mask,       "\033[21;3~",    0,    0},
	{ XK_F11,           XK_NO_MOD,      "\033[23~",      0,    0},
	{ XK_F11, /* F23 */ ShiftMask,      "\033[23;2~",    0,    0},
	{ XK_F11, /* F35 */ ControlMask,    "\033[23;5~",    0,    0},
	{ XK_F11, /* F47 */ Mod4Mask,       "\033[23;6~",    0,    0},
	{ XK_F11, /* F59 */ Mod1Mask,       "\033[23;3~",    0,    0},
	{ XK_F12,           XK_NO_MOD,      "\033[24~",      0,    0},
	{ XK_F12, /* F24 */ ShiftMask,      "\033[24;2~",    0,    0},
	{ XK_F12, /* F36 */ ControlMask,    "\033[24;5~",    0,    0},
	{ XK_F12, /* F48 */ Mod4Mask,       "\033[24;6~",    0,    0},
	{ XK_F12, /* F60 */ Mod1Mask,       "\033[24;3~",    0,    0},
	{ XK_F13,           XK_NO_MOD,      "\033[1;2P",     0,    0},
	{ XK_F14,           XK_NO_MOD,      "\033[1;2Q",     0,    0},
	{ XK_F15,           XK_NO_MOD,      "\033[1;2R",     0,    0},
	{ XK_F16,           XK_NO_MOD,      "\033[1;2S",     0,    0},
	{ XK_F17,           XK_NO_MOD,      "\033[15;2~",    0,    0},
	{ XK_F18,           XK_NO_MOD,      "\033[17;2~",    0,    0},
	{ XK_F19,           XK_NO_MOD,      "\033[18;2~",    0,    0},
	{ XK_F20,           XK_NO_MOD,      "\033[19;2~",    0,    0},
	{ XK_F21,           XK_NO_MOD,      "\033[20;2~",    0,    0},
	{ XK_F22,           XK_NO_MOD,      "\033[21;2~",    0,    0},
	{ XK_F23,           XK_NO_MOD,      "\033[23;2~",    0,    0},
	{ XK_F24,           XK_NO_MOD,      "\033[24;2~",    0,    0},
	{ XK_F25,           XK_NO_MOD,      "\033[1;5P",     0,    0},
	{ XK_F26,           XK_NO_MOD,      "\033[1;5Q",     0,    0},
	{ XK_F27,           XK_NO_MOD,      "\033[1;5R",     0,    0},
	{ XK_F28,           XK_NO_MOD,      "\033[1;5S",     0,    0},
	{ XK_F29,           XK_NO_MOD,      "\033[15;5~",    0,    0},
	{ XK_F30,           XK_NO_MOD,      "\033[17;5~",    0,    0},
	{ XK_F31,           XK_NO_MOD,      "\033[18;5~",    0,    0},
	{ XK_F32,           XK_NO_MOD,      "\033[19;5~",    0,    0},
	{ XK_F33,           XK_NO_MOD,      "\033[20;5~",    0,    0},
	{ XK_F34,           XK_NO_MOD,      "\033[21;5~",    0,    0},
	{ XK_F35,           XK_NO_MOD,      "\033[23;5~",    0,    0},
};
#endif // FIXKEYBOARDINPUT_PATCH

static uint selmasks[] = {
	[SEL_RECTANGULAR] = Mod1Mask,
};

static char ascii_printable[] =
	" !\"#$%&'()*+,-./0123456789:;<=>?"
	"@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
	"`abcdefghijklmnopqrstuvwxyz{|}~";

#if RIGHTCLICKTOPLUMB_PATCH
static char *plumb_cmd = "plumb";
#endif // RIGHTCLICKTOPLUMB_PATCH

#if UNDERCURL_PATCH
#define UNDERCURL_CURLY 0
#define UNDERCURL_SPIKY 1
#define UNDERCURL_CAPPED 2
/* Active undercurl style — CURLY looks best in nvim diagnostics */
#define UNDERCURL_STYLE UNDERCURL_CURLY
#endif // UNDERCURL_PATCH
