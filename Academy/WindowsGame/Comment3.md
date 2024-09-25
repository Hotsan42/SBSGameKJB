# Window API 1����
---
## 1. ������ ���

### ������ ���� �� �ʿ��� ���
 1. ���� ����ϴ� ���
 ```cpp
 // TextOut 
 TextOut(HDC hdc, int x, int y, LPCWSTR lpString, int c)

 //hdc - Device Context (ȭ�� ����ü)
 // x, y - � ��ġ�� 
 //lpString - � ���ڿ�
 // c - ���ڿ� ����

 //�ֿܼ��� printf�� ���� ���
 // ���߿� �� ����
 // ���� ������ �� ���� �ܼ� â ����ΰ� �մϴ�.
 //printf�� �ܼ�â�� ������
 //TextOut�� ȭ�鿡 �׷���

 //LPCWSTR - WCHAR* ����
 //WCHAR - wchar_t
 ```

 ### WCHAR, CHAR ����
 ```
 //wchar_t - �� �����ϱ�
 //char, wchar

 char - 1byte
 wchar - 2byte

 �ѱ��� 2byte��
 ������ 1byte �Դϴ�.

 1byte�� ũ�Ⱑ 256 
 �׷��ٺ��� ������ ���ڸ� �� ǥ�� x

 1byte�� UTF-8(ASCII)�̶�� �ϴ� ���ڿ� ������ ���
 UTF - ���������� ?bit������� �� 65�� 0 32�� a �̷��� ǥ������. ���ڿ� �԰�

 2byte�� �����µ� 
 � ��ǻ�Ϳ����� aa��� �ν��ϰ� � ��ǻ�Ϳ����� �̻��� ���ڷ� �ν�

 �̰Ÿ� �ϳ��� ����

 ���� �ؿܱ������� �ۺ����� �����ϸ�
 UTF-16���� �۾��ϰ� �˴ϴ�.

 UTF-8 - char
 UTF-16 - wchar
 ```

## 2. �簢�� �׸���
### �簢�� �׸� �� �ʿ��� ���
1. �簢���� �׸��� ���

```cpp
//�簢�� �׸���
Rectangle(hdc, left, top, right, bottom);
//�� �׸���
Ellipse(hdc, left, top, right, bottom);

left - ���� x��ǥ
top - ��� y��ǥ
right - ���� x ��ǥ
bottom  �ϴ� y ��ǥ

//windows api ��ǥ��� ���� ����� 0,0 �Դϴ�.

// �簢���� �׸��ų� Ÿ���� �׸� �� 
// x, y, width, height �̰� �� �� ������ ������
// ������ �Լ��� ������� ����

//Windows API �� �Լ��� ����ϱ� ���ϰ� 

//���� �ð� KST 9���ε� UTC�� 0�ôϱ�


```

### namespace
```
namespace�� �̸�����

using namespace std;
//std�� �����ϰ� �Լ��� �ۼ��ϰڴ�.
//std :: cout ==> cout

```

### ����
```
1�� ~ 9��Ű�� ������
���� 
1�� ������
2�� ������
������� �ٲٰ�

0�� Ű�� ������ 1�� ~ 9�� ���� �� ��������

```