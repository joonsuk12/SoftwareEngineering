#pragma once
#include "membershipcontrol.h"

/*
클래스 이름 :SignUpUI
기능 : 입력파일에서 회원가입하는 회원의 정보를 읽고 출력파일에 쓰는 기능을 담당
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
*/
class SignUpUI {
private:
	SignUp* sign_up;
	string name;
	string resident_number; //주민등록번호
	string id;
	string password;
public:
	SignUpUI(SignUp* sign_up);
	void inputInformation(istream& readFile, ostream& writeFile);
};

/*
클래스 이름 :ResignUI
기능 : 탈퇴하려는 회원의 id정보를 받아 출력파일에 쓰는 기능을 담당
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
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
클래스 이름 :LoginUI
기능 : 입력파일에서 로그인하는 회원의 정보를 읽고 출력파일에 쓰는 기능을 담당
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
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
클래스 이름 :LogoutUI
기능 : 로그아웃하는 회원의 id정보를 받아 출력파일에 쓰는 기능을 담당
작성 날짜: 2022-06-02
작성자: 정경욱
메일: nhlee4@naver.com
*/
class LogoutUI {
private:
	Logout* logout;
	string id;
public:
	LogoutUI(Logout* logout);
	void checkLogout(ostream& writeFile);
};