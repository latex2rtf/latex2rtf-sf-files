#ifndef	__DROPSHELL_H__
#define	__DROPSHELL_H__

void			InitToolbox(void);
Boolean			InitGlobals(void);
void			SetUpMenus(void);
void 			InstallSplashScreen(void); 
void			ShowAbout(void);
void			DoMenu(long retVal);
void			DoMouseDown(EventRecord *curEvent);
void			DoKeyDown(EventRecord *curEvent);

#endif
