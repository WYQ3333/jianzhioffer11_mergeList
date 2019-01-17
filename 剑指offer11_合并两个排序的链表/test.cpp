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
	//Î²²å
	void PushBack(DataType data){

		ListNode* NewNode = (ListNode*)BuyNewNode(data);

		if (_pHead == nullptr){
			_pHead = NewNode;
		}
		ListNode* cur = _pHead;
		while (cur){
			cur = cur->next;
		}
		cur = NewNode;
	}
	
	//ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	//{

	//}

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