/******************************************************************************
**
**  Project Name:	DropShell
**     File Name:	DSGlobals.h
**
**   Description:	Globals used by DropShell
**
*******************************************************************************
**                       A U T H O R   I D E N T I T Y
*******************************************************************************
**
**	Initials	Name
**	--------	-----------------------------------------------
**	LDR			Leonard Rosenthol
**	MTC			Marshall Clow
**	SCS			Stephan Somogyi
**
*******************************************************************************
**                      R E V I S I O N   H I S T O R Y
*******************************************************************************
**
**	  Date		Time	Author	Description
**	--------	-----	------	---------------------------------------------
**	04/15/96			RWD		Removed #ifndef __MWERKS__ which caused problems
**								when not using Precompiled Headers.
**	02/20/94			LDR		Added commenting for Metrowerks
**	12/09/91			LDR		Added gSplashScreen
**	11/24/91			LDR		Added some new #defs & a #inc for DSUtils
**	10/29/91			SCS		Changes for THINK C 5
**	10/28/91			LDR		Officially renamed DropShell (from QuickShell)
**	10/06/91	00:02	MTC		Converted to MPW C
**	04/09/91	00:03	LDR		Added to Projector
**
******************************************************************************/

#ifndef	__DSGLOBALS_H__
#define	__DSGLOBALS_H__


#include <Types.h>
#include <Memory.h>
#include <QuickDraw.h>
#include <OSUtils.h>
#include <ToolUtils.h>
#include <Menus.h>
#include <Packages.h>
#include <Traps.h>
#include <Files.h>
#include <Aliases.h>
#include <AppleEvents.h>
#include <Gestalt.h>
#include <Processes.h>

#define	kAppleNum			32000
#define	kFileNum			32001

#define	kErrStringID		100
#define	kCantRunErr			1
#define	kAEVTErr			2
#define	kResourceLoadError	3
#define	kMemoryError		4

#define qWalkFolders 0 /* define this as 0 to treat folders as items */

extern Boolean		gDone, gOApped, gHasAppleEvents, gWasEvent;
extern EventRecord	gEvent;
extern MenuHandle	gAppleMenu, gFileMenu;
extern WindowPtr	gSplashScreen;

#endif
