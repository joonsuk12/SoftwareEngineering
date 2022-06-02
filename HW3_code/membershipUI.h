#pragma once
#include "membershipcontrol.h"

/*
Ŭ���� �̸� :SignUpUI
��� : �Է����Ͽ��� ȸ�������ϴ� ȸ���� ������ �а� ������Ͽ� ���� ����� ���
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class SignUpUI {
private:
	SignUp* sign_up;
	string name;
	string resident_number; //�ֹε�Ϲ�ȣ
	string id;
	string password;
public:
	SignUpUI(SignUp* sign_up);
	void inputInformation(istream& readFile, ostream& writeFile);
};

/*
Ŭ���� �̸� :ResignUI
��� : Ż���Ϸ��� ȸ���� id������ �޾� ������Ͽ� ���� ����� ���
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class ResignUI {
private:
	Resign* resign;
	string id;
public:
	ResignUI(Resign* resign);
	void checkResign(ostream& writeFile);
};

/*
Ŭ���� �̸� :LoginUI
��� : �Է����Ͽ��� �α����ϴ� ȸ���� ������ �а� ������Ͽ� ���� ����� ���
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class LoginUI {
private:
	Login* login;
	string id;
	string password;
public:
	LoginUI(Login* login);
	void inputLoginInfo(Member** member, istream& readFile, ostream& writeFile);
};

/*
Ŭ���� �̸� :LogoutUI
��� : �α׾ƿ��ϴ� ȸ���� id������ �޾� ������Ͽ� ���� ����� ���
�ۼ� ��¥: 2022-06-02
�ۼ���: �����
����: nhlee4@naver.com
*/
class LogoutUI {
private:
	Logout* logout;
	string id;
public:
	LogoutUI(Logout* logout);
	void checkLogout(ostream& writeFile);
};