#pragma once
#include "member.h"

/*
클래스 이름 :SignUp
기능 : 회원을 회원리스트에 추가하여 회원가입 기능을 수행
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
*/
class SignUp {
private:
	vector<Member*>* member_list;
public:
	SignUp(vector<Member*>* member_list);
	void addNewMember(string name, string resident_number, string id, string pw);
};

/*
클래스 이름 :Resign
기능 : 회원을 회원리스트에 삭제하여 회원탈퇴 기능을 수행
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
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
클래스 이름 :Login
기능 : 회원이 시스템에 로그인하는 기능을 수행함
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
*/
class Login {
private:
	vector<Member*>* member_list;
public:
	Login(vector<Member*>* member_list);
	Member* checkLogin(Member** member, string id, string password);
};

/*
클래스 이름 :Logout
기능 : 회원이 시스템에 로그아웃하는 기능을 수행함
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
*/
class Logout {
private:
	Member* member;
public:
	Logout(Member*& member);
	string doLogout();
};