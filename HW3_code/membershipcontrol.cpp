#include "membershipcontrol.h"

/*
�Լ� �̸� : SignUp
��� : SignUp�� �����ڷν� ���޹��� ��� ������ vector�� ������ ���� member_list�� �ʱ�ȭ�Ѵ�.
�Ű����� : vector<Member*>* member_list -> ����� �����Ͱ��� �����ϰ� �ִ� vector�� �ּҰ�
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
SignUp::SignUp(vector<Member*>* member_list) {
	this->member_list = member_list;
}

/*
�Լ� �̸� : addNewMember
��� : �Ű������� ���� ������ �̿��Ͽ� ���ο� ȸ���� ������
�Ű����� : string name -> ȸ���� �̸�
		   string resident_number -> ȸ���� �ֹε�Ϲ�ȣ
		   string id -> ȸ���� id
		   string pw -> ȸ���� �н�����
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
void SignUp::addNewMember(string name, string resident_number, string id, string pw) {
	Member* member = new Member(name, resident_number, id, pw);
	member_list->push_back(member);
}

/*
�Լ� �̸� : Resign
��� : Resign�� �����ڷν� ���޹��� ��� ������ vector�� ������ ���� member_list�� �ʱ�ȭ�ϰ� ���� �α��εǾ� �ִ� ����� ������ ���� member�� �ʱ�ȭ �Ѵ�.
�Ű����� : Member* logined_member -> �ý��ۿ� �α��εǾ� �ִ� ����� ������
		   vector<Member*>* member_list -> ����� �����Ͱ��� �����ϰ� �ִ� vector�� �ּҰ�
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
Resign::Resign(Member* logined_member, vector<Member*>* member_list) {
	member = logined_member;
	this->member_list = member_list;
}

/*
�Լ� �̸� : resignMember
��� : �α��εǾ� �ִ� ȸ���� ȸ��Ż�� �����ϰ� ȸ���� id�� boundaryŬ������ ����
�Ű����� : ����
��ȯ�� : string id -> ȸ��Ż�� �����ϴ� ȸ���� id
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
string Resign::resignMember() {
	string id = member->getID();

	for (int i = 0; i < member_list->size(); i++) {
		if ((*member_list)[i]->getID() == id) {
			delete (*member_list)[i];
			member_list->erase(member_list->begin() + i);
		}
	}

	return id;
}

/*
�Լ� �̸� : Login
��� : Login�� �����ڷν� ���޹��� ��� ������ vector�� ������ ���� member_list�� �ʱ�ȭ�Ѵ�.
�Ű����� : vector<Member*>* member_list -> ����� �����Ͱ��� �����ϰ� �ִ� vector�� �ּҰ�
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
Login::Login(vector<Member*>* member_list)
{
	this->member_list = member_list;
}

/*
�Լ� �̸� : checkLogin
��� : ȸ���� �α��� ����� �����Ѵ�.
�Ű����� : Member** member -> �ý��ۿ� �α��� �� ��� �������� ������
		   string id -> ȸ���� �Է��� id
		   string password -> ȸ���� �Է��� �н�����
��ȯ�� : Member* login_member -> �Է��� id, �н������ ��ġ�ϴ� ����� ������
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
Member* Login::checkLogin(Member** member, string id, string password) {
	Member* login_member = nullptr;
	Member* search_member = nullptr;

	for (int i = 0; i < member_list->size(); i++) {
		if ((*member_list)[i]->getID() == id) {
			search_member = (*member_list)[i];
		}
	}

	string PW = search_member->getPW();

	if (PW == password) {
		login_member = search_member;
		*member = login_member;
	}

	return login_member;
}

/*
�Լ� �̸� : Logout
��� : Logout�� �����ڷν� ���� �α��εǾ� �ִ� ����� ������ ���� member�� �ʱ�ȭ �Ѵ�.
�Ű����� : Member* member -> �ý��ۿ� �α��εǾ� �ִ� ����� ������
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
Logout::Logout(Member*& member) {
	this->member = member;
}

/*
�Լ� �̸� : doLogout
��� : �α׾ƿ� �ϴ� ����� ID�� boundary Ŭ������ �����Ѵ�.
�Ű����� : ����
��ȯ�� : string id -> �α׾ƿ��ϴ� ����� ID
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
string Logout::doLogout() {
	return member->getID();
}
