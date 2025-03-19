#include <stdio.h>

int num = 0;

void hanoi(int n, char from, char middle, char to)
{
    if (n >= 1) {
        hanoi(n - 1, from, to, middle);
        printf("%d�� ������ %c���� %c�� �̵�\n", n, from, to);
        num++;
        hanoi(n - 1, middle, from, to);
    }
}
int main() {
    int n;
    printf("������ ������ �Է��Ͻÿ�: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');
    printf("�� �̵� Ƚ��: %d", num);
    
    return 0;
}