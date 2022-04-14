#include <iostream>
#include "Reader.hpp"
#include "Writer.hpp"

int main(int ac, char *av[])
{
	Writer w(av[1]);
	Reader r(av[1]);

	if (!w.isWriterUsable() || !r.isReaderUsable())
		return (1);

	
	// 이니셜라이저 : 입력 유효성 파악하고, 적합하면 리더/롸이터 생성.
	// 리더/롸이터 -> 입력fd, 출력fd가 저장. iostream을 반환하고 입력받는 함수
	// 리플레이서 -> 리더/롸이터를 인자로 받음. 변환 방식이 저장된 클래스.
	return (0);
}