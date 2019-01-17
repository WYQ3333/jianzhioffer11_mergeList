#include<iostream>

#include<assert.h>

using namespace std;

typedef int DataType;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr){
	}
};


class Solution {
public:
	Solution()
		:_pHead(nullptr)
	{}

	ListNode* BuyNewNode(DataType data){
		ListNode* NewNode = new ListNode(data);
		if (NewNode == nullptr){
			assert(NewNode);
			return nullptr;
		}
		return NewNode;
	}
	//β��
	void PushBack(DataType data){

		ListNode* NewNode = (ListNode*)BuyNewNode(data);

		if (_pHead == nullptr){
			_pHead = NewNode;
		}
		else{
			ListNode* cur = _pHead;
			while (cur->next){
				cur = cur->next;
			}
			cur->next = NewNode;
		}
	}
	
	//�ϲ�������������
	//����һ

	ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* NpHead = nullptr;
		ListNode* Ncur = NpHead;
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		if (pHead1 == nullptr&&pHead2 == nullptr){
			return nullptr;
		}
		if (pHead1 == nullptr&&pHead2!=nullptr){
			NpHead = pHead2;
			return NpHead;
		}
		if (pHead2 == nullptr&&pHead1!=nullptr){
			NpHead = pHead1;
			return NpHead;
		}

		while (cur1 != nullptr&&cur2 != nullptr){
			if (cur1 != nullptr&&cur2 != nullptr&&cur1->val <= cur2->val){
				if (NpHead == nullptr){
					NpHead = cur1;
					Ncur = NpHead;
					cur1 = cur1->next;
					NpHead->next = nullptr;
				}
				else{
					Ncur->next = cur1;
					cur1 = cur1->next;
					Ncur->next->next = nullptr;
					Ncur = Ncur->next;
				}
			}
			if (cur1 != nullptr&&cur2 != nullptr&&cur1->val > cur2->val){
				if (NpHead == nullptr){
					NpHead = cur2;
					Ncur = NpHead;
					cur2 = cur2->next;
					NpHead->next = nullptr;
				}
				else{
					Ncur->next = cur2;
					cur2 = cur2->next;
					Ncur->next->next = nullptr;
					Ncur = Ncur->next;
				}
			}
		}

		if (cur1 == nullptr&&cur2 != nullptr){
			Ncur->next = cur2;
		}
		if (cur2 == nullptr&&cur1 != nullptr){
			Ncur->next = cur1;
		}
		
		return NpHead;
	}

	ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		else if (pHead2 == NULL)
			return pHead1;

		ListNode* newhead = NULL;

		if (pHead1->val<pHead2->val)

		{
			newhead = pHead1;
			newhead->next = Merge2(pHead1->next, pHead2);
		}
		else
		{
			newhead = pHead2;
			newhead->next = Merge2(pHead1, pHead2->next);
		}
		_pHead = newhead;
		return newhead;
	}

	ListNode* Merge3(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1)
			return pHead2;
		if (!pHead2)
			return pHead1;
		ListNode* Head;
		ListNode* p;
		//ȡ��Сֵ��ͷ��� 
		if (pHead1->val <= pHead2->val){
			Head = pHead1;
			pHead1 = pHead1->next;
		}
		else{
			Head = pHead2;
			pHead2 = pHead2->next;
		}
		//��ʼ�����ϲ� 
		p = Head;                                                   //pΪ�ϲ��������Ĺ���ָ�� 
		while (pHead1&&pHead2){                       //����һ��������βʱ��ѭ������ 
			if (pHead1->val <= pHead2->val){          //�������1�Ľ��С������2�Ľ�� 
				p->next = pHead1;                            //ȡ���������ϲ����� 
				pHead1 = pHead1->next;                 //����1����һλ 
				p = p->next;                                      //����ָ�����һλ 
			}
			else{                                               //����ȡ����2�Ľ�� 
				p->next = pHead2;
				pHead2 = pHead2->next;
				p = p->next;
			}
		}
		if (pHead1 == NULL)           //����1�������� 
			p->next = pHead2;         //�������2Ҳ�������ˣ���pHead2=NULL 
		if (pHead2 == NULL)            //����2�������� 
			p->next = pHead1;			///�������1Ҳ�������ˣ���pHead1=NULL 

		_pHead = Head;
		return Head;
	}

public:
	ListNode * _pHead;
};


void TestFunc1(){
	ListNode* cur = nullptr;
	Solution s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);

	cout << "��һ��β����������Ϊ��";
	cur = s1._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;

	Solution s2;
	s2.PushBack(3);
	s2.PushBack(4);
	s2.PushBack(5);
	s2.PushBack(6);
	s2.PushBack(7);
	s2.PushBack(8);


	cout << "�ڶ���β����������Ϊ��";
	cur = s2._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;


	Solution s3;
	cur = s3.Merge1(s1._pHead, s2._pHead);

	cout << "�����κϲ�����������������Ϊ��";
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
}

void TestFunc2(){
	ListNode* cur = nullptr;
	Solution s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);

	cout << "��һ��β����������Ϊ��";
	cur = s1._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;

	Solution s2;
	s2.PushBack(3);
	s2.PushBack(4);
	s2.PushBack(5);
	s2.PushBack(6);
	s2.PushBack(7);
	s2.PushBack(8);


	cout << "�ڶ���β����������Ϊ��";
	cur = s2._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;


	Solution s3;
	cur = s3.Merge2(s1._pHead, s2._pHead);

	cout << "�����κϲ�����������������Ϊ��";
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
}

void TestFunc3(){
	ListNode* cur = nullptr;
	Solution s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);

	cout << "��һ��β����������Ϊ��";
	cur = s1._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;

	Solution s2;
	s2.PushBack(3);
	s2.PushBack(4);
	s2.PushBack(5);
	s2.PushBack(6);
	s2.PushBack(7);
	s2.PushBack(8);


	cout << "�ڶ���β����������Ϊ��";
	cur = s2._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;


	Solution s3;
	cur = s3.Merge3(s1._pHead, s2._pHead);

	cout << "�����κϲ�����������������Ϊ��";
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	TestFunc3();
	system("pause");
	return 0;
}