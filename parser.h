/*
 * $Id: parser.h,v 1.1 1998/10/27 04:46:43 glehner Exp $
 * History:
 * $Log: parser.h,v $
 * Revision 1.1  1998/10/27 04:46:43  glehner
 * Initial revision
 *
 *
 * LEG 070798 adapted Frank Barnes contribution to r2l coding conventions
 */
/****************************************************************************/
/* file: parser.h                                                           */
/*                                                                          */
/* Description:                                                             */
/*    Contains declarations for a generic recursive parser the              */
/*    LaTex2RTF code.                                                       */
/*                                                                          */
/* Revision history                                                         */
/* ================                                                         */
/* 26th June 1998 - Created initial version - fb                            */
/****************************************************************************/

#define POSSTACKSIZE   256  /* Size of stack to save positions              */

void CmdIgnoreParameter(int);
char *GetParam();
bool GetBracketParam(char *string, int size);
void GetBraceParam(char *string, int size);
void rewind_one(void);

/****************************************************************************/
/* End of file parser.h                                                     */
/****************************************************************************/
