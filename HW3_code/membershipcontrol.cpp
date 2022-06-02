#include "membershipcontrol.h"

/*
함수 이름 : SignUp
기능 : SignUp의 생성자로써 전달받은 멤버 포인터 vector의 포인터 값을 member_list에 초기화한다.
매개변수 : vector<Member*>* member_list -> 멤버의 포인터값을 저장하고 있는 vector의 주소값
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
SignUp::SignUp(vector<Member*>* member_list) {
	this->member_list = member_list;
}

/*
함수 이름 : addNewMember
기능 : 매개변수로 받은 값들을 이용하여 새로운 회원을 생성함
매개변수 : string name -> 회원의 이름
		   string resident_number -> 회원의 주민등록번호
		   string id -> 회원의 id
		   string pw -> 회원의 패스워드
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
void SignUp::addNewMember(string name, string resident_number, string id, string pw) {
	Member* member = new Member(name, resident_number, id, pw);
	member_list->push_back(member);
}

/*
함수 이름 : Resign
기능 : Resign의 생성자로써 전달받은 멤버 포인터 vector의 포인터 값을 member_list에 초기화하고 현재 로그인되어 있는 멤버의 포인터 값을 member에 초기화 한다.
매개변수 : Member* logined_member -> 시스템에 로그인되어 있는 멤버의 포인터
		   vector<Member*>* member_list -> 멤버의 포인터값을 저장하고 있는 vector의 주소값
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
Resign::Resign(Member* logined_member, vector<Member*>* member_list) {
	member = logined_member;
	this->member_list = member_list;
}

/*
함수 이름 : resignMember
기능 : 로그인되어 있는 회원의 회원탈퇴를 진행하고 회원의 id를 boundary클래스에 전달
매개변수 : 없음
반환값 : string id -> 회원탈퇴를 진행하는 회원의 id
작성 날짜 : 2022-06-02
작성자 : 정경욱
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
함수 이름 : Login
기능 : Login의 생성자로써 전달받은 멤버 포인터 vector의 포인터 값을 member_list에 초기화한다.
매개변수 : vector<Member*>* member_list -> 멤버의 포인터값을 저장하고 있는 vector의 주소값
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
Login::Login(vector<Member*>* member_list)
{
	this->member_list = member_list;
}

/*
함수 이름 : checkLogin
기능 : 회원의 로그인 기능을 수행한다.
매개변수 : Member** member -> 시스템에 로그인 할 멤버 포인터의 포인터
		   string id -> 회원이 입력한 id
		   string password -> 회원이 입력한 패스워드
반환값 : Member* login_member -> 입력한 id, 패스워드와 일치하는 멤버의 포인터
작성 날짜 : 2022-06-02
작성자 : 정경욱
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
함수 이름 : Logout
기능 : Logout의 생성자로써 현재 로그인되어 있는 멤버의 포인터 값을 member에 초기화 한다.
매개변수 : Member* member -> 시스템에 로그인되어 있는 멤버의 포인터
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
Logout::Logout(Member*& member) {
	this->member = member;
}

/*
함수 이름 : doLogout
기능 : 로그아웃 하는 멤버의 ID를 boundary 클래스에 전달한다.
매개변수 : 없음
반환값 : string id -> 로그아웃하는 멤버의 ID
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
string Logout::doLogout() {
	return member->getID();
}
