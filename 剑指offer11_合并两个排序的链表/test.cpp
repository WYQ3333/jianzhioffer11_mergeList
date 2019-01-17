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
	//尾插
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
	
	//合并两个有序单链表
	//方法一

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
		//取较小值作头结点 
		if (pHead1->val <= pHead2->val){
			Head = pHead1;
			pHead1 = pHead1->next;
		}
		else{
			Head = pHead2;
			pHead2 = pHead2->next;
		}
		//开始遍历合并 
		p = Head;                                                   //p为合并后的链表的工作指针 
		while (pHead1&&pHead2){                       //当有一个链表到结尾时，循环结束 
			if (pHead1->val <= pHead2->val){          //如果链表1的结点小于链表2的结点 
				p->next = pHead1;                            //取这个结点加入合并链表 
				pHead1 = pHead1->next;                 //链表1后移一位 
				p = p->next;                                      //工作指针后移一位 
			}
			else{                                               //否则取链表2的结点 
				p->next = pHead2;
				pHead2 = pHead2->next;
				p = p->next;
			}
		}
		if (pHead1 == NULL)           //链表1遍历完了 
			p->next = pHead2;         //如果链表2也遍历完了，则pHead2=NULL 
		if (pHead2 == NULL)            //链表2遍历完了 
			p->next = pHead1;			///如果链表1也遍历完了，则pHead1=NULL 

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

	cout << "第一次尾插所得链表为：";
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


	cout << "第二次尾插所得链表为：";
	cur = s2._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;


	Solution s3;
	cur = s3.Merge1(s1._pHead, s2._pHead);

	cout << "第三次合并有序链表所得链表为：";
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

	cout << "第一次尾插所得链表为：";
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


	cout << "第二次尾插所得链表为：";
	cur = s2._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;


	Solution s3;
	cur = s3.Merge2(s1._pHead, s2._pHead);

	cout << "第三次合并有序链表所得链表为：";
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

	cout << "第一次尾插所得链表为：";
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


	cout << "第二次尾插所得链表为：";
	cur = s2._pHead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;


	Solution s3;
	cur = s3.Merge3(s1._pHead, s2._pHead);

	cout << "第三次合并有序链表所得链表为：";
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