/*
 * $Id: encode.c,v 1.4 1998/07/03 06:53:17 glehner Exp $
 * History:
 * $Log: encode.c,v $
 * Revision 1.4  1998/07/03 06:53:17  glehner
 * fixed missing spaces in Write_ISO8859_1
 *
 * Revision 1.3  1997/02/15 20:48:22  ralf
 * Removed separate declaration of globals.
 *
 * Revision 1.2  1995/05/10 06:37:43  ralf
 * Added own includefile (for consistency checking of decls)
 *
 * Revision 1.1  1995/03/23  16:09:01  ralf
 * Initial revision
 *
 */
/***************************************************************************
   name : encode.c
 author : POLZER Friedrich, TRISKO Gerhard 
purpose : to convert Latin-1 
 ****************************************************************************/

/********************************* includes *********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "fonts.h"
#include "funct1.h"
#include "encode.h"
/*****************************************************************************/

/******************************************************************************/
void Write_ISO_8859_1 (char theChar)
/******************************************************************************
     purpose : converts theChar (ISO 8859-1) to an equivalent Rtf-Command
   parameter : theChar  will be converted, result is written to Rtf-file
     globals : fRtf
 ******************************************************************************/
{
  switch ((unsigned char) theChar)
    {
      /*LEG140498Begin
	The first "8" conversions had no space at the end and therefore did
	not translate to the correct character.
	
	Also I changed the very first case value to octal notation, because in
	decimal notation it did not convert. Ask me why????
	*/
      /*case 246:fprintf(fRtf, "\\ansi\\'f6\\pc");*/
    case 0366:fprintf(fRtf, "\\ansi\\'f6\\pc ");
      break; /* "o */
    case 214:fprintf(fRtf, "\\ansi\\'d6\\pc ");
      break; /* "O */
    case 228:fprintf(fRtf, "\\ansi\\'e4\\pc ");
      break; /* "a */
    case 196:fprintf(fRtf, "\\ansi\\'c4\\pc ");
      break; /* "A */
    case 252:fprintf(fRtf, "\\ansi\\'fc\\pc ");
      break; /* "u */
    case 220:fprintf(fRtf, "\\ansi\\'dc\\pc ");
      break; /* "U */
    case 203:fprintf(fRtf, "\\ansi\\'cb\\pc ");
      break; /* "E */
    case 207:fprintf(fRtf, "\\ansi\\'cf\\pc ");
      break; /* "I */
    case 235:fprintf(fRtf, "\\ansi\\'eb\\pc ");
      break; /* "e */
    case 239:fprintf(fRtf, "\\ansi\\'ef\\pc ");
      break; /* "i */
    case 255:fprintf(fRtf, "\\ansi\\'ff\\pc ");
      break; /* "y */
      /*LEG140498End*/

    case 192:fprintf(fRtf, "\\ansi\\'c0\\pc ");
             break; /* `A */
    case 200:fprintf(fRtf, "\\ansi\\'c8\\pc ");
             break; /* `E */
    case 204:fprintf(fRtf, "\\ansi\\'cc\\pc ");
             break; /* `I */
    case 210:fprintf(fRtf, "\\ansi\\'d2\\pc ");
             break; /* `O */
    case 217:fprintf(fRtf, "\\ansi\\'d9\\pc ");
             break; /* `U */
    case 224:fprintf(fRtf, "\\ansi\\'e0\\pc ");
             break; /* `a */
    case 232:fprintf(fRtf, "\\ansi\\'e8\\pc ");
             break; /* `e */
    case 236:fprintf(fRtf, "\\ansi\\'ec\\pc ");
             break; /* `i */
    case 242:fprintf(fRtf, "\\ansi\\'f2\\pc ");
             break; /* `o */
    case 249:fprintf(fRtf, "\\ansi\\'f9\\pc ");
             break; /* `u */

    case 193:fprintf(fRtf, "\\ansi\\'c1\\pc ");
             break; /* 'A */
    case 201:fprintf(fRtf, "\\ansi\\'c9\\pc ");
             break; /* 'E */
    case 205:fprintf(fRtf, "\\ansi\\'cd\\pc ");
             break; /* 'I */
    case 211:fprintf(fRtf, "\\ansi\\'d3\\pc ");
             break; /* 'O */
    case 218:fprintf(fRtf, "\\ansi\\'da\\pc ");
             break; /* 'U */
    case 225:fprintf(fRtf, "\\ansi\\'e1\\pc ");
             break; /* 'a */
    case 233:fprintf(fRtf, "\\ansi\\'e9\\pc ");
             break; /* 'e */
    case 237:fprintf(fRtf, "\\ansi\\'ed\\pc ");
             break; /* 'i */
    case 243:fprintf(fRtf, "\\ansi\\'f3\\pc ");
             break; /* 'o */
    case 250:fprintf(fRtf, "\\ansi\\'fa\\pc ");
             break; /* 'u */
    case 221:fprintf(fRtf, "\\ansi\\'dd\\pc ");
             break; /* 'Y */
    case 253:fprintf(fRtf, "\\ansi\\'fd\\pc ");
             break; /* 'y */

    case 194:fprintf(fRtf, "\\ansi\\'c2\\pc ");
             break; /* ^A */
    case 202:fprintf(fRtf, "\\ansi\\'ca\\pc ");
             break; /* ^E */
    case 206:fprintf(fRtf, "\\ansi\\'ce\\pc ");
             break; /* ^I */
    case 212:fprintf(fRtf, "\\ansi\\'d4\\pc ");
             break; /* ^O */
    case 219:fprintf(fRtf, "\\ansi\\'db\\pc ");
             break; /* ^U */
    case 226:fprintf(fRtf, "\\ansi\\'e2\\pc ");
             break; /* ^a */
    case 234:fprintf(fRtf, "\\ansi\\'ea\\pc ");
             break; /* ^e */
    case 238:fprintf(fRtf, "\\ansi\\'ee\\pc ");
             break; /* ^i */
    case 244:fprintf(fRtf, "\\ansi\\'f4\\pc ");
             break; /* ^o */
    case 251:fprintf(fRtf, "\\ansi\\'fb\\pc ");
             break; /* ^u */
 
    case 195:fprintf(fRtf, "\\ansi\\'c3\\pc ");
             break; /* ~A */
    case 213:fprintf(fRtf, "\\ansi\\'d5\\pc ");
             break; /* ~O */
    case 227:fprintf(fRtf, "\\ansi\\'e3\\pc ");
             break; /* ~a */
    case 245:fprintf(fRtf, "\\ansi\\'f5\\pc ");
             break; /* ~o */
    case 209:fprintf(fRtf, "\\ansi\\'d1\\pc ");
             break; /* ~N */
    case 241:fprintf(fRtf, "\\ansi\\'f1\\pc ");
             break; /* ~n */

    case 223:fprintf(fRtf, "\\ansi\\'df\\pc ");
             break; /* sz */
    case 161:fprintf(fRtf, "\\ansi\\'a1\\pc ");
             break; /* ! */
    case 162:fprintf(fRtf, "\\ansi\\'a2\\pc ");
             break; /* cent */
    case 163:fprintf(fRtf, "\\ansi\\'a3\\pc ");
             break; /* pound */
    case 164:fprintf(fRtf, "\\ansi\\'a4\\pc ");
             break; /*  */
    case 165:fprintf(fRtf, "\\ansi\\'a5\\pc ");
             break; /* Yen */
    case 166:fprintf(fRtf, "\\ansi\\'a6\\pc ");
             break; /* pipe */
    case 167:fprintf(fRtf, "\\ansi\\'a7\\pc ");
             break; /* paragraph */
    case 168:fprintf(fRtf, "\\ansi\\'a8\\pc ");
             break; /* dots */
    case 169:fprintf(fRtf, "\\ansi\\'a9\\pc ");
             break; /* copyright */
    case 170:fprintf(fRtf, "\\ansi\\'aa\\pc ");
             break; /* a_ */
    case 171:fprintf(fRtf, "\\ansi\\'ab\\pc ");
             break; /* << */
    case 172:fprintf(fRtf, "\\ansi\\'ac\\pc ");
             break; /* -| */
    case 173:fprintf(fRtf, "\\ansi\\'ad\\pc ");
             break; /* - */
    case 174:fprintf(fRtf, "\\ansi\\'ae\\pc ");
             break; /* registered */
    case 175:fprintf(fRtf, "\\ansi\\'af\\pc ");
             break; /* highscore */
    case 176:fprintf(fRtf, "\\ansi\\'b0\\pc ");
             break; /* degree */
    case 177:fprintf(fRtf, "\\ansi\\'b1\\pc ");
             break; /* +- */
    case 178:fprintf(fRtf, "\\ansi\\'b2\\pc ");
             break; /* ^2 */
    case 179:fprintf(fRtf, "\\ansi\\'b3\\pc ");
             break; /* ^3 */
    case 180:fprintf(fRtf, "\\ansi\\'b4\\pc ");
             break; /* ' */
    case 181:fprintf(fRtf, "\\ansi\\'b5\\pc ");
             break; /* my */
    case 182:fprintf(fRtf, "\\ansi\\'b6\\pc ");
             break; /* pi */
    case 183:fprintf(fRtf, "\\ansi\\'b7\\pc ");
             break; /* bullet */
    case 184:fprintf(fRtf, "\\ansi\\'b8\\pc ");
             break; /* dot */
    case 185:fprintf(fRtf, "\\ansi\\'b9\\pc ");
             break; /* ^1 */
    case 186:fprintf(fRtf, "\\ansi\\'ba\\pc ");
             break; /* ^0_ */
    case 187:fprintf(fRtf, "\\ansi\\'bb\\pc ");
             break; /* >> */
    case 188:fprintf(fRtf, "\\ansi\\'bc\\pc ");
             break; /* 1/4 */
    case 189:fprintf(fRtf, "\\ansi\\'bd\\pc ");
             break; /* 1/2 */
    case 190:fprintf(fRtf, "\\ansi\\'be\\pc ");
             break; /* 3/4 */
    case 191:fprintf(fRtf, "\\ansi\\'bf\\pc ");
             break; /* ? */

    case 197:fprintf(fRtf, "\\ansi\\'c5\\pc ");
             break; /* oA */
    case 198:fprintf(fRtf, "\\ansi\\'c6\\pc ");
             break; /* AE */
    case 199:fprintf(fRtf, "\\ansi\\'c7\\pc ");
             break; /* french C */

    case 208:fprintf(fRtf, "\\ansi\\'d0\\pc ");
             break; /* D */

    case 215:fprintf(fRtf, "\\ansi\\'d7\\pc ");
             break; /* x */
    case 216:fprintf(fRtf, "\\ansi\\'d8\\pc ");
             break; /* /O */

    case 222:fprintf(fRtf, "\\ansi\\'de\\pc ");
             break; /*  */

    case 229:fprintf(fRtf, "\\ansi\\'e5\\pc ");
             break; /* oa */
    case 230:fprintf(fRtf, "\\ansi\\'e6\\pc ");
             break; /* ae */
    case 231:fprintf(fRtf, "\\ansi\\'e7\\pc ");
             break; /* french c */

    case 240:fprintf(fRtf, "\\ansi\\'f0\\pc ");
             break; /*  */

    case 247:fprintf(fRtf, "\\ansi\\'f7\\pc ");
             break; /* / */
    case 248:fprintf(fRtf, "\\ansi\\'f8\\pc ");
             break; /* /o */

    case 254:fprintf(fRtf, "\\ansi\\'fe\\pc ");
             break; /*  */

    default:
             fprintf (fRtf, "%c", theChar);      /* other characters are
						    written out unchanged */
   }
}
