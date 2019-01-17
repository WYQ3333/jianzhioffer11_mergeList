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

	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
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
	cur = s3.Merge(s1._pHead, s2._pHead);

	cout << "第三次合并有序链表所得链表为：";
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	TestFunc1();
	system("pause");
	return 0;
}