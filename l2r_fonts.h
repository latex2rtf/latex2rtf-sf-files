/*
 * $Id: fonts.h,v 1.2 1997/02/15 20:55:50 ralf Exp $
 * History:
 * $Log: fonts.h,v $
 * Revision 1.2  1997/02/15 20:55:50  ralf
 * Some reformatting and changes suggested by lclint
 * Removed direct access to data structures in cfg.c
 *
 * Revision 1.1  1994/06/17 11:26:29  ralf
 * Initial revision
 *
 */

#define F_ROMAN        1
#define F_SLANTED      2
#define F_SANSSERIF    3
#define F_TYPEWRITER   4
#define F_ROMAN_1      5
#define F_SLANTED_1    6
#define F_SANSSERIF_1  7
#define F_TYPEWRITER_1 8

#define CMD_BOLD 1
#define CMD_ITALIC 2
#define CMD_UNDERLINE 3
#define CMD_CAPS 4
#define CMD_BOLD_1 5
#define CMD_ITALIC_1 6
#define CMD_CAPS_1 7

/* ----------------------------------- */
#define CMD_CENTERED 8
/* ----------------------------------- */

void            WriteFontHeader( /* @dependent@ */ FILE * fRtf);
bool            SetFont(char *TexFont, FILE * fRtf);
size_t          GetFontNumber(char *Fname);
void            RemoveFontlist(void);
size_t          getTexFontNumber(char *Fname);

void            CmdSetFontStyle(int code);
void            CmdSetFont(int code);
void            CmdSetFontSize(int code);
void            SetDocumentFontSize(int code);
int             CurrentFontSize(void);
void            BasicSetFontSize(int code);
