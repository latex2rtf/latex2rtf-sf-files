/***************************************************************************
   name : chars.c
 author : PRAHL, Scott
 
 Contributions by,  
          DORNER Fernando, 
          GRANZER Andreas
          POLZER, Friedrich,
          TRISKO, Gerhard
          TAUPIN, Daniel
          LEHNER, Georg

purpose : handles special characters and logos
          
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "commands.h"
#include "l2r_fonts.h"
#include "cfg.h"
#include "ignore.h"
#include "util.h"
#include "encode.h"
#include "parser.h"
#include "chars.h"

void TeXlogo();
void LaTeXlogo();

void CmdUmlauteChar(int code)
/*****************************************************************************
CmdUmlaute

 purpose : converts german symbols from LaTeX to Rtf
 globals : fRtf
 ******************************************************************************/
{
  size_t num;
  char *cParam = GetParam();
  if (cParam == NULL) return;
  
  switch(cParam[0])
  {
    case 'o': fprintf(fRtf,"{\\ansi\\'f6}");
	      break;
    case 'O': fprintf(fRtf,"{\\ansi\\'d6}");
	      break;
    case 'a': fprintf(fRtf,"{\\ansi\\'e4}");
	      break;
    case 'A': fprintf(fRtf,"{\\ansi\\'c4}");
	      break;
    case 'u': fprintf(fRtf,"{\\ansi\\'fc}");
	      break;
    case 'U': fprintf(fRtf,"{\\ansi\\'dc}");
	      break;
    case 'E':fprintf(fRtf, "{\\ansi\\'cb}");
	     break;
    case 'I':fprintf(fRtf, "{\\ansi\\'cf}");
	     break;
    case 'e':fprintf(fRtf, "{\\ansi\\'eb}");
	     break;
    case 'i':fprintf(fRtf, "{\\ansi\\'ef}");
	     break;
    case 'y':fprintf(fRtf, "{\\ansi\\'ff}");
	     break;

    default:
      num = GetFontNumber("MT Extra");
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'26\\'26))}", cParam[0], num);
      fprintf(fRtf, "{\\fldrslt }}");
      break;

  }
  free (cParam);
}

void CmdLApostrophChar(/*@unused@*/ int code)
/******************************************************************************
 purpose: converts special symbols from LaTex to Rtf
 globals : fRtf
 ******************************************************************************/
{
  size_t num;
  char *cParam = GetParam();
  if (cParam == NULL) return;
  
  switch(cParam[0])
  {
    case 'A':fprintf(fRtf, "{\\ansi\\'c0}");
	     break;
    case 'E':fprintf(fRtf, "{\\ansi\\'c8}");
	     break;
    case 'I':fprintf(fRtf, "{\\ansi\\'cc}");
	     break;
    case 'O':fprintf(fRtf, "{\\ansi\\'d2}");
	     break;
    case 'U':fprintf(fRtf, "{\\ansi\\'d9}");
	     break;
    case 'a':fprintf(fRtf, "{\\ansi\\'e0}");
	     break;
    case 'e':fprintf(fRtf, "{\\ansi\\'e8}");
	     break;
    case 'i':fprintf(fRtf, "{\\ansi\\'ec}");
	     break;
    case 'o':fprintf(fRtf, "{\\ansi\\'f2}");
	     break;
    case 'u':fprintf(fRtf, "{\\ansi\\'f9}");
	     break;
	default:
      num = GetFontNumber("MT Extra");
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'23))}", cParam[0], num);
      fprintf(fRtf, "{\\fldrslt }}");
      break;
  }
  free (cParam);
}

void CmdRApostrophChar(/*@unused@*/ int code)
/******************************************************************************
 purpose: converts special symbols from LaTex to Rtf
 globals : fRtf
 ******************************************************************************/
{
  char *cParam = GetParam();
  if (cParam == NULL) return;
  
  switch(cParam[0])
  {
    case 'A':fprintf(fRtf, "{\\ansi\\'c1}");
	     break;
    case 'E':fprintf(fRtf, "{\\ansi\\'c9}");
	     break;
    case 'I':fprintf(fRtf, "{\\ansi\\'cd}");
	     break;
    case 'O':fprintf(fRtf, "{\\ansi\\'d3}");
	     break;
    case 'U':fprintf(fRtf, "{\\ansi\\'da}");
	     break;
    case 'a':fprintf(fRtf, "{\\ansi\\'e1}");
	     break;
    case 'e':fprintf(fRtf, "{\\ansi\\'e9}");
	     break;
    case 'i':fprintf(fRtf, "{\\ansi\\'ed}");
	     break;
    case 'o':fprintf(fRtf, "{\\ansi\\'f3}");
	     break;
    case 'u':fprintf(fRtf, "{\\ansi\\'fa}");
	     break;
    case 'y':fprintf(fRtf, "{\\ansi\\'fd}");
	     break;
    case 'Y':fprintf(fRtf, "{\\ansi\\'dd}");
	     break;
	default:
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,\\\\S(\\'b4))}", cParam[0]);
      fprintf(fRtf, "{\\fldrslt }}");
      break;

  }
  free (cParam);
}

void CmdMacronChar(int code)
/******************************************************************************
 purpose: converts special symbols from LaTex to Rtf
 ******************************************************************************/
{
  int upsize;
  char *cParam = GetParam();
  if (cParam == NULL) return;

  switch(cParam[0])
  {
    case 'a':
    case 'c':
    case 'e':
    case 'g':
    case 'i':
    case 'j':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf,"(%c,\\\\S(\\'af))}", cParam[0]);
      fprintf(fRtf, "{\\fldrslt }}");
      break;

    default: 
      upsize = (0.05*CurrentFontSize())+0.45;
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf,"(%c,\\\\S\\\\up%d(\\'af))}", cParam[0], upsize);
      fprintf(fRtf, "{\\fldrslt }}");
 }

  free (cParam);
}

void CmdHatChar(int code)
/******************************************************************************
 purpose: \^{o} and \hat{o} symbols from LaTex to Rtf
 globals : fRtf
 ******************************************************************************/
{
  size_t num;
  char *cParam = GetParam();
  if (cParam == NULL) return;

  switch(cParam[0])
  {
    case 'A':fprintf(fRtf, "{\\ansi\\'c2}");
	     break;
    case 'E':fprintf(fRtf, "{\\ansi\\'ca}");
	     break;
    case 'I':fprintf(fRtf, "{\\ansi\\'ce}");
	     break;
    case 'O':fprintf(fRtf, "{\\ansi\\'d4}");
	     break;
    case 'U':fprintf(fRtf, "{\\ansi\\'db}");
	     break;
    case 'a':fprintf(fRtf, "{\\ansi\\'e2}");
	     break;
    case 'e':fprintf(fRtf, "{\\ansi\\'ea}");
	     break;
    case 'i':fprintf(fRtf, "{\\ansi\\'ee}");
	     break;
    case 'o':fprintf(fRtf, "{\\ansi\\'f4}");
	     break;
    case 'u':fprintf(fRtf, "{\\ansi\\'fb}");
	     break;

    default:
      num = GetFontNumber("MT Extra");
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'24))}", cParam[0], num);
      fprintf(fRtf, "{\\fldrslt }}");
      break;
  }

  free (cParam);
}

void CmdOaccentChar(int code)
/******************************************************************************
 purpose: converts \r accents from LaTex to Rtf
 ******************************************************************************/
{
  size_t num;
 
  char *cParam = GetParam();
  if (cParam == NULL) return;

  switch(cParam[0])
  {
    case 'A':  fprintf(fRtf, "{\\ansi\\'c5}");
               break;
               
    case 'a':  fprintf(fRtf, "{\\ansi\\'e5}");
               break;
               
    case '\\': if (strcmp(cParam,"\\i") == 0)
                  fprintf(fRtf, "\\'ee");
               else
                  fprintf(stderr,"Cannot put \\r on '%s'",cParam);
               break;
               
    case 'c':
    case 'e':
    case 'g':
    case 'i':
    case 'j':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      num = GetTexFontNumber("MacRoman");
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'fb ))}", cParam[0], num);
      fprintf(fRtf, "{\\fldrslt }}");
      break;

    default:
          num = GetTexFontNumber("MacRoman");
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'fb))}", cParam[0], num);
      fprintf(fRtf, "{\\fldrslt }}");
  }

  free (cParam);
}

void CmdTildeChar(/*@unused@*/ int code)
/******************************************************************************
 purpose: converts \~{n} from LaTex to Rtf
 globals : fRtf
 ******************************************************************************/
{
  size_t num;
  char *cParam = GetParam();
  if (cParam == NULL) return;

  switch(cParam[0])
  {
    case 'A':fprintf(fRtf, "{\\ansi\\'c3}");
	     break;
    case 'O':fprintf(fRtf, "{\\ansi\\'d5}");
	     break;
    case 'a':fprintf(fRtf, "{\\ansi\\'e3}");
	     break;
    case 'o':fprintf(fRtf, "{\\ansi\\'f5}");
	     break;
    case 'n':fprintf(fRtf, "{\\ansi\\'f1}");
	     break;
    case 'N':fprintf(fRtf, "{\\ansi\\'d1}");
	     break;
    default:
      num = GetFontNumber("MT Extra");
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'25))}", cParam[0], num);
      fprintf(fRtf, "{\\fldrslt }}");
      break;
  }
  free (cParam);
}

/*****************************************************************************
 purpose: converts \c{c} from LaTex to Rtf
 ******************************************************************************/
void CmdCedillaChar(/*@unused@*/ int code)
{
  char *cParam = GetParam();
  if (cParam == NULL) return;

  switch(cParam[0])
  {
     case 'C':fprintf(fRtf, "{\\ansi\\'c7}");
             break;
     case 'c': fprintf(fRtf,"{\\ansi\\'e7}");
            break;
            
     default:
            fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
            fprintf(fRtf, "(%c,\\'b8)}", cParam[0]);
            fprintf(fRtf, "{\\fldrslt }}");
            break;
  }
  
  free (cParam);
}

/*****************************************************************************
 purpose: converts \vec{o} from LaTex to Rtf
 ******************************************************************************/
void CmdVecChar(/*@unused@*/ int code)
{
  size_t num;
  int upsize;

  char *cParam = GetParam();
  if (cParam == NULL) return;

  switch(cParam[0])
  {
    case 'a':
    case 'c':
    case 'e':
    case 'g':
    case 'i':
    case 'j':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
             upsize = (3*CurrentFontSize())/8;
             break;
    default: 
             upsize = (CurrentFontSize()*3)/4;
  }

  num = GetFontNumber("MT Extra");

  fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
  fprintf(fRtf, "(%c,\\\\S(\\up%d\\f%ld\\'72))}", cParam[0], upsize, num);
  fprintf(fRtf, "{\\fldrslt }}");
  free (cParam);
}

/*****************************************************************************
 purpose: converts \u{o} and \breve{o} from LaTex to Rtf
          word 98 at least is broken and will not recognize \'28 properly
          for now just fake it with a u
 ******************************************************************************/
void CmdBreveChar(/*@unused@*/ int code)
{
  size_t num;
  int upsize;
  char *cParam = GetParam();
  if (cParam == NULL) return;

  num = GetTexFontNumber("MacRoman");
  upsize = CurrentFontSize();

  fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
  fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'f9))}", cParam[0], num);
  fprintf(fRtf, "{\\fldrslt }}");
  
  free (cParam);
}

void CmdUnderdotChar(int code)
/******************************************************************************
 purpose: converts cedillas from LaTex to Rtf
 ******************************************************************************/
{
  int dnsize;
  char *cParam = GetParam();
  if (cParam == NULL) return;

  dnsize = (0.2*CurrentFontSize())+0.45;

  fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
  fprintf(fRtf, "(%c,\\\\S\\\\do%d(\\'2e))}", cParam[0], dnsize);
  fprintf(fRtf, "{\\fldrslt }}");

  free (cParam);
}

void CmdHacekChar(int code)
/******************************************************************************
 purpose: converts \v from LaTex to Rtf
          need something that looks like \\O(a,\\S(\f1\'da)) in rtf file
 ******************************************************************************/
{
  size_t num;
  int upsize;
  char *cParam = GetParam();
  if (cParam == NULL) return;

  upsize = (0.4*CurrentFontSize())+0.45;
  num = GetFontNumber("Symbol");

  fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
  fprintf(fRtf, "(%c,\\\\S(\\up%d\\f%ld\\'da))}", cParam[0], upsize, num);
  fprintf(fRtf, "{\\fldrslt }}");

   free (cParam);
}

/******************************************************************************
 purpose: converts \.{o} and \dot{o} from LaTex to Rtf
          need something that looks like \\O(a,\\S(\f2\'26)) in rtf file
 ******************************************************************************/
void CmdDotChar(int code)
{
  size_t num;
  char *cParam = GetParam();
  if (cParam == NULL) return;
  
  num = GetFontNumber("MT Extra");

  fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
  fprintf(fRtf, "(%c,\\\\S(\\f%ld\\'26))}", cParam[0], num);
  fprintf(fRtf, "{\\fldrslt }}");

  free (cParam);
}

/******************************************************************************
 purpose: converts \.{o} and \dot{o} from LaTex to Rtf
          need something that looks like \\O(a,\\S(\f2\'26)) in rtf file
 ******************************************************************************/
void CmdUnderbarChar(int code)
{
  size_t num;
  char *cParam = GetParam();
  if (cParam == NULL) return;
  
  num = GetFontNumber("MT Extra");

  if(cParam[0])
  {
      fprintf(fRtf, "{\\field{\\*\\fldinst  EQ \\\\O");
      fprintf(fRtf, "(%c,_)}", cParam[0]);
      fprintf(fRtf, "{\\fldrslt }}");
  }

  free (cParam);
}

void TeXlogo()
/******************************************************************************
 purpose : prints the Tex logo in the Rtf-File (D Taupin)
 ******************************************************************************/
{
  float DnSize;
  int dnsize;

  DnSize = 0.3*CurrentFontSize(); dnsize = DnSize+0.45;
  fprintf(fRtf,"T{\\dn%d E}X", dnsize);
}

/******************************************************************************/
void LaTeXlogo()
/******************************************************************************
 purpose : prints the LaTex logo in the Rtf-File (D Taupin)
 ******************************************************************************/
{
  float UpSize;
  float FloatFsize;
  int upsize, Asize;

      if(CurrentFontSize() > 14)
        { FloatFsize = 0.667*CurrentFontSize();
        } else { FloatFsize = CurrentFontSize();
        }; Asize = FloatFsize+0.45;

  UpSize = 0.25*CurrentFontSize(); upsize = UpSize+0.45;
  fprintf(fRtf,"L{\\up%d\\fs%d A}", upsize, Asize); TeXlogo();
}

/******************************************************************************/
void CmdLogo(int code)
/******************************************************************************
 purpose : prints the LaTex, Tex, SLiTex and BibTex-Logos as an ordinary text
           in the Rtf-File (D Taupin)
 ******************************************************************************/
{ int font_num, dnsize;
  float FloatFsize;
  float DnSize;
  switch(code)
  {
    case CMD_TEX: TeXlogo(); break;
    case CMD_LATEX: LaTeXlogo(); break;
    case CMD_SLITEX: fprintf(fRtf, "SLiTeX"); break;
    case CMD_BIBTEX: fprintf(fRtf, "BibTeX");break;
    case CMD_LATEXE: LaTeXlogo();
      if(CurrentFontSize() > 14)
        { FloatFsize = 0.75*CurrentFontSize();
        } else { FloatFsize = CurrentFontSize();
        };
      DnSize = 0.3*CurrentFontSize(); dnsize = DnSize+0.45;
      font_num = GetFontNumber("Symbol");
      fprintf(fRtf, "2{\\dn%d\\f%d e}", dnsize,font_num); break;
  }
}
