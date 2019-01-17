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
			if (cur1->val <= cur2->val){
				if (NpHead == nullptr){
					NpHead = cur1;
				}
				else{
					Ncur->next = cur1;
					Ncur->next->next = nullptr;
					cur1 = cur1->next;
					Ncur = Ncur->next;
				}
			}
			if (cur1->val > cur2->val){
				if (NpHead == nullptr){
					NpHead = cur2;
				}
				else{
					Ncur->next = cur2;
					Ncur->next->next = nullptr;
					cur2 = cur2->next;
					Ncur = Ncur->next;
				}
			}
		}
		return NpHead;
	}

public:
	ListNode * _pHead;
};


void TestFunc1(){
	Solution s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);

}

int main(){
	TestFunc1();
	system("pause");
	return 0;
}