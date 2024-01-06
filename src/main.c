
#define F_CPU 8000000UL // ����������� ������� ������ ��
#include <avr/io.h>     // ���������� �����/������ ������� �������� ����������� ����� ����� �����/������ ���� � ����������������
#include <util/delay.h> //�������� ��������

unsigned char button_state()
{
        if (!(PINB & (1<<0))) // ���� ������ ������ � button_state ������������ 1     
    {
        _delay_ms(15);
        if (!(PINB & (1<<0))) return 1; 
    }
    return 0; // ���� ������ �� ������ � button_state ������������ 0  
}

int main (void)
{
    unsigned char n_led = 1; // ��������� ���������� n_led, ����������� � 1
    
    DDRB  = 0b00000000; //
    PORTB = 0b00000001; // ����������� 0 ��� � �� �����, ����� ������� ����������� ��������� ���������� ��� ������� ������

    DDRD  =0b00011100; //	���������� 2,3,4 ����
    PORTD =0b00000000; 
    
    while (1)
    {
        if (button_state()) // ���� ������ ������, button_state ��������������� 1 ���������� ���������� �������
        {

            switch(n_led){
                case 1:
                PORTD ^= (1<<2); // ������ ������� n_led=1 ������������ � case 1 ���������� �������� �� 2 ����
                
                break;
                case 2:
                PORTD ^= (1<<3); // ������ ������� n_led=2 ������������ � case 2 ���������� �������� �� 3 ����
                
                break;
                case 3:
                PORTD ^= (1<<4); // ������ ������� n_led=3 ������������ � case 3 ���������� �������� �� 4 ����
                break;
                case 4:
                PORTD = 0b00000000; // ��������� ������� n_led=4 ������������ � case 4 ���������� �������
                n_led=0; // n_led ������������ � ����
                break;
            }
            n_led++; // ��� ������ ������� n_led ����������������
            _delay_ms(300);
        }
    }
   }