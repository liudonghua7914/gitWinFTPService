// gitWinFTPService.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Winsock2.h>
#include<stdio.h> 
#pragma comment(lib,"ws2_32.lib")


#define EINVAL 1
#define ENOMEM 2
#define ENODEV 3

#define msg110 "110 MARK %s = %s."
/*
         110 Restart marker reply.
             In this case, the text is exact and not left to the
             particular implementation; it must read:
                  MARK yyyy = mmmm
             Where yyyy is User-process data stream marker, and mmmm
             server's equivalent marker (note the spaces between markers
             and "=").
*/
#define msg120 "120 Service ready in nnn minutes."
#define msg125 "125 Data connection already open; transfer starting."
#define msg150 "150 File status okay; about to open data connection."
#define msg150recv "150 Opening BINARY mode data connection for %s (%i bytes)."
#define msg150stor "150 Opening BINARY mode data connection for %s."
#define msg200 "200 Command okay."
#define msg202 "202 Command not implemented, superfluous at this site."
#define msg211 "211 System status, or system help reply."
#define msg212 "212 Directory status."
#define msg213 "213 File status."
#define msg214 "214 %s."
/*
             214 Help message.
             On how to use the server or the meaning of a particular
             non-standard command.  This reply is useful only to the
             human user.
*/
#define msg214SYST "214 %s system type."
/*
         215 NAME system type.
             Where NAME is an official system name from the list in the
             Assigned Numbers document.
*/
#define msg220 "220 lwIP FTP Server ready."
/*
         220 Service ready for new user.
*/
#define msg221 "221 Goodbye."
/*
         221 Service closing control connection.
             Logged out if appropriate.
*/
#define msg225 "225 Data connection open; no transfer in progress."
#define msg226 "226 Closing data connection."
/*
             Requested file action successful (for example, file
             transfer or file abort).
*/
#define msg227 "227 Entering Passive Mode (%i,%i,%i,%i,%i,%i)."
/*
         227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).
*/
#define msg230 "230 User logged in, proceed."
#define msg250 "250 Requested file action okay, completed."
#define msg257PWD "257 \"%s\" is current directory."
#define msg257 "257 \"%s\" created."
/*
         257 "PATHNAME" created.
*/
#define msg331 "331 User name okay, need password."
#define msg332 "332 Need account for login."
#define msg350 "350 Requested file action pending further information."
#define msg421 "421 Service not available, closing control connection."
/*
             This may be a reply to any command if the service knows it
             must shut down.
*/
#define msg425 "425 Can't open data connection."
#define msg426 "426 Connection closed; transfer aborted."
#define msg450 "450 Requested file action not taken."
/*
             File unavailable (e.g., file busy).
*/
#define msg451 "451 Requested action aborted: local error in processing."
#define msg452 "452 Requested action not taken."
/*
             Insufficient storage space in system.
*/
#define msg500 "500 Syntax error, command unrecognized."
/*
             This may include errors such as command line too long.
*/
#define msg501 "501 Syntax error in parameters or arguments."
#define msg502 "502 Command not implemented."
#define msg503 "503 Bad sequence of commands."
#define msg504 "504 Command not implemented for that parameter."
#define msg530 "530 Not logged in."
#define msg532 "532 Need account for storing files."
#define msg550 "550 Requested action not taken."
/*
             File unavailable (e.g., file not found, no access).
*/
#define msg551 "551 Requested action aborted: page type unknown."
#define msg552 "552 Requested file action aborted."
/*
             Exceeded storage allocation (for current directory or
             dataset).
*/
#define msg553 "553 Requested action not taken."
/*
             File name not allowed.
*/

enum FTP_SERVICE
{
	FTPD_USER,
	FTPD_PASS,
	FTPD_IDLE,
	FTPD_NLST,
	FTPD_LIST,
	FTPD_RETR,
	FTPD_RNFR,
	FTPD_STOR,
	FTPD_QUIT
};


typedef struct  
{
	BYTE ftpServicestatus;
	SOCKET sftpSerives;
	SOCKET sftpNewSerives;
	WSADATA sftpSerivesData;
	SOCKADDR_IN saftpSerives;
	SOCKADDR_IN remoteSerives;
	char SerivesRecvBuf[512];
	HANDLE hFTPSeriversThread;
	BOOL bKillFTPSeriversThread;
}FTP_INFO;

FTP_INFO ftpInfo;
FTP_INFO *pftpInfo;


/*************************************************************************************************************************
**函数名称：	sendMsg
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void sendMsg(SOCKET ssocket,char *p,char *msg,...)
{
	int ret;
	int nLeft;
	int idx;

	va_list arg;
	char buffer[256];
	int len;
	memset(buffer,'\0',sizeof(buffer));
	len  = strlen(p);
	memcpy(buffer,p,len);

	va_start(arg, msg);
	vsprintf(&buffer[len], msg, arg);
	va_end(arg);
	strcat(buffer, "\r\n");
	len = strlen(buffer);


	
	nLeft = len;
	idx = 0;
	while(nLeft > 0)
	{
		ret = send(ssocket,&buffer[idx],nLeft,0);
		if (ret == SOCKET_ERROR)
		{
			printf("\r\n send error");
		}
		nLeft -= ret;
		idx += ret;
	}
}
/*************************************************************************************************************************
**函数名称：	cmd_user
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_user(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_pass
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_pass(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_port
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_port(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_quit
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_quit(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_cwd
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_cwd(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_cdup
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_cdup(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_pwd
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_pwd(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_nlst
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_nlst(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_list
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_list(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_retr
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_retr(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_stor
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_stor(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_noop
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_noop(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_syst
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_syst(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_abrt
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_abrt(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_type
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_type(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_mode
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_mode(const char *p,UINT16 len)
{


}
/*************************************************************************************************************************
**函数名称：	cmd_rnfr
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_rnfr(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_rnto
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_rnto(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_mkd
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_mkd(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_rmd
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_rmd(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_dele
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_dele(const char *p,UINT16 len)
{

}
/*************************************************************************************************************************
**函数名称：	cmd_pasv
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void cmd_pasv(const char *p,UINT16 len)
{

}


struct ftpd_command {
	char *cmd;
	void (*func) (const char *p,UINT16 len);
};

static struct ftpd_command ftpd_commands[] = {
	{"USER", cmd_user},
	{"PASS", cmd_pass},
	{"PORT", cmd_port},
	{"QUIT", cmd_quit},
	{"CWD", cmd_cwd},
	{"CDUP", cmd_cdup},
	{"PWD", cmd_pwd},
	{"XPWD", cmd_pwd},
	{"NLST", cmd_nlst},
	{"LIST", cmd_list},
	{"RETR", cmd_retr},
	{"STOR", cmd_stor},
	{"NOOP", cmd_noop},
	{"SYST", cmd_syst},
	{"ABOR", cmd_abrt},
	{"TYPE", cmd_type},
	{"MODE", cmd_mode},
	{"RNFR", cmd_rnfr},
	{"RNTO", cmd_rnto},
	{"MKD", cmd_mkd},
	{"XMKD", cmd_mkd},
	{"RMD", cmd_rmd},
	{"XRMD", cmd_rmd},
	{"DELE", cmd_dele},
	{"PASV", cmd_pasv},
	{NULL, NULL}
};

/*************************************************************************************************************************
**函数名称：	ftpServiceProcess
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
void ftpServiceProcess(char *p,UINT16 len)
{
	printf("sftpSerives rev:  %s ",p);
	struct ftpd_command *ftpd_cmd;
	char cmd[5];
	memcpy(cmd,p,4);
	for (ftpd_cmd = ftpd_commands; ftpd_cmd->cmd != NULL; ftpd_cmd++) 
	{
		if (!strcmp(ftpd_cmd->cmd, cmd))
			break;
	}
	if (ftpd_cmd->func)
	{
		printf("func name: %s ",ftpd_cmd->cmd);
		ftpd_cmd->func(p,len);
	}
}
/*************************************************************************************************************************
**函数名称：	ThreadFTPSeriversFunc
**函数功能:
**入口参数:
**返回参数:
*************************************************************************************************************************/
DWORD WINAPI ThreadFTPSeriversFunc(LPVOID arg)
{
	int ret,err;
	WORD dwVersion;
	dwVersion = MAKEWORD(2,2);
	err = WSAStartup(dwVersion,&pftpInfo->sftpSerivesData);
	if ( err != 0 ) 
	{
		printf("\r\n Tell the user that we could not find a usable WinSock DLL");
		return 0;
	}

	if ( LOBYTE(pftpInfo->sftpSerivesData.wVersion ) != 2 ||HIBYTE(pftpInfo->sftpSerivesData.wVersion ) != 2 ) 
	{
		printf("\r\n Tell the user that we could not find a usable WinSock DLL. ");
		WSACleanup();
		return 0;
	}

	pftpInfo->sftpSerives = socket(AF_INET,SOCK_STREAM,0);
	if(INVALID_SOCKET == pftpInfo->sftpSerives)
	{
		printf("\r\n sftpSerives Tell the user that socket INVALID_SOCKET ");
		WSACleanup();
	}
	 BOOL bBroadcast = TRUE;
	setsockopt(pftpInfo->sftpSerives,SOL_SOCKET,SO_BROADCAST,(const char *)&bBroadcast,sizeof(BOOL));
	/*if(INVALID_SOCKET == pftpInfo->sftpSerives)
	{
	printf("\r\n sftpSerives Tell the user that socket INVALID_SOCKET ");
	WSACleanup();
	}*/
	pftpInfo->saftpSerives.sin_family = AF_INET;
	pftpInfo->saftpSerives.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	pftpInfo->saftpSerives.sin_port =  htons(21);
	if(INVALID_SOCKET == bind(pftpInfo->sftpSerives,(SOCKADDR *)&pftpInfo->saftpSerives,sizeof(pftpInfo->saftpSerives)))
	{
		DWORD dwErr = GetLastError();
		printf("\r\n sftpSerives Tell the user that bind INVALID_SOCKET %d ",dwErr);
	}
	listen(pftpInfo->sftpSerives,8);
	int addrlen = sizeof(pftpInfo->remoteSerives);
	pftpInfo->sftpNewSerives = accept(pftpInfo->sftpSerives,(SOCKADDR *)&pftpInfo->remoteSerives,&addrlen);
	if(INVALID_SOCKET == pftpInfo->sftpNewSerives)
	{
		DWORD dwErr = GetLastError();
		printf("\r\n sftpSerives Tell the user that accept INVALID_SOCKET %d ",dwErr);
	}
	while(!pftpInfo->bKillFTPSeriversThread)
	{
		memset(pftpInfo->SerivesRecvBuf,'\0',sizeof(pftpInfo->SerivesRecvBuf));
		ret = recv(pftpInfo->sftpNewSerives,pftpInfo->SerivesRecvBuf,sizeof(pftpInfo->SerivesRecvBuf) - 1,0);
		if(INVALID_SOCKET == ret)
		{
			printf("\r\n sftpSerives Tell the user that accept INVALID_SOCKET ");
			pftpInfo->bKillFTPSeriversThread = TRUE;
		}
		if(ret > 0)
		{
			ftpServiceProcess(pftpInfo->SerivesRecvBuf,ret);
		}
	}
	printf("\r\n sftpSerives closesocket");
	closesocket(pftpInfo->sftpSerives);
	WSACleanup();
	CloseHandle(pftpInfo->hFTPSeriversThread);
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	memset(&ftpInfo,0,sizeof(ftpInfo));
	pftpInfo = &ftpInfo;
	pftpInfo->bKillFTPSeriversThread = FALSE;
	pftpInfo->hFTPSeriversThread = CreateThread(NULL,0,ThreadFTPSeriversFunc,NULL,0,NULL);
	if(NULL == pftpInfo->hFTPSeriversThread)
	{
		printf("\r\n CreateThread Fail");
	}
	while(1);
	return 0;
}

