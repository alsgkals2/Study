// Crypt Kicker.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct AlphaInform 
{
	char a='.';
	int num=1;
	AlphaInform *nextI = NULL;

}Ainform;

char* input = new char();
int n = 0;

void CandidateSave(char** dic,int** candidate, int alphaCount, int n, int* numInform, Ainform* alphaLink, int inputElement, int wordcount, int linkcount) {
	//input[inputelement]�� �ش��ϴ� ���ڸ� alphaLink���� Ž��

	char firstAlpha = NULL;
	Ainform* next = new Ainform;
	int elementCount = 0;
	int i = 0;
	for (int lc = 0; lc < linkcount; lc++) {
		if (input[inputElement] == alphaLink[lc].a) {
			

			//alphaLink���� ���ĺ��� dic�� �ش��ϴ� ù���ڿ� ����, ����ũ�� ��ġ�ϸ� candidate�� ����
			next = &alphaLink[lc];
			if (next->nextI) {
				next = next->nextI;
				for (int nn = 0; nn < n; nn++) {
					if (next->a == dic[nn][0] && alphaCount == numInform[nn]) {
						candidate[wordcount - 1][elementCount++] = nn;
					}
				}
			}
		}
		
	}

}


char* CandidateEdit(char** dic, int** candidate, int wordcount, int inputElement, Ainform* alphaLink,int alphaCount,int* numInform,int alpha_count) {//wordcount�� 1���� ����
	int i = 0;
	int elementCount = 0;
	//ù���ڿ� �ش��ϴ� �ĺ����ĺ� Ž��

	//candidate�� ù���ڿ� ���� �ĺ��� �߰�
	inputElement = inputElement + 1;
	elementCount = 0;
	i = 0;
	int dicElement = 1;
	Ainform* next = new Ainform;
	while (input[inputElement] != ' ') {
		if (input[inputElement] == alphaLink[i].a) {//��ũ����Ʈ���� �ι�°���ĺ��� ��ġ�ϴ°� ã����
			next =& alphaLink[i];
													//�ĺ������� �ι�°���ĺ��� ��ġ�ϴ��� �˻��Ѵ�.
			for (int nn = 0; nn < n; nn++)
				if (candidate[wordcount - 1][nn] >= 0)
				{
					//�˻��ϸ鼭 ��ġ���� �ʴ� �ĺ����� -1�� ����
					while (next->nextI) {
						next = next->nextI;
						if (dic[candidate[wordcount - 1][nn]][dicElement] != next->a) {
							candidate[wordcount - 1][nn] = -1;
						}
					}
				}

			inputElement++;
			dicElement++;
			wordcount++;
			i = 0;
		}
		else i++;
	}
	//�ݺ��ؼ� �����ĺ�������
	

	//��ġ���� ������'.'
	 return ".";
 }

void Delete(Ainform a[]) {
	Ainform* first = a;

	Ainform* next = a;
	int high = 0;

	//num�� ��������� Ž��
		while (next->nextI) {
			next = next->nextI;
			if (next->num>high) {
				high = next->num;
			}
		}


	next = a;
	
	//��������� �ƴϸ� ����
	AlphaInform *before = new AlphaInform;

		while (next->nextI) {
			before = next;
			next = next->nextI;
			
			if (next->num != high) {
				if (next->nextI) {
					next = next->nextI;
					before->nextI = next;
				}
				else if(!next->nextI) {
					before->nextI = NULL;
					break;
				}
			}
		}
}

int main()
{
	int i = 0, count = 0;

	cin >> n;

	char** dic = new char*[n];
	int *numInform = new int[n]; int numEnd = 1;//�� �ܾ�� ���Ĺ�� ����

	for (i = 0; i < n; i++) {
		numInform[i] = 0;
	}
	int swit = true;

	for (i = 0; i < n; i++) {
		dic[i] = new char();//��ȣȭ�� �ܾ��
		cin >> dic[i];

		//��ȣȭ�� �ܾ���� ����ũ�� ���� ����
		count = 0; swit = true;
		for (int j = 0; dic[i][j]; j++) {
			count++;
		}
		numInform[i] = count;//���������� �� �ܾ��� ���Ĺ� �� ����
	}

	//��ȣȭ�� �ܾ� �Է�
	cin.ignore();//�����Է� ����
	cin.getline(input, 80);

	//input(��ȣȭ �迭) ũ������
	int input_count = 0;
	for (i = 0; input[i]; i++) { input_count++; }
	input[input_count++] = ' ';//�Ǹ��������� ���鰪 �߰�

	//��ȣȭ�� �ܾ�鿡 ���ؼ� ��ũ�帮��Ʈ�� ���� �߰�
	Ainform *AlphaInform = new Ainform;
	int alpha_count = 0;
	swit = false;


	//��ȣȭ�� �ܾ� ��� ����
	for (i = 0; i < input_count; i++) {
		if (input[i] != ' ') {
			//��ȣȭ�� �ܾ� ���ĺ��� ������ִ��� Ȯ��
			swit = false;
			for (int e = 0; e < alpha_count; e++) {
				//����������� break
				if (AlphaInform[e].a == input[i]) { swit = true;  break; }
			}
			//��������� ������ ����
			if (swit == false)
			{
				AlphaInform[alpha_count].a = input[i];
				AlphaInform[alpha_count].num = 1;
				AlphaInform[alpha_count].nextI = NULL;
				alpha_count++;
			}
		}
	}
	//�󵵼� ����(dic,numinform�� �̿��ؼ� ainform�� ��������

	Ainform *nextInform = new Ainform;
	count = 0;//��ȣȭ�� �迭���� ī����
	int word_count = 0; //�ܾ� ī����
	swit = false;
	bool switinptWordCount = false;
	int wordcount = 0;
	int plusCount = 0;
	for (i = 0; i < input_count; i++) {//input �迭ũ��
		word_count++;
		if (input[i] != ' '&&switinptWordCount == false) {
			switinptWordCount = true;
			wordcount++;
		}
		else if (input[i] == ' ') {
			//�ܾ� ũ��� ������ �ܾ����� ��ũ
			switinptWordCount = false;
			--word_count;
			for (int j = 0; j < n; j++) {//n=�����ܾ��
				if (word_count == numInform[j]) { //�������� �������ڼ��� ������
					plusCount = -1;

					while (++plusCount != word_count) {//input�� ���� �Ѵܾ���������� ��ũ����Ʈ�� �߰��Ϸ�����.
						for (int a_count = 0; a_count < alpha_count; a_count++) {//alpha_count�� ��ũ����Ʈ����
							if (AlphaInform[a_count].a == input[i - word_count+plusCount]) {//��ũ���� �������ĺ��� ã������
								swit = false;

								nextInform = &AlphaInform[a_count];
								//Ainform *lastInform = &AlphaInform[a_count];
								while (nextInform->nextI)
								{
									nextInform = nextInform->nextI;
									if (nextInform->a == dic[j][plusCount])
									{
										nextInform->num++; swit = true; break;
									}
								}
								if (swit == false)//������ ��������� ������
								{
									
									/*while (lastInform->nextI) { //��������ġŽ��
										lastInform = lastInform->nextI;
									}*/
									nextInform->nextI = new Ainform;
									nextInform = nextInform->nextI;

									nextInform->a = dic[j][plusCount];

									
									break;
								}
							}
						}
					}
				}
			}
			word_count = 0;//���ڰ��� �ʱ�ȭ
		}
	}
	

//��ũ�帮��Ʈ�� �󵵼��� ���������(��) �̿ܿ� ��� ����.
	for (i = 0; i < alpha_count; i++) {
		Delete(&AlphaInform[i]);
	}


	//��ȣȭ

	//wordcount:input�ܾ���� ����
	int** candidate = new int*[wordcount];//�� input�ܾ ���� �ĺ����� ��Ҹ� ������
	for (i = 0; i < wordcount; i++) {
		candidate[i] = new int();
	}

	//�ܾ������ŭ�� �迭�� ���ĺ����� ����
	int* alphaCount = new int[wordcount]; //���ĺ�����
	for (i = 0; i < wordcount; i++) {
		alphaCount[i] = 0;
	}

	int j = 0;
	for(i=0; i<input_count; i++)
	{
		if (input[i] != ' ')
		{
			alphaCount[j]++;
		}
		else if (input[i] == ' ')
		{
			j++;
		}
	}



	//�ĺ��� ����
	switinptWordCount = false;
	wordcount = 0;
	for (i = 0; i < input_count; i++) {
		//input[i]�� ' '�� �ƴѰ�� ����ù���ڿ� �ش��ϴ� �ĺ���ϵ��� candidate�� �����ϴ� �Լ�
		if (input[i] != ' '&&switinptWordCount == false) {//ù�����ΰ��
			switinptWordCount = true; wordcount++;
			CandidateSave(dic,candidate,alphaCount[wordcount-1],n,numInform,AlphaInform,i,wordcount,alpha_count);
		}
		else if (input[i] == ' ') { switinptWordCount = false; }//�����ΰ��
	}



	//�ĺ��� ��

	switinptWordCount = false;
	wordcount = 0;
	for (i = 0; i < input_count; i++) {
	 //input[i]�� ' '�� �ƴѰ�� ����ù���ڿ� �ش��ϴ� �ĺ���ϵ��� candidate�� �����ϴ� �Լ�
		if (input[i] != ' '&&switinptWordCount == false) {//ù�����ΰ��
			switinptWordCount = true; wordcount++;
			CandidateEdit(dic,candidate ,wordcount,i, AlphaInform, alphaCount[wordcount-1], numInform, alpha_count);
		}
		else if (input[i] == ' ') { switinptWordCount = false; }//�����ΰ��
	}


	//�Ҵ� ����

	return 0;
}