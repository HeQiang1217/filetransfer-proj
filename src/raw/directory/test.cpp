
#include"head.h"




/*  judgePath()������makeDir����ʹ�ò���  */
void main()
{
    printf("judgePath()����ʹ�ò��ԣ�\n");
    printf("�������ļ�/�ļ���·��������ʽ��D:/Program Files/OpenCV/imgs.jpg �� D:\\\\Program Files\\\\OpenCV\\\\imgs.jpg �� D:\\Program Files\\OpenCV\\imgs.jpg��\n");
    //printf("��ǰ֧�����·�����ȣ�200�ֽ�\n");
    char path[200] = { 0 };
    gets_s(path, 200);
    int result = judgePath(path);

    switch (result)
    {
    case 1:printf("It's a folder!\n"); break;
    case 2:printf("It's a file!\n"); break;
    case 3:printf("This path is not exist!\n"); break;
    default:
        break;
    }
    printf("makeDir()����ʹ�ò��ԣ�\n");
    char relative[80] = { 0 }, root[80] = { 0 };
    printf("���������·����(��ʽ�� hwmm\\\\foo����ǰ֧�����·�����ȣ�80�ֽڣ�\n");
    gets_s(relative, 80);
    printf("���������·����(��ʽ�� D:\\\\recv�� ��ǰ֧�����·�����ȣ�80�ֽڣ�\n");
    gets_s(root, 80);
    result = makeDir(relative, root);
    if (result == CREATE_SUCCESS)
        printf("�����ɹ���\n");
    else
        printf("����ʧ��!\n");
   


}