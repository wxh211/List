#include <iostream>
using namespace std ;
int Error = 0 ;

#define MAXLISTLEN 100
int ListLen = 0 ;
int SeqList [MAXLISTLEN + 1] ;
//˳������
int SearchSeqList (int i)
{
    if ((i > ListLen) || (i < 1) || (ListLen == 0))
    {
        Error = -1 ;
        return (-1) ;    //���ҳ�����
    }
    else
    {
        return SeqList [i] ;    //����ָ��λ�õ�Ԫ��ֵ
    }
}
//˳���Ĳ���
void InsertSeqList (int NewItem , int i)
{
    int j ;

    if ((i > ListLen + 1) || (i < 1) || (ListLen == MAXLISTLEN))
    {
        Error = -2 ;    //���������
        cout << "���������������";
    }
    else
    {
        for (j = ListLen ; j >= i ; j -- )    //�Ӻ���ǰ��
        {
            SeqList [j+1] = SeqList [j] ;
        }
        SeqList [i] = NewItem ;        //������Ԫ��
        ListLen = ListLen + 1 ;        //����һ
    }
}
//˳���ָ��λ�����ݵ�ɾ��
void DeleteSeqList (int i)
{
    int j ;

    if ((i > ListLen)||(i < 1) || (ListLen == 0))
    {
        Error = -3 ;    //ɾ��������
        cout << "ɾ��������������" ;
    }
    else
    {
        for (j = i ; j < ListLen ; j ++ )    //��ǰ������
        {
            SeqList [j] = SeqList [j+1] ;
        }
        ListLen = ListLen - 1 ;        //����һ
    }
}
//˳�����ʾ
void ShowSeqList ()
{
    int i ;

    cout << "The list : " ;
    for (i = 1 ; i <= ListLen ; i ++ )
    {
        cout <<SeqList[i]<<" " ;    //�����ʾ����Ԫ��
    }
    cout << endl ;            //����

}
//������
int main (int argc , char * argv[])
{
int r[MAXLISTLEN] , i , SearchPos , NewPos , NewItem , DelPos ;

cout << "Please input the ListLen : " ;
cin >> ListLen ;    //����������Ŀ������
//����˳���
for (i = 1 ; i <= ListLen ; i++)
{
    cout << "Please input No." << i <<"Item : " ;
    cin >> SeqList[i] ;
}
ShowSeqList () ;    //��ʾ˳���

cout << "Please input the search pos : " ;
cin >> SearchPos ;    //�������λ��

cout << "Your Searched Item is : " <<SearchSeqList (SearchPos) << endl ;    //������ҵ�����Ԫ��ֵ

cout << "Please input the NewPos where you want to insert : " ;
cin >> NewPos ;        //����λ������
cout << "Please input the NewItem what you want to insert : " ;
cin >> NewItem ;    //����Ԫ������
InsertSeqList (NewItem , NewPos) ;    //�����ݲ���˳�����
cout << "After insert : " ;
ShowSeqList () ;        //�������ݺ�����µ�˳���

cout << "Please input the DelPos where you want to delete : " ;
cin >> DelPos ;        //����ɾ��Ԫ��λ��
DeleteSeqList (DelPos) ;    //��λ��ɾ������
cout << "After delete : " ;
ShowSeqList () ;

if (Error < 0) cout <<"Error" << Error << endl ;

return 0 ;
}
