#include "membershipUI.h"

/*
�Լ� �̸� : SignUpUI
��� : SignUpUI�� �����ڷν� ���޹��� SignUp ��ü�� �����Ͱ��� sign_up������ �ʱ�ȭ�Ѵ�.
�Ű����� : SignUp* sign_up -> SignUp ��Ʈ�� Ŭ������ ��ü ������
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
SignUpUI::SignUpUI(SignUp* sign_up) :sign_up(sign_up) {}

/*
�Լ� �̸� : inputInformation
��� : �Է� ������ ȸ������ ������ �а� ���� controlŬ������ �ش� �������� �����Ѵ�.
�Ű����� : istream& readFile -> �Է������� ���۷���
		   ostream& writeFile -> ��������� ���۷���
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
void SignUpUI::inputInformation(istream& readFile, ostream& writeFile) {
	readFile >> name >> resident_number >> id >> password;
	sign_up->addNewMember(name, resident_number, id, password);
	writeFile << "1.1. ȸ������" << endl;
	writeFile << "> " << name << ' ' << resident_number << ' ' << id << ' ' << password << ' ' << '\n' << '\n';
}

/*
�Լ� �̸� : ResignUI
��� : ResignUI�� �����ڷν� ���޹��� Resign ��ü�� �����Ͱ��� resign ������ �ʱ�ȭ�Ѵ�.
�Ű����� : Resign* resign -> Resign ��Ʈ�� Ŭ������ ��ü ������
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
ResignUI::ResignUI(Resign* resign) : resign(resign) {}

/*
�Լ� �̸� : checkResign
��� : ȸ��Ż���ϴ� ȸ���� id�� ������Ͽ� ����.
�Ű����� : ostream& writeFile -> ��������� ���۷���
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
void ResignUI::checkResign(ostream& writeFile) {
	writeFile << "1.2. ȸ��Ż��" << endl;

	id = resign->resignMember();

	writeFile << "> " << id << '\n' << '\n';
}

/*
�Լ� �̸� : LoginUI
��� : LoginUI�� �����ڷν� ���޹��� Login ��ü�� �����Ͱ��� login ������ �ʱ�ȭ�Ѵ�.
�Ű����� : Login* login -> Login ��Ʈ�� Ŭ������ ��ü ������
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
LoginUI::LoginUI(Login* login) : login(login) { }

/*
�Լ� �̸� : inputLoginInfo
��� : �Է� ������ �α��� ������ �а� ���� controlŬ������ �ش� �������� �����Ѵ�.
�Ű����� : Member** member -> �ý��ۿ� �α��� �� ��� �������� ������
		   istream& readFile -> �Է������� ���۷���
		   ostream& writeFile -> ��������� ���۷���
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
void LoginUI::inputLoginInfo(Member** member, istream& readFile, ostream& writeFile) {
	readFile >> id >> password;

	Member* return_id = login->checkLogin(member, id, password);

	if (return_id != nullptr) { // �α��� ������ �´� ���
		writeFile << "2.1. �α���" << endl;
		writeFile << "> " << id << ' ' << password << '\n' << '\n';
	}
}

/*
�Լ� �̸� : LogoutUI
��� : LogoutUI�� �����ڷν� ���޹��� Logout ��ü�� �����Ͱ��� logout ������ �ʱ�ȭ�Ѵ�.
�Ű����� : Logout* logout -> Logout ��Ʈ�� Ŭ������ ��ü ������
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
LogoutUI::LogoutUI(Logout* logout) :logout(logout) { }

/*
�Լ� �̸� : checkLogout
��� : �α׾ƿ��ϴ� ȸ���� id�� ������Ͽ� ����.
�Ű����� : ostream& writeFile -> ��������� ���۷���
��ȯ�� : ����
�ۼ� ��¥ : 2022-06-02
�ۼ��� : �����
*/
void LogoutUI::checkLogout(ostream& writeFile) {
	writeFile << "2.2. �α׾ƿ�" << endl;

	id = logout->doLogout();

	writeFile << "> " << id << '\n' << '\n';
}
