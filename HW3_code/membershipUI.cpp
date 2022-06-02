#include "membershipUI.h"

/*
함수 이름 : SignUpUI
기능 : SignUpUI의 생성자로써 전달받은 SignUp 객체의 포인터값을 sign_up변수에 초기화한다.
매개변수 : SignUp* sign_up -> SignUp 컨트롤 클래스의 객체 포인터
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
SignUpUI::SignUpUI(SignUp* sign_up) :sign_up(sign_up) {}

/*
함수 이름 : inputInformation
기능 : 입력 파일의 회원가입 정보를 읽고 쓰며 control클래스에 해당 정보들을 전달한다.
매개변수 : istream& readFile -> 입력파일의 래퍼런스
		   ostream& writeFile -> 출력파일의 래퍼런스
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
void SignUpUI::inputInformation(istream& readFile, ostream& writeFile) {
	readFile >> name >> resident_number >> id >> password;
	sign_up->addNewMember(name, resident_number, id, password);
	writeFile << "1.1. 회원가입" << endl;
	writeFile << "> " << name << ' ' << resident_number << ' ' << id << ' ' << password << ' ' << '\n' << '\n';
}

/*
함수 이름 : ResignUI
기능 : ResignUI의 생성자로써 전달받은 Resign 객체의 포인터값을 resign 변수에 초기화한다.
매개변수 : Resign* resign -> Resign 컨트롤 클래스의 객체 포인터
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
ResignUI::ResignUI(Resign* resign) : resign(resign) {}

/*
함수 이름 : checkResign
기능 : 회원탈퇴하는 회원의 id를 출력파일에 쓴다.
매개변수 : ostream& writeFile -> 출력파일의 래퍼런스
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
void ResignUI::checkResign(ostream& writeFile) {
	writeFile << "1.2. 회원탈퇴" << endl;

	id = resign->resignMember();

	writeFile << "> " << id << '\n' << '\n';
}

/*
함수 이름 : LoginUI
기능 : LoginUI의 생성자로써 전달받은 Login 객체의 포인터값을 login 변수에 초기화한다.
매개변수 : Login* login -> Login 컨트롤 클래스의 객체 포인터
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
LoginUI::LoginUI(Login* login) : login(login) { }

/*
함수 이름 : inputLoginInfo
기능 : 입력 파일의 로그인 정보를 읽고 쓰며 control클래스에 해당 정보들을 전달한다.
매개변수 : Member** member -> 시스템에 로그인 할 멤버 포인터의 포인터
		   istream& readFile -> 입력파일의 래퍼런스
		   ostream& writeFile -> 출력파일의 래퍼런스
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
void LoginUI::inputLoginInfo(Member** member, istream& readFile, ostream& writeFile) {
	readFile >> id >> password;

	Member* return_id = login->checkLogin(member, id, password);

	if (return_id != nullptr) { // 로그인 정보가 맞는 경우
		writeFile << "2.1. 로그인" << endl;
		writeFile << "> " << id << ' ' << password << '\n' << '\n';
	}
}

/*
함수 이름 : LogoutUI
기능 : LogoutUI의 생성자로써 전달받은 Logout 객체의 포인터값을 logout 변수에 초기화한다.
매개변수 : Logout* logout -> Logout 컨트롤 클래스의 객체 포인터
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
LogoutUI::LogoutUI(Logout* logout) :logout(logout) { }

/*
함수 이름 : checkLogout
기능 : 로그아웃하는 회원의 id를 출력파일에 쓴다.
매개변수 : ostream& writeFile -> 출력파일의 래퍼런스
반환값 : 없음
작성 날짜 : 2022-06-02
작성자 : 정경욱
*/
void LogoutUI::checkLogout(ostream& writeFile) {
	writeFile << "2.2. 로그아웃" << endl;

	id = logout->doLogout();

	writeFile << "> " << id << '\n' << '\n';
}
