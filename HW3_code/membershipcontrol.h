#pragma once
#include "member.h"

/*
Ŭ���� �̸� :SignUp
��� : ȸ���� ȸ������Ʈ�� �߰��Ͽ� ȸ������ ����� ����
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class SignUp {
private:
	vector<Member*>* member_list;
public:
	SignUp(vector<Member*>* member_list);
	void addNewMember(string name, string resident_number, string id, string pw);
};

/*
Ŭ���� �̸� :Resign
��� : ȸ���� ȸ������Ʈ�� �����Ͽ� ȸ��Ż�� ����� ����
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class Resign {
private:
	Member* member;
	vector<Member*>* member_list;
public:
	Resign(Member* logined_member, vector<Member*>* member_list);
	string resignMember();
};

/*
Ŭ���� �̸� :Login
��� : ȸ���� �ý��ۿ� �α����ϴ� ����� ������
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class Login {
private:
	vector<Member*>* member_list;
public:
	Login(vector<Member*>* member_list);
	Member* checkLogin(Member** member, string id, string password);
};

/*
Ŭ���� �̸� :Logout
��� : ȸ���� �ý��ۿ� �α׾ƿ��ϴ� ����� ������
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class Logout {
private:
	Member* member;
public:
	Logout(Member*& member);
	string doLogout();
};