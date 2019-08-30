#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/timeb.h>
#include <errno.h>

#ifndef _WIN
#include <unistd.h>  //
#endif // _WIN
#include <signal.h>


#define MAX_LINE_LEN 55000

#define INLINE  static __inline
#ifdef _DEBUG
#define PRINT   printf
#else
#define PRINT(...)
#endif


INLINE void write_file(const bool cover, const char * const buff, const char * const filename);



void write_result(const char * const buff, const char * const filename)
{
	// �Ը��ǵķ�ʽд��
	write_file(1, buff, filename);

}


INLINE void write_file(const bool cover, const char * const buff, const char * const filename)
{
	if (buff == NULL)
		return;

	const char *write_type = cover ? "w" : "a";//1:����д�ļ���0:׷��д�ļ�
	FILE *fp = fopen(filename, write_type);
	if (fp == NULL)
	{
		PRINT("Fail to open file %s, %s.\n", filename, strerror(errno));
		return;
	}
	//PRINT("Open file %s OK.\n", filename);
	fputs(buff, fp);
	fputs("\n", fp);
	fclose(fp);
}

