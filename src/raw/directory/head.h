#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <io.h>
#include <direct.h>
#include <windows.h>
#include<stdlib.h>
#include <sys/stat.h>
#define IS_FOLDER 1
#define IS_FILE 2
#define NOT_EXIST 3
#define CREATE_SUCCESS 1
#define CREATE_FAIL 2



/*
    ����judgePath():
    �����û�����ı���·�����жϸ�·����Ŀ¼��directory�������ļ���file�������߸��������ڸ�Ŀ¼���ļ���
    ����ֵ�����ǣ�1 Ŀ¼��2 �ļ���3 �õ�ַ������
    int judgePath(const char path[]);
*/


int judgePath(const char path[]) {
    struct _stat buf;
    /*  result:Ϊ-1ʱ�������ڣ�Ϊ0ʱ�������  */
    int result = _stat(path, &buf);
    int type = 0;
    if (_S_IFDIR & buf.st_mode) {
        type = IS_FOLDER;
    }
    else if (_S_IFREG & buf.st_mode) {
        type = IS_FILE;
    }
    else
        type = NOT_EXIST;
    return type;
}

/*
   ����makeDir():
   ����Windows�µ����Ŀ¼�����ṩ�ĸ�Ŀ¼�µݹ鴴����Ӧ�ļ���
   ����1�������ɹ���
   ����2����Ȩ�޲��������ԭ�������ʧ��
   int makeDir(const char relative[], const char root[]);

*/
int makeDir(const char relative[], const char root[]) {
    char path[200];
    char dir[200];//֧�����200�ֽھ���·��������
    strcpy(dir, root);
    FILE* fp;
    sprintf(path, "mkdir %s\\%s", root, relative);
    system(path);//����Ŀ¼
    strcat(dir, "\\");
    strcat(dir, relative);
    int result = judgePath(dir);//�ж�Ŀ¼�Ƿ����
    int signal = CREATE_FAIL;
    if (result == IS_FOLDER) {
        signal = CREATE_SUCCESS;
    }

    return signal;
}
