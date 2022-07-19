// ������..... �ϰ� ������ �ڷᱸ���� �Ǳ����ض�
// ���� �ҰŴ� �غ�����

// ����Ʈ������ ������

// list 
//������ �����͸� ���� ������ malloc���� ���� 
//�����͸� ���� �� ������ �������ִ°� �ֿ� ����Ʈ***
//���?? �����͸� �̿��ؼ� ���� �����͸� ����Ű�� �Ѵ�.
//�׷� ������ �������� ���� �����Ϳ� �����Ͱ� ���� �Ѵ� --> ����ü

// ź�����
//array�� ������

//int a[10];
//���� 1 : ũ�⺯ȯ �Ұ���
//���� 2 : �迭�� �߰��� ������ �ڿ��� �ϳ��ϳ��� ������ ��������(�߰������� �ſ� ����,��ȿ����)
//���� 1 : ������ 
//���� 2 : direct access�� ���� (a[n]���� �а� ���� ����)
//���� 3 : ������, �ֳĸ� ������ ��� ����(malloc�� �޸𸮰� �����ϸ� ������ �� ����)  
//�� ������(Ư�� 3��) ������ �Ӻ���� �ý����� array�� �� ���� ��

// mallc ���� �ȵǿ�??
//�����̵�� -> 1�� ���� �ذ� 
//�׷���. 1�� ������ �ذ��ϱ����� �ٸ� malloc���� �̻縦 ������(��ȿ����)
//���� 2���� �Ȼ���� 

//list �����͸� �������� ������ ��ħ
//������ ���ö����� �����شٴ� ����  --> array�� ���� 1 ���� 2 �ذ�
// ���� �� ���̵��

//�ڱ����� ����ü ����°� ����� �̾����� ����


#include <stdio.h>
#include <stdlib.h>

struct node {                           //list���� ������ ������ node
	int data;
	struct node* next;                          // ������ ���� �̷��� ������� 
};

// addToList
//�Էµ�����(_data)�� ��忡 �����ϰ�
//����Ʈ�� ���δ�

//����Ʈ�� �� �� ��带 ����Ű�� ������
//�ʱⰪ 0�� ����ִ� ����Ʈ��� �� 

struct node* head = 0;      // �� ���������� // ����Ʈ�� �ؾ��ϴϱ�

void addToList(int _data)           //_�� ���� data�� ������ ����
{
	struct node* new_node = 0;

	// 1.��� ����(_data�� ����)
	new_node = (struct node*)malloc(sizeof(struct node));     

	// 2.��忡 ������ �����ϰ� ������ �ʱ�ȭ 
	new_node->data = _data;
	new_node->next = 0;    //���� ������ ����ų �ְ� ����.
						   // �̹� �ִ� ���� �ڿ� �ٿ��� �ϴµ� �� ���� ������?
	                       // �̸��� head��� �ϰ� �װ� �˸� �װ��� ������ +1,2,3... ���� ���� �� �� ����

	// 3.���� ����Ʈ�� �߰�
	//ó���� ��� ����Ʈ�� ���� �������

	if (head == 0)             //����Ʈ ������ ù°
	{
		head = new_node;      // ����尡 ��尡 �� �Ѵ� ������ ���¶� ����
	}

	

	else
	{
		//1.����Ʈ�� ������ ��带 ã�´�.
		struct node* temp = head;                    //���� ����!!! �����̸� �ȵ�  �׷��� �ӽ� �����͸� ����
		while (temp->next != 0)
		{
			temp = temp->next;     // temp �� ���� ��带 ����Ű���Ѵ�. ������ ��尡 �Ǹ� ������ ����ų�� ����.
		}

		//2.������ ���(temp)�� next�� new_node�� ����Ű�� �Ѵ�.
		temp->next = new_node;
		
	}

	
}

//List�� ��� ��絥���͸� �����ִ� �Լ�
//�ӽ������͸� ���� �� �����ͷ� ���� ���������

void showList(void)
{
	struct node* temp = head;

	if (temp == 0)                 // ���� ���� ����ó�� �ʿ�
	{
		printf("\n����Ʈ �����,,,, ��������!!!!!!!!\n");
	}

	else
	{
		while (temp != 0)         // ������ 0�� �ƴѵ���
		{
			printf("%d --> ", temp->data);   //���� ����Ʈ
			temp = temp->next;             //������ ������ ����Ű���� 
		}

		//������ �������� ����Ű�� ����
	}
}

//malloc�� ������ free�� �ؾ�������
//���α׷� ������ �˾Ƽ� free�Ǳ� ������ 
//��� ����� �Ǹ� �ؾ���

void clearList()
{
	struct node* temp = head;
	
	while (head != 0)
	{
		head = head->next;
		free(temp);
		temp = head;              // ����ü ������ ũ��� �̵��ϱ⸸ �ϸ� �ȵǳ�?
	}
}

//1.���� (�߰��� �־����)
//2.���� (�ʿ��ѰŸ� �����)  (�˻�--->�ش��� ����)


//�����ϴ°� ���� 
// �� �� ���� 
// �߰�����
// �� �� ����        //���������� ���Ÿ� ���������� ����� �����

//�����͸� ���� ��带 ã�Ƽ� 
//�� ����� �ּҸ� ��ȯ
//��ȯ ���� ����ü�� �ּ���, _data�� ������ 0��ȯ

struct node* findFromList(int _data)
{
	struct node* temp = head;

	if (temp == 0)
	{
		return temp;              // temp �ȿ� 0 ��� �����ϱ�
	}
	else {

		while (temp != 0)
		{
			if (temp->data == _data)
			{
				return temp;      
			}
			else {
				temp = temp->next;
			}
		}
		return temp;       
	}
}

//me �� ����Ű�� ���� ���
struct node* findPreNode(struct node* me)
{
	struct node* temp = head;

		if (temp->next == me)
		{
			//thankyou case
			return temp;
		}
		else
		{
			temp = temp->next;
		}
}

void delFromList(int _data)
{
	struct node* temp = findFromList(_data);

	if (temp == 0)    // �� ��� ����.
	{
		// thankyou case
		printf("\n%s�� ����. ������.. ��������\n",_data);
		return;
	}

	// 1.�� ���� ��
	if (temp == head)
	{
		head = head->next;
		free(temp);
		return;
	}


	// 2.�߰��� // ����� ���� �ּҰ� �߿��� (�űⰡ ����Ű�°��� ����� �����ɷ� ������ �ϴϱ�)�׷��� ������ �� 

	else if (temp->next != 0)
	{
		struct node* prev = findPreNode(temp);
		prev->next = temp->next;
		free(temp);
		return;
	}

	else //3.��������
	{
		struct node* prev = findPreNode(temp);
		prev->next = 0;
		free(temp);
		return;
	}

}

//����

//�ߺ� ���ڴ� ����. ����
//where ���ã�Ƽ� �� �ڿ� what ��� ����
void insertIntoList(int _where, int _what)
{
	//1. _where ��� ã�� 
	struct node* temp = findFromList(_where);
	struct node* new_node = 0;

	//����  ��尡 ���� 
	if (temp == 0)
	{
		// �Ұ� ���� ��
		return; //�ް�
	}

	//2. _what ��� �űԻ���

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _what;
	new_node->next = 0;

	//3. _what ��� �߱�
	new_node->next = temp->next;
	temp->next = new_node;

}

// ���� 2 -> �տ� �ֱ�
// �� ���̸� head�� �ٲ�� �Ŵϱ� �װ� ���� �� �ϱ�

void insertbeforeIntoList(int _where, int _what)
{
	//1. _where ��� ã�� 
	struct node* temp = findFromList(_where);
	struct node* new_node = 0;

	//����  ��尡 ���� 
	if (temp == 0)
	{
		// �Ұ� ���� ��
		return; //�ް�
	}

	//2. _what ��� �űԻ���

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _what;
	new_node->next = 0;
	
	// 3.where�� head�� ���
	if (temp == head)
	{
		new_node->next = head;
		head = new_node;
		return;
	}

	// haed�� �ƴѰ��
	struct node* temp2 = 0;
	temp2 = findPreNode(temp);  // ��ǥ temp�� �� node�� temp2�� ����Ŵ
	new_node->next = temp;
	temp2->next = new_node;
	return;

}



int main()
{
	addToList(10);
	addToList(20);
	addToList(30);

	showList();
	
	// ����� ���
	//�ǵں���? �� �������� �ϳ� ����� ã�°Ŵ� ����
	//��忡 �ӽ� �����͸� ����� ��带 ���� ���� �ű��.
	//�ӽ������͸� ���� ���� �ű�� ���� ��忡 �ִ� ��带 �ٴ��� ���� 
	//�ݺ�-> 0�̸� ��
	clearList();
	showList();

	printf("\n_________________________\n");
	addToList(10);
	addToList(20);
	addToList(30);

	delFromList(20);
	showList();
	clearList();

	printf("\n_________________________\n");

	addToList(10);
	addToList(20);
	addToList(30);


	insertIntoList(20, 50);   //20�ڿ� 50 ���� ����

	showList();
	clearList();

	printf("\n_________________________\n");
	addToList(10);
	addToList(20);
	addToList(30);


	insertbeforeIntoList(20, 50);   //20�տ� 50 ���� ����

	showList();
	clearList();

	 
}


// �ڵ� �÷��ֽô°Ŷ� ���غ���

//������ ��������

