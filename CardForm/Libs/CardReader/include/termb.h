
#ifndef AIFACE_TERMB_H
#define AIFACE_TERMB_H

int __stdcall InitComm(int port);
int __stdcall InitCommExt();
int __stdcall CloseComm();
int __stdcall Authenticate();
//int Read_Content( int active);
int __stdcall Read_Content_Path(char* cPath, int active);
//int GetDeviceID( char * pMsg );
//BSTR  GetSAMID();
//int  GetPhoto(char * Wlt_File);

#endif
